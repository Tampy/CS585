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
    IAllocator<JsonEntity> jsonAllocator;
    JsonEntity helperParser( const std::string& rawJson );
  public:
    JsonEntity* fromString( const std::string& rawJson, IAllocator* allocator = 0 );
};
}
}

#endif