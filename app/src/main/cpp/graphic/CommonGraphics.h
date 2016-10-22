//
//  CommonGraphics.h
//  Physical.Simulation.Tool
//
//  Created by Silvio Fragnani da Silva on 14/06/12.
//  
//

#ifndef COMMONGRAPHICS_H
#define COMMONGRAPHICS_H

// COMMON INCLUDES
//#include <OpenGLES/ES1/gl.h>
//#include <OpenGLES/ES1/glext.h>
//#include <OpenGLES/ES2/gl.h>
//#include <OpenGLES/ES2/glext.h>

#include <GLES/gl.h>
#include <GLES/glext.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#include "common/CommonStructures.h"

// COMMON ENUN FOR LIBRARY
enum
{
    ATTRIB_VERTEX,
    ATTRIB_COLOR,
    ATTRIB_NORMAL
};

#define UNIFORM_MODELVIEWPROJECTION_MATRIX "UNIFORM_MODELVIEWPROJECTION_MATRIX"
#define UNIFORM_ORTHO_MATRIX "UNIFORM_ORTHO_MATRIX"
#define UNIFORM_LOOKAT_MATRIX "UNIFORM_LOOKAT_MATRIX"
#define UNIFORM_PERSPECTIVE_MATRIX "UNIFORM_PERSPECTIVE_MATRIX"
#define UNIFORM_NORMAL_MATRIX "UNIFORM_NORMAL_MATRIX"

#endif
