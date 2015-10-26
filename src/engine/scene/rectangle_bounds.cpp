// rectangle_bounds.cpp

namespace StevensDev {
namespace sgds {

float RectangleBounds::x() const {
    return x;
}

float RectangleBounds::y() const {
    return y;
}

float RectangleBounds::width() const {
    return width;
}

float RectangleBounds::height() const {
    return height;
}

void RectangleBounds::setX( float x ) {
    this.x = x;
}

void RectangleBounds::setY( float y ) {
    this.y = y;
}

void RectangleBounds::setWidth( float width ) {
    this.width = width;
}

void RectangleBounds::setHeight( float height ) {
    this.height = height;
}

void RectangleBounds::setDimensions( float width, float height ) {
    this.width = width;
    this.height = height;
}

void RectangleBounds::setPosition( float x, float y ) {
    this.x = x;
    this.y = y;
}

bool RectangleBounds::doesCollide( const RectangleBounds& candidate ) {
    float rectBoundsX = candidate.x() + candidate.width();
    float rectBoundsY = candidate.x() + candidate.height();
    if( rectBoundsX > x && rectBoundsX < x + width ) {
        if( rectBoundsY > y && rectBoundsY < y + height ) {
            return true;
        }
    }
    return false;
}

}
}