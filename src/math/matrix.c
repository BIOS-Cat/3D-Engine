#include <math/matrix.h>

mat4 *orthographic_projection_matrix(mat4 *result, float left, float right, float bottom, float top, float near, float far)
{
    result->m[0]  =  2.0f / (right - left);
    result->m[1]  =  0.0f;
    result->m[2]  =  0.0f;
    result->m[3]  =  0.0f;
    result->m[4]  =  0.0f;
    result->m[5]  =  2.0f / (top - bottom);
    result->m[6]  =  0.0f;
    result->m[7]  =  0.0f;
    result->m[8]  =  0.0f;
    result->m[9]  =  0.0f;
    result->m[10] = -2.0f / (far - near);
    result->m[11] =  0.0f;
    result->m[12] = -(right + left) / (right - left);
    result->m[13] = -(top + bottom) / (top - bottom);
    result->m[14] = -(far + near) / (far - near);
    result->m[15] =  1.0f;

    return result;
}

mat4 *perspection_projection_matrix(mat4 *result, float aspect_ratio, float field_of_view_angle, float near, float far)
{
    return result;
}
