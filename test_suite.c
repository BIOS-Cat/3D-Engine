#include <check.h>
#include <stdlib.h>

START_TEST(a_test)
{
    ck_assert(1);
}
END_TEST

Suite *make_engine_suite()
{
    Suite *s; 
    TCase *tc;

    tc = tcase_create("Core");
    s = suite_create("suite");

    tcase_add_test(tc, a_test);

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

    srunner_run_all(sr, CK_VERBOSE);

    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed==0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
