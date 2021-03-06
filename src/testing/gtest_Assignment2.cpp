// gtest.cpp

#include <gtest/gtest.h>
#include <dynamic_array.h>

TEST( DynamicArray, push ) {
    StevensDev::sgdc::DynamicArray<int> array;
    
    array.push(0);
    array.push(1);
    array.push(2);
    array.push(3);
    array.push(4);
    array.push(5);
    array.push(6);
    array.push(7);
    array.push(8);
    array.push(9);
    array.push(10);
    
    EXPECT_EQ( 0, array.at( 0 ) );
    EXPECT_EQ( 1, array.at( 1 ) );
    EXPECT_EQ( 2, array.at( 2 ) );
    EXPECT_EQ( 7, array.at( 7 ) );
}

TEST( DynamicArray, pushFront ) {
    StevensDev::sgdc::DynamicArray<int> array;
    
    array.pushFront(0);
    array.pushFront(1);
    array.pushFront(2);
    array.pushFront(3);
    array.pushFront(4);
    array.pushFront(5);
    array.pushFront(6);
    array.pushFront(7);
    array.pushFront(8);
    array.pushFront(9);
    array.pushFront(10);
    
    EXPECT_EQ( 10, array.at( 0 ) );
    EXPECT_EQ( 9 , array.at( 1 ) );
    EXPECT_EQ( 8 , array.at( 2 ) );
    EXPECT_EQ( 1, array.at( 9 ) );
}

TEST( DynamicArray, pop ) {
    StevensDev::sgdc::DynamicArray<int> array;
    
    array.push(0);
    array.push(1);
    array.push(2);
    array.push(3);
    array.push(4);
    array.push(5);
    array.push(6);
    array.push(7);
    array.push(8);
    array.push(9);
    array.push(10);
    
    EXPECT_EQ( 10, array.pop() );
    EXPECT_EQ( 9, array.pop() );
    EXPECT_EQ( 8, array.pop() );
}

TEST( DynamicArray, popFront ) {
    StevensDev::sgdc::DynamicArray<int> array;
    
    array.push(0);
    array.push(1);
    array.push(2);
    array.push(3);
    array.push(4);
    array.push(5);
    array.push(6);
    array.push(7);
    array.push(8);
    array.push(9);
    array.push(10);
    
    EXPECT_EQ( 0, array.popFront() );
    EXPECT_EQ( 1, array.popFront() );
    EXPECT_EQ( 2, array.popFront() );
}

TEST( DynamicArray, getLength ) {
    StevensDev::sgdc::DynamicArray<int> array;
    
    EXPECT_EQ( 0, array.getLength() );
    array.push(0);
    array.push(1);
    array.push(2);
    array.push(3);
    EXPECT_EQ( 4, array.getLength() );
    array.push(4);
    array.push(5);
    array.push(6);
    array.push(7);
    EXPECT_EQ( 8, array.getLength() );
    array.push(8);
    array.push(9);
    array.push(10);
    EXPECT_EQ( 11, array.getLength() );
}

TEST( DynamicArray, at ) {
    StevensDev::sgdc::DynamicArray<int> array;
    
    array.push(0);
    array.push(1);
    array.push(2);
    array.push(3);
    array.push(4);
    array.push(5);
    array.push(6);
    array.push(7);
    array.push(8);
    array.push(9);
    array.push(10);
    
    EXPECT_EQ( 1, array.at( 1 ) );
    EXPECT_EQ( 6, array.at( 6 ) );
    EXPECT_EQ( 7, array.at( 7 ) );
    // EXPECT_EQ( 0, array.at( 13 ) );
}

TEST( DynamicArray, brackets ) {
    StevensDev::sgdc::DynamicArray<int> array;
    
    array.push(0);
    array.push(1);
    array.push(2);
    array.push(3);
    array.push(4);
    array.push(5);
    array.push(6);
    array.push(7);
    array.push(8);
    array.push(9);
    array.push(10);
    
    EXPECT_EQ( 1, array[1] );
    EXPECT_EQ( 2, array[2] );
    EXPECT_EQ( 7, array[7] );
}

/*TEST( DynamicArray, removeAt ) {

}

TEST( DynamicArray, insertAt ) {

}*/

int main( int argc, char *argv[] ) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
