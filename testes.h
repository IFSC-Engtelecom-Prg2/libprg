//
// Created by msobral on 27/02/24.
//

#ifndef LIBPRG_TESTES_H
#define LIBPRG_TESTES_H

#define MUNIT_ENABLE_ASSERT_ALIASES
#include "munit.h"

#define define_test(name) MunitResult name(const MunitParameter params[], void* user_data_or_fixture)

#define create_test1(name) {"::" #name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}

#define create_test2(name, ...) {"::" #name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, create_test1(__VA_ARGS__)

#define create_test3(name, ...) {"::" #name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, create_test2(__VA_ARGS__)

#define create_test4(name, ...) {"::" #name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, create_test3(__VA_ARGS__)

#define create_test5(name, ...) {"::" #name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, create_test4(__VA_ARGS__)

#define create_test6(name, ...) {"::" #name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, create_test5(__VA_ARGS__)

#define create_test7(name, ...) {"::" #name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, create_test6(__VA_ARGS__)

#define create_test8(name, ...) {"::" #name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, create_test7(__VA_ARGS__)

#define create_test9(name, ...) {"::" #name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, create_test8(__VA_ARGS__)

#define create_test10(name, ...) {"::" #name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, create_test9(__VA_ARGS__)

#define create_test11(name, ...) {"::" #name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, create_test10(__VA_ARGS__)

#define create_test12(name, ...) {"::" #name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, create_test11(__VA_ARGS__)

#define create_test13(name, ...) {"::" #name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, create_test12(__VA_ARGS__)

#define create_test14(name, ...) {"::" #name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, create_test13(__VA_ARGS__)

#define create_test15(name, ...) {"::" #name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, create_test14(__VA_ARGS__)

#define create_test16(name, ...) {"::" #name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, create_test15(__VA_ARGS__)

#define create_test17(name, ...) {"::" #name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, \
create_test16(__VA_ARGS__)

#define create_test18(name, ...) {"::" #name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, \
create_test17(__VA_ARGS__)

#define create_test19(name, ...) {"::" #name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, \
create_test18(__VA_ARGS__)

#define create_test20(name, ...) {"::" #name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, \
create_test19(__VA_ARGS__)

#define create_tests(name, ntests, ...) MunitTest name[] = { \
create_test##ntests(__VA_ARGS__),\
{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }}

#define create_suite(var, name, ntests, ...) create_tests(name, ntests, __VA_ARGS__); \
static const MunitSuite var = { \
        #name, /* name */ \
        name, /* tests */ \
        NULL, /* suites */ \
        1, /* iterations */ \
        MUNIT_SUITE_OPTION_NONE /* options */ \
}

#define exec_tests(name) return munit_suite_main(&name, NULL, argc, argv)

#endif //LIBPRG_TESTES_H
