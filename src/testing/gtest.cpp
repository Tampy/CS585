// gtest.cpp

#include <gtest/gtest.h>
#include <dynamic_array.h>
#include <map.h>

TEST( Map, has ) {
    StevensDev::sgdc::Map<int> map;
    map["test"] = 4;
    EXPECT_EQ( true, map.has( "test" ) );
}

TEST( Map, keys ) {
    StevensDev::sgdc::Map<int> map;
    StevensDev::sgdc::DynamicArray<std::string> array;
    
    map["test"] = 4;
    array = map.keys();
    EXPECT_EQ( "test", array[0] );
}

TEST( Map, values ) {
    StevensDev::sgdc::Map<int> map;
    StevensDev::sgdc::DynamicArray<int> array;
    
    map["test"] = 4;
    array = map.values();
    EXPECT_EQ( 4, array[0] );
}

TEST( Map, remove ) {
    StevensDev::sgdc::Map<int> map;
    StevensDev::sgdc::DynamicArray<int> array;
    
    map["test"] = 4;
    map["armed"] = 6;
    EXPECT_EQ( 6, map.remove( "armed" ) );
}

int main( int argc, char *argv[] ) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
