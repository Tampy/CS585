// gtest.cpp

#include <gtest/gtest.h>


/*TEST( Map, remove ) {
    StevensDev::sgdc::Map<int> map;
    StevensDev::sgdc::DynamicArray<int> array;
    
    map["test"] = 4;
    map["armed"] = 6;
    EXPECT_EQ( 6, map.remove( "armed" ) );
    EXPECT_EQ( 0, map.remove( "armed" ) );
    EXPECT_TRUE( map.has( "test" ) );
    EXPECT_FALSE( map.has( "armed" ) );
}*/

int main( int argc, char *argv[] ) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
