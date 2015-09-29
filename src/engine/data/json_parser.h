// json_parser.h

#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include "json_entity.h"
#include <memory/default_allocator.h>
#include <memory/iallocator.h>
#include <string>

namespace StevensDev {
namespace sgdd {
struct JsonParser {
  private:
    enum Token {
        STRING,
        INT,
        DOUBLE,
        ARRAY_START,
        ARRAY_END,
        VALUE_START,
        NEW_ITEM,
        END
    };
    static sgdm::DefaultAllocator<JsonEntity> jsonAllocator;
    static sgdc::Map<JsonEntity> map;
    static std::string jsonDocument;
    static std::string tokenValue;
    static unsigned int currentLocation;
    static unsigned int jsonLength;

    static Token parser() {
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
                returnToken = VALUE_START;
                break;
            case ',':
                returnToken = NEW_ITEM;
                break;
            case '}':
                returnToken = END;
                break;
            default:
                break;
        }
    }

    static void parseString() {
        std::string parsedString = "";
        for( currentLocation; currentLocation < jsonLength; currentLocation++ ) {
            char quoteTest = jsonDocument[currentLocation];
            if( quoteTest != '\'' ) {
                parsedString += quoteTest;
            }
            else {
                break;
            }
        }
        tokenValue = parsedString;
    }

    static void parseNum() {
        std::string parsedNum = "";
        for( currentLocation; currentLocation < jsonLength; currentLocation++ ) {
            char numTest = jsonDocument[currentLocation];
            if( numTest >= '0' && numTest <= '9' ) {
                parsedNum += numTest ;
            }
            else if( numTest == '.' ) {
                // TODO: do double
                parsedNum += numTest;
            }
            else {
                break;
            }
        }
        tokenValue = parsedNum;
    }

    static void removeSpaces() {
        for( currentLocation; currentLocation < jsonLength; currentLocation++ ) {
            char spaceTest = jsonDocument[currentLocation];
            if( spaceTest != ' ' && spaceTest != '\t' && spaceTest != '\n' ) {
                break;
            }
        }
    }

    static void parseArray() {

    }
  public:
    static JsonEntity* fromString( const std::string& rawJson, 
                                        sgdm::IAllocator<JsonEntity>* allocator = 0 ) {
        /*if( !allocator ) {
            jsonAllocator = sgdm::DefaultAllocator<JsonEntity>();
        }
        else {
            jsonAllocator = allocator;
        }*/
        currentLocation = 0;
        jsonLength = rawJson.length();
        jsonDocument = rawJson;
        Token token;
        std::string name;
        while( currentLocation < jsonLength ) {
            token = parser();
            if( token == VALUE_START ) {
                name = tokenValue;
                tokenValue.clear();
            }
            else if( token == NEW_ITEM ) {
                map[name] = tokenValue;
            }
            else if( token == END ) {
                map[name] = tokenValue;
                int i;
                JsonEntity* entities = jsonAllocator.get( map.getLength() );
                for( i = 0; i < map.getLength(); i++ ) {
                    jsonAllocator.construct( &entities[i], JsonEntity() );
                    entities[i] = tokenValue;
                }
                return &entity;
            }
        }
        return nullptr;
    }
};
}
}

#endif