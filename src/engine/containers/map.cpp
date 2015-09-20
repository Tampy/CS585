// map.cpp

#include "map.h"

namespace StevensDev {
namespace sgdc {
template<typename T>
Map<T>::Map() {
    allocator = DefaultAllocator();
}

template<typename T>
Map<T>::Map( IAllocator* alloc ) {
    allocator = alloc;
}

template<typename T>
Map Map<T>::&operator = ( const &Map ) {
    
}

template<typename T>
T Map<T>::&operator [] ( const string& key ) {
    int hashValue = hash( key );
    return table.at( hashValue ).value;
}

template<typename T>
const T Map<T>::&operator [] ( const string &key ) {
    int hashValue = hash( key );
    return table.at( hashValue ).value;
}

template<typename T>
int Map<T>::hash( const string &key ) {
      // TODO: Use a better hash.
    int hashValue = 0;
    int i = 0;
    for ( i= 0; i < key.length(); i++ ) {
        hashValue += key[i];
    }
    hashValue = hashValue % table.getLength();
    return hashValue;
}

template<typename T>
bool Map<T>::has( const string &key ) {
    int hashValue = hash( key );
    if ( table.at( hashValue ) == nullptr ) {
        return false;
    }
    return true;

}

template<typename T>
const DynamicArray<string>& Map<T>::keys() const {
    int i = 0;
    DynamicArray<string> keyArray;
    for( i = 0; i < table.getLength; i++ ) {
        keyArray.push( table.at( i ).key );
    }
    return &keyArray;
}

template<typename T>
const DynamicArray<T>& Map<T>::values() const {
    int i = 0;
    DynamicArray<T> valueArray;
    for( i = 0; i < table.getLength(); i++ ) {
        keyArray.push( table.at( i ).value );
    }
    return &valueArray;
}

template<typename T>
T Map<T>::remove( const string& key ) {
    if( !has( key ) ) {
        return nullptr;
    }
    int hashValue = hash( key );
    T removedValue = table.at( hashValue ).value;
    table[hashValue] = nullptr;
    return removedValue;
}
}
}