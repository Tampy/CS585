// player_controller.cpp
// controls how the player character moves

#include "player_controller.h"
#include <scene/scene.h>
#include <iostream>

namespace StevensDev
{
namespace mgc
{

PlayerController::PlayerController()
{
    collider.bounds().setDimensions( 64, 64 );
    collider.setFlags( 1 );
}

PlayerController::PlayerController( PlayerController& otherController )
{
    collider.bounds().setDimensions( 64, 64 );
    collider.setFlags( 1 );
}

PlayerController::~PlayerController()
{

}

PlayerController& PlayerController::operator=( PlayerController& otherController )
{
    collider.bounds().setDimensions( 64, 64 );
    collider.setFlags( 1 );
}

sgdr::RenderableSprite& PlayerController::getSprite() {
    return playerSprite;
}

void PlayerController::updatePosition()
{
    if( sgdi::Input::inst().isDown( sgdi::Input::InputType::W_KEY ) || sgdi::Input::inst().isDown( sgdi::Input::InputType::UP_ARROW_KEY ) )
    {
        playerSprite.move( 0, -10 );
        while( sgds::Scene::inst().getSceneGraph().find( &collider ).getLength() != 0 ) {
            playerSprite.move( 0, 30 );
            collider.bounds().setPosition( playerSprite.getPositionX(), playerSprite.getPositionY() );
        }
    }
    else if( sgdi::Input::inst().isDown( sgdi::Input::InputType::A_KEY ) || sgdi::Input::inst().isDown( sgdi::Input::InputType::LEFT_ARROW_KEY ) )
    {
        playerSprite.move( -10, 0 );
        while( sgds::Scene::inst().getSceneGraph().find( &collider ).getLength() != 0 ) {
            playerSprite.move( 30, 0 );
            collider.bounds().setPosition( playerSprite.getPositionX(), playerSprite.getPositionY() );
        }
    }
    else if( sgdi::Input::inst().isDown( sgdi::Input::InputType::S_KEY ) || sgdi::Input::inst().isDown( sgdi::Input::InputType::DOWN_ARROW_KEY ) )
    {
        playerSprite.move( 0, 10 );
        while( sgds::Scene::inst().getSceneGraph().find( &collider ).getLength() != 0 ) {
            playerSprite.move( 0, -30 );
            collider.bounds().setPosition( playerSprite.getPositionX(), playerSprite.getPositionY() );
        }
    }
    else if( sgdi::Input::inst().isDown( sgdi::Input::InputType::D_KEY ) || sgdi::Input::inst().isDown( sgdi::Input::InputType::RIGHT_ARROW_KEY ) )
    {
        playerSprite.move( 10, 0 );
        while( sgds::Scene::inst().getSceneGraph().find( &collider ).getLength() != 0 ) {
            playerSprite.move( -30, 0 );
            collider.bounds().setPosition( playerSprite.getPositionX(), playerSprite.getPositionY() );
        }
    }
    collider.bounds().setPosition( playerSprite.getPositionX(), playerSprite.getPositionY() );
}

sgds::ICollider& PlayerController::getCollider()
{
    return collider;
}

}
}