// counting_allocator.h

#ifndef COUNTING_ALLOCATOR_H
#define COUNTING_ALLOCATOR_H

#include "default_allocator.h"

namespace sgdm {
template<class T>
class CountingAllocator<T>;
}

template<class T>
class CountingAllocator : public DefaultAllocator<T> {
  private:
    int allocCount;
    int releaseCount;
    static int totalAlloc;
    static int totalRelease;
  public:
      // CONSTRUCTORS //
    CountingAllocator();
      // default constructors
    CountingAllocator( CountingAllocator alloc );
      // copy constructor
    ~CountingAllocator();
      // destructor
      // FREE OPERATIONS //
    CountingAllocator &operator = ( const &CountingAllocator );
      // assignment operator
      // ACCESSORS //
    int const getAllocationCount();
      // number of allocations that occurred
    int const getReleaseCount();
      // number of releases that occurred
    int const getOutstandingCount();
      // allocations - releases
    static int getTotalAllocationCount();
      // allocations across instances
    static int getTotalReleaseCount();
      // releases across instances
    static int getOutstandingCount();
      // allocations - releases across instances
};

#endif