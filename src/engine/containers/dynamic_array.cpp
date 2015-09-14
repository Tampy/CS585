// dynamic_array.cpp

#include "dynamic_array.h"
#include <default_allocator.h>

template<typename T> class DynamicArray {
    DynamicArray::DynamicArray() {
        arrayAlloc = DefaultAllocator();
    }

    DynamicArray::DynamicArray( IAllocator* alloc ) {
        *arrayAlloc = alloc;
    }

    DynamicArray::DynamicArray( DynamicArray array ) {
        arrayAlloc = DefaultAllocator();
        int i = 0;
        for( i = 0; i < array.getLength(); i++ ) {
            push( array[i] );
        }
    }

    DynamicArray DynamicArray::&operator = ( const DynamicArray &array ) {
        arrayAlloc = DefaultAllocator();
        int i = 0;
        for( i = 0; i < &array.getLength(); i++ ) {
            push( &array[i] );
        }
        delete(array);
    }

    void DynamicArray::push( const T& element ) {
        arrayAlloc.get(*T.size());
    }

    void DynamicArray::pushFront( T element) {

    }

    T DynamicArray::pop() {

    }

    T DynamicArray::popFront() {

    }

    unsigned int const DynamicArray::getLength() {

    }

    T const DynamicArray::at( unsigned int index ) {

    }

    T DynamicArray::operator [] ( int ) {

    }
    T const DynamicArray::operator [] ( int ) {

    }

    T DynamicArray::removeAt( unsigned int index ) {

    }

    T DynamicArray::insertAt( unsigned int index ) {

    }
};