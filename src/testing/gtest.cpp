// gtest.cpp

#include <gtest/gtest.h>

/*TEST( SquareTest, PositiveNos ) {
    EXPECT_EQ( 81.0, Square::square( 9.0 ) );
}
  // Test positive values of square.

TEST( SquareTest, ZeroAndNegativeNos ) {
    EXPECT_EQ( 0.0, Square::square( 0.0 ) );
    EXPECT_EQ( 81.0, Square::square( -9.0 ) );
}
  // Test negative values of square.

TEST( SquareRootTest, PositiveNos ) {
    EXPECT_EQ( 9.0, Square::squareRoot( 81.0 ) );
}

TEST( SquareRootTest, ZeroAndNegativeNos ) {
    EXPECT_EQ( 0.0, Square::squareRoot( 0.0 ) );
}*/

TEST( DefaultAllocTest, PositiveNos ) {

}

TEST( TotalAllocTest, PositiveNos ) {

}

TEST( TotalDeleteTest, PositiveNos ) {

}

TEST( TotalOustandingTest, PositiveNos ) {

}

TEST( SimpleDynamicArrayTest, PositiveNos ) {

}

TEST( IncrementingDynamicArrayTest, PositiveNos) {

}

TEST( EdgeDynamicArrayTest, PositiveNos ) {
    
}

int main( int argc, char *argv[] ) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}