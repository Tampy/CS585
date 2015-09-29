// json_entity.h

#ifndef JSON_ENTITY_H
#define JSON_ENTITY_H

#include <containers/map.h>
#include <containers/dynamic_array.h>
#include <string>

namespace StevensDev {
namespace sgdd {
class JsonEntity {
  private:
    enum EntityTypes { INT, STRING, DOUBLE, ARRAY, OBJECT };
    struct Entity {
        EntityTypes type;
        union {
            int jsonNumber;
            std::string jsonString;
            double jsonDecimalNumber;
            sgdc::DynamicArray<JsonEntity> jsonArray;
            sgdc::Map<JsonEntity> jsonMap;
        };
    };
    Entity entity;
  public:
      // CONSTRUCTORS //
    JsonEntity();
      // default constructor
    JsonEntity( sgdc::Map<JsonEntity>& jsonObject );
      // constructor for overarching JSON object
    JsonEntity( JsonEntity& otherEntity );
      // copy constructor
    ~JsonEntity();
      // destructor
      // FREE OPERATORS //
    JsonEntity &operator = ( const JsonEntity &otherEntity );
      // assignment operator
    JsonEntity& operator = ( const int &jsonObject );
      // assignment operator so ints can become JsonEntities
    JsonEntity& operator = ( const std::string &jsonObject );
    JsonEntity& operator = ( const double &jsonObject );
    JsonEntity& operator = ( const sgdc::DynamicArray<JsonEntity> &jsonObject );
    JsonEntity& operator = ( const sgdc::Map<JsonEntity> &jsonObject );
      // ACCESSORS //
    JsonEntity::EntityTypes const type();
      // Enum detailing the type of data stored
    int const asInt();
    const std::string& asString() const;
    double const asDouble();
    const sgdc::DynamicArray <JsonEntity>&  asArray() const;
    const JsonEntity asJsonEntity() const;
    bool const isInt();
    bool const isString();
    bool const isDouble();
    bool const isArray();
    bool const isObject();
    const JsonEntity& operator [] ( const std::string& key ) const;
    const JsonEntity& operator [] ( const int index ) const;
    JsonEntity& operator [] ( const std::string& key );
};
}
}

#endif