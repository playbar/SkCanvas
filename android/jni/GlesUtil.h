#ifndef ESUTIL_H
#define ESUTIL_H

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

struct ESMatrix
{
public:
    GLfloat   m[4][4];
};

extern GLuint		gProObject;
extern ESMatrix 	gOrthographic;
extern ESMatrix 	gMatrix;

extern GLint	gShaderPosition;
extern GLint	gShaderTexCoord;
extern GLint 	gShaderImgTexture;
extern GLint	gvpMatrix;

extern GLint 	gColorFlag;
extern GLint 	gColorLoc;

extern GLuint	gTextureTmp;
extern GLuint	gMainTexture;
extern GLuint	gFrameBuffer;


extern float gWidthd2;
extern float gHeightd2;
extern float gWidth;
extern float gHeight;

//////////////////////

extern GLuint	gTextureTmp;	// temp texture
extern GLuint	gMainTexture;	// off screen textrue
extern GLuint	gFrameBuffer;	//buffer

#ifdef __cplusplus
extern "C" {
#endif

///
/// \brief Load a shader, check for compile errors, print error messages to output log
/// \param type Type of shader (GL_VERTEX_SHADER or GL_FRAGMENT_SHADER)
/// \param shaderSrc Shader source string
/// \return A new shader object on success, 0 on failure
//
GLuint esLoadShader ( GLenum type, const char *shaderSrc );

///
/// \brief Load a vertex and fragment shader, create a program object, link program.
///        Errors output to log.
/// \param vertShaderSrc Vertex shader source code
/// \param fragShaderSrc Fragment shader source code
/// \return A new program object linked with the vertex/fragment shader pair, 0 on failure
//
GLuint esLoadProgram ( const char *vertShaderSrc, const char *fragShaderSrc );

//
/// \brief Generates geometry for a sphere.  Allocates memory for the vertex data and stores 
///        the results in the arrays.  Generate index list for a TRIANGLE_STRIP
/// \param numSlices The number of slices in the sphere
/// \param vertices If not NULL, will contain array of float3 positions
/// \param normals If not NULL, will contain array of float3 normals
/// \param texCoords If not NULL, will contain array of float2 texCoords
/// \param indices If not NULL, will contain the array of indices for the triangle strip
/// \return The number of indices required for rendering the buffers (the number of indices stored in the indices array
///         if it is not NULL ) as a GL_TRIANGLE_STRIP
//
int esGenSphere ( int numSlices, float radius, GLfloat **vertices, GLfloat **normals,
                             GLfloat **texCoords, GLushort **indices );

/// \brief Generates geometry for a cube.  Allocates memory for the vertex data and stores 
///        the results in the arrays.  Generate index list for a TRIANGLES
/// \param scale The size of the cube, use 1.0 for a unit cube.
/// \param vertices If not NULL, will contain array of float3 positions
/// \param normals If not NULL, will contain array of float3 normals
/// \param texCoords If not NULL, will contain array of float2 texCoords
/// \param indices If not NULL, will contain the array of indices for the triangle strip
/// \return The number of indices required for rendering the buffers (the number of indices stored in the indices array
///         if it is not NULL ) as a GL_TRIANGLES
//
int esGenCube ( float scale, GLfloat **vertices, GLfloat **normals,
                           GLfloat **texCoords, GLushort **indices );

/// \brief Loads a PNG image from a file
/// \param fileName Base file of the name on disk (without png extension)
/// \param width Width of loaded image in pixels
/// \param height Height of loaded image in pixels
///  \return Pointer to loaded image.  NULL on failure. 
///
char* esLoadPNG ( char *fileName, int *width, int *height );


/// \brief multiply matrix specified by result with a scaling matrix and return new matrix in result
/// \param result Specifies the input matrix.  Scaled matrix is returned in result.
/// \param sx, sy, sz Scale factors along the x, y and z axes respectively
//
void esScale(ESMatrix *result, GLfloat sx, GLfloat sy, GLfloat sz);

//
/// \brief multiply matrix specified by result with a translation matrix and return new matrix in result
/// \param result Specifies the input matrix.  Translated matrix is returned in result.
/// \param tx, ty, tz Scale factors along the x, y and z axes respectively
//
void esTranslate(ESMatrix *result, GLfloat tx, GLfloat ty, GLfloat tz);

//
/// \brief multiply matrix specified by result with a rotation matrix and return new matrix in result
/// \param result Specifies the input matrix.  Rotated matrix is returned in result.
/// \param angle Specifies the angle of rotation, in degrees.
/// \param x, y, z Specify the x, y and z coordinates of a vector, respectively
//
void esRotate(ESMatrix *result, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);

//
// \brief multiply matrix specified by result with a perspective matrix and return new matrix in result
/// \param result Specifies the input matrix.  new matrix is returned in result.
/// \param left, right Coordinates for the left and right vertical clipping planes
/// \param bottom, top Coordinates for the bottom and top horizontal clipping planes
/// \param nearZ, farZ Distances to the near and far depth clipping planes.  Both distances must be positive.
//
void esFrustum(ESMatrix *result, float left, float right, float bottom, float top, float nearZ, float farZ);

//
/// \brief multiply matrix specified by result with a perspective matrix and return new matrix in result
/// \param result Specifies the input matrix.  new matrix is returned in result.
/// \param fovy Field of view y angle in degrees
/// \param aspect Aspect ratio of screen
/// \param nearZ Near plane distance
/// \param farZ Far plane distance
//
void esPerspective(ESMatrix *result, float fovy, float aspect, float nearZ, float farZ);

//esUtil.cpp
/// \brief multiply matrix specified by result with a perspective matrix and return new matrix in result
/// \param result Specifies the input matrix.  new matrix is returned in result.
/// \param left, right Coordinates for the left and right vertical clipping planes
/// \param bottom, top Coordinates for the bottom and top horizontal clipping planes
/// \param nearZ, farZ Distances to the near and far depth clipping planes.  These values are negative if plane is behind the viewer
//
void esOrtho(ESMatrix *result, float left, float right, float bottom, float top, float nearZ, float farZ);

//
/// \brief perform the following operation - result matrix = srcA matrix * srcB matrix
/// \param result Returns multiplied matrix
/// \param srcA, srcB Input matrices to be multiplied
//
void esMatrixMultiply(ESMatrix *result, ESMatrix *srcA, ESMatrix *srcB);

//
//// \brief return an indentity matrix 
//// \param result returns identity matrix
//
void esMatrixLoadIdentity(ESMatrix *result);


GLint CreateGlesEnv( );

void GlesBindOffScreen();

void GlesEnvChanged(  int width, int height );

void LoadImgDataTextuer(GLuint textureID, int width, int height, unsigned char * data );

void GlesPaintTexture( GLuint textureID, int dl, int dt, int dr, int db,
		GLfloat sl, GLfloat st, GLfloat sr, GLfloat sb );

void LoadImgDataTex(int width, int height, unsigned char * data );

void SetDrawOffScreen(bool bOffScreen );

void GlesPaint( );

void GlesFlush();

#ifdef __cplusplus
}
#endif

#endif // ESUTIL_H
