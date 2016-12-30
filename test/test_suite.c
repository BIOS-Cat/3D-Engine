#include <check.h>
#include <stdlib.h>

#include "plus/plus_test.h"
#include "minus/minus_test.h"

int main()
{
    int number_failed; 
    Suite *s;
    SRunner *sr;

    sr = srunner_create(make_plus_suite());
    srunner_add_suite(sr, make_minus_suite());

    srunner_run_all(sr, CK_NORMAL);

    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed==0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
