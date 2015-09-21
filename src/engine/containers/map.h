// map.h

#ifndef MAP_H
#define MAP_H

#include <dynamic_array.h>
#include <exception>
#include <iallocator.h>
#include <string>

namespace StevensDev {
namespace sgdc {
template<typename T> class Map {
  private:
    struct node {
        std::string key;
        T value;
    };
    DynamicArray<node> table;
    sgdm::DefaultAllocator<T> allocator;
      // MEMBER FUNCTIONS //
    int hash( const std::string &key ) {
          // TODO: Use a better hash.
        int hashValue = 0;
        int i = 0;
        for ( i= 0; i < key.length(); i++ ) {
            hashValue += key[i];
        }
        hashValue = hashValue % table.getLength();
        return hashValue;
    }
  public:
     // CONSTRUCTORS //
    Map() {
        allocator = sgdm::DefaultAllocator<T>();
    }
      // default constructor
    Map( sgdm::IAllocator<T>* alloc ) {
        *allocator = alloc;
    }
      // constructor for allocator
      // FREE OPERATORS //
    Map &operator = ( const Map<T> &otherMap);
      // assignment operator
    T &operator [] ( const std::string& key ) {
        int hashValue = hash( key );
        if( !has( key ) ) {
            node newNode;
            newNode.key = key;
            table[hashValue] = newNode;
        }
        return table[hashValue].value;
    }
      // Mutable
    T &operator [] ( const std::string &key ) const {
        int hashValue = hash( key );
        if( !has( key ) ) {
            node newNode;
            newNode.key = key;
            table[hashValue] = newNode;
        }
        return table[hashValue].value;
    }
      // No mutation
      // ACCESSORS //
    bool has( const std::string &key ) {
        int hashValue = hash( key );
        try {
            table.at( hashValue );
            return true;
        }
        catch( std::exception& e ) {
            return false;
        }
    }
          // Determines if a key exists in the map
    const DynamicArray<std::string>& keys() const {
        int i = 0;
        DynamicArray<std::string> keyArray;
        for( i = 0; i < table.getLength; i++ ) {
            keyArray.push( table.at( i ).key );
        }
        return &keyArray;
    }
      // Retrives all key (immutable)
    const DynamicArray<T>& values() const {
        int i = 0;
        DynamicArray<T> valueArray;
        for( i = 0; i < table.getLength(); i++ ) {
            valueArray.push( table.at( i ).value );
        }
        return &valueArray;
    }
      // Retrieves all values (immutable)
      // MUTATORS //
    T remove( const std::string& key ) {
        if( !has( key ) ) {
            return nullptr;
        }
        int hashValue = hash( key );
        T removedValue = table.at( hashValue ).value;
        table[hashValue] = nullptr;
        return removedValue;
    }
      // Removes a key-value
};
}
}

#endif
