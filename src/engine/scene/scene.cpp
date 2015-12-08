// scene.cpp

#include "scene.h"

namespace StevensDev {
namespace sgds {

Scene::Scene() {
    tickCount = 0;
}

Scene::Scene( Scene& otherScene ) {
    if( this != &otherScene ) {
        tickables = otherScene.tickables;
        sceneRenderer = otherScene.sceneRenderer;
        tickCount = otherScene.tickCount;
    }
}

Scene::~Scene() {
    tickables.~DynamicArray<ITickable*>();
    sceneRenderer->~Renderer();
}

Scene& Scene::operator = ( const Scene& otherScene ) {
    if( this != &otherScene ) {
        tickables = otherScene.tickables;
        sceneRenderer = otherScene.sceneRenderer;
        tickCount = otherScene.tickCount;
    }
    return *this;
}

Scene& Scene::inst() {
    static Scene instance;
    return instance;
}

sgds::NxNSceneGraph& Scene::getSceneGraph()
{
    return *sceneGraph;

}

void Scene::tick() {
    int i;
    for( i = 0; i < tickables.getLength(); i++ ) {
        tickables[i]->preTick();
        tickables[i]->tick( tickCount );
        tickables[i]->postTick();
    }
    sceneGraph->preTick();
    sceneRenderer->draw();
    tickCount++;
}

void Scene::addTickable( ITickable* tickable ) {
    tickables.push( tickable );
}

void Scene::removeTickable( ITickable* tickable ) {
    //tickables.removeByValue( tickable );
}

void Scene::setRenderer( sgdr::Renderer* renderer ) {
    sceneRenderer = renderer;
}

void Scene::setSceneGraph( sgds::NxNSceneGraph* graph )
{
    sceneGraph = graph;
}

}
}
