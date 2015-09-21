// iallocator.h

#ifndef IALLOCATOR_H
#define IALLOCATOR_H

#include <utility>

namespace StevensDev {
namespace sgdm {
template<typename T>
class IAllocator {
  public:
    virtual T* get( int count ) = 0;
    virtual void release( T*, int count ) = 0;
    void construct( T* pointer, const T& value) {
        new ( pointer ) T( value );
    }
    void construct( T* pointer, const T&& value ) {
        new ( pointer ) T( std::move( value ) );
    }
    void destruct( T* pointer ) {
        pointer->~T( );
    }
};
}
}

#endif
