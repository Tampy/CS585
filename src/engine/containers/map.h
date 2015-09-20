// map.h

#ifndef MAP_H
#define MAP_H

#include <dynamic_array.h>
#include <iallocator.h>
#include <string>

namespace StevensDev {
namespace sgdc {
template<typename T> class Map {
  private:
    namespace {
    struct node {
        string key;
        T value;
    };
    DynamicArray<node> table;
    IAllocator allocator;
    }
      // MEMBER FUNCTIONS //
    int hash( const string &key );
  public:
     // CONSTRUCTORS //
    Map();
      // default constructor
    Map( IAllocator* alloc );
      // constructor for allocator
      // FREE OPERATORS //
    Map &operator = ( const &Map );
      // assignment operator
    T &operator [] ( const string& key );
      // Mutable
    const T &operator [] ( const string &key );
      // No mutation
      // ACCESSORS //
    bool has( const string &key );
      // Determines if a key exists in the map
    const DynamicArray<string>& keys() const;
      // Retrives all key (immutable)
    const DynamicArray<T>& values() const;
      // Retrieves all values (immutable)
      // MUTATORS //
    T remove( const string& key );
      // Removes a key-value
};
}
}

#endif