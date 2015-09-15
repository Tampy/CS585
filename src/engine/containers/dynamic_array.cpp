// dynamic_array.cpp

#include "dynamic_array.h"
#include <default_allocator.h>
#include <iostream>

template<typename T> class DynamicArray {class
    DynamicArray::DynamicArray<T>() {
        arrayAlloc = DefaultAllocator();
        maxSize = 10;
        array = arrayAlloc.get(sizeof(T) * maxSize);
        length = 0;
    }

    DynamicArray::DynamicArray( IAllocator* alloc ) {
        *arrayAlloc = alloc;
        array = arrayAlloc.get(sizeof(T) * maxSize);
        length = 0;
    }

    DynamicArray::DynamicArray( DynamicArray otherArray ) {
        arrayAlloc = DefaultAllocator();
        maxSize = otherArray.getLength();
        array = arrayAlloc.get(sizeof(T) * 10);
        int i = 0;
        for( i = 0; i < maxSize; i++ ) {
            push( array[i] );
        }
        length = otherArray.getLength();
    }

    DynamicArray DynamicArray::&operator = ( const DynamicArray &otherArray ) {
        arrayAlloc = DefaultAllocator();
        maxSize = &otherArray.getLength();
        int i = 0;
        for( i = 0; i < maxSize; i++ ) {
            push( array[i] );
        }
        length = &otherArray.getLength();
        delete( array );
    }

    void DynamicArray::push( const T& element ) {
        if( length >= maxSize ) {
            reallocate( length + 10 );
        }
        array[length] = &element;
        length++;
    }

    void DynamicArray::pushFront( T element) {
        if( length >= maxSize ) {
            reallocate( length + 10 );
        }
        shiftRight( 0 );
        array[0] = &element;
        length++;
    }

    T DynamicArray::pop() {
        T poppedElement = array[length];
        array[length - 1] = nullptr;
        length--;
        return poppedElement;
    }

    T DynamicArray::popFront() {
        T poppedElement = array[0];
        shiftLeft( 1 );
        length--;
        return poppedElement;
    }

    unsigned int const DynamicArray::getLength() {
        return length;
    }

    T const DynamicArray::at( unsigned int index ) {
        try {
            if( index >= length ) {
                throw;
            }
            return array[index];
        }
        catch (Exception e) {
            cout << "Out of bounds exception." << endl;
            return nullptr;
        }
    }

    T DynamicArray::operator [] ( int index ) {
        return array[index];

    }
    T const DynamicArray::operator [] ( int index ) {
        return array[index];
    }

    T DynamicArray::removeAt( unsigned int index ) {
        T removedElement = array[index];
        shiftLeft( index + 1 );
        length--;
        return removedElement;
    }

    void DynamicArray::insertAt( unsigned int index, const T &element ) {
        shiftRight( index );
        array[index] = &element;
        length++;
    }
    
    void DynamicArray::shiftLeft( int startingIndex ) {
        int i = (startingIndex == 0) ? 1 : 0;   // Used to prevent out of bounds
        for( i; i < length; i++) {
            array[i - 1] = array[i];
        }
        array[i] = nullptr;
    }
    
    void DynamicArray::shiftRight( int startingIndex ) {
        if( length >= maxSize ) {
            reallocate( length + 10 );
        }
        int i;
        for( i = length - 1; i > startingIndex; i-- ) {
            array[i] = array[i - 1];
        }
        array[i] = nullptr;
    }
    
    void DynamicArray::reallocate( int size ) {
        T* newArray = arrayAlloc.get( sizeof(T) * size );
        int i;
        for( i = 0; i < length; i++ ) {
            newArray[i] = array[i];
        }
        arrayAlloc.release( array, sizeof( T ) * maxSize );
        array = newArray;
    }
}
