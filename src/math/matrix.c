#include <math/matrix.h>

#include <math.h>

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

mat4 *perspective_projection_matrix(mat4 *result, float aspect_ratio, float field_of_view_angle, float near, float far)
{
    float tan_half_fov = (float) tan((M_PI / 180.0f) * field_of_view_angle * 0.5f);

    result->m[0]  = 1.0f / (tan_half_fov * aspect_ratio);
    result->m[1]  = 0.0f;
    result->m[2]  = 0.0f;
    result->m[3]  = 0.0f;

    result->m[4]  = 0.0f;
    result->m[5]  = 1.0f / tan_half_fov;
    result->m[6]  = 0.0f;
    result->m[7]  = 0.0f;

    result->m[8]  = 0.0f;
    result->m[9]  = 0.0f;
    result->m[10] = -(far + near) / (near - far);
    result->m[11] = 1.0f;

    result->m[12] = 0.0f;
    result->m[13] = 0.0f;
    result->m[14] = (2.0f * far * near) / (near - far);
    result->m[15] = 0.0f;

    return result;
}

mat3 *rotation_matrix_x(mat3 *result, float angle)
{
    float s = (float) sin(angle);
    float c = (float) cos(angle);

    result->m[0] = 1.0f; result->m[3] = 0.0f; result->m[6] = 0.0f;
    result->m[1] = 0.0f; result->m[4] = c;    result->m[7] = -s;
    result->m[2] = 0.0f; result->m[5] = s;    result->m[8] =  c;

    return result;
}

mat3 *rotation_matrix_y(mat3 *result, float angle)
{
    return result;
}

mat3 *rotation_matrix_z(mat3 *result, float angle)
{
    return result;
}
