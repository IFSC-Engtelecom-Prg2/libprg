//
// Created by msobral on 27/02/2024.
//

#include "testes.h"
#include <unistd.h>

define_test(test1) {
    assert_int(2, ==, 2);
    return MUNIT_OK;
}

define_test(test2) {
    assert_string_equal("blabla", "coisarada");
    return MUNIT_OK;
}

create_suite(suite, testes, 2, test1, test2);

int main(int argc, char* argv[]) {
    /* Use µnit here. */
    exec_tests(suite);
}