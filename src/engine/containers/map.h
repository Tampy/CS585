// map.h

#ifndef MAP_H
#define MAP_H

#include <exception>
#include <containers/dynamic_array.h>
#include <memory/iallocator.h>
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
        int hashValue = 0;
        int i = 0;
        for ( i= 0; i < key.length(); i++ ) {
            hashValue += key[i];
        }
        hashValue = hashValue % table.getMaxSize();
        return hashValue;
    }
      // creates a hash value from a key
  public:
     // CONSTRUCTORS //
    Map() {
        table = DynamicArray<node>( 127 );
        allocator = sgdm::DefaultAllocator<T>();
    }
      // default constructor
    Map( sgdm::IAllocator<T>* alloc ) {
        table = DynamicArray<node>( 127 );
        allocator = alloc;
    }
      // constructor for allocator
    Map( Map<T>& otherMap ) {
        table = DynamicArray<node>( 127 );
        allocator = sgdm::DefaultAllocator<T>();
        DynamicArray<std::string> keyArray = otherMap.keys();
        int i = 0;
        for( i = 0; i < keyArray.getLength(); i++ ) {
            table[keyArray[i]] = otherMap[keyArray[i]];
        }
    }
      // copy constructor
    ~Map() { }
      // destructor
      // FREE OPERATORS //
    Map &operator = ( const Map<T> &otherMap) {
        DynamicArray<std::string> keyArray = otherMap.keys();
        int i = 0;
        for( i = 0; i < keyArray.getLength(); i++ ) {
            table[keyArray[i]] = otherMap[keyArray[i]];
        }
        return *this;
    }
      // assignment operator
    T &operator [] ( const std::string& key ) {
        int hashValue = hash( key );
        while ( table[hashValue].key != "" ) {
            hashValue = (hashValue + 1) % table.getMaxSize();
        }
        node newNode;
        newNode.key = key;
        table.insertAt( hashValue, newNode );
        return table[hashValue].value;
    }
      // Mutable
    const T &operator [] ( const std::string &key ) const {
        int hashValue = hash( key );
        int lookupChecks = 0;
        while ( table[hashValue].key != key ) {
            hashValue = ( hashValue + 1 ) % table.getMaxSize();
            lookupChecks++;
            if( lookupChecks > key.length() ) {
                std::cout << "Key does not exist." << std::endl;
                return 0;
            }
        }
        std::cout << table[hashValue].value << std::endl;
        return table[hashValue].value;
    }
      // No mutation
      // ACCESSORS //
    const T &get( const std::string key )
    {
        int hashValue = hash( key );
        int lookupChecks = 0;
        while ( table[hashValue].key != key ) {
            hashValue = ( hashValue + 1 ) % table.getMaxSize();
            lookupChecks++;
            if( lookupChecks > key.length() ) {
                std::cout << "Key does not exist." << std::endl;
                throw std::runtime_error( "Key does not exist." );
            }
        }
        return table[hashValue].value;
    }
      // gets value based on key
    bool has( const std::string &key ) {
        int hashValue = hash( key );
        int lookupChecks = 0;
        try {
            while ( table[hashValue].key != key ) {
                hashValue = ( hashValue + 1 ) % table.getMaxSize();
                lookupChecks++;
                if( lookupChecks > key.length() ) {
                    return false;
                }
            }
            return true;
        }
        catch( std::exception& e ) {
            return false;
        }
    }
      // Determines if a key exists in the map
    DynamicArray<std::string> keys() const {
        int i = 0;
        DynamicArray<std::string> keyArray;;
        for( i = 0; i < table.getMaxSize(); i++ ) {
            if ( table[i].key != "" ) {
                keyArray.push( table[i].key );
            }
        }
        return keyArray;
    }
      // Retrives all key (immutable)
    DynamicArray<T> values() const {
        int i = 0;
        DynamicArray<T> valueArray;
        for( i = 0; i < table.getMaxSize(); i++ ) {
            if ( table[i].key != "" ) {
                valueArray.push( table[i].value );
            }
        }
        return valueArray;
    }
      // Retrieves all values (immutable)
      // MUTATORS //
    T remove( const std::string& key ) {
        if( !has( key ) ) {
            std::cout << "Key does not exist." << std::endl;
            return 0;
        }
        int hashValue = hash( key );
        T removedValue = table[hashValue].value;
        table[hashValue] = node();
        return removedValue;
    }
      // Removes a key-value
    unsigned int getLength() {
        return keys().getLength();
    }
};
}
}

#endif
