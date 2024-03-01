//
// Created by msobral on 27/02/2024.
//

#include "testes.h"
#include <unistd.h>
#include "libprg/libprg.h"

define_test(test1) {
    assert_int(2, ==, 2);
    return MUNIT_OK;
}

define_test(test2) {
    assert_string_equal("blabla", "blabla");
    return MUNIT_OK;
}

int soma(int x, int y) {
    return x - y;
}

define_test(teste_soma) {
    result_t z = compute(1, 1, SUM);

    assert_double(z.value, ==, 2);

    return MUNIT_OK;
}

create_suite(suite, testes, 3, test1, test2, teste_soma);

int main(int argc, char* argv[]) {
    /* Use µnit here. */
    exec_tests(suite);
}