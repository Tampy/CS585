// counting_allocator.h

#ifndef COUNTING_ALLOCATOR_H
#define COUNTING_ALLOCATOR_H

#include "default_allocator.h"

namespace StevensDev {
namespace sgdm {
template<typename T>
class CountingAllocator : public DefaultAllocator<T> {
  private:
    int allocCount;
    int releaseCount;
    static int totalAlloc;
    static int totalRelease;
  public:
      // CONSTRUCTORS //
    CountingAllocator() {
        allocCount = 0;
        releaseCount = 0;
    }
      // default constructor
    CountingAllocator( CountingAllocator& alloc ) {
      allocCount = alloc.getAllocationCount();
      releaseCount = alloc.getReleaseCount();
    }
      // copy constructor
      // ACCESSORS //
    int const getAllocationCount() { return allocCount; }
      // number of allocations that occurred
    int const getReleaseCount() { return releaseCount; }
      // number of releases that occurred
    int const getOutstandingCount() { return allocCount - releaseCount; }
      // allocations - releases
    static int getTotalAllocationCount() { return totalAlloc; }
      // allocations across instances
    static int getTotalReleaseCount() { return totalRelease; }
      // releases across instances
    static int getTotalOutstandingCount() { return totalAlloc - totalRelease; }
      // allocations - releases across instances
    T* get( int count ) {
        allocCount++;
        totalAlloc++;
        DefaultAllocator<T>::get( count );
    }
      // adjustment to default get in order to count
    void release( T* pointer, int count ) {
        releaseCount++;
        totalRelease++;
        DefaultAllocator<T>::release( pointer, count );
    }
      // adjustment to default release in order to count
};
}
}

#endif
