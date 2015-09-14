// counting_allocator.cpp

#include "counting_allocator.h"

int const CountingAllocator::getAllocationCount() {
    return allocCount;
}
int const CountingAllocator::getReleaseCount() {
    return releaseCount;
}
int const CountingAllocator::getOutstandingCount() {
    return allocCount - releaseCount;
}
static int CountingAllocator::getTotalAllocationCount() {
    return totalAlloc;
}
static int CountingAllocator::getTotalReleaseCount() {
    return totalRelease;
}
static int CountingAllocator::getOutstandingCount() {
    return totalAlloc - totalRelease;
}

T* CountingAllocator::get( int count ) {
    allocCount++;
    totalAlloc++;
    DefaultAllocator::get( count );
}

void CountingAllocator::release( T* pointer, int count ) {
    releaseCount++;
    totalRelease++;
    DefaultAllocator::release( pointer, count );
}