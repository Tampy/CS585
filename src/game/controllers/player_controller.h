// player_controller.h
// controls how the player character moves

#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include <input/input.h>
#include <rendering/renderable_sprite.h>

namespace StevensDev
{
namespace mgc
{
class PlayerController
{
  private:
    sgdr::RenderableSprite playerSprite;
  public:
      // CONSTRUCTORS //
    PlayerController();
      // default constructor
    PlayerController( PlayerController& otherController );
      // copy constructor
    ~PlayerController();
      // destructor
      // FREE OPERATORS //
    PlayerController& operator=( PlayerController& otherController );
      // assignment operator
      // ACCESSORS //
    sgdr::RenderableSprite& getSprite();
      // gets sprite used by player
      // MUTATORS //
    void updatePosition();
      // check input and update position based on input
    void checkForCollision();
      // if colliding, prevent position updating
};
}
}

#endif
