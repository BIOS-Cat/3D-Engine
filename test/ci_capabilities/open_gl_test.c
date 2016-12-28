#include <check.h>
#include <stdlib.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl3.h>

START_TEST(we_can_query_for_the_OpenGL_version)
{
    CGLError err1, err2, err3, err4, err5;
    CGLPixelFormatAttribute attribs[3] = {
        kCGLPFAOpenGLProfile,
        (CGLPixelFormatAttribute) kCGLOGLPVersion_GL4_Core,
        (CGLPixelFormatAttribute) 0
    };
    CGLPixelFormatObj pixel_format;
    GLint number_pixel_formats = 0;
    CGLContextObj context;

    GLint major_version = 0;
    GLint minor_version = 0;

    err1 = CGLChoosePixelFormat(attribs, &pixel_format, &number_pixel_formats);
    err2 = CGLCreateContext(pixel_format, NULL, &context);
    err3 = CGLDestroyPixelFormat(pixel_format);
    err4 = CGLSetCurrentContext(context);

    glGetIntegerv(GL_MAJOR_VERSION, &major_version);
    glGetIntegerv(GL_MINOR_VERSION, &minor_version);

    err5 = CGLDestroyContext(context);

    ck_assert_int_eq(err1, kCGLNoError);
    ck_assert_int_eq(err2, kCGLNoError);
    ck_assert_int_eq(err3, kCGLNoError);
    ck_assert_int_eq(err4, kCGLNoError);
    ck_assert_int_eq(err5, kCGLNoError);

    ck_assert_int_eq(major_version, 4);
    ck_assert_int_eq(minor_version, 1);
}
END_TEST

#ifndef __travis__
START_TEST(we_can_create_an_accelerated_OpenGL_context)
{
    CGLError err1, err2, err3, err4, err5;
    CGLPixelFormatAttribute attribs[] =
    {
        kCGLPFAAccelerated,
        0
    };
    CGLPixelFormatObj pixel_format;
    GLint number_pixel_formats = 0;
    CGLContextObj context;

    err1 = CGLChoosePixelFormat(attribs, &pixel_format, &number_pixel_formats);
    err2 = CGLCreateContext(pixel_format, NULL, &context);
    err3 = CGLDestroyPixelFormat(pixel_format);
    err4 = CGLSetCurrentContext(context);
    err5 = CGLDestroyContext(context);

    ck_assert_int_eq(err1, kCGLNoError);
    ck_assert_int_eq(err2, kCGLNoError);
    ck_assert_int_eq(err3, kCGLNoError);
    ck_assert_int_eq(err4, kCGLNoError);
    ck_assert_int_eq(err5, kCGLNoError);
}
END_TEST
#endif

START_TEST(we_can_create_an_OpenGL_context_with_double_buffering)
{
    CGLError err1, err2, err3, err4, err5;
    CGLPixelFormatAttribute attribs[] =
    {
        kCGLPFADoubleBuffer,
        0
    };
    CGLPixelFormatObj pixel_format;
    GLint number_pixel_formats = 0;
    CGLContextObj context;

    err1 = CGLChoosePixelFormat(attribs, &pixel_format, &number_pixel_formats);
    err2 = CGLCreateContext(pixel_format, NULL, &context);
    err3 = CGLDestroyPixelFormat(pixel_format);
    err4 = CGLSetCurrentContext(context);
    err5 = CGLDestroyContext(context);

    ck_assert_int_eq(err1, kCGLNoError);
    ck_assert_int_eq(err2, kCGLNoError);
    ck_assert_int_eq(err3, kCGLNoError);
    ck_assert_int_eq(err4, kCGLNoError);
    ck_assert_int_eq(err5, kCGLNoError);
}
END_TEST

START_TEST(we_can_create_an_OpenGL_context)
{
    CGLError err1, err2, err3, err4, err5;
    CGLPixelFormatAttribute attribs[] =
    {
        0
    };
    CGLPixelFormatObj pixel_format;
    GLint number_pixel_formats = 0;
    CGLContextObj context;

    err1 = CGLChoosePixelFormat(attribs, &pixel_format, &number_pixel_formats);
    err2 = CGLCreateContext(pixel_format, NULL, &context);
    err3 = CGLDestroyPixelFormat(pixel_format);
    err4 = CGLSetCurrentContext(context);
    err5 = CGLDestroyContext(context);

    ck_assert_int_eq(err1, kCGLNoError);
    ck_assert_int_eq(err2, kCGLNoError);
    ck_assert_int_eq(err3, kCGLNoError);
    ck_assert_int_eq(err4, kCGLNoError);
    ck_assert_int_eq(err5, kCGLNoError);
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

    s = suite_create("OpenGL CI Test");
    tc = tcase_create("Core");

    tcase_add_test(tc, we_can_choose_an_OpenGL_pixel_format);
    tcase_add_test(tc, we_can_create_an_OpenGL_context);
    tcase_add_test(tc, we_can_create_an_OpenGL_context_with_double_buffering);

#ifndef __travis__
    tcase_add_test(tc, we_can_create_an_accelerated_OpenGL_context);
#endif
    tcase_add_test(tc, we_can_query_for_the_OpenGL_version);

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
