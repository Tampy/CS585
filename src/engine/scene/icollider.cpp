// icollider.cpp

#include "icollider.h"

namespace StevensDev {
namespace sgds {

ICollider::ICollider() { }

ICollider::ICollider( ICollider& otherCollider ) {
    rectBounds = otherCollider.bounds();
    colliderFlags = otherCollider.flags();
}

ICollider::~ICollider() {
    rectBounds.~RectangleBounds();
}

ICollider& ICollider::operator =( const ICollider& otherCollider ) {
    rectBounds = otherCollider.rectBounds;
    colliderFlags = otherCollider.colliderFlags;
}

const RectangleBounds& ICollider::bounds() const {
    return rectBounds;
}

unsigned short ICollider::flags() const {
    return colliderFlags;
}

void ICollider::setFlags( unsigned short flags ) {
    colliderFlags = flags;
}

bool ICollider::canCollide( unsigned short flags ) const {
    if( colliderFlags != flags ) {
        return false;
    }
    return true;
}

bool ICollider::doesCollide( const RectangleBounds& candidate ) {
    return rectBounds.doesCollide( candidate );
}

}
}