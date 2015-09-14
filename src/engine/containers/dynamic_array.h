// dynamic_array.h

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iallocator.h>

namespace sgdc {
template<typename T> class DynamicArray;
}

template<typename T> class DynamicArray {
  private:
    IAllocator<T> arrayAlloc;
  public:
    DynamicArray( IAllocator<T>* alloc );
      // pointer to an allocator for use with memory
    void push( const T& element );
      // adds element to end of collection, grow
    void pushFront( T element);
      // pushes to the front of the collection, grow, shift
    T pop();
      // removes and retrieves the last element, shifts
    T popFront();
      // removes and retrieves the first element, shifts
    unsigned int const getLength();
      // number of elements contained
    T const at( unsigned int index );
      // retrieves an element at a location, throws if out of bounds
    T operator [] ( int index );
      // sets an element, undefined behavior if out of bounds
    T const operator [] ( int index );
      // retrieves an element, undefined behavior if out of bounds
    T removeAt( unsigned int index );
      // removes, throws if invalid, shifts
    T insertAt( unsigned int index );
      // can grow, shifts
};

#endif