#ifndef __ALL_TEST_HPP__
#define __ALL_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "rand.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"


TEST(AllTest, EvaluateSubMult) {
    Base* two = new Op(2);
    Base* three = new Op(3);
    Base* mult = new Mult(two, three);
    Base* sub = new Sub(mult, two);
    EXPECT_EQ(sub->evaluate(), 4);
}

TEST(AllTest, EvaluateAddPow) {
    Base* two = new Op(2);
    Base* three = new Op(3);
    Base* pow = new Pow(three, two);
    Base* add = new Add(two, pow);
    EXPECT_EQ(add->evaluate(), 11);
}

TEST(AllTest, EvaluateAddDiv) {
    Base* two = new Op(2);
    Base* three = new Op(3);
    Base* div = new Div(two, two);
    Base* add = new Add(three, div);
    EXPECT_EQ(add->evaluate(), 4);
}

TEST(AllTest, EvaluateMultDiv) {
    Base* two = new Op(2);
    Base* six = new Op(6);
    Base* four = new Op(4);
    Base* mult = new Mult(two, six);
    Base* div = new Div(mult, four);
    EXPECT_EQ(div->evaluate(), 3);
}

TEST(AllTest, EvaluateAddAdd) {
    Base* two = new Op(2);
    Base* three = new Op(3);
    Base* add1 = new Add(two, two);
    Base* add2 = new Add(three, add1);
    EXPECT_EQ(add2->evaluate(), 7);
}


TEST(AllTest, StringifySubMult) {
    Base* two = new Op(2);
    Base* three = new Op(3);
    Base* mult = new Mult(two, three);
    Base* sub = new Sub(mult, two);
    EXPECT_EQ(sub->stringify(), "2.000000 * 3.000000 - 2.000000");
}

TEST(AllTest, StringifyAddPow) {
    Base* two = new Op(2);
    Base* three = new Op(3);
    Base* pow = new Pow(three, two);
    Base* add = new Add(two, pow);
    EXPECT_EQ(add->stringify(), "2.000000 + 3.000000 ** 2.000000");
}

TEST(AllTest, StringifyAddDiv) {
    Base* two = new Op(2);
    Base* three = new Op(3);
    Base* div = new Div(two, two);
    Base* add = new Add(three, div);
    EXPECT_EQ(add->stringify(), "3.000000 + 2.000000 / 2.000000");
}

TEST(AllTest, StringifyMultDiv) {
    Base* two = new Op(2);
    Base* six = new Op(6);
    Base* four = new Op(4);
    Base* mult = new Mult(two, six);
    Base* div = new Div(mult, four);
    EXPECT_EQ(div->stringify(), "2.000000 * 6.000000 / 4.000000");
}

TEST(AllTest, StringifyAddAdd) {
    Base* two = new Op(2);
    Base* three = new Op(3);
    Base* add1 = new Add(two, two);
    Base* add2 = new Add(three, add1);
    EXPECT_EQ(add2->stringify(), "3.000000 + 2.000000 + 2.000000");
}



#endif //__ALL_TEST_HPP__


