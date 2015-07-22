#ifndef GrContext_DEFINED
#define GrContext_DEFINED

#include "GrClipData.h"
#include "GrColor.h"
#include "GrPaint.h"
#include "GrPathRendererChain.h"
#include "GrPoint.h"
#include "GrRenderTarget.h"
#include "GrTexture.h"
#include "SkMatrix.h"
#include "SkTypes.h"

class GrAARectRenderer;
class GrAutoScratchTexture;
class GrDrawState;
class GrDrawTarget;
class GrEffect;
class GrFontCache;
class GrGpu;
class GrIndexBuffer;
class GrIndexBufferAllocPool;
class GrInOrderDrawBuffer;
class GrOvalRenderer;
class GrPath;
class GrPathRenderer;
class GrResourceEntry;
class GrResourceCache;
class GrStencilBuffer;
class GrTestTarget;
class GrTextureParams;
class GrVertexBuffer;
class GrVertexBufferAllocPool;
class GrSoftwarePathRenderer;
class SkStrokeRec;

class SK_API GrContext : public SkRefCnt
{
public:
    SK_DECLARE_INST_COUNT(GrContext)

    static GrContext* Create( );
    virtual ~GrContext();
	void resetContext(uint32_t state = kAll_GrBackendState);
    typedef void (*PFCleanUpFunc)(const GrContext* context, void* info);
    void addCleanUp(PFCleanUpFunc cleanUp, void* info) {
        CleanUpData* entry = fCleanUpData.push();

        entry->fFunc = cleanUp;
        entry->fInfo = info;
    }
    void contextLost();
    void contextDestroyed();
    void freeGpuResources();
    size_t getGpuTextureCacheBytes() const;

    GrTexture* createTexture(const GrTextureParams* params,
                             const GrTextureDesc& desc,
                             const GrCacheID& cacheID,
                             void* srcData,
                             size_t rowBytes,
                             GrResourceKey* cacheKey = NULL);

    GrTexture* findAndRefTexture(const GrTextureDesc& desc,
                                 const GrCacheID& cacheID,
                                 const GrTextureParams* params);

    bool isTextureInCache(const GrTextureDesc& desc,
                          const GrCacheID& cacheID,
                          const GrTextureParams* params) const;

    enum ScratchTexMatch 
	{
        kExact_ScratchTexMatch,
        kApprox_ScratchTexMatch
    };

    GrTexture* lockAndRefScratchTexture(const GrTextureDesc&, ScratchTexMatch match);
    void unlockScratchTexture(GrTexture* texture);
    void purgeCache();
    void purgeAllUnlockedResources();
    GrTexture* createUncachedTexture(const GrTextureDesc& desc,
                                     void* srcData,
                                     size_t rowBytes);

    bool supportsIndex8PixelConfig(const GrTextureParams*,
                                   int width,
                                   int height) const;

    void getTextureCacheLimits(int* maxTextures, size_t* maxTextureBytes) const;

    void setTextureCacheLimits(int maxTextures, size_t maxTextureBytes);

    int getMaxTextureSize() const;

    void setMaxTextureSizeOverride(int maxTextureSizeOverride);

    void setRenderTarget(GrRenderTarget* target) {
        fRenderTarget.reset(SkSafeRef(target));
    }

    const GrRenderTarget* getRenderTarget() const { return fRenderTarget.get(); }
    GrRenderTarget* getRenderTarget() { return fRenderTarget.get(); }

    GrAARectRenderer* getAARectRenderer() { return fAARectRenderer; }

    bool isConfigRenderable(GrPixelConfig config, bool withMSAA) const;

    int getMaxRenderTargetSize() const;

    int getMaxSampleCount() const;
    GrTexture* wrapBackendTexture(const GrBackendTextureDesc& desc);
    GrRenderTarget* wrapBackendRenderTarget(const GrBackendRenderTargetDesc& desc);

    const SkMatrix& getMatrix() const { return fViewMatrix; }

