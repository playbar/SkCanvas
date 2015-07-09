#ifndef SkView_DEFINED
#define SkView_DEFINED

#include "SkEventSink.h"
#include "SkRect.h"
#include "SkDOM.h"
#include "SkTDict.h"
#include "SkMatrix.h"
#include "SkMetaData.h"

class SkCanvas;
class SkLayerView;

class SkView : public SkEventSink {
public:
    enum Flag_Shift {
        kVisible_Shift,
        kEnabled_Shift,
        kFocusable_Shift,
        kFlexH_Shift,
        kFlexV_Shift,
        kNoClip_Shift,

        kFlagShiftCount
    };
    enum Flag_Mask {
        kVisible_Mask   = 1 << kVisible_Shift,      //!< set if the view is visible
        kEnabled_Mask   = 1 << kEnabled_Shift,      //!< set if the view is enabled
        kFocusable_Mask = 1 << kFocusable_Shift,    //!< set if the view can receive focus
        kFlexH_Mask     = 1 << kFlexH_Shift,        //!< set if the view's width is stretchable
        kFlexV_Mask     = 1 << kFlexV_Shift,        //!< set if the view's height is stretchable
        kNoClip_Mask    = 1 << kNoClip_Shift,        //!< set if the view is not clipped to its bounds

        kAllFlagMasks   = (uint32_t)(0 - 1) >> (32 - kFlagShiftCount)
    };

                SkView(uint32_t flags = 0);
    virtual     ~SkView();

    uint32_t    getFlags() const { return fFlags; }
    void        setFlags(uint32_t flags);

    int         isVisible() const { return fFlags & kVisible_Mask; }
    int         isEnabled() const { return fFlags & kEnabled_Mask; }
    int         isFocusable() const { return fFlags & kFocusable_Mask; }
    int         isClipToBounds() const { return !(fFlags & kNoClip_Mask); }
    void        setVisibleP(bool);
    void        setEnabledP(bool);
    void        setFocusableP(bool);
    void        setClipToBounds(bool);

    float    width() const { return fWidth; }
    float    height() const { return fHeight; }
    void        setSize(float width, float height);
    void        setSize(const SkPoint& size) { this->setSize(size.fX, size.fY); }
    void        setWidth(float width) { this->setSize(width, fHeight); }
    void        setHeight(float height) { this->setSize(fWidth, height); }
    void        getLocalBounds(SkRect* bounds) const;

    float    locX() const { return fLoc.fX; }
    float    locY() const { return fLoc.fY; }
    void        setLoc(float x, float y);
    void        setLoc(const SkPoint& loc) { this->setLoc(loc.fX, loc.fY); }
    void        setLocX(float x) { this->setLoc(x, fLoc.fY); }
    void        setLocY(float y) { this->setLoc(fLoc.fX, y); }
    const SkMatrix& getLocalMatrix() const { return fMatrix; }
    void            setLocalMatrix(const SkMatrix& matrix);
    void        offset(float dx, float dy);
    virtual void draw(SkCanvas* canvas);
    void        inval(SkRect* rectOrNull);
    SkView* getFocusView() const;
    bool    hasFocus() const;

    enum FocusDirection {
        kNext_FocusDirection,
        kPrev_FocusDirection,

        kFocusDirectionCount
    };
    bool    acceptFocus();

    class Click 
	{
    public:
        Click(SkView* target);
        virtual ~Click();

        const char* getType() const { return fType; }
        bool        isType(const char type[]) const;
        void        setType(const char type[]);     // does NOT make a copy of the string
        void        copyType(const char type[]);    // makes a copy of the string

        enum State 
		{
            kDown_State,
            kMoved_State,
            kUp_State
        };
        SkPoint     fOrig, fPrev, fCurr;
        SkIPoint    fIOrig, fIPrev, fICurr;
        State       fState;
        void*       fOwner;
        unsigned    fModifierKeys;

        SkMetaData  fMeta;
    private:
        SkEventSinkID   fTargetID;
        char*           fType;
        bool            fWeOwnTheType;

        void resetType();

        friend class SkView;
    };
    Click*  findClickHandler(float x, float y, unsigned modifierKeys);

    static void DoClickDown(Click*, int x, int y, unsigned modi);
    static void DoClickMoved(Click*, int x, int y, unsigned modi);
    static void DoClickUp(Click*, int x, int y, unsigned modi);

	SkView* sendEventToParents(const SkEvent&);
    SkView* sendQueryToParents(SkEvent*);

    SkView*     getParent() const { return fParent; }
    SkView*     attachChildToFront(SkView* child);
    SkView*     attachChildToBack(SkView* child);
    void        detachFromParent();
    void        detachAllChildren();
    bool        globalToLocal(SkPoint* pt) const 
	{
        if (NULL != pt)
		{
            return this->globalToLocal(pt->fX, pt->fY, pt);
        }
        return true;  // nothing to do so return true
    }
    bool globalToLocal(float globalX, float globalY, SkPoint* local) const;

    /** \class F2BIter

        Iterator that will return each of this view's children, in
        front-to-back order (the order used for clicking). The first
        call to next() returns the front-most child view. When
        next() returns null, there are no more child views.
    */
	class F2BIter {
	public:
		F2BIter(const SkView* parent);
		SkView* next();
	private:
		SkView* fFirstChild, *fChild;
	};

    /** \class B2FIter

        Iterator that will return each of this view's children, in
        back-to-front order (the order they are drawn). The first
        call to next() returns the back-most child view. When
        next() returns null, there are no more child views.
    */
	class B2FIter
	{
	public:
		B2FIter(const SkView* parent);
		SkView* next();
	private:
		SkView* fFirstChild, *fChild;
	};

    class Artist : public SkRefCnt 
	{
    public:
        SK_DECLARE_INST_COUNT(Artist)

        void draw(SkView*, SkCanvas*);
        void inflate(const SkDOM&, const SkDOM::Node*);
    protected:
        virtual void onDraw(SkView*, SkCanvas*) = 0;
        virtual void onInflate(const SkDOM&, const SkDOM::Node*);
    private:
        typedef SkRefCnt INHERITED;
    };

    Artist* getArtist() const;

    Artist* setArtist(Artist* artist);
    class Layout : public SkRefCnt {
    public:
        SK_DECLARE_INST_COUNT(Layout)

        void layoutChildren(SkView* parent);
        void inflate(const SkDOM&, const SkDOM::Node*);
    protected:
        virtual void onLayoutChildren(SkView* parent) = 0;
        virtual void onInflate(const SkDOM&, const SkDOM::Node*);
    private:
        typedef SkRefCnt INHERITED;
    };

    Layout* getLayout() const;
    Layout* setLayout(Layout*, bool invokeLayoutNow = true);
    void    invokeLayout();
    void    inflate(const SkDOM& dom, const SkDOM::Node* node);
    void    postInflate(const SkTDict<SkView*>& ids);

    SkDEBUGCODE(void dump(bool recurse) const;)

protected:
    virtual void    onDraw(SkCanvas*);
    virtual void    onSizeChange();
    virtual bool    handleInval(const SkRect*);
    virtual SkCanvas* beforeChildren(SkCanvas* c) { return c; }
    virtual void afterChildren(SkCanvas* orig) {}
    virtual void beforeChild(SkView* child, SkCanvas* canvas) {}
    virtual void afterChild(SkView* child, SkCanvas* canvas) {}
    virtual Click* onFindClickHandler(float x, float y, unsigned modi);

    virtual bool onSendClickToChildren(float x, float y, unsigned modi);
    virtual bool    onClick(Click*);
    virtual void    onInflate(const SkDOM& dom, const SkDOM::Node* node);
    virtual void    onPostInflate(const SkTDict<SkView*>&);

public:
    virtual void    onFocusChange(bool gainFocusP);

protected:
    virtual bool    onGetFocusView(SkView**) const { return false; }
    virtual bool    onSetFocusView(SkView*) { return false; }

private:
    float    fWidth, fHeight;
    SkMatrix    fMatrix;
    SkPoint     fLoc;
	SkView*     fParent;
	SkView*     fChild;
    SkView*     fNextSibling;
    SkView*     fPrevSibling;
    uint8_t     fFlags;
    uint8_t     fContainsFocus;

    friend class B2FIter;
    friend class F2BIter;

    friend class SkLayerView;

    bool    setFocusView(SkView* fvOrNull);
    SkView* acceptFocus(FocusDirection);
    void    detachFromParent_NoLayout();
    void    localToGlobal(SkMatrix* matrix) const;
};

#endif
