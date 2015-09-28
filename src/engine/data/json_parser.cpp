// json_parser.cpp

#include "json_parser.h"
#include "json_entity.h"
#include <memory/default_allocator.h>

JsonEntity* JsonParser::fromString( const std::string& rawJson, IAllocator<JsonEntity>* allocator ) {
    if( !allocator ) {
        jsonAllocator = DefaultAllocator<JsonEntity>();
    }
    else {
        jsonAllocator = allocator;
    }
    currentLocation = 0;
    jsonLength = rawJson.length();
    jsonDocument = rawJson;
}

Token JsonParser::parser() {
    while( currentLocation < jsonLength ) {
        removeSpaces();
        Token returnToken;
        char tokenTest = jsonDocument[currentLocation];
        switch( tokenTest ) {
            case '\'':
                parseString();
                returnToken = STRING;
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                returnToken = parseNum();
                break;
            case '[':
                parseArray();
                returnToken = ARRAY_START;
                break;
            default:
                break;
        }
    }
}

String& JsonParser::parseString() {
    std::string parsedString = "";
    for( currentLocation; currentLocation < jsonLength; currentLocation++ ) {
        char quoteTest = jsonDocument[currentLocation];
        if ( quoteTest != '\'' ) {
            parsedString.append( jsonDocument[currentLocation] );
        }
        else {
            break;
        }
    }
    return parsedString;
}

void JsonParser::removeSpaces() {
    for( currentLocation; currentLocation < jsonLength; currentLocation++ ) {
        char spaceTest = jsonDocument[currentLocation];
        if ( spaceTest != ' ' && spaceTest != '\t' && spaceTest != '\n' ) {
            break;
        }
    }
}

/*JsonEntity JsonParser::helperParser ( const std::string& rawJson ) {
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
}*/