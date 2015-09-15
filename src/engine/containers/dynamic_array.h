// dynamic_array.h

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iallocator.h>

namespace StevensDev {
namespace sgdc {
template<typename T> class DynamicArray {
  private:
    IAllocator<T> arrayAlloc;
    T* array;
    int length;
    int maxSize;
      // MUTATORS //
    void shiftLeft( int startingIndex );
      // move all array items one over left
    void shiftRight( int startingIndex );
      // move all array items one over right
    void reallocate( int numElements );
      // add more spaces for elements
  public:
      // CONSTRUCTORS //
    DynamicArray();
      // default constructor
    DynamicArray( IAllocator<T>* alloc );
      // pointer to an allocator for use with memory
    DynamicArray( DynamicArray<T> &alloc );
      // copy constructor
    ~DynamicArray();
      // desturctor
      // FREE OPERATORS //
    DynamicArray &operator = ( const DynamicArray &alloc);
      // assignment operator
      // MUTATORS //
    void push( const T& element );
      // adds element to end of collection, grow
    void pushFront( T element);
      // pushes to the front of the collection, grow, shift
    T pop();
      // removes and retrieves the last element, shifts
    T popFront();
      // removes and retrieves the first element, shifts
    T removeAt( unsigned int index );
      // removes, throws if invalid, shifts
    void insertAt( unsigned int index );
      // can grow, shifts
      // ACCESSORS //
    unsigned int const getLength();
      // number of elements contained
    T const at( unsigned int index );
      // retrieves an element at a location, throws if out of bounds
    T operator [] ( int index );
      // sets an element, undefined behavior if out of bounds
    T operator [] ( int index ) const;
      // retrieves an element, undefined behavior if out of bounds
};
}
}

#endif
