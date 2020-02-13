#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "mult.hpp"

TEST(MultTest, MultEvaluateZeroMZero) {
	Op* zero = new Op(0);
	Mult* mult = new Mult(zero, zero);
	EXPECT_EQ(mult->evaluate(), 0);
}

TEST(MultTest, MultEvaluatePosMPos) {
	Op* six = new Op(6);
	Mult* mult = new Mult(six, six);
	EXPECT_EQ(mult->evaluate(), 36);
}

TEST(MultTest, MultEvaluateNegMNeg) {
	Op* nsix = new Op(-6);
	Mult* mult = new Mult(nsix, nsix);
	EXPECT_EQ(mult->evaluate(), 36);
}

TEST(MultTest, MultStringifyZeroMZero) {
	Op* zero = new Op(0);
	Mult* mult = new Mult(zero, zero);
	EXPECT_EQ(mult->stringify(), "0.000000 * 0.000000");
}

TEST(MultTest, MultStringifyPosMPos) {
	Op* six = new Op(6);
	Mult* mult = new Mult(six, six);
	EXPECT_EQ(mult->stringify(), "6.000000 * 6.000000");
}

TEST(MultTest, MultStringifyNegMNeg) {
	Op* nsix = new Op(-6);
	Mult* mult = new Mult(nsix, nsix);
	EXPECT_EQ(mult->stringify(), "-6.000000 * -6.000000");
}

#endif //__MULT_TEST_HPP__
