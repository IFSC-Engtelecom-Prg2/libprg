//
// Created by msobral on 27/02/2024.
//

#include "munit.h"

void your_function(int foo, int bar) {
    munit_assert_int(foo, ==, bar);
}

void main(void) {
    /* Use µnit here. */
    your_function(1,2);
}