// json_entity.cpp

#include "json_entity.h"
#include <iostream>
#include <stdexcept>

JsonEntity::JsonEntity() {
    type = OBJECT;
    entity = nullptr;
}

JsonEntity::JsonEntity( JsonEntity& otherEntity ) {
    type = otherEntity.type();
    switch( type ) {
        case INT:
            entity = otherEntity.asInt();
            break;
        case STRING:
            entity = otherEntity.asString();
            break;
        case DOUBLE:
            entity = otherEntity.asDouble(); 
            break;
        case ARRAY:
            entity = otherEntity.asArray();
            break;
        default:
            entity = otherEntity.asString();
            break;
    }
}

JsonEntity &operator = ( const JsonEntity &otherEntity ) {
    JsonEntity( otherEntity );
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

std::string& const JsonEntity::asString() const {
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

JsonEntity& const JsonEntity::operator [] ( std::string& key ) const {
    if( !isObject() ) {
        std::cout << "Invalid argument." << std::endl;
    }
    return entity[key];
}

JsonEntity& const JsonEntity::operator [] ( int index ) const {
    if( !isArray() ) {
        std::cout << "Invalid argument." << std::endl;
    }
    return entity[index];
}

JsonEntity& JsonEntity::operator [] ( std::string& key ) {
    if( !isObject() ) {
        std::cout << "Invalid argument." << std::endl;
    }
    return entity[key];
}