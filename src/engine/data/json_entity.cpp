// json_entity.cpp

#include "json_entity.h"
#include <stdexcept>

EntityTypes const JsonEntity::type() {
    if ( isInt() ) {
        return INT;
    }
    else if ( isString() ) {
        return STRING;
    }
    else if ( isDouble() ) {
        return DOUBLE;
    }
    else if ( isArray() ) {
        return ARRAY;
    }
    else {
        return OBJECT;
    }
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
    if( type() == OBJECT ) {
        return true;
    }
    return false;
}

JsonEntity& const JsonEntity::operator [] ( std::string& key ) const {

}

JsonEntity& const JsonEntity::operator [] ( int index ) const {
    
}