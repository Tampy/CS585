// icollider.cpp

namespace StevensDev {
namespace sgds {

const RectangleBounds& ICollider::bounds() const {
    return bounds;
}

unsigned short ICollider::flags() const {
    return flags;
}

void ICollider::setFlags( unsigned short flags ) {
    this.flags = flags;
}

bool ICollider::canCollide( unsigned short flags ) const {
    if( this.flags != flags ) {
        return false;
    }
    return true;
}

bool ICollider::doesCollide( const RectangleBounds& candidate ) {
    return bounds.doesCollide( candidate );
}

}
}