// gtest.cpp

#include <gtest/gtest.h>
/*#include <data/json_entity.h>
#include <data/json_parser.h>
#include <memory/stack_guard.h>
#include <string>

TEST( Json, basic ) {
    std::string json = "{ 'test' : 'success' }";
    StevensDev::sgdd::JsonEntity* config = StevensDev::sgdd::JsonParser::fromString( json );
    StevensDev::sgdm::StackGuard<StevensDev::sgdd::JsonEntity> guard( config );

    EXPECT_EQ( "success", (*config)["test"].asString() );
}*/

int main( int argc, char *argv[] ) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
