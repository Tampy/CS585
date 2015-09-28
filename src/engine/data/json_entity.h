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
        EntityTypes entityType;
        union EntityUnion {
            int jsonNumber;
            std::string jsonName;
            double jsonDecimalNumber;
            DynamicArray<JsonEntity> jsonArray;
            Object jsonItem;
            Map<JsonEntity> jsonMap;
        }
    };
    Entity entity;
  public:
      // CONSTRUCTORS //
    JsonEntity();
      // default constructor
    JsonEntity( JsonEntity& otherEntity );
      // copy constructor
    ~JsonEntity();
      // destructor
      // FREE OPERATORS //
    JsonEntity &operator = ( const JsonEntity &otherEntity );
      // assignment operator
      // ACCESSORS //
    JsonEntity::EntityTypes const type();
      // Enum detailing the type of data stored
    int const asInt();
    std::string& const asString() const;
    double const asDouble();
    DynamicArray <JsonEntity>& const asArray() const;
    JsonEntity const asJsonEntity() const;
    bool const isInt();
    bool const isString();
    bool const isDouble();
    bool const isArray();
    bool const isObject();
    JsonEntity& const operator [] ( std::string& key ) const;
    JsonEntity& const operator [] ( int index ) const;
    JsonEntity& operator [] ( std::string& key );
};
}
}

#endif