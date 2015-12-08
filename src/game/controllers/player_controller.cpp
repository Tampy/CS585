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
}

PlayerController::PlayerController( PlayerController& otherController )
{
    collider.bounds().setDimensions( 64, 64 );
}

PlayerController::~PlayerController()
{

}

PlayerController& PlayerController::operator=( PlayerController& otherController )
{
    collider.bounds().setDimensions( 64, 64 );
}

sgdr::RenderableSprite& PlayerController::getSprite() {
    return playerSprite;
}

void PlayerController::updatePosition()
{
    int originalX = playerSprite.getPositionX();
    int originalY = playerSprite.getPositionY();
    if( sgdi::Input::inst().isDown( sgdi::Input::InputType::W_KEY ) || sgdi::Input::inst().isDown( sgdi::Input::InputType::UP_ARROW_KEY ) )
    {
        playerSprite.move( 0, -10 );
        if( sgds::Scene::inst().getSceneGraph().find( &collider ).getLength() != 0 ) {
            playerSprite.setPosition( originalX, originalY + 10 );
        }
    }
    else if( sgdi::Input::inst().isDown( sgdi::Input::InputType::A_KEY ) || sgdi::Input::inst().isDown( sgdi::Input::InputType::LEFT_ARROW_KEY ) )
    {
        playerSprite.move( -10, 0 );
        if( sgds::Scene::inst().getSceneGraph().find( &collider ).getLength() != 0 ) {
            playerSprite.setPosition( originalX + 10, originalY );
        }
    }
    else if( sgdi::Input::inst().isDown( sgdi::Input::InputType::S_KEY ) || sgdi::Input::inst().isDown( sgdi::Input::InputType::DOWN_ARROW_KEY ) )
    {
        playerSprite.move( 0, 10 );
        if( sgds::Scene::inst().getSceneGraph().find( &collider ).getLength() != 0 ) {
            playerSprite.setPosition( originalX, originalY - 10 );
        }
    }
    else if( sgdi::Input::inst().isDown( sgdi::Input::InputType::D_KEY ) || sgdi::Input::inst().isDown( sgdi::Input::InputType::RIGHT_ARROW_KEY ) )
    {
        playerSprite.move( 10, 0 );
        if( sgds::Scene::inst().getSceneGraph().find( &collider ).getLength() != 0 ) {
            playerSprite.setPosition( originalX - 10, originalY );
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