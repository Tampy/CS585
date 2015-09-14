// dynamic_array.cpp

#include "dynamic_array.h"

template<typename T> class DynamicArray {
    DynamicArray( IAllocator* alloc ) {
        *arrayAlloc = alloc;
    }

    void push( const T& element ) {
        arrayAlloc.get(*T.size());
    }

    void pushFront( T element) {

    }

    T pop() {

    }

    T popFront() {

    }

    unsigned int const getLength() {

    }

    T const at( unsigned int index ) {

    }

    T operator [] ( int ) {

    }
    T const operator [] ( int ) {

    }

    T removeAt( unsigned int index ) {

    }

    T insertAt( unsigned int index ) {

    }
};