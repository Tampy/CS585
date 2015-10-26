// rectangle_bounds.h

#ifndef RECTANGLE_BOUNDS_H
#define RECTANGLE_BOUNDS_H

namespace StevensDev {
namespace sgds {
class RectangleBounds {
  private:
    float x;
    float y;
    float width;
    float height;
  public:
    float x() const;
    float y() const;
    float width() const;
    float height() const;
    void setX( float x );
    void setY( float y );
    void setWidth( float width );
    void setHeight( float height );
    void setDimensions( float width, float height );
    void setPosition( float x, float y );
    bool doesCollide( const RectangleBounds& candidate );
};
}
}

#endif