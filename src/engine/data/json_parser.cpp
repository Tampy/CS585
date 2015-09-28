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
    Token token;
    while( currentLocation < jsonLength ) {
        token = parser();
    }
}

Token JsonParser::parser() {
    
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
            parseNum();
            returnToken = INT;
            break;
        case '[':
            parseArray();
            returnToken = ARRAY_START;
            break;
        case ':':
            returnToken = VALUE_START
        case ',':
            returnToken = NEW_ITEM;
            break;
        default:
            break;
    }
}

void JsonParser::parseString() {
    std::string parsedString = "";
    for( currentLocation; currentLocation < jsonLength; currentLocation++ ) {
        char quoteTest = jsonDocument[currentLocation];
        if( quoteTest != '\'' ) {
            parsedString.append( quoteTest );
        }
        else {
            break;
        }
    }
    tokenValue = parsedString;
}

void JsonParser::parseNum() {
    std::string parsedNum = "";
    for( currentLocation; currentLocation < jsonLength; currentLocation++ ) {
        char numTest = jsonDocument[i];
        if( numTest >= '0' && numTest <= '9' ) {
            parsedNum.append( numTest );
        }
        else if( numTest == '.' ) {
            // TODO: do double
            parsedNum.append( numTest );
        }
        else {
            break;
        }
    }
    tokenValue = parsedNum;
}

void JsonParser::removeSpaces() {
    for( currentLocation; currentLocation < jsonLength; currentLocation++ ) {
        char spaceTest = jsonDocument[currentLocation];
        if( spaceTest != ' ' && spaceTest != '\t' && spaceTest != '\n' ) {
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