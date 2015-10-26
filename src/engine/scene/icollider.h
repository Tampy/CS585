// icollider.h

#ifndef ICOLLIDER_H
#define ICOLLIDER_H

#include "rectangle_bounds.h"

namespace StevensDev {
namespace sgds {
class ICollider {
  private:
    RectangleBounds bounds;
    unsigned short flags;
  public:
    const RectangleBounds& bounds() const;
    unsigned short flags() const;
    void setFlags( unsigned short flags );
    bool canCollide( unsigned short flags ) const;
    bool doesCollide( const RectangleBounds& candidate );
};
}
}

#endif