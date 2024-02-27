//
// Created by msobral on 27/02/2024.
//

#include "testes.h"
#include <unistd.h>

MunitResult test1(const MunitParameter params[], void* user_data_or_fixture) {
    munit_assert_int(2, ==, 2);
    sleep(1);
    return MUNIT_OK;
}

//MunitTest testes[] = {
//        {
//            "/Teste1",
//            test1,
//            NULL,
//            NULL,
//            MUNIT_TEST_OPTION_NONE,
//            NULL
//        },
//        { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
//};

#define create_test1(name, func) {name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}

#define create_test2(name, func, ...) {name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, create_test1(__VA_ARGS__)

#define create_test3(name, func, ...) {name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, create_test2(__VA_ARGS__)

#define create_test4(name, func, ...) {name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, create_test3(__VA_ARGS__)

#define create_test5(name, func, ...) {name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, create_test4(__VA_ARGS__)

#define create_test6(name, func, ...) {name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, create_test5(__VA_ARGS__)

#define create_test7(name, func, ...) {name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, create_test6(__VA_ARGS__)

#define create_test8(name, func, ...) {name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, create_test7(__VA_ARGS__)

#define create_test9(name, func, ...) {name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, create_test8(__VA_ARGS__)

#define create_test10(name, func, ...) {name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, create_test9(__VA_ARGS__)

#define create_test11(name, func, ...) {name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, create_test10(__VA_ARGS__)

#define create_test12(name, func, ...) {name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, create_test11(__VA_ARGS__)

#define create_test13(name, func, ...) {name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, create_test12(__VA_ARGS__)

#define create_test14(name, func, ...) {name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, create_test13(__VA_ARGS__)

#define create_test15(name, func, ...) {name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, create_test14(__VA_ARGS__)

#define create_test16(name, func, ...) {name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, create_test15(__VA_ARGS__)

#define create_test17(name, func, ...) {name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, \
create_test16(__VA_ARGS__)

#define create_test18(name, func, ...) {name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, \
create_test17(__VA_ARGS__)

#define create_test19(name, func, ...) {name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, \
create_test18(__VA_ARGS__)

#define create_test20(name, func, ...) {name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, \
create_test19(__VA_ARGS__)

#define create_tests(name, ntests, ...) MunitTest name[] = { \
create_test##ntests(__VA_ARGS__),\
{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }}

create_tests(testes, 1, "/teste1", test1);

create_suite(suite, "/testes", testes);
//static const MunitSuite suite = {
//        "/testes", /* name */
//        testes, /* tests */
//        NULL, /* suites */
//        1, /* iterations */
//        MUNIT_SUITE_OPTION_NONE /* options */
//};

int main(int argc, char* argv[]) {
    /* Use µnit here. */
    exec_tests(suite);
//    return munit_suite_main(&suite, NULL, argc, argv);
}