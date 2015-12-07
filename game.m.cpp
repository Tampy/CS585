// game.m.cpp

#include "game.h"
#include <controllers/player_controller.h>
#include <controllers/ai_controller.h>
#include <iostream>
#include <input/input.h>
#include <rendering/renderable_sprite.h>
#include <rendering/renderer.h>
#include <scene/nxn_scene_graph.h>
#include <scene/scene.h>
#include <SFML/Graphics.hpp>
#include <unistd.h>

int main( int argc, char *argv[] ) {
    using namespace StevensDev;
    const int windowWidth = 800;
    const int windowHeight = 600;
    const int spritePosX = 300;
    const int spritePosY = 500;

    sgds::Scene::inst().addTickable( &sgdi::Input::inst() );

    sgdr::Renderer renderer;
    renderer.setupWindow( windowWidth, windowHeight );

    mgc::PlayerController player;
    mgc::AIController ai;

    if ( !renderer.loadTexture( "texture.png", "../graphics/" ) ) {
        std::cout << "Error." << std::endl;
        return 1;
    }
    sf::Texture texture = renderer.getTexture( "texture.png" );
    player.getSprite().setTexture( texture );
    ai.getSprite().setBasicTexture( 0, 255, 0 );
    player.getSprite().setPosition( spritePosX, spritePosY );
    ai.getSprite().setPosition( 100, 100 );
    renderer.addSprite( &player.getSprite() );
    renderer.addSprite( &ai.getSprite() );

    sgds::Scene::inst().setRenderer( &renderer );

    NxNSceneGraph sceneGraph;
    sceneGraph.addCollider( &player.getCollider() );
    sceneGraph.addCollider( &ai.getCollider() );

    //create walls
    sgdr::RenderableSprite wall1, wall2, wall3, wall4;
    wall1.setBasicTexture( 255, 255, 255, 255, 400, 5 );
    wall2.setBasicTexture( 255, 255, 255, 255, 5, 400 );
    wall3.setBasicTexture( 255, 255, 255, 255, 5, 200 );
    wall4.setBasicTexture( 255, 255, 255, 255, 200, 5 );

    sgds::Scene::inst().addTickable( &sceneGraph );
    while( true ) {
        //std::cout << "loop" << std::endl;
        sgds::Scene::inst().tick();
        player.updatePosition();
        ai.moveAI( player.getSprite().getPositionX(), player.getSprite().getPositionY() );
        ai.modifyVulnerability();
    }

    return 0;
}