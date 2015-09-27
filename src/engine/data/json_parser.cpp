// json_parser.cpp

#include "json_parser.h"
#include <
#include "json_entity.h"
#include <sstream>

JsonEntity* JsonParser::fromString( const std::string& rawJson, IAllocator allocator ) {
    /*DynamicArray<string> splitJson;
    std::stringstream ss( rawJson );
    std::string jsonObject;
    
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
    if( !allocator ) {
        jsonAllocator = DefaultAllocator<JsonEntity>();
    }
}

JsonEntity JsonParser::helperParser ( const std::string& rawJson ) {
    int i, j, substrCount;
    std::string index = "";
    std::string value = "";
    for( i = 0; i < rawJson.length(); i++ ) {
        if( rawJson[i] == '\'' ) {
            i++;
            substrCount = rawJson.find( '\'' );
            index.append( rawJson.substr( i, substrCount - 1 ) );
            rawJson.erase( 0, substrCount );
            i++;
        }

        if( rawJson[i] == ':' ) {
            i++;
            while( rawJson[i] == ' ' ) {
                i++;
            }
            if( rawJson[i] == '[' ) {
                DynamicArray<JsonEntity> jsonArray;
                std::string jsonArrayValue = "";
                int bracketLocation = rawJson.find( ']' );
                while( i < bracketLocation ) {
                    if ( rawJson[i] == '\'' ) {
                        i++;
                        substrCount = rawJson.find( '\'' );
                        jsonArrayValue = rawJson.substr( i, substrCount - 1 );
                        rawJson.erase( 0, substrCount );
                        i++;
                        jsonArray.push( jsonArrayValue );
                    }
                    else {
                        i++;
                        substrCount = rawJson.find( ',' );
                        if ( substrCount == string::npos || substrCount > bracketLocation )
                        value.append( rawJson.substr( i, substrCount - 1 ) );
                        rawJson.erase( 0, substrCount );
                        i++;

                    }

                }
            }
            if ( rawJson[i] == '\'' ) {
                i++;
                substrCount = rawJson.find( '\'' );
                value.append( rawJson.substr( i, substrCount - 1 ) );
                rawJson.erase( 0, substrCount );
                i++;
            }
            else {
                i++;
                substrCount = rawJson.find( ',' );
                value.append( rawJson.substr( i, substrCount - 1 ) );
                rawJson.erase( 0, substrCount );
                i++;
            }
        }
    }

    splitJson.push( index, value );
}