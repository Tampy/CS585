// json_entity.cpp

#include "json_entity.h"
#include <iostream>
#include <stdexcept>

JsonEntity::JsonEntity() {
    type = OBJECT;
    entity = Map<JsonEntity>;
}

JsonEntity::JsonEntity( JsonEntity& otherEntity ) {
    entity.type = otherEntity.type();
    switch( type ) {
        case INT:
            entity.jsonNumber = otherEntity.asInt();
            break;
        case STRING:
            entity.jsonName = otherEntity.asString();
            break;
        case DOUBLE:
            entity.jsonDecimalNumber = otherEntity.asDouble(); 
            break;
        case ARRAY:
            entity.jsonArray = otherEntity.asArray();
            break;
        default:
            entity = otherEntity.asString();
            break;
    }
}

JsonEntity::~JsonEntity() {

}

JsonEntity& JsonEntity::operator = ( const JsonEntity &otherEntity ) {
    JsonEntity( otherEntity );
    return this;
}

JsonEntity& JsonEntity::operator = ( const int &jsonObject ) {
    entity.jsonNumber = jsonObject;
    entity.type = INT;
    return this;
}

JsonEntity& JsonEntity::operator = ( const std::string &jsonObject ) {
    entity.jsonString = jsonObject;
    entity.type = STRING;
    return this;
}

JsonEntity& JsonEntity::operator = ( const double &jsonObject ) {
    entity.jsonDecimalNumber = jsonObject;
    entity.type = DOUBLE;
    return this;
}

JsonEntity& JsonEntity::operator = ( const DynamicArray<JsonEntity> &jsonObject ) {
    entity.jsonArray = jsonObject;
    entity.type = ARRAY;
    return this;
}

JsonEntity& JsonEntity::operator = ( const Map<JsonEntity> &jsonObject ) {
    entity.jsonMap = jsonObject;
    entity.type = OBJECT;
    return this;
}

EntityTypes const JsonEntity::type() {
    return type;
}

int const JsonEntity::asInt() {
    if( isInt() ) {
        return std::stoi( entity );
    }
    throw std::invalid_argument;
}

const std::string& JsonEntity::asString() const {
    if( isString() ) {
        return std::to_string();
    }
    throw std::invalid_argument;
}

double const JsonEntity::asDouble() {
    if( isInt() ) {
        return std::stod( entity );
    }
    throw std::invalid_argument;
}

DynamicArray <JsonEntity>& const JsonEntity::asArray() const {
    if( isString() ) {
        return DynamicArray<JsonEntity>( entity );
    }
    throw std::invalid_argument;
}

bool const JsonEntity::isInt() {
    try {
        std::stoi( entity );
        return true;
    }
    catch ( std::invalid_argument e ) {
        return false;
    }
}

bool const JsonEntity::isString() {
    std::string appendTest = "";
    try {
        appendTest.append( entity );
    }
    catch ( std::exception e ) {
        return false;
    }
}

bool const JsonEntity::isDouble() {
    try {
        std::stod( entity );
        return true;
    }
    catch ( std::invalid_argument e ) {
        return false;
    }
}

bool const JsonEntity::isArray() {
    const std::type_info& arrayType = typeid( DynamicArray<JsonEntity> );
    const std::type_info& entityType = typeid( entity );
    if( arrayType == entityType ) {
        return true;
    }
    return false;
}

bool const JsonEntity::isObject() {
    const std::type_info& objectType = typeid( Map<JsonEntity> );
    const std::type_info& entityType = typeid( entity );
    if( objectType == entityType ) {
        return true;
    }
    return false;
}

const JsonEntity& JsonEntity::operator [] ( const std::string& key ) const {
    if( !isObject() ) {
        std::cout << "Invalid argument." << std::endl;
    }
    return entity[key];
}

const JsonEntity& JsonEntity::operator [] ( const int index ) const {
    if( !isArray() ) {
        std::cout << "Invalid argument." << std::endl;
    }
    return entity[index];
}

JsonEntity& JsonEntity::operator [] ( const std::string& key ) {
    if( !isObject() ) {
        std::cout << "Invalid argument." << std::endl;
    }
    return entity[key];
}