// default_allocator.h

#ifndef DEFAULT_ALLOCATOR_H
#define DEFAULT_ALLOCATOR_H

#include "iallocator.h"

namespace sgdm {
template<class T>
class DefaultAllocator;
}

template<class T>
class DefaultAllocator : public IAllocator {
  public:
    DefaultAllocator();
    T* get( int count );
    void release( T*, int count );
};

#endif
