#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "pow.hpp"

TEST(PowTest, PowEvaluateZeroPZero) {
    Op* zero = new Op(0);
    Pow* pow = new Pow(zero, zero);
    EXPECT_EQ(pow->evaluate(), 1);
}

TEST(PowTest, PowEvaluatePositivePPositive) {
    Op* five = new Op(5);
    Op* two = new Op(2);
    Pow* pow = new Pow(five, two);
    EXPECT_EQ(pow->evaluate(), 25);
}

TEST(PowTest, PowEvaluatNegativePPositive) {
    Op* ntwo = new Op(-2);
    Op* three = new Op(3);
    Pow* pow = new Pow(ntwo, three);
    EXPECT_EQ(pow->evaluate(), -8);
}

TEST(PowTest, PowEvaluatPositivePNegative) {
    Op* ntwo = new Op(-2);
    Op* two = new Op(2);
    Pow* pow = new Pow(two, ntwo);
    EXPECT_EQ(pow->evaluate(), 0.25);
}

TEST(PowTest, PowStringifyZeroPZero) {
    Op* zero = new Op(0);
    Pow* pow = new Pow(zero, zero);
    EXPECT_EQ(pow->stringify(), "0.000000 ** 0.000000");
}

TEST(PowTest, PowSringifyPositivePPositive) {
    Op* five = new Op(5);
    Pow* pow = new Pow(five, five);
    EXPECT_EQ(pow->stringify(), "5.000000 ** 5.000000");
}

TEST(PowTest, PowSringifyNegativePNegative) {
    Op* nfive = new Op(-5);
    Pow* pow = new Pow(nfive, nfive);
    EXPECT_EQ(pow->stringify(), "-5.000000 ** -5.000000");
}

#endif //__POW_TEST_HPP__


