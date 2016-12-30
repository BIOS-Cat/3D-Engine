#ifndef ASSETS_H
#define ASSETS_H

#include <OpenGL.h> // Need this for GLGLfloat and GLuint types

/*
 *  Just some basic assets which can be used to test out 2D/3D graphics.
 *  All platonic solids are centered at the origin and have vertices on the unit shpere.
 *
 *  For now, only position data is here. Color/Texture data can come later, if we want.
 *
 *  I did not check to see if the winding order is consistently CCW on these.
 */

#define A 0.57735027f // = sqrt(3)/3
static const GLfloat cube_vertex_data[] = {
    -A, -A, -A, -A, -A,  A, -A,  A,  A,
     A,  A, -A, -A, -A, -A, -A,  A, -A,
     A, -A,  A, -A, -A, -A,  A, -A, -A,
     A,  A, -A,  A, -A, -A, -A, -A, -A,
    -A, -A, -A, -A,  A,  A, -A,  A, -A,
     A, -A,  A, -A, -A,  A, -A, -A, -A,
    -A,  A,  A, -A, -A,  A,  A, -A,  A,
     A,  A,  A,  A, -A, -A,  A,  A, -A,
     A, -A, -A,  A,  A,  A,  A, -A,  A,
     A,  A,  A,  A,  A, -A, -A,  A, -A,
     A,  A,  A, -A,  A, -A, -A,  A,  A,
     A,  A,  A, -A,  A,  A,  A, -A,  A
};
#undef A

#define A 0.81649658f // = sqrt(6)/3
#define B 0.57735027f // = sqrt(3)/3
static const GLfloat tetrahedron_vertex_data[] = {
     A,  0, -B, -A,  0, -B,  0,  A,  B,
     A,  0, -B, -A,  0, -B,  0, -A,  B,
    -A,  0, -B, -A,  0, -B,  0,  A,  B,
    -A,  0, -B, -A,  0, -B,  0, -A,  B
};
#undef A
#undef B

#define A 0.86602540f // = sqrt(3)/2
static const GLfloat triangle_vertex_data[] = {
     0,  1,  0,  A, -0.5f,  0, -A, -0.5f
};
#undef A

#define A 0.70710678f // = sqrt(2)/2
static const GLfloat square_vertex_data[] = {
     A,  A, 0, -A,  A, 0,  A,  -A, 0,
    -A, -A, 0,  A, -A, 0, -A,   A, 0,
};
#undef A

// This 8x8 texture will show show up as a Red/Yellow checkerboard for big endian
// and Red/Pink for little endian. I chose these colors so that the alpha channel
// will always be fully on. The "bottom" row of this image is pure white, which
// might be the top row depending on how screen/texture coordinates are stored.
static const GLuint checker_texture[] = {
    0xFF0000FF, 0xFFFF00FF, 0xFF0000FF, 0xFFFF00FF, 0xFF0000FF, 0xFFFF00FF, 0xFF0000FF, 0xFFFF00FF,
    0xFFFF00FF, 0xFF0000FF, 0xFFFF00FF, 0xFF0000FF, 0xFFFF00FF, 0xFF0000FF, 0xFFFF00FF, 0xFF0000FF,
    0xFF0000FF, 0xFFFF00FF, 0xFF0000FF, 0xFFFF00FF, 0xFF0000FF, 0xFFFF00FF, 0xFF0000FF, 0xFFFF00FF,
    0xFFFF00FF, 0xFF0000FF, 0xFFFF00FF, 0xFF0000FF, 0xFFFF00FF, 0xFF0000FF, 0xFFFF00FF, 0xFF0000FF,
    0xFF0000FF, 0xFFFF00FF, 0xFF0000FF, 0xFFFF00FF, 0xFF0000FF, 0xFFFF00FF, 0xFF0000FF, 0xFFFF00FF,
    0xFFFF00FF, 0xFF0000FF, 0xFFFF00FF, 0xFF0000FF, 0xFFFF00FF, 0xFF0000FF, 0xFFFF00FF, 0xFF0000FF,
    0xFF0000FF, 0xFFFF00FF, 0xFF0000FF, 0xFFFF00FF, 0xFF0000FF, 0xFFFF00FF, 0xFF0000FF, 0xFFFF00FF,
    0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
};



#endif
