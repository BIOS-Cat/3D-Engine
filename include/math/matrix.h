#ifndef MATRIX_H
#define MATRIX_H

typedef union {
    float v[3];
    struct {
        float x, y, z;
    };
    struct {
        float r, g, b;
    };
} vec3;

typedef union {
    float v[4];
    struct {
        float x, y, z, w;
    };
    struct {
        float r, g, b, a;
    };
} vec4;

static inline float dot3(const vec3 *const u, const vec3 *const v)
{
    return u->v[0]*v->v[0] + u->v[1]*v->v[1] + u->v[2]*v->v[2];
}

static inline float dot4(const vec4 *const u, const vec4 *const v)
{
    return u->v[0]*v->v[0] + u->v[1]*v->v[1] + u->v[2]*v->v[2] + u->v[3]*v->v[3];
}

static inline vec3 *cross(vec3 *result, const vec3 *const u, const vec3 *const v)
{
    result->v[0] = u->v[1]*v->v[2] - u->v[2]*v->v[1];
    result->v[1] = u->v[2]*v->v[0] - u->v[0]*v->v[2];
    result->v[2] = u->v[0]*v->v[1] - u->v[1]*v->v[0];

    return result;
}

#endif /* MATRIX_H */
