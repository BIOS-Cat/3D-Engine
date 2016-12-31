#include <check.h>

#include <math/matrix.h>
#include "matrix_test.h"

#define ck_assert_vec3_eq(_U, _V)    \
{                                    \
    ck_assert_float_eq(_U.x, _V.x);  \
    ck_assert_float_eq(_U.y, _V.y);  \
    ck_assert_float_eq(_U.z, _V.z);  \
} while(0)

#define ck_assert_vec4_eq(_U, _V)    \
{                                    \
    ck_assert_float_eq(_U.x, _V.x);  \
    ck_assert_float_eq(_U.y, _V.y);  \
    ck_assert_float_eq(_U.z, _V.z);  \
    ck_assert_float_eq(_U.w, _V.w);  \
} while(0)

#define ck_assert_mat3_eq(_A, _B)                                                                                      \
{                                                                                                                      \
    ck_assert_float_eq(_A.m[0], _B.m[0]); ck_assert_float_eq(_A.m[3], _B.m[3]); ck_assert_float_eq(_A.m[6], _B.m[6]);  \
    ck_assert_float_eq(_A.m[1], _B.m[1]); ck_assert_float_eq(_A.m[4], _B.m[4]); ck_assert_float_eq(_A.m[7], _B.m[7]);  \
    ck_assert_float_eq(_A.m[2], _B.m[2]); ck_assert_float_eq(_A.m[5], _B.m[5]); ck_assert_float_eq(_A.m[8], _B.m[8]);  \
} while(0)

#define ck_assert_mat4_eq(_A, _B)                                                                                                                                \
{                                                                                                                                                                \
    ck_assert_float_eq(_A.m[0], _B.m[0]); ck_assert_float_eq(_A.m[4], _B.m[4]); ck_assert_float_eq(_A.m[8] , _B.m[8]);  ck_assert_float_eq(_A.m[12], _B.m[12]);  \
    ck_assert_float_eq(_A.m[1], _B.m[1]); ck_assert_float_eq(_A.m[5], _B.m[5]); ck_assert_float_eq(_A.m[9] , _B.m[9]);  ck_assert_float_eq(_A.m[13], _B.m[13]);  \
    ck_assert_float_eq(_A.m[2], _B.m[2]); ck_assert_float_eq(_A.m[6], _B.m[6]); ck_assert_float_eq(_A.m[10], _B.m[10]); ck_assert_float_eq(_A.m[14], _B.m[14]);  \
    ck_assert_float_eq(_A.m[3], _B.m[3]); ck_assert_float_eq(_A.m[7], _B.m[7]); ck_assert_float_eq(_A.m[11], _B.m[11]); ck_assert_float_eq(_A.m[15], _B.m[15]);  \
} while(0)

START_TEST(normalize4_normalizes_a_vec4)
{
    vec4 v = {1.25f, 0.0f, 0.0f, 0.0f};
    vec4 expected = {1.0f, 0.0f, 0.0f, 0.0f};
    vec4 result = { };

    normalize4(&result, &v);

    ck_assert_vec4_eq(result, expected);
}
END_TEST

START_TEST(normalize3_normalizes_a_vec3)
{
    vec3 v = {1.25f, 0.0f, 0.0f};
    vec3 expected = {1.0f, 0.0f, 0.0f};
    vec3 result = { };

    normalize3(&result, &v);

    ck_assert_vec3_eq(result, expected);
}
END_TEST

START_TEST(scale4_scales_a_vec4)
{
    vec4 v = {1.0f, 2.0f, 3.0f, 4.0f};
    vec4 expected = {1.5f, 3.0f, 4.5f, 6.0f};
    vec4 result = { };

    scale4(&result, 1.5f, &v);

    ck_assert_vec4_eq(result, expected);
}
END_TEST

START_TEST(scale3_scales_a_vec3)
{
    vec3 v = {1.0f, 2.0f, 3.0f};
    vec3 expected = {1.5f, 3.0f, 4.5f};
    vec3 result = { };

    scale3(&result, 1.5f, &v);

    ck_assert_vec3_eq(result, expected);
}
END_TEST

START_TEST(norm4_returns_the_norm_of_a_vec4)
{
    vec4 v = {3.0f, 4.0f, 0.0f, 0.0f};

    ck_assert_float_eq(norm4(&v), 5.0f);
}
END_TEST

START_TEST(norm3_returns_the_norm_of_a_vec3)
{
    vec3 v = {3.0f, 4.0f, 0.0f};

    ck_assert_float_eq(norm3(&v), 5.0f);
}
END_TEST

START_TEST(cross_computes_cross_product_correctly)
{
    vec3 u = {1.0f, 2.0f, 3.0f};
    vec3 v = {4.0f, 5.0f, 6.0f};
    vec3 expected = {-3.0f, 6.0f, -3.0f};
    vec3 result = { };

    cross(&result, &u, &v);

    ck_assert_vec3_eq(result, expected);
}
END_TEST

START_TEST(vec4_dot_computes_dot_product_correctly)
{
    vec4 u = {1.0f, 2.0f, 3.0f, 4.0f};
    vec4 v = {5.0f, 6.0f, 7.0f, 8.0f};

    ck_assert_float_eq(dot4(&u, &v), 70.0f);
}
END_TEST

START_TEST(vec3_dot_computes_dot_product_correctly)
{
    vec3 u = {1.0f, 2.0f, 3.0f};
    vec3 v = {4.0f, 5.0f, 6.0f};

    ck_assert_float_eq(dot3(&u, &v), 32.0f);
}
END_TEST

START_TEST(orthographic_projection_matrix_creates_an_orthographic_matrix)
{
    mat4 matrix = { };
    mat4 expected = {                   // Recall that matrices in OpenGL are column major, so this
         0.2f,  0.0f,   0.0f, 0.0f,     // is written as the transpose of how it is represented in memory.
         0.0f,  0.02f , 0.0f, 0.0f,
         0.0f,  0.0f,  -0.4f, 0.0f,
        -7.0f, -3.0f,  -3.0f, 1.0f};

    orthographic_projection_matrix(&matrix, 30.0, 40.0f, 100.0f, 200.0f, 5.0f, 10.0f);

    ck_assert_mat4_eq(expected, matrix);
}
END_TEST

START_TEST(perspection_projection_matrix_creates_a_perspective_matrix)
{
    mat4 matrix = { };
    mat4 expected = {
        0.5f, 0.0f,  0.0f, 0.0f,
        0.0f, 1.0f,  0.0f, 0.0f,
        0.0f, 0.0f,  1.2f, 1.0f,
        0.0f, 0.0f, -2.2f, 0.0f};

    perspection_projection_matrix(&matrix, 2.0, 90.0f, 1.0f, 11.0f);

    ck_assert_mat4_eq(expected, matrix);
}
END_TEST

START_TEST(mat3_mul_multiplies_two_matrices)
{
    mat3 result = { };
    mat3 mat_A = {
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f};
    mat3 mat_B = {
        3.0f, -2.0f, 1.0f,
        4.0f, 5.0f, 1.0f,
        6.0f, 1.0f, 0.0f};
    mat3 expected = {
        2.0f, 4.0f, 6.0f,
        31.0f, 41.0f, 51.0f,
        10.0f, 17.0f, 24.0f};

    mat3_mul(&result, &mat_A, &mat_B);

    ck_assert_mat3_eq(expected, result);
}
END_TEST

START_TEST(mat4_mul_multiplies_two_matrices)
{
    mat4 result = { };
    mat4 mat_A = {
         1.0f,  2.0f,  3.0f,  4.0f,
         5.0f,  6.0f,  7.0f,  8.0f,
         9.0f, 10.0f, 11.0f, 12.0f,
        13.0f, 14.0f, 15.0f, 16.0f};
    mat4 mat_B = {
         2.0f,  1.0f,  1.0f,  1.0f,
         4.0f, -6.0f,  0.0f,  3.0f,
         9.0f, 11.0f, 10.0f, -2.0f,
        -1.0f, -9.0f, 15.0f, -7.0f};
    mat4 expected = {
        29.0f, 34.0f, 39.0f, 44.0f,
        13.0f, 14.0f, 15.0f, 16.0f,
        128.0f, 156.0f, 184.0f, 212.0f,
        -2.0f, -4.0f, -6.0f, -8.0f};

    mat4_mul(&result, &mat_A, &mat_B);

    ck_assert_mat4_eq(expected, result);
}
END_TEST

START_TEST(mat3_vec3_mul_multiplies_a_vector_by_a_matrix)
{
    vec3 result = { };
    mat3 mat = {
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f};
    vec3 v = {3.0f, -2.0f, 1.0f};
    vec3 expected = {2.0f, 4.0f, 6.0f};

    mat3_vec3_mul(&result, &mat, &v);

    ck_assert_vec3_eq(expected, result);
}
END_TEST

START_TEST(mat4_vec4_mul_multiplies_a_vector_by_a_matrix)
{
    vec4 result = { };
    mat4 mat = {
         1.0f,  2.0f,  3.0f,  4.0f,
         5.0f,  6.0f,  7.0f,  8.0f,
         9.0f, 10.0f, 11.0f, 12.0f,
        13.0f, 14.0f, 15.0f, 16.0f};
    vec4 v = {-7.0f, -2.0f, 10.0f, 0.0f};
    vec4 expected = {73.0f, 74.0f, 75.0f, 76.0f};

    mat4_vec4_mul(&result, &mat, &v);

    ck_assert_vec4_eq(expected, result);
}
END_TEST

START_TEST(scale3_allows_the_user_to_pass_the_same_parameter_for_v_as_result)
{
    vec3 v = {1.0f, 2.0f, 3.0f};
    vec3 expected = {3.0f, 6.0f, 9.0f};

    scale3(&v, 3.0f, &v);

    ck_assert_vec3_eq(expected, v);
}
END_TEST

START_TEST(scale4_allows_the_user_to_pass_the_same_parameter_for_v_as_result)
{
    vec4 v = {1.0f, 2.0f, 3.0f, 4.0f};
    vec4 expected = {3.0f, 6.0f, 9.0f, 12.0f};

    scale4(&v, 3.0f, &v);

    ck_assert_vec4_eq(expected, v);
}
END_TEST

START_TEST(mat3_mul_allows_the_user_to_pass_the_same_parameter_for_mat_A_as_result)
{
    mat3 mat_A = {
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f};
    mat3 mat_B = {
        3.0f, -2.0f, 1.0f,
        4.0f, 5.0f, 1.0f,
        6.0f, 1.0f, 0.0f};
    mat3 expected = {
        2.0f, 4.0f, 6.0f,
        31.0f, 41.0f, 51.0f,
        10.0f, 17.0f, 24.0f};

    mat3_mul(&mat_A, &mat_A, &mat_B);

    ck_assert_mat3_eq(expected, mat_A);
}
END_TEST

START_TEST(mat3_mul_allows_the_user_to_pass_the_same_parameter_for_mat_B_as_result)
{
    mat3 mat_A = {
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f};
    mat3 mat_B = {
        3.0f, -2.0f, 1.0f,
        4.0f, 5.0f, 1.0f,
        6.0f, 1.0f, 0.0f};
    mat3 expected = {
        2.0f, 4.0f, 6.0f,
        31.0f, 41.0f, 51.0f,
        10.0f, 17.0f, 24.0f};

    mat3_mul(&mat_B, &mat_A, &mat_B);

    ck_assert_mat3_eq(expected, mat_B);
}
END_TEST

START_TEST(mat4_mul_allows_the_user_to_pass_the_same_parameter_for_mat_A_as_result)
{
    mat4 mat_A = {
         1.0f,  2.0f,  3.0f,  4.0f,
         5.0f,  6.0f,  7.0f,  8.0f,
         9.0f, 10.0f, 11.0f, 12.0f,
        13.0f, 14.0f, 15.0f, 16.0f};
    mat4 mat_B = {
         2.0f,  1.0f,  1.0f,  1.0f,
         4.0f, -6.0f,  0.0f,  3.0f,
         9.0f, 11.0f, 10.0f, -2.0f,
        -1.0f, -9.0f, 15.0f, -7.0f};
    mat4 expected = {
        29.0f, 34.0f, 39.0f, 44.0f,
        13.0f, 14.0f, 15.0f, 16.0f,
        128.0f, 156.0f, 184.0f, 212.0f,
        -2.0f, -4.0f, -6.0f, -8.0f};

    mat4_mul(&mat_A, &mat_A, &mat_B);

    ck_assert_mat4_eq(expected, mat_A);
}
END_TEST

START_TEST(mat4_mul_allows_the_user_to_pass_the_same_parameter_for_mat_B_as_result)
{
    mat4 mat_A = {
         1.0f,  2.0f,  3.0f,  4.0f,
         5.0f,  6.0f,  7.0f,  8.0f,
         9.0f, 10.0f, 11.0f, 12.0f,
        13.0f, 14.0f, 15.0f, 16.0f};
    mat4 mat_B = {
         2.0f,  1.0f,  1.0f,  1.0f,
         4.0f, -6.0f,  0.0f,  3.0f,
         9.0f, 11.0f, 10.0f, -2.0f,
        -1.0f, -9.0f, 15.0f, -7.0f};
    mat4 expected = {
        29.0f, 34.0f, 39.0f, 44.0f,
        13.0f, 14.0f, 15.0f, 16.0f,
        128.0f, 156.0f, 184.0f, 212.0f,
        -2.0f, -4.0f, -6.0f, -8.0f};

    mat4_mul(&mat_B, &mat_A, &mat_B);

    ck_assert_mat4_eq(expected, mat_B);
}
END_TEST

START_TEST(mat3_vec3_mul_allows_the_user_to_pass_the_same_parameter_for_v_as_result)
{
    mat3 mat = {
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f};
    vec3 v = {3.0f, -2.0f, 1.0f};
    vec3 expected = {2.0f, 4.0f, 6.0f};

    mat3_vec3_mul(&v, &mat, &v);

    ck_assert_vec3_eq(expected, v);
}
END_TEST

START_TEST(mat4_vec4_mul_allows_the_user_to_pass_the_same_parameter_for_v_as_result)
{
    mat4 mat = {
         1.0f,  2.0f,  3.0f,  4.0f,
         5.0f,  6.0f,  7.0f,  8.0f,
         9.0f, 10.0f, 11.0f, 12.0f,
        13.0f, 14.0f, 15.0f, 16.0f};
    vec4 v = {-7.0f, -2.0f, 10.0f, 0.0f};
    vec4 expected = {73.0f, 74.0f, 75.0f, 76.0f};

    mat4_vec4_mul(&v, &mat, &v);

    ck_assert_vec4_eq(expected, v);
}
END_TEST

Suite *make_matrix_suite()
{
    Suite *s;
    TCase *tc;

    s = suite_create("Matrix and Vectors");
    tc = tcase_create("Vectors");

    tcase_add_test(tc, vec3_dot_computes_dot_product_correctly);
    tcase_add_test(tc, vec4_dot_computes_dot_product_correctly);
    tcase_add_test(tc, cross_computes_cross_product_correctly);
    tcase_add_test(tc, norm3_returns_the_norm_of_a_vec3);
    tcase_add_test(tc, norm4_returns_the_norm_of_a_vec4);
    tcase_add_test(tc, scale3_scales_a_vec3);
    tcase_add_test(tc, scale4_scales_a_vec4);
    tcase_add_test(tc, normalize3_normalizes_a_vec3);
    tcase_add_test(tc, normalize4_normalizes_a_vec4);
    suite_add_tcase(s, tc);

    tc = tcase_create("Projection Matrix");
    tcase_add_test(tc, orthographic_projection_matrix_creates_an_orthographic_matrix);
    tcase_add_test(tc, perspection_projection_matrix_creates_a_perspective_matrix);
    suite_add_tcase(s, tc);

    tc = tcase_create("Matrix Operations");
    tcase_add_test(tc, mat3_mul_multiplies_two_matrices);
    tcase_add_test(tc, mat4_mul_multiplies_two_matrices);
    tcase_add_test(tc, mat3_vec3_mul_multiplies_a_vector_by_a_matrix);
    tcase_add_test(tc, mat4_vec4_mul_multiplies_a_vector_by_a_matrix);
    suite_add_tcase(s, tc);

    tc = tcase_create("Edge Cases");
    tcase_add_test(tc, scale3_allows_the_user_to_pass_the_same_parameter_for_v_as_result);
    tcase_add_test(tc, scale4_allows_the_user_to_pass_the_same_parameter_for_v_as_result);
    tcase_add_test(tc, mat3_mul_allows_the_user_to_pass_the_same_parameter_for_mat_A_as_result);
    tcase_add_test(tc, mat3_mul_allows_the_user_to_pass_the_same_parameter_for_mat_B_as_result);
    tcase_add_test(tc, mat4_mul_allows_the_user_to_pass_the_same_parameter_for_mat_A_as_result);
    tcase_add_test(tc, mat4_mul_allows_the_user_to_pass_the_same_parameter_for_mat_B_as_result);
    tcase_add_test(tc, mat3_vec3_mul_allows_the_user_to_pass_the_same_parameter_for_v_as_result);
    tcase_add_test(tc, mat4_vec4_mul_allows_the_user_to_pass_the_same_parameter_for_v_as_result);
    suite_add_tcase(s, tc);

    return s;
}
