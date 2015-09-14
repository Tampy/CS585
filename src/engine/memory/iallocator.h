// iallocator.h

#ifndef IALLOCATOR_H
#define IALLOCATOR_H

namespace sgdm {
template<class T>
class IAllocator;
}

template<class T>
class IAllocator {
  public:
    virtual T* get( int count );
    virtual void release( T*, int count );
};
#endif