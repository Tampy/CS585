// renderable_sprite.h

#ifndef RENDERABLE_SPRITE_H
#define RENDERABLE_SPRITE_H

#include <Sprite.hpp>

namespace StevensDev {
namespace sgdr {
class RenderableSprite {
  private:
    sf::Sprite dsprite;
  public:
      // CONSTRUCTORS //
    RenderableSprite();
      // default constructor
    RenderableSprite( RenderableSprite& otherSprite );
      // copy constructor
    ~RenderableSprite();
      // destructor
      // FREE OPERATORS //
    RenderableSprite& operator = ( const RenderableSprite &otherSprite );
      // assignment operator
      // MUTATORS //
    void setPosition( float x, float y );
      // Sets absolute x/y position
    void move( float x, float y );
      // Increments x by x, y by y
      // ACCESSORS //
    const sf::Sprite& sprite() const;
      // Gets sprite stored in class
    float getPositionX();
      // Gets absolute x position
    float getPositionY();
      // Get absolute y position
};
}
}

#endif