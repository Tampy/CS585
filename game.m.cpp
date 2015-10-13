// game.m.cpp

#include "game.h"
#include <iostream>
#include <input/input.h>
#include <rendering/renderable_sprite.h>
#include <rendering/renderer.h>
#include <scene/scene.h>
#include <SFML/Graphics.hpp>

int main( int argc, char *argv[] ) {
    using namespace StevensDev;
    const int windowWidth = 800;
    const int windowHeight = 600;
    const int spritePosX = 0;
    const int spritePosY = 0;

    sgds::Scene::inst().addTickable( &sgdi::Input::inst() );

    sgdr::Renderer renderer;
    renderer.setupWindow( windowWidth, windowHeight );

    sgdr::RenderableSprite sprite;
    if ( !renderer.loadTexture( "texture.png", "../graphics/" ) ) {
        std::cout << "Error." << std::endl;
        return 1;
    }
    sprite.setTexture( renderer.getTexture( "texture.png" ) );
    sgds::Scene::inst().setRenderer( &renderer );
    sprite.setPosition( spritePosX, spritePosY );
    while( true ) {
        sgds::Scene::inst().tick();
    }

    return 0;
}