    void setMatrix(const SkMatrix& m) { fViewMatrix = m; }
    void setIdentityMatrix() { fViewMatrix.reset(); }
    void concatMatrix(const SkMatrix& m) { fViewMatrix.preConcat(m); }


    ///////////////////////////////////////////////////////////////////////////
    // Clip state
    /**
     * Gets the current clip.
     * @return the current clip.
     */
    const GrClipData* getClip() const { return fClip; }

    /**
     * Sets the clip.
     * @param clipData  the clip to set.
     */
    void setClip(const GrClipData* clipData) { fClip = clipData; }

    ///////////////////////////////////////////////////////////////////////////
    // Draws

    /**
     * Clear the entire or rect of the render target, ignoring any clips.
     * @param rect  the rect to clear or the whole thing if rect is NULL.
     * @param color the color to clear to.
     * @param canIgnoreRect allows partial clears to be converted to whole
     *                      clears on platforms for which that is cheap
     * @param target if non-NULL, the render target to clear otherwise clear
     *               the current render target
     */
    void clear(const SkIRect* rect, GrColor color, bool canIgnoreRect,
               GrRenderTarget* target = NULL);

    /**
     *  Draw everywhere (respecting the clip) with the paint.
     */
    void drawPaint(const GrPaint& paint);

    /**
     *  Draw the rect using a paint.
     *  @param paint        describes how to color pixels.
     *  @param stroke       the stroke information (width, join, cap).
     *                      If stroke == NULL, then the rect is filled.
     *                      Otherwise, if stroke width == 0, then the stroke
     *                      is always a single pixel thick, else the rect is
     *                      mitered/beveled stroked based on stroke width.
     *  @param matrix       Optional matrix applied to the rect. Applied before
     *                      context's matrix or the paint's matrix.
     *  The rects coords are used to access the paint (through texture matrix)
     */
    void drawRect(const GrPaint& paint,
                  const SkRect&,
                  const SkStrokeRec* stroke = NULL,
                  const SkMatrix* matrix = NULL);

    /**
     * Maps a rect of local coordinates onto the a rect of destination
     * coordinates. Each rect can optionally be transformed. The localRect
     * is stretched over the dstRect. The dstRect is transformed by the
     * context's matrix. Additional optional matrices for both rects can be
     * provided by parameters.
     *
     * @param paint         describes how to color pixels.
     * @param dstRect       the destination rect to draw.
     * @param localRect     rect of local coordinates to be mapped onto dstRect
     * @param dstMatrix     Optional matrix to transform dstRect. Applied before context's matrix.
     * @param localMatrix   Optional matrix to transform localRect.
     */
    void drawRectToRect(const GrPaint& paint,
                        const SkRect& dstRect,
                        const SkRect& localRect,
                        const SkMatrix* dstMatrix = NULL,
                        const SkMatrix* localMatrix = NULL);

    /**
     *  Draw a roundrect using a paint.
     *
     *  @param paint        describes how to color pixels.
     *  @param rrect        the roundrect to draw
     *  @param stroke       the stroke information (width, join, cap)
     */
    void drawRRect(const GrPaint& paint,
                   const SkRRect& rrect,
                   const SkStrokeRec& stroke);

    /**
     * Draws a path.
     *
     * @param paint         describes how to color pixels.
     * @param path          the path to draw
     * @param stroke        the stroke information (width, join, cap)
     */
    void drawPath(const GrPaint& paint, const SkPath& path, const SkStrokeRec& stroke);

    /**
     * Draws vertices with a paint.
     *
     * @param   paint           describes how to color pixels.
     * @param   primitiveType   primitives type to draw.
     * @param   vertexCount     number of vertices.
     * @param   positions       array of vertex positions, required.
     * @param   texCoords       optional array of texture coordinates used
     *                          to access the paint.
     * @param   colors          optional array of per-vertex colors, supercedes
     *                          the paint's color field.
     * @param   indices         optional array of indices. If NULL vertices
     *                          are drawn non-indexed.
     * @param   indexCount      if indices is non-null then this is the
     *                          number of indices.
     */
    void drawVertices(const GrPaint& paint,
                      GrPrimitiveType primitiveType,
                      int vertexCount,
                      const GrPoint positions[],
                      const GrPoint texs[],
                      const GrColor colors[],
                      const uint16_t indices[],
                      int indexCount);

    /**
     * Draws an oval.
     *
     * @param paint         describes how to color pixels.
     * @param oval          the bounding rect of the oval.
     * @param stroke        the stroke information (width, style)
     */
    void drawOval(const GrPaint& paint,
                  const SkRect& oval,
                  const SkStrokeRec& stroke);

    ///////////////////////////////////////////////////////////////////////////
    // Misc.
    /**
     * Call to ensure all drawing to the context has been issued to the
     * underlying 3D API.
     * @param flagsBitfield     flags that control the flushing behavior. See
     *                          FlushBits.
     */
    void flush( );

   /**
    * These flags can be used with the read/write pixels functions below.
    */
    enum PixelOpsFlags {
        /** The GrContext will not be flushed. This means that the read or write may occur before
            previous draws have executed. */
        kDontFlush_PixelOpsFlag = 0x1,
        /** The src for write or dst read is unpremultiplied. This is only respected if both the
            config src and dst configs are an RGBA/BGRA 8888 format. */
        kUnpremul_PixelOpsFlag  = 0x2,
    };

    /**
     * Reads a rectangle of pixels from a render target.
     * @param target        the render target to read from. NULL means the current render target.
     * @param left          left edge of the rectangle to read (inclusive)
     * @param top           top edge of the rectangle to read (inclusive)
     * @param width         width of rectangle to read in pixels.
     * @param height        height of rectangle to read in pixels.
     * @param config        the pixel config of the destination buffer
     * @param buffer        memory to read the rectangle into.
     * @param rowBytes      number of bytes bewtween consecutive rows. Zero means rows are tightly
     *                      packed.
     * @param pixelOpsFlags see PixelOpsFlags enum above.
     *
     * @return true if the read succeeded, false if not. The read can fail because of an unsupported
     *         pixel config or because no render target is currently set and NULL was passed for
     *         target.
     */
    bool readRenderTargetPixels(GrRenderTarget* target,
                                int left, int top, int width, int height,
                                GrPixelConfig config, void* buffer,
                                size_t rowBytes = 0,
                                uint32_t pixelOpsFlags = 0);

    /**
     * Copy the src pixels [buffer, row bytes, pixel config] into a render target at the specified
     * rectangle.
     * @param target        the render target to write into. NULL means the current render target.
     * @param left          left edge of the rectangle to write (inclusive)
     * @param top           top edge of the rectangle to write (inclusive)
     * @param width         width of rectangle to write in pixels.
     * @param height        height of rectangle to write in pixels.
     * @param config        the pixel config of the source buffer
     * @param buffer        memory to read the rectangle from.
     * @param rowBytes      number of bytes between consecutive rows. Zero means rows are tightly
     *                      packed.
     * @param pixelOpsFlags see PixelOpsFlags enum above.
     *
     * @return true if the write succeeded, false if not. The write can fail because of an
     *         unsupported combination of target and pixel configs.
     */
    bool writeRenderTargetPixels(GrRenderTarget* target,
                                 int left, int top, int width, int height,
                                 GrPixelConfig config, const void* buffer,
                                 size_t rowBytes = 0,
                                 uint32_t pixelOpsFlags = 0);

    /**
     * Reads a rectangle of pixels from a texture.
     * @param texture       the texture to read from.
     * @param left          left edge of the rectangle to read (inclusive)
     * @param top           top edge of the rectangle to read (inclusive)
     * @param width         width of rectangle to read in pixels.
     * @param height        height of rectangle to read in pixels.
     * @param config        the pixel config of the destination buffer
     * @param buffer        memory to read the rectangle into.
     * @param rowBytes      number of bytes between consecutive rows. Zero means rows are tightly
     *                      packed.
     * @param pixelOpsFlags see PixelOpsFlags enum above.
     *
     * @return true if the read succeeded, false if not. The read can fail because of an unsupported
     *         pixel config.
     */
    bool readTexturePixels(GrTexture* texture,
                           int left, int top, int width, int height,
                           GrPixelConfig config, void* buffer,
                           size_t rowBytes = 0,
                           uint32_t pixelOpsFlags = 0);

    /**
     * Writes a rectangle of pixels to a texture.
     * @param texture       the render target to read from.
     * @param left          left edge of the rectangle to write (inclusive)
     * @param top           top edge of the rectangle to write (inclusive)
     * @param width         width of rectangle to write in pixels.
     * @param height        height of rectangle to write in pixels.
     * @param config        the pixel config of the source buffer
     * @param buffer        memory to read pixels from
     * @param rowBytes      number of bytes between consecutive rows. Zero
     *                      means rows are tightly packed.
     * @param pixelOpsFlags see PixelOpsFlags enum above.
     * @return true if the write succeeded, false if not. The write can fail because of an
     *         unsupported combination of texture and pixel configs.
     */
    bool writeTexturePixels(GrTexture* texture,
                            int left, int top, int width, int height,
                            GrPixelConfig config, const void* buffer,
                            size_t rowBytes,
                            uint32_t pixelOpsFlags = 0);


    /**
     * Copies a rectangle of texels from src to dst. The size of dst is the size of the rectangle
     * copied and topLeft is the position of the rect in src. The rectangle is clipped to src's
     * bounds.
     * @param src           the texture to copy from.
     * @param dst           the render target to copy to.
     * @param topLeft       the point in src that will be copied to the top-left of dst. If NULL,
     *                      (0, 0) will be used.
     */
    void copyTexture(GrTexture* src, GrRenderTarget* dst, const SkIPoint* topLeft = NULL);

    /**
     * Resolves a render target that has MSAA. The intermediate MSAA buffer is
     * down-sampled to the associated GrTexture (accessible via
     * GrRenderTarget::asTexture()). Any pending draws to the render target will
     * be executed before the resolve.
     *
     * This is only necessary when a client wants to access the object directly
     * using the backend API directly. GrContext will detect when it must
     * perform a resolve to a GrTexture used as the source of a draw or before
     * reading pixels back from a GrTexture or GrRenderTarget.
     */
    void resolveRenderTarget(GrRenderTarget* target);

#ifdef SK_DEVELOPER
    void dumpFontCache() const;
#endif

    ///////////////////////////////////////////////////////////////////////////
    // Helpers

    class AutoRenderTarget : public ::SkNoncopyable
	{
    public:
        AutoRenderTarget(GrContext* context, GrRenderTarget* target) 
		{
            fPrevTarget = context->getRenderTarget();
            SkSafeRef(fPrevTarget);
            context->setRenderTarget(target);
            fContext = context;
        }
        AutoRenderTarget(GrContext* context) {
            fPrevTarget = context->getRenderTarget();
            SkSafeRef(fPrevTarget);
            fContext = context;
        }
        ~AutoRenderTarget() {
            if (NULL != fContext) {
                fContext->setRenderTarget(fPrevTarget);
            }
            SkSafeUnref(fPrevTarget);
        }
    private:
        GrContext*      fContext;
        GrRenderTarget* fPrevTarget;
    };

    /**
     * Save/restore the view-matrix in the context. It can optionally adjust a paint to account
     * for a coordinate system change. Here is an example of how the paint param can be used:
     *
     * A GrPaint is setup with GrEffects. The stages will have access to the pre-matrix source
     * geometry positions when the draw is executed. Later on a decision is made to transform the
     * geometry to device space on the CPU. The effects now need to know that the space in which
     * the geometry will be specified has changed.
     *
     * Note that when restore is called (or in the destructor) the context's matrix will be
     * restored. However, the paint will not be restored. The caller must make a copy of the
     * paint if necessary. Hint: use SkTCopyOnFirstWrite if the AutoMatrix is conditionally
     * initialized.
     */
    class AutoMatrix : public ::SkNoncopyable 
	{
    public:
        AutoMatrix() : fContext(NULL) {}
        ~AutoMatrix() { this->restore(); }

        /**
         * Initializes by pre-concat'ing the context's current matrix with the preConcat param.
         */
        void setPreConcat(GrContext* context, const SkMatrix& preConcat, GrPaint* paint = NULL) {
            this->restore();

            fContext = context;
            fMatrix = context->getMatrix();
            this->preConcat(preConcat, paint);
        }

        /**
         * Sets the context's matrix to identity. Returns false if the inverse matrix is required to
         * update a paint but the matrix cannot be inverted.
         */
        bool setIdentity(GrContext* context, GrPaint* paint = NULL) {

            this->restore();

            if (NULL != paint) {
                if (!paint->localCoordChangeInverse(context->getMatrix())) {
                    return false;
                }
            }
            fMatrix = context->getMatrix();
            fContext = context;
            context->setIdentityMatrix();
            return true;
        }

        /**
         * Replaces the context's matrix with a new matrix. Returns false if the inverse matrix is
         * required to update a paint but the matrix cannot be inverted.
         */
        bool set(GrContext* context, const SkMatrix& newMatrix, GrPaint* paint = NULL) {
            if (NULL != paint) {
                if (!this->setIdentity(context, paint)) {
                    return false;
                }
                this->preConcat(newMatrix, paint);
            } else {
                this->restore();
                fContext = context;
                fMatrix = context->getMatrix();
                context->setMatrix(newMatrix);
            }
            return true;
        }

        /**
         * If this has been initialized then the context's matrix will be further updated by
         * pre-concat'ing the preConcat param. The matrix that will be restored remains unchanged.
         * The paint is assumed to be relative to the context's matrix at the time this call is
         * made, not the matrix at the time AutoMatrix was first initialized. In other words, this
         * performs an incremental update of the paint.
         */
        void preConcat(const SkMatrix& preConcat, GrPaint* paint = NULL) {
            if (NULL != paint) {
                paint->localCoordChange(preConcat);
            }
            fContext->concatMatrix(preConcat);
        }

        /**
         * Returns false if never initialized or the inverse matrix was required to update a paint
         * but the matrix could not be inverted.
         */
        bool succeeded() const { return NULL != fContext; }

        /**
         * If this has been initialized then the context's original matrix is restored.
         */
        void restore() {
            if (NULL != fContext) {
                fContext->setMatrix(fMatrix);
                fContext = NULL;
            }
        }

    private:
        GrContext*  fContext;
        SkMatrix    fMatrix;
    };

    class AutoClip : public ::SkNoncopyable 
	{
    public:
        // This enum exists to require a caller of the constructor to acknowledge that the clip will
        // initially be wide open. It also could be extended if there are other desirable initial
        // clip states.
        enum InitialClip {
            kWideOpen_InitialClip,
        };

        AutoClip(GrContext* context, InitialClip initialState)
        : fContext(context) {
            fNewClipData.fClipStack = &fNewClipStack;

            fOldClip = context->getClip();
            context->setClip(&fNewClipData);
        }

        AutoClip(GrContext* context, const SkRect& newClipRect)
        : fContext(context)
        , fNewClipStack(newClipRect) {
            fNewClipData.fClipStack = &fNewClipStack;

            fOldClip = fContext->getClip();
            fContext->setClip(&fNewClipData);
        }

        ~AutoClip() {
            if (NULL != fContext) {
                fContext->setClip(fOldClip);
            }
        }
    private:
        GrContext*        fContext;
        const GrClipData* fOldClip;

        SkClipStack       fNewClipStack;
        GrClipData        fNewClipData;
    };

