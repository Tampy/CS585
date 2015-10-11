// scene.h

#ifndef SCENE_H
#define SCENE_H

#include "itickable.h"
#include <rendering/renderer.h>

namespace StevensDev {
namespace sgds {
class Scene {
  private:
      // CONSTRUCTORS //
    Scene();
      // default constructor
    Scene( Scene& otherScene );
      // copy constructor
    Scene& operator = ( const Renderer &otherScene );
      // assignment operator
  public:
    static Scene& inst();
      // get instance of Scene
    void tick();
      // Progress time forward one unit.
    void addTickable( ITickable* tickable );
      // Add ITickable object
    void removeTickable( ITickable* tickable );
      // Remove ITickable object
    void setRenderer( Renderer* renderer );
      // Set Renderer object
};
}
}

#endif