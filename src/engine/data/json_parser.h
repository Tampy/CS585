// json_parser.h

#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include "json_entity.h"
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
        NEW_ITEM
    }
    IAllocator<JsonEntity> jsonAllocator;
    std::string tokenValue;
    unsigned int currentLocation;
    unsigned int jsonLength;
    Token parser( const std::string& rawJson );
  public:
    JsonEntity* fromString( const std::string& rawJson, IAllocator* allocator = 0 );
};
}
}

#endif