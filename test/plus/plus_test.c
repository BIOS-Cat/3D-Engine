#include <check.h>
#include <stdlib.h>

#include <plus/plus.h>

START_TEST(two_plus_three_equals_five)
{
    ck_assert_int_eq(plus(2, 3), 5);
}
END_TEST

Suite *make_engine_suite()
{
    Suite *s; 
    TCase *tc;

    s = suite_create("Plus");
    tc = tcase_create("Core");

    tcase_add_test(tc, two_plus_three_equals_five);

    suite_add_tcase(s, tc);

    return s;
}

int main()
{
    int number_failed; 
    Suite *s;
    SRunner *sr;

    s = make_engine_suite();

    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);

    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed==0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
