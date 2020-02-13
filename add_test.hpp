#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "add.hpp"

TEST(AddTest, AddEvaluateZeroPZero) {
    Op* zero = new Op(0);
    Add* add = new Add(zero, zero);
    EXPECT_EQ(add->evaluate(), 0);
}

TEST(AddTest, AddEvaluatePositivePPositive) {
    Op* five = new Op(5);
    Add* add = new Add(five, five);
    EXPECT_EQ(add->evaluate(), 10);
}

TEST(AddTest, AddEvaluatNegativePNegative) {
    Op* nfive = new Op(-5);
    Add* add = new Add(nfive, nfive);
    EXPECT_EQ(add->evaluate(), -10);
}

TEST(AddTest, AddStringifyZeroPZero) {
    Op* zero = new Op(0);
    Add* add = new Add(zero, zero);
    EXPECT_EQ(add->stringify(), "0.000000 + 0.000000");
}

TEST(AddTest, AddSringifyPositivePPositive) {
    Op* five = new Op(5);
    Add* add = new Add(five, five);
    EXPECT_EQ(add->stringify(), "5.000000 + 5.000000");
}

TEST(AddTest, AddSringifyNegativePNegative) {
    Op* nfive = new Op(-5);
    Add* add = new Add(nfive, nfive);
    EXPECT_EQ(add->stringify(), "-5.000000 + -5.000000");
}

#endif //__ADD_TEST_HPP__

