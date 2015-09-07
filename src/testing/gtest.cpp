// gtest.cpp

#include <gtest/gtest.h>
#include "src/testing/square.h"

Testing test;

TEST(SquareTest, PositiveNos) {
    EXPECT_EQ(81.0, test.square(9.0));
}

TEST(SquareTest, ZeroAndNegativeNos) {
    EXPECT_EQ(0.0, test.square(0.0));
    EXPECT_EQ(81.0, test.square(-9.0));
}

TEST(SquareRootTest, PositiveNos) {
    EXPECT_EQ(9.0, test.squareRoot(81.0));
}

TEST(SquareRootTest, ZeroAndNegativeNos) {
    EXPECT_EQ(0.0, test.squareRoot(0.0));
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}