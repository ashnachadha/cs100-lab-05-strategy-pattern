#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "sub.hpp"

TEST(SubTest, SubEvaluateZeroSZero) {
	Op* zero = new Op(0);
	Sub* sub = new Sub(zero, zero);
	EXPECT_EQ(sub->evaluate(), 0);
}

TEST(SubTest, SubEvaluatePosSPos) {
	Op* five = new Op(5);
	Op* four = new Op(4);
	Sub* sub = new Sub(five, four);
	EXPECT_EQ(sub->evaluate(), 1);
}

TEST(SubTest, SubEvaluateNegSNeg) {
	Op* nfive = new Op(-5);
	Sub* sub = new Sub(nfive, nfive);
	EXPECT_EQ(sub->evaluate(), 0);
}

TEST(SubTest, SubStringifyZeroSZero) {
	Op* zero = new Op(0);
	Sub* sub = new Sub(zero, zero);
	EXPECT_EQ(sub->stringify(), "0.000000 - 0.000000");
}

TEST(SubTest, SubStringifyPosSPos) {
	Op* five = new Op(5);
	Op* four = new Op(4);
	Sub* sub = new Sub(five, four);
	EXPECT_EQ(sub->stringify(), "5.000000 - 4.000000");
}

TEST(SubTest, SubStringifyNegSNeg) {
	Op* nfive = new Op(-5);
	Sub* sub = new Sub(nfive, nfive);
	EXPECT_EQ(sub->stringify(), "-5.000000 - -5.000000");
}

#endif //__SUB_TEST_HPP__
