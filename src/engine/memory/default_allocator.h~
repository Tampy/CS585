// default_allocator.h

#ifndef DEFAULT_ALLOCATOR_H
#define DEFAULT_ALLOCATOR_H

#include <assert.h>
#include "iallocator.h"

namespace StevensDev{
namespace sgdm {
template<typename T>
class DefaultAllocator : public IAllocator<T> {
  public:
      // CONSTRUCTORS //
    DefaultAllocator() { }
      // default constructor
    ~DefaultAllocator() { }
      // destructor
     // MEMBER FUNCTIONS //
    T* get( int count ) {
        assert( count != 0 );

        return reinterpret_cast<T*>(::operator new(count * sizeof (T)));
    }
    void release( T* pointer, int count ) {
        delete(pointer);
    }
};
}
}

#endif
