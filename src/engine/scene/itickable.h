// itickable.h

#ifndef ITICKABLE_H
#define ITICKABLE_H

namespace StevensDev {
namespace sgds {
class ITickable {
  public:
    virtual void preTick() = 0;
    virtual void tick( float dtS ) = 0;
    virtual void postTick() = 0;
};
}
}

#endif