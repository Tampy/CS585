// player_controller.h
// controls how the player character moves

#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include <input/input.h>
#include <rendering/renderable_sprite.h>
#include <scene/icollider.h>

namespace StevensDev
{
namespace mgc
{
class PlayerController
{
  private:
    sgdr::RenderableSprite playerSprite;
    sgds::ICollider collider;
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
    sgds::ICollider& getCollider();
      // get collider used by player
    bool checkIfDead();
      // check if we have collided with AI
      // MUTATORS //
    void updatePosition();
      // check input and update position based on input
};
}
}

#endif
