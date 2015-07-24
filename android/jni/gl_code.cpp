/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// OpenGL ES 2.0 code

#include <jni.h>
#include <android/log.h>

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "GlesUtil.h"

#define  LOG_TAG    "libgl2jni"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

#define	checkImageWidth 64
#define	checkImageHeight 64
static GLubyte checkImage[checkImageHeight][checkImageWidth][4];
static GLubyte otherImage[checkImageHeight][checkImageWidth][4];

static GLuint texName;
static GLuint guVbo;

void makeCheckImages(void)
{
   int i, j, c;

   for (i = 0; i < checkImageHeight; i++) {
      for (j = 0; j < checkImageWidth; j++) {
         c = ((((i&0x8)==0)^((j&0x8))==0))*255;
         checkImage[i][j][0] = (GLubyte) c;
         checkImage[i][j][1] = (GLubyte) c;
         checkImage[i][j][2] = (GLubyte) c;
         checkImage[i][j][3] = (GLubyte) 255;
         c = ((((i&0x10)==0)^((j&0x10))==0))*255;
         otherImage[i][j][0] = (GLubyte) c;
         otherImage[i][j][1] = (GLubyte) 0;
         otherImage[i][j][2] = (GLubyte) 0;
         otherImage[i][j][3] = (GLubyte) 255;
      }
   }
}


static void printGLString(const char *name, GLenum s) {
    const char *v = (const char *) glGetString(s);
    LOGI("GL %s = %s\n", name, v);
}

static void checkGlError(const char* op) {
    for (GLint error = glGetError(); error; error
            = glGetError()) {
        LOGI("after %s() glError (0x%x)\n", op, error);
    }
}

static const char gVertexShader[] = 
	"uniform mat4 u_TransMatrix;	\n"
    "attribute vec4 vPosition;		\n"
	"attribute vec2 a_texCoord;   	\n"
	"varying vec2 v_texCoord;    	 \n"
    "void main() {					\n"
    "  gl_Position = u_TransMatrix* vPosition;	\n"
	"  v_texCoord = a_texCoord;					\n"
    "}								\n";

static const char gFragmentShader[] = 
    "precision mediump float;		\n"
	"varying vec2 v_texCoord;    	\n"
	"uniform sampler2D s_ImgTexture;\n"
    "void main() {\n"
    //"  gl_FragColor = vec4(0.0, 1.0, 0.0, 1.0);\n"
	"	 gl_FragColor = texture2D( s_ImgTexture, v_texCoord );\n"
    "}\n";

GLuint loadShader(GLenum shaderType, const char* pSource) {
    GLuint shader = glCreateShader(shaderType);
    if (shader) {
        glShaderSource(shader, 1, &pSource, NULL);
        glCompileShader(shader);
        GLint compiled = 0;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
        if (!compiled) {
            GLint infoLen = 0;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
            if (infoLen) {
                char* buf = (char*) malloc(infoLen);
                if (buf) {
                    glGetShaderInfoLog(shader, infoLen, NULL, buf);
                    LOGE("Could not compile shader %d:\n%s\n",
                            shaderType, buf);
                    free(buf);
                }
                glDeleteShader(shader);
                shader = 0;
            }
        }
    }
    return shader;
}

GLuint createProgram(const char* pVertexSource, const char* pFragmentSource) {
    GLuint vertexShader = loadShader(GL_VERTEX_SHADER, pVertexSource);
    if (!vertexShader) {
        return 0;
    }

    GLuint pixelShader = loadShader(GL_FRAGMENT_SHADER, pFragmentSource);
    if (!pixelShader) {
        return 0;
    }

    GLuint program = glCreateProgram();
    if (program) {
        glAttachShader(program, vertexShader);
        checkGlError("glAttachShader");
        glAttachShader(program, pixelShader);
        checkGlError("glAttachShader");
        glLinkProgram(program);
        GLint linkStatus = GL_FALSE;
        glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
        if (linkStatus != GL_TRUE) {
            GLint bufLength = 0;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &bufLength);
            if (bufLength) {
                char* buf = (char*) malloc(bufLength);
                if (buf) {
                    glGetProgramInfoLog(program, bufLength, NULL, buf);
                    LOGE("Could not link program:\n%s\n", buf);
                    free(buf);
                }
            }
            glDeleteProgram(program);
            program = 0;
        }
    }
    return program;
}

GLuint gProgram;
GLuint gvPositionHandle;

GLfloat fwidth = 20.0f;
GLfloat fheight = 20.0f;

const GLfloat gTriangleVertices[ 5 * 6] =
{
	-fwidth, -fheight, 0.0f, 0.0f, 0.0f,
	-fwidth,  fheight, 0.0f, 0.0f, 1.0f,
	fwidth,   fheight, 0,	1.0f, 1.0f,

	-fwidth, -fheight, 0,	0.0f, 0.0f,
	fwidth,  fheight, 0,	1.0f, 1.0f,
	fwidth,  -fheight, 0,	1.0f, 0.0f
};

int gsCount = 500;

GLfloat gTriangleTmp[ 5 * 6 ];

void randVertices( float rand )
{
	if( rand < 0.01 && rand > -0.01 )
	{
		rand = 1.0f;
	}

	for( int i = 0; i < 6; i++ )
	{
		gTriangleTmp[i * 5 ] = gTriangleVertices[i * 5 ] + rand;
		gTriangleTmp[i * 5 + 1] = gTriangleVertices[i * 5 + 1] + rand;
		gTriangleTmp[i * 5 + 2] = gTriangleVertices[i * 5 + 2];
		gTriangleTmp[i * 5 + 3] = gTriangleVertices[i * 5 + 3];
		gTriangleTmp[i * 5 + 4] = gTriangleVertices[i * 5 + 4];
	}
}

void createRenderBuffer()
{

	int istep =  5 * 6 * sizeof( GLfloat);
	glGenBuffers( 1, &guVbo );
	glBindBuffer( GL_ARRAY_BUFFER, guVbo );
	glBufferData( GL_ARRAY_BUFFER, istep * gsCount, NULL, GL_STREAM_DRAW );
	for( int i = 0; i < gsCount; i++ )
	{
		LOGE("-------->");
		randVertices( i * 0.2 );
		glBufferSubData( GL_ARRAY_BUFFER, i * istep, istep, gTriangleTmp );
	}

}

bool setupGraphics(int w, int h)
{

    printGLString("Version", GL_VERSION);
    printGLString("Vendor", GL_VENDOR);
    printGLString("Renderer", GL_RENDERER);
    printGLString("Extensions", GL_EXTENSIONS);

    LOGI("setupGraphics(%d, %d)", w, h);
    gProgram = createProgram(gVertexShader, gFragmentShader);
    if (!gProgram) {
        LOGE("Could not create program.");
        return false;
    }
    gvPositionHandle = glGetAttribLocation(gProgram, "vPosition");
    gShaderTexCoord  = glGetAttribLocation ( gProgram, "a_texCoord" );
    gvpMatrix 	      = glGetUniformLocation( gProgram, "u_TransMatrix" );
    gShaderImgTexture = glGetUniformLocation( gProgram, "s_ImgTexture" );


    makeCheckImages();
    glGenTextures( 1, &texName );
    glBindTexture(GL_TEXTURE_2D, texName);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth,
                 checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                 checkImage);

    glUseProgram(gProgram);
    glEnableVertexAttribArray(gvPositionHandle);
    glEnableVertexAttribArray( gShaderTexCoord );
    glUniform1i ( gShaderImgTexture, 0 );


    gWidthd2 = w / 2;
	gHeightd2 = h / 2;

	esMatrixLoadIdentity( &gOrthographic );
	//esOrtho(&gOrthographic, 0, mWidth, -mHeight, 0, 5.0f, -5.0f );
	esOrtho(&gOrthographic, -gWidthd2, gWidthd2, -gHeightd2, gHeightd2, 5.0f, -5.0f );

	ESMatrix modelview;
	esMatrixLoadIdentity( &gMatrix );
	esMatrixLoadIdentity( &modelview );
	esMatrixMultiply( &gMatrix, &modelview, &gOrthographic );

	glViewport(0, 0, w, h);

	glUniformMatrix4fv( gvpMatrix, 1, GL_FALSE, (GLfloat *)&gMatrix );

	//glGenBuffers( 1, &guVbo );
	//glBindBuffer( GL_ARRAY_BUFFER, guVbo );
	//glBufferData( GL_ARRAY_BUFFER, 5 * 6 * sizeof( GLfloat), gTriangleVertices, GL_STREAM_DRAW );

	glActiveTexture ( GL_TEXTURE0 );
	glBindTexture ( GL_TEXTURE_2D, texName );
	createRenderBuffer();

	//ESMatrix matrixTrans;
	//ESMatrix modelview;
	//esMatrixLoadIdentity( &modelview );

	//esTranslate( &modelview, -fx, fy, 0.0 );
	//esMatrixMultiply( &matrixTrans, &modelview, &gOrthographic );
	glUniformMatrix4fv( gvpMatrix, 1, GL_FALSE, (GLfloat *)&gOrthographic );

    return true;
}


void renderFrame()
{

    static float grey;
    grey += 0.01f;
    if (grey > 1.0f) {
        grey = 0.0f;
    }
    glClearColor(grey, grey, grey, 1.0f);
    glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	glVertexAttribPointer(gvPositionHandle, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glVertexAttribPointer( gShaderTexCoord, 2, GL_FLOAT, GL_FALSE, 5 * sizeof( GLfloat),(GLvoid*)(3 * sizeof( GLfloat )));
	glDrawArrays(GL_TRIANGLES, 0, 6 * gsCount );

//    glActiveTexture ( GL_TEXTURE0 );
//    glBindTexture ( GL_TEXTURE_2D, texName );
//    glVertexAttribPointer(gvPositionHandle, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), gTriangleVertices);
//    glVertexAttribPointer( gShaderTexCoord, 2, GL_FLOAT, GL_FALSE, 5 * sizeof( GLfloat), &gTriangleVertices[3]);
//    glDrawArrays(GL_TRIANGLES, 0, 6 );
//    checkGlError("glDrawArrays");
}

extern "C" {
    JNIEXPORT void JNICALL Java_com_android_gl2jni_GL2JNILib_init(JNIEnv * env, jobject obj,  jint width, jint height);
    JNIEXPORT void JNICALL Java_com_android_gl2jni_GL2JNILib_step(JNIEnv * env, jobject obj);
};

JNIEXPORT void JNICALL Java_com_android_gl2jni_GL2JNILib_init(JNIEnv * env, jobject obj,  jint width, jint height)
{
    setupGraphics(width, height);
}

JNIEXPORT void JNICALL Java_com_android_gl2jni_GL2JNILib_step(JNIEnv * env, jobject obj)
{
    renderFrame();
}
