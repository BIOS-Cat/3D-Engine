#include <check.h>

#include <math/matrix.h>
#include "matrix_test.h"

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

    float result = dot4(&u, &v);

    ck_assert(result == 70.0f);
}
END_TEST

START_TEST(vec3_dot_computes_dot_product_correctly)
{
    vec3 u = {1.0f, 2.0f, 3.0f};
    vec3 v = {4.0f, 5.0f, 6.0f};

    float result = dot3(&u, &v);

    ck_assert(result == 32.0f);
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

    suite_add_tcase(s, tc);

    return s;
}
