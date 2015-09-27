// json_parser.cpp

#include "json_parser.h"
#include "json_entity.h"
#include <sstream>

JsonEntity* JsonParser::fromString( const std::string& rawJson, IAllocator allocator ) {
    /*DynamicArray<string> splitJson;
    std::stringstream ss( rawJson );
    std::string jsonObject;
    std::string index = "";
    std::string value = "";
    int delimLocation;
    while ( std::getline( ss, jsonObject, "," ) ) {
        delimLocation = jsonObject.find( ":" );
        index = jsonObject.substr( 0, delimLocation );
        value = jsonObject.substr( delimLocation, jsonObject.length() );
        delimLocation = jsonObject.find( "[" )
        if ( bracketLocation ) {

        }
        ss.insertAt( index, value );
    }*/

    DynamicArray<string> splitJson;
    int i, j, substrCount;
    bool indexRetrieved = false;
    bool valueRetrieved = false;
    for( i = 0; i < rawJson.length(); i++ ) {
        if( rawJson[i] == '\'' ) {
            i++;
            substrCount = rawJson.find( '\'' );
            index.append( rawJson.substr( i, substrCount - 1 ) );
            i++;
        }

        if( rawJson[i] == ':' ) {
            i++;
            while( rawJson[i] == ' ' ) {
                i++;
            }
            if( rawJson[i] == '[' ) {
                //TODO
            }
            else if ( rawJson[i] == '\'' ) {
                i++;
                substrCount = rawJson.find( '\'' );
                value.append( rawJson.substr( i, substrCount - 1 ) );
                i++;
            }
            else {
                i++;
                substrCount = rawJson.find( ',' );
                value.append( rawJson.substr( i, substrCount - 1) );
                i++;
            }
        }
    }

    splitJson.push( index, value );
}

string parser (const std::string rawJson ) {

}