// nxn_scene_graph.cpp

#include "nxn_scene_graph.h"

namespace StevensDev {
namespace sgds {

NxNSceneGraph::NxNSceneGraph() {
    dimensions = 200;
    divisions = 200;
}

NxNSceneGraph::NxNSceneGraph( NxNSceneGraph& otherScene ) {
    dimensions = otherScene.dimensions;
    divisions = otherScene.divisions;
    colliders = otherScene.colliders;
    collidersToAdd = otherScene.collidersToAdd;
    collidersToRemove = otherScene.collidersToRemove;
}

NxNSceneGraph::NxNSceneGraph( float dimensions, int divisions ) {
    this->dimensions = dimensions;
    this->divisions = divisions;
}

NxNSceneGraph::~NxNSceneGraph() {
    colliders.~DynamicArray<ICollider*>();
    collidersToAdd.~DynamicArray<ICollider*>();
    collidersToRemove.~DynamicArray<ICollider*>();
}

NxNSceneGraph& NxNSceneGraph::operator =( const NxNSceneGraph& otherScene ) {
    dimensions = otherScene.dimensions;
    divisions = otherScene.divisions;
    colliders = otherScene.colliders;
    collidersToAdd = otherScene.collidersToAdd;
    collidersToRemove = otherScene.collidersToRemove;
}

void NxNSceneGraph::addCollider( ICollider* collider ) {
    collidersToAdd.push( collider );
}

void NxNSceneGraph::removeCollider( ICollider* collider ) {
    //collidersToRemove.removeByValue( collider );
}

sgdc::DynamicArray<ICollider*> NxNSceneGraph::find( float x, float y,
    float width, float height ) {
    int i;
    sgdc::DynamicArray<ICollider*> foundColliders;
    RectangleBounds newRectangle( x, y, width, height );
    for( i = 0; i < colliders.getLength(); i++ ) {
        if( colliders[i]->doesCollide( newRectangle ) ) {
            foundColliders.push( colliders[i] );
        }
    }
    return foundColliders;
}

sgdc::DynamicArray<ICollider*> NxNSceneGraph::find( float x, float y,
    float width, float height, unsigned short flags ) {
    int i;
    sgdc::DynamicArray<ICollider*> foundColliders;
    RectangleBounds newRectangle( x, y, width, height );
    for( i = 0; i < colliders.getLength(); i++ ) {
        if( colliders[i]->doesCollide( newRectangle ) && colliders[i]->canCollide( flags ) ) {
            foundColliders.push( colliders[i] );
        }
    }
    return foundColliders;
}

sgdc::DynamicArray<ICollider*> NxNSceneGraph::find( const RectangleBounds& bounds ) {
    int i;
    sgdc::DynamicArray<ICollider*> foundColliders;
    for( i = 0; i < colliders.getLength(); i++ ) {
        if( colliders[i]->doesCollide( bounds ) ) {
            foundColliders.push( colliders[i] );
        }
    }
    return foundColliders;
}

sgdc::DynamicArray<ICollider*> NxNSceneGraph::find( const RectangleBounds& bounds,
    unsigned short flags ) {
    int i;
    sgdc::DynamicArray<ICollider*> foundColliders;
    for( i = 0; i < colliders.getLength(); i++ ) {
        if( colliders[i]->doesCollide( bounds ) && colliders[i]->canCollide( flags ) ) {
            foundColliders.push( colliders[i] );
        }
    }
    return foundColliders;
}

sgdc::DynamicArray<ICollider*> NxNSceneGraph::find( const ICollider* collider ) {
    int i;
    sgdc::DynamicArray<ICollider*> foundColliders;
    for( i = 0; i < colliders.getLength(); i++ ) {
        if( colliders[i] == collider ) {
            foundColliders.push( colliders[i] );
        }
    }
    return foundColliders;
}

void NxNSceneGraph::preTick() {
    int i;
    for( i = 0; i < collidersToAdd.getLength(); i++ )
    {
        colliders.push( collidersToAdd[i] );
    }
    for( i = 0; i < collidersToRemove.getLength(); i++ )
    {
        colliders.push( collidersToRemove[i] );
    }
}

void NxNSceneGraph::tick( float dtS ) {

}

void NxNSceneGraph::postTick() {

}

}
}