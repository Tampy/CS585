// rectangle_bounds.h

#ifndef RECTANGLE_BOUNDS_H
#define RECTANGLE_BOUNDS_H

namespace StevensDev {
namespace sgds {
class RectangleBounds {
  private:
    float rectX;
    float rectY;
    float rectWidth;
    float rectHeight;
  public:
      // CONSTRUCTORS //
    RectangleBounds();
      // default constructor
    RectangleBounds( RectangleBounds& otherBounds );
      // copy constructor
    RectangleBounds( float x, float y, float width, float height );
      // constructor that creates a certain kind of rectangle
    ~RectangleBounds();
      // destructor
      // FREE OPERATORS //
    RectangleBounds &operator = ( const RectangleBounds& otherBounds );
      // assignment operator
      // ACCESSORS //
    float x() const;
    float y() const;
    float width() const;
    float height() const;
    bool doesCollide( const RectangleBounds& candidate );
      // MUTATORS //
    void setX( float x );
    void setY( float y );
    void setWidth( float width );
    void setHeight( float height );
    void setDimensions( float width, float height );
    void setPosition( float x, float y );
};
}
}

#endif