// Copyright 2013 Dolphin Emulator Project
// Licensed under GPLv2
// Refer to the license.txt file included.

#ifndef _GLINIT_H_
#define _GLINIT_H_

#include "VideoConfig.h"
#include "MathUtil.h"
#include "GLInterface/GLInterface.h"
#include "GLExtensions/GLExtensions.h"

#ifndef GL_DEPTH24_STENCIL8_EXT // allows FBOs to support stencils
#define GL_DEPTH_STENCIL_EXT 0x84F9
#define GL_UNSIGNED_INT_24_8_EXT 0x84FA
#define GL_DEPTH24_STENCIL8_EXT 0x88F0
#define GL_TEXTURE_STENCIL_SIZE_EXT 0x88F1
#endif

#ifndef _WIN32

#include <sys/types.h>

#endif
void InitInterface();

// Helpers
GLuint OpenGL_CompileProgram(const char *vertexShader, const char *fragmentShader);

// Error reporting - use the convenient macros.
GLuint OpenGL_ReportGLError(const char *function, const char *file, int line);
bool OpenGL_ReportFBOError(const char *function, const char *file, int line);

#if defined(_DEBUG) || defined(DEBUGFAST)
#define GL_REPORT_ERROR()         OpenGL_ReportGLError(__FUNCTION__, __FILE__, __LINE__)
#define GL_REPORT_ERRORD()        OpenGL_ReportGLError(__FUNCTION__, __FILE__, __LINE__)
#define GL_REPORT_FBO_ERROR()     OpenGL_ReportFBOError(__FUNCTION__, __FILE__, __LINE__)
#else
__forceinline GLenum GL_REPORT_ERROR() { return GL_NO_ERROR; }
#define GL_REPORT_ERRORD() (void)GL_NO_ERROR
#define GL_REPORT_FBO_ERROR() (void)true
#endif

// this should be removed in future, but as long as glsl is unstable, we should really read this messages
#if defined(_DEBUG) || defined(DEBUGFAST)
#define DEBUG_GLSL 1
#else
#define DEBUG_GLSL 0
#endif

// Isn't defined if we aren't using GLEW 1.6
#ifndef GL_ONE_MINUS_SRC1_ALPHA
#define GL_ONE_MINUS_SRC1_ALPHA 0x88FB
#endif

#endif  // _GLINIT_H_
