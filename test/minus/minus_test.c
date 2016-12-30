#include <check.h>
#include <stdlib.h>

#include <minus/minus.h>
#include "minus_test.h"

START_TEST(five_minus_two_equals_three)
{
    ck_assert_int_eq(minus(5, 2), 3);
}
END_TEST

#if 0
START_TEST(a_failing_test)
{
    ck_assert_int_eq(0, 1);
}
END_TEST
#endif

Suite *make_minus_suite()
{
    Suite *s; 
    TCase *tc;

    s = suite_create("Minus");
    tc = tcase_create("Core");

    tcase_add_test(tc, five_minus_two_equals_three);
#if 0
    tcase_add_test(tc, a_failing_test);
#endif
    suite_add_tcase(s, tc);

    return s;
}
