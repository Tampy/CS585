// ai_controller.h
// controls how the ghost characters move

#ifndef AI_CONTROLLER_H
#define AI_CONTROLLER_H

#include <ctime>
#include <rendering/renderable_sprite.h>
#include <scene/icollider.h>

namespace StevensDev
{
namespace mgc
{
class AIController
{
  private:
    sgdr::RenderableSprite aiSprite;
    sgds::ICollider collider;
    std::clock_t vulnerabilityStartTime;
    bool vulnerable;
  public:
      // CONSTRUCTORS //
    AIController();
      // default constructor
    AIController( AIController& otherController );
      // copy constructor
    AIController( float x, float y );
      // constructor with initial position
    ~AIController();
      // destructor
      // FREE OPERATORS //
    AIController& operator=( AIController& otherController );
      // assignment operator
      // ACCESSORS //
    sgdr::RenderableSprite& getSprite();
      // gets sprite used by AI
    bool isVulnerable();
      // check whether the AI is vulnerable in this moment or not
      // MUTATORS //
    void moveAI( float characterX, float characterY );
      // update AI position automatically, checking for collisions
    void modifyVulnerability();
      // if colliding, prevent position updating
};
}
}

#endif
