// gtest.cpp

#include <gtest/gtest.h>
#include <scene/rectangle_bounds.h>


TEST( RectangleBounds, basic ) {
    StevensDev::sgds::RectangleBounds bounds( 0, 0, 200, 200 );
    EXPECT_EQ( 0, bounds.x() );
    EXPECT_EQ( 0, bounds.y() );
    EXPECT_EQ( 200, bounds.width() );
    EXPECT_EQ( 200, bounds.height() );

    bounds.setX( 50 );
    bounds.setY( 70 ) ;
    bounds.setWidth( 100 );
    bounds.setHeight( 80 );
    EXPECT_EQ( 50, bounds.x() );
    EXPECT_EQ( 70, bounds.y() );
    EXPECT_EQ( 100, bounds.width() );
    EXPECT_EQ( 80, bounds.height() );

    bounds.setPosition( 32, 23 );
    bounds.setDimensions( 300, 200 );
    EXPECT_EQ( 32, bounds.x() );
    EXPECT_EQ( 23, bounds.y() );
    EXPECT_EQ( 300, bounds.width() );
    EXPECT_EQ( 200, bounds.height() );
}

TEST( RectangleBounds, compare ) {
    StevensDev::sgds::RectangleBounds bounds1( 0, 0, 200, 200 );
    StevensDev::sgds::RectangleBounds bounds2( 20, 20, 50, 50 );
    StevensDev::sgds::RectangleBounds bounds3( 500, 500, 2, 2 );

    EXPECT_TRUE( bounds1.doesCollide( bounds2 ) );
    EXPECT_FALSE( bounds1.doesCollide( bounds3 ) );
}

int main( int argc, char *argv[] ) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
