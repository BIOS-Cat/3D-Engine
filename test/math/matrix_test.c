#include <check.h>

#include <math/matrix.h>
#include "matrix_test.h"

START_TEST(normalize4_normalizes_a_vec4)
{
    vec4 v = {1.25f, 0.0f, 0.0f, 0.0f};

    vec4 result = { };

    normalize4(&result, &v);

    ck_assert(result.v[0] == 1.0f);
    ck_assert(result.v[1] == 0.0f);
    ck_assert(result.v[2] == 0.0f);
    ck_assert(result.v[3] == 0.0f);
}
END_TEST

START_TEST(normalize3_normalizes_a_vec3)
{
    vec3 v = {1.25f, 0.0f, 0.0f};

    vec3 result = { };

    normalize3(&result, &v);

    ck_assert(result.v[0] == 1.0f);
    ck_assert(result.v[1] == 0.0f);
    ck_assert(result.v[2] == 0.0f);
}
END_TEST

START_TEST(scale4_scales_a_vec3)
{
    vec4 v = {1.0f, 2.0f, 3.0f, 4.0f};

    vec4 result = { };

    scale4(&result, 1.5f, &v);

    ck_assert(result.v[0] == 1.5f);
    ck_assert(result.v[1] == 3.0f);
    ck_assert(result.v[2] == 4.5f);
    ck_assert(result.v[3] == 6.0f);
}
END_TEST

START_TEST(scale3_scales_a_vec3)
{
    vec3 v = {1.0f, 2.0f, 3.0f};

    vec3 result = { };

    scale3(&result, 1.5f, &v);

    ck_assert(result.v[0] == 1.5f);
    ck_assert(result.v[1] == 3.0f);
    ck_assert(result.v[2] == 4.5f);
}
END_TEST

START_TEST(norm4_returns_the_norm_of_a_vec4)
{
    vec4 v = {3.0f, 4.0f, 0.0f, 0.0f};

    ck_assert(norm4(&v) == 5.0f);
}
END_TEST

START_TEST(norm3_returns_the_norm_of_a_vec3)
{
    vec3 v = {3.0f, 4.0f, 0.0f};

    ck_assert(norm3(&v) == 5.0f);
}
END_TEST

START_TEST(cross_computes_cross_product_correctly)
{
    vec3 u = {1.0f, 2.0f, 3.0f};
    vec3 v = {4.0f, 5.0f, 6.0f};

    vec3 result = { };

    cross(&result, &u, &v);

    ck_assert(result.v[0] == -3.0f);
    ck_assert(result.v[1] ==  6.0f);
    ck_assert(result.v[2] == -3.0f);
}
END_TEST

START_TEST(vec4_dot_computes_dot_product_correctly)
{
    vec4 u = {1.0f, 2.0f, 3.0f, 4.0f};
    vec4 v = {5.0f, 6.0f, 7.0f, 8.0f};

    ck_assert(dot4(&u, &v) == 70.0f);
}
END_TEST

START_TEST(vec3_dot_computes_dot_product_correctly)
{
    vec3 u = {1.0f, 2.0f, 3.0f};
    vec3 v = {4.0f, 5.0f, 6.0f};

    ck_assert(dot3(&u, &v) == 32.0f);
}
END_TEST

Suite *make_matrix_suite()
{
    Suite *s;
    TCase *tc;

    s = suite_create("Matrix");
    tc = tcase_create("Vectors");

    tcase_add_test(tc, vec3_dot_computes_dot_product_correctly);
    tcase_add_test(tc, vec4_dot_computes_dot_product_correctly);
    tcase_add_test(tc, cross_computes_cross_product_correctly);
    tcase_add_test(tc, norm3_returns_the_norm_of_a_vec3);
    tcase_add_test(tc, norm4_returns_the_norm_of_a_vec4);
    tcase_add_test(tc, scale3_scales_a_vec3);
    tcase_add_test(tc, scale4_scales_a_vec3);
    tcase_add_test(tc, normalize3_normalizes_a_vec3);
    tcase_add_test(tc, normalize4_normalizes_a_vec4);

    suite_add_tcase(s, tc);

    return s;
}