    class AutoWideOpenIdentityDraw
	{
    public:
        AutoWideOpenIdentityDraw(GrContext* ctx, GrRenderTarget* rt)
            : fAutoClip(ctx, AutoClip::kWideOpen_InitialClip)
            , fAutoRT(ctx, rt) {
            fAutoMatrix.setIdentity(ctx);
            // should never fail with no paint param.
        }

    private:
        AutoClip fAutoClip;
        AutoRenderTarget fAutoRT;
        AutoMatrix fAutoMatrix;
    };

    ///////////////////////////////////////////////////////////////////////////
    // Functions intended for internal use only.
    GrGpu* getGpu() { return fGpu; }
    const GrGpu* getGpu() const { return fGpu; }
    GrFontCache* getFontCache() { return fFontCache; }
    GrDrawTarget* getTextTarget();
    const GrIndexBuffer* getQuadIndexBuffer() const;

    // Called by tests that draw directly to the context via GrDrawTarget
    void getTestTarget(GrTestTarget*);

    /**
     * Stencil buffers add themselves to the cache using addStencilBuffer. findStencilBuffer is
     * called to check the cache for a SB that matches an RT's criteria.
     */
    void addStencilBuffer(GrStencilBuffer* sb);
    GrStencilBuffer* findStencilBuffer(int width, int height, int sampleCnt);

    GrPathRenderer* getPathRenderer(
                    const SkPath& path,
                    const SkStrokeRec& stroke,
                    const GrDrawTarget* target,
                    bool allowSW,
                    GrPathRendererChain::DrawType drawType = GrPathRendererChain::kColor_DrawType,
                    GrPathRendererChain::StencilSupport* stencilSupport = NULL);



private:
    // Used to indicate whether a draw should be performed immediately or queued in fDrawBuffer.
    enum BufferedDraw
	{
        kYes_BufferedDraw,
        kNo_BufferedDraw,
    };
    BufferedDraw fLastDrawWasBuffered;

    GrGpu*                          fGpu;
    SkMatrix                        fViewMatrix;
    SkAutoTUnref<GrRenderTarget>    fRenderTarget;
    const GrClipData*               fClip;  // TODO: make this ref counted
    GrDrawState*                    fDrawState;

    GrResourceCache*                fTextureCache;
    GrFontCache*                    fFontCache;

    GrPathRendererChain*            fPathRendererChain;
    GrSoftwarePathRenderer*         fSoftwarePathRenderer;

    GrVertexBufferAllocPool*        fDrawBufferVBAllocPool;
    GrIndexBufferAllocPool*         fDrawBufferIBAllocPool;
    GrInOrderDrawBuffer*            fDrawBuffer;

    // Set by OverbudgetCB() to request that GrContext flush before exiting a draw.
    bool                            fFlushToReduceCacheSize;

    GrAARectRenderer*               fAARectRenderer;
    GrOvalRenderer*                 fOvalRenderer;

    bool                            fDidTestPMConversions;
    int                             fPMToUPMConversion;
    int                             fUPMToPMConversion;

    struct CleanUpData
	{
        PFCleanUpFunc fFunc;
        void*         fInfo;
    };

    SkTDArray<CleanUpData>          fCleanUpData;

    int                             fMaxTextureSizeOverride;

    GrContext(); // init must be called after the constructor.
    bool init( );

    void setupDrawBuffer();

    class AutoRestoreEffects;
    class AutoCheckFlush;
    /// Sets the paint and returns the target to draw into. The paint can be NULL in which case the
    /// draw state is left unmodified.
    GrDrawTarget* prepareToDraw(const GrPaint*, BufferedDraw, AutoRestoreEffects*, AutoCheckFlush*);

    void internalDrawPath(GrDrawTarget* target, bool useAA, const SkPath& path,
                          const SkStrokeRec& stroke);

    GrTexture* createResizedTexture(const GrTextureDesc& desc,
                                    const GrCacheID& cacheID,
                                    void* srcData,
                                    size_t rowBytes,
                                    bool filter);

    // Needed so GrTexture's returnToCache helper function can call
    // addExistingTextureToCache
    friend class GrTexture;
    friend class GrStencilAndCoverPathRenderer;

