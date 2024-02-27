//
// Created by msobral on 27/02/24.
//

#ifndef LIBPRG_TESTES_H
#define LIBPRG_TESTES_H

//
// Created by msobral on 27/02/2024.
//

#include "munit.h"
//#include <unistd.h>
//
//MunitResult test1(const MunitParameter params[], void* user_data_or_fixture) {
//    munit_assert_int(2, ==, 2);
//    sleep(1);
//    return MUNIT_OK;
//}
//
//MunitTest testes[] = {
//        {
//                "/Teste1",
//                test1,
//                      NULL,
//                            NULL,
//                                  MUNIT_TEST_OPTION_NONE,
//                                                          NULL
//        },
//        { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
//};

#define create_suite(var, name, tests) static const MunitSuite var = { \
        name, /* name */ \
        tests, /* tests */ \
        NULL, /* suites */ \
        1, /* iterations */ \
        MUNIT_SUITE_OPTION_NONE /* options */ \
}

#define exec_tests(name) return munit_suite_main(&name, NULL, argc, argv)

#endif //LIBPRG_TESTES_H
