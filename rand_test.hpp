#ifndef __RAND_TEST_HPP__
#define __RAND_TEST_HPP__

#include <stdlib.h>

#include "gtest/gtest.h"

#include "op.hpp"
#include "rand.hpp"

TEST(RandTest, RandEvaluate) {
    srand(523);
    Rand* rand = new Rand();
    EXPECT_EQ(rand->evaluate(), 55);
}

TEST(RandTest, RandStringify) {
    srand(523);
    Rand* rand = new Rand();
    EXPECT_EQ(rand->stringify(), "55.000000");
}

#endif //__RAND_TEST_HPP__
