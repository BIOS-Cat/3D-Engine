#ifndef ASSETS_H
#define ASSETS_H

/*
 *  Just some basic assets which can be used to test out 2D/3D graphics.
 *  All platonic solids are centered at the origin and have vertices on the unit shpere.
 */

#define A 0.47140452f // = sqrt(2)/3

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

#endif
