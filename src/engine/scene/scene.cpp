// scene.cpp

#include "scene.h"

Scene::Scene() {

}

Scene::Scene( Scene& otherScene ) {

}

Scene& Scene::operator = ( const Renderer &otherScene ) {

}

static Scene& Scene::inst() {

}

void Scene::tick() {

}

void Scene::addTickable( ITickable* tickable ) {

}

void Scene::removeTickable( ITickable* tickable ) {

}

void Scene::setRenderer( Renderer* renderer ) {
    
}

