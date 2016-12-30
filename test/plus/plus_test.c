#include <check.h>
#include <stdlib.h>

#include <plus/plus.h>
#include "plus_test.h"

START_TEST(two_plus_three_equals_five)
{
    ck_assert_int_eq(plus(2, 3), 5);
}
END_TEST

Suite *make_plus_suite()
{
    Suite *s; 
    TCase *tc;

    s = suite_create("Plus");
    tc = tcase_create("Core");

    tcase_add_test(tc, two_plus_three_equals_five);

    suite_add_tcase(s, tc);

    return s;
}