    // Add an existing texture to the texture cache. This is intended solely
    // for use with textures released from an GrAutoScratchTexture.
    void addExistingTextureToCache(GrTexture* texture);

    /**
     * These functions create premul <-> unpremul effects if it is possible to generate a pair
     * of effects that make a readToUPM->writeToPM->readToUPM cycle invariant. Otherwise, they
     * return NULL.
     */
    const GrEffectRef* createPMToUPMEffect(GrTexture* texture,
                                           bool swapRAndB,
                                           const SkMatrix& matrix);
    const GrEffectRef* createUPMToPMEffect(GrTexture* texture,
                                           bool swapRAndB,
                                           const SkMatrix& matrix);

    /**
     *  This callback allows the resource cache to callback into the GrContext
     *  when the cache is still overbudget after a purge.
     */
    static bool OverbudgetCB(void* data);

    /** Creates a new gpu path, based on the specified path and stroke and returns it.
     * The caller owns a ref on the returned path which must be balanced by a call to unref.
     *
     * @param skPath the path geometry.
     * @param stroke the path stroke.
     * @return a new path or NULL if the operation is not supported by the backend.
     */
    GrPath* createPath(const SkPath& skPath, const SkStrokeRec& stroke);

    typedef SkRefCnt INHERITED;
};

/**
 * Gets and locks a scratch texture from a descriptor using either exact or approximate criteria.
 * Unlocks texture in the destructor.
 */
class GrAutoScratchTexture : public ::SkNoncopyable {
public:
    GrAutoScratchTexture()
        : fContext(NULL)
        , fTexture(NULL) {
    }

    GrAutoScratchTexture(GrContext* context,
                         const GrTextureDesc& desc,
                         GrContext::ScratchTexMatch match = GrContext::kApprox_ScratchTexMatch)
      : fContext(NULL)
      , fTexture(NULL) {
      this->set(context, desc, match);
    }

    ~GrAutoScratchTexture() {
        this->reset();
    }

    void reset() {
        if (NULL != fContext && NULL != fTexture) {
            fContext->unlockScratchTexture(fTexture);
            fTexture->unref();
            fTexture = NULL;
        }
    }

    /*
     * When detaching a texture we do not unlock it in the texture cache but
     * we do set the returnToCache flag. In this way the texture remains
     * "locked" in the texture cache until it is freed and recycled in
     * GrTexture::internal_dispose. In reality, the texture has been removed
     * from the cache (because this is in AutoScratchTexture) and by not
     * calling unlockScratchTexture we simply don't re-add it. It will be
     * reattached in GrTexture::internal_dispose.
     *
     * Note that the caller is assumed to accept and manage the ref to the
     * returned texture.
     */
    GrTexture* detach() {
        if (NULL == fTexture) {
            return NULL;
        }
        GrTexture* texture = fTexture;
        fTexture = NULL;

        // This GrAutoScratchTexture has a ref from lockAndRefScratchTexture, which we give up now.
        // The cache also has a ref which we are lending to the caller of detach(). When the caller
        // lets go of the ref and the ref count goes to 0 internal_dispose will see this flag is
        // set and re-ref the texture, thereby restoring the cache's ref.
        texture->setFlag((GrTextureFlags) GrTexture::kReturnToCache_FlagBit);
        texture->unref();

        return texture;
    }

    GrTexture* set(GrContext* context,
                   const GrTextureDesc& desc,
                   GrContext::ScratchTexMatch match = GrContext::kApprox_ScratchTexMatch) {
        this->reset();

        fContext = context;
        if (NULL != fContext) {
            fTexture = fContext->lockAndRefScratchTexture(desc, match);
            if (NULL == fTexture) {
                fContext = NULL;
            }
            return fTexture;
        } else {
            return NULL;
        }
    }

    GrTexture* texture() { return fTexture; }

private:
    GrContext*                    fContext;
    GrTexture*                    fTexture;
};

#endif
