// ai_controller.h
// controls how the ghost characters move

#ifndef AI_CONTROLLER_H
#define AI_CONTROLLER_H

namespace StevensDev
{
namespace mgc
{
class AIController
{
  public:
      // CONSTRUCTORS //
    AIController();
      // default constructor
    AIController( AIController& otherController );
      // copy constructor
    ~AIController();
      // destructor
      // FREE OPERATORS //
    AIController& operator=( AIController& otherController );
      // assignment operator
      // MUTATORS //
    void MoveAI();
      // update AI position automatically, checking for collisions
    void ModifyVulnerability();
      // if colliding, prevent position updating
};
}
}

#endif
