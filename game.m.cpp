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

void setVariables() {

}

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
    player.getSprite().setPosition( 550, 300 );
    ai.getSprite().setPosition( 600, 100 );
    renderer.addSprite( &player.getSprite() );
    renderer.addSprite( &ai.getSprite() );

    sgds::NxNSceneGraph sceneGraph;
    sceneGraph.addCollider( &player.getCollider() );
    sceneGraph.addCollider( &ai.getCollider() );

    //create walls
    sgdr::RenderableSprite wall1, wall2, wall3, wall4, wall5;
    wall1.setBasicTexture( 255, 255, 255, 255, 400, 5 );
    wall2.setBasicTexture( 255, 255, 255, 255, 5, 400 );
    //wall3.setBasicTexture( 255, 255, 255, 255, 5, 200 );
    //wall4.setBasicTexture( 255, 255, 255, 255, 5, 200 );
    //wall5.setBasicTexture( 255, 255, 255, 255, 400, 5 );
    wall1.setPosition( 100, 100 );
    wall2.setPosition( 100, 100 );
    //wall3.setPosition( 700, 300 );
    //wall4.setPosition( 300, 300 );
    //wall5.setPosition( 300, 500 );
    renderer.addSprite( &wall1 );
    renderer.addSprite( &wall2 );
    //renderer.addSprite( &wall3 );
    //renderer.addSprite( &wall4 );
    //renderer.addSprite( &wall5 );
    sgds::ICollider wall1Collider( 100, 100, 400, 5 );
    sgds::ICollider wall2Collider( 100, 100, 5, 400 );
    //sgds::ICollider wall3Collider( 700, 300, 5, 200 );
    //sgds::ICollider wall4Collider( 300, 300, 5, 200 );
    //sgds::ICollider wall5Collider( 300, 500, 400, 5 );
    sceneGraph.addCollider( &wall1Collider );
    sceneGraph.addCollider( &wall2Collider );
    //sceneGraph.addCollider( &wall3Collider );
    //sceneGraph.addCollider( &wall4Collider );
    //sceneGraph.addCollider( &wall5Collider );

    sgds::Scene::inst().setRenderer( &renderer );
    sgds::Scene::inst().setSceneGraph( &sceneGraph );
    bool keepAi = true;
    while( true ) {
        std::cout << "loop" << std::endl;
        sgds::Scene::inst().tick();
        player.updatePosition();
        /* if( player.checkIfDead() )
        {
            break;
        }*/
        if( keepAi )
        {
            ai.modifyVulnerability();
            keepAi = ai.moveAI( player.getSprite().getPositionX(), player.getSprite().getPositionY() );
        }
    }

    return 0;
}