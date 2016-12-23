#include <check.h>
#include <stdlib.h>
#include <OpenGL/OpenGL.h>

START_TEST(we_can_create_an_OpenGL_context)
{
    CGLError err1, err2 = 0;
    CGLPixelFormatAttribute attribs[] =
    {
        kCGLPFAAccelerated,
        kCGLPFAColorSize, 24,
        kCGLPFADepthSize, 16,
        kCGLPFADoubleBuffer,
        kCGLPFASupersample,
        0
    };
    CGLPixelFormatObj pixel_format;
    GLint number_pixel_formats = 0;

    err1 = CGLChoosePixelFormat(attribs, &pixel_format, &number_pixel_formats);
    err2 = CGLDestroyPixelFormat(pixel_format);

    ck_assert_int_eq(err1, kCGLNoError);
    ck_assert_int_eq(err2, kCGLNoError);
}
END_TEST

START_TEST(we_can_choose_an_OpenGL_pixel_format)
{
    CGLError err = 0;
    CGLPixelFormatAttribute attribs[] = {(CGLPixelFormatAttribute) 0};
    CGLPixelFormatObj pixel_format;

    GLint number_pixel_formats = 0;

    err = CGLChoosePixelFormat(attribs, &pixel_format, &number_pixel_formats);

    ck_assert_int_eq(err, 0);

    CGLDestroyPixelFormat(pixel_format);
}
END_TEST

Suite *make_engine_suite()
{
    Suite *s;
    TCase *tc;

    tc = tcase_create("Core");
    s = suite_create("suite");

    tcase_add_test(tc, we_can_choose_an_OpenGL_pixel_format);
    tcase_add_test(tc, we_can_create_an_OpenGL_context);

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
