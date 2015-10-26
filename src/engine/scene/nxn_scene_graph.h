// nxn_scene_graph.h

#ifndef NXN_SCENE_GRAPH_H
#define NXN_SCENE_GRAPH_H

#include <containers/dynamic_array.h>
#include "icollider.h"
#include "itickable.h"

namespace StevensDev {
namespace sgds {
class NxNSceneGraph : public ITickable {
  private:
    sgdc::DynamicArray<ICollider*> colliders;
  public:
    NxNSceneGraph( float dimensions, int divisions );
    void addCollider( ICollider* collider );
    void removeCollider( ICollider* collider );
    sgdc::DynamicArray<ICollider*> find( float x, float y, float width, float height );
    sgdc::DynamicArray<ICollider*> find( float x, float y,
        float width, float height, unsigned short flags );
    sgdc::DynamicArray<ICollider*> find( const RectangleBounds& bounds );
    sgdc::DynamicArray<ICollider*> find( const RectangleBounds& bounds,
        unsigned short flags );
    sgdc::DynamicArray<ICollider*> find( const ICollider* collider );
      // Do not return self
};
}
}

#endif