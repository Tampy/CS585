// icollider.h

#ifndef ICOLLIDER_H
#define ICOLLIDER_H

#include "rectangle_bounds.h"

namespace StevensDev {
namespace sgds {
class ICollider {
  private:
    RectangleBounds rectBounds;
    unsigned short colliderFlags;
  public:
      // CONSTRUCTORS //
    ICollider();
      // default constructor
    ICollider( ICollider& otherCollider );
      // copy constructor
    ~ICollider();
      // destructor
      // FREE OPERATORS //
    ICollider &operator =( const ICollider &otherCollider );
      // assignment operator
      // ACCESSORS //
    RectangleBounds& bounds();
    unsigned short flags() const;
    bool canCollide( unsigned short flags ) const;
    bool doesCollide( const RectangleBounds& candidate );
      // MUTATORS //
    void setFlags( unsigned short flags );
};
}
}

#endif