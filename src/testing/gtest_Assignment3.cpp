// gtest.cpp

#include <gtest/gtest.h>
#include <containers/dynamic_array.h>
#include <containers/map.h>
#include <stdexcept>

TEST( Map, has ) {
    StevensDev::sgdc::Map<int> map;
    map["test"] = 4;
    EXPECT_EQ( true, map.has( "test" ) );
    EXPECT_FALSE( map.has( "armed" ) );
}

TEST( Map, keys ) {
    StevensDev::sgdc::Map<int> map;
    StevensDev::sgdc::DynamicArray<std::string> array;
    
    map["test"] = 4;
    array = map.keys();
    EXPECT_EQ( "test", array[0] );
    EXPECT_THROW( array.at( 11 ), std::out_of_range );
}

TEST( Map, values ) {
    StevensDev::sgdc::Map<int> map;
    StevensDev::sgdc::DynamicArray<int> array;
    
    map["test"] = 4;
    array = map.values();
    EXPECT_EQ( 4, array.at ( 0 ) );
    EXPECT_THROW( array.at ( 11 ), std::out_of_range );
}

TEST( Map, remove ) {
    StevensDev::sgdc::Map<int> map;
    StevensDev::sgdc::DynamicArray<int> array;
    
    map["test"] = 4;
    map["armed"] = 6;
    EXPECT_EQ( 6, map.remove( "armed" ) );
    EXPECT_EQ( 0, map.remove( "armed" ) );
    EXPECT_TRUE( map.has( "test" ) );
    EXPECT_FALSE( map.has( "armed" ) );
}

int main( int argc, char *argv[] ) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
