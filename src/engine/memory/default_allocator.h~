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
      // CONSTRUCTORS //
    DefaultAllocator();
      // default constructor
    DefaultAllocator( DefaultAllocator alloc );
      // copy constructor
    ~DefaultAllocator();
      // destructor
      // FREE OPERATIONS //
    DefaultAllocator operator = ( const DefaultAllocator );
     // MEMBER FUNCTIONS //
    T* get( int count );
    void release( T*, int count );
};

#endif
