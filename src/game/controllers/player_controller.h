// player_controller.h
// controls how the player character moves

#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include <input/input.h>

namespace StevensDev
{
namespace mgc
{
class PlayerController
{
  private:
    sgdi::Input input;
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
      // MUTATORS //
    void UpdatePosition();
      // check input and update position based on input
    void CheckForCollision();
      // if colliding, prevent position updating
};
}
}

#endif
