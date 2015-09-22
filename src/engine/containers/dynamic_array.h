// dynamic_array.h

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <exception>
#include <default_allocator.h>
#include <iallocator.h>
#include <iostream>
#include <stdexcept>

namespace StevensDev {
namespace sgdc {
template<typename T> class DynamicArray {
  private:
  struct node {
        std::string key;
        T value;
    };
    sgdm::DefaultAllocator<T> arrayAlloc;
    T* array;
    int length;
    int maxSize;
      // MUTATORS //
    void shiftLeft( int startingIndex ) {
        int i = (startingIndex == 0) ? 1 : 0;   // Used to prevent out of bounds
        for( i; i < length; i++) {
            array[i - 1] = array[i];
        }
        arrayAlloc.destruct( &array[i - 1] );
    }
      // move all array items one over left
    void shiftRight( int startingIndex ) {
        if( length >= maxSize ) {
            reallocate( length + 10 );
        }
        int i;
        for( i = length - 1; i > startingIndex; i-- ) {
            array[i] = array[i - 1];
        }
        // arrayAlloc.destruct( &array[0], sizeof( T ) * maxSize );
    }
      // move all array items one over right
    void reallocate( int numElements ) {
        T* newArray = arrayAlloc.get( numElements );
        int i;
        for( i = 0; i < length; i++ ) {
            arrayAlloc.construct( &newArray[i], T() );
            newArray[i] = array[i];
            arrayAlloc.destruct( &array[i] );
            
        }
        arrayAlloc.release( array, sizeof( T ) * maxSize );
        array = newArray;
        maxSize = sizeof(T) * numElements;
    }
      // add more spaces for elements
  public:
      // CONSTRUCTORS //
    DynamicArray() {
        maxSize = 10;
        array = arrayAlloc.get( maxSize );
        int i;
        for( i = 0; i < maxSize; i++ ) {
            arrayAlloc.construct( &array[i], T() );
            array[i] = T();
        }
        length = 0;
    }
      // default constructor
    DynamicArray( sgdm::IAllocator<T>* alloc ) {
        *arrayAlloc = alloc;
        array = arrayAlloc.get( maxSize );
        int i;
        for( i = 0; i < maxSize; i++ ) {
            arrayAlloc.construct( &array[i], T() );
        }
        length = 0;
    }
      // pointer to an allocator for use with memory
    DynamicArray ( int startingMaxSize ) {
        maxSize = startingMaxSize;
        array = arrayAlloc.get( maxSize );
        int i;
        for( i = 0; i < maxSize; i++ ) {
            arrayAlloc.construct( &array[i], T() );
        }
        length = 0;
    }
      //  initializes with a certain maximum size
    DynamicArray( DynamicArray<T> &otherArray ) {
        maxSize = otherArray.getLength();
        array = arrayAlloc.get( 10 );
        int i = 0;
        for( i = 0; i < maxSize; i++ ) {
            arrayAlloc.construct( &array[i], T() );
            push( array[i] );
        }
        length = otherArray.getLength();
    }
      // copy constructor
    ~DynamicArray() {
        int i;
        for( i = 0; i < maxSize; i++ ) {
            arrayAlloc.destruct( &array[i] );
        }
        // arrayAlloc.release( array, sizeof( T ) * maxSize );
    }
      // destructor
      // FREE OPERATORS //
    DynamicArray &operator = ( const DynamicArray &otherArray) {
        maxSize = otherArray.getMaxSize();
        array = arrayAlloc.get( maxSize );
        int i = 0;
        for( i = 0; i < maxSize; i++ ) {
            arrayAlloc.construct( &array[i], otherArray[i] );
        }
        length = otherArray.getLength();
    }
      // assignment operator
      // MUTATORS //
    void push( const T& element ) {
        if( length >= maxSize ) {
            reallocate( length + 10 );
        }
        array[length] = element;
        length++;
    }
      // adds element to end of collection, grow
    void pushFront( T element ) {
        if( length >= maxSize ) {
            reallocate( length + 10 );
        }
        shiftRight( 0 );
        array[0] = element;
        length++;
    }
      // pushes to the front of the collection, grow, shift
    T pop() {
        T poppedElement = array[length - 1];
        arrayAlloc.destruct( &array[length - 1] );
        length--;
        return poppedElement;
    }
      // removes and retrieves the last element, shifts
    T popFront() {
        T poppedElement = array[0];
        shiftLeft( 1 );
        length--;
        return poppedElement;
    }
      // removes and retrieves the first element, shifts
    T removeAt( unsigned int index ) {
        T removedElement = array[index];
        shiftLeft( index + 1 );
        length--;
        return removedElement;
    }
      // removes, throws if invalid, shifts
    void insertAt( unsigned int index, const T& element ) {
        shiftRight( index );
        array[index] = element;
        length++;
    }
      // can grow, shifts
      // ACCESSORS //
    unsigned int getLength() const { return length; }
      // number of elements contained
    unsigned int getMaxSize() const { return maxSize; }
      // number of elements currently allowed to be added
    T at( unsigned int index ) const {
        if( index >= maxSize ) {
            throw std::out_of_range("index larger than length");
        }
        return array[index];
    }
      // retrieves an element at a location, throws if out of bounds
    T& operator [] ( int index ) { return array[index]; }
      // sets an element, undefined behavior if out of bounds
    T& operator [] ( int index ) const { return array[index]; }
      // retrieves an element, undefined behavior if out of bounds
};
}
}

#endif
