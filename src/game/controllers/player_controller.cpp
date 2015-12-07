// player_controller.cpp
// controls how the player character moves

#include "player_controller.h"

namespace StevensDev
{
namespace mgc
{

PlayerController::PlayerController()
{

}

PlayerController::PlayerController( PlayerController& otherController )
{

}

PlayerController::~PlayerController()
{

}

PlayerController& PlayerController::operator=( PlayerController& otherController )
{

}

sgdr::RenderableSprite& PlayerController::getSprite() {
    return playerSprite;
}

void PlayerController::updatePosition()
{
    if( sgdi::Input::inst().isDown( sgdi::Input::InputType::W_KEY ) || sgdi::Input::inst().isDown( sgdi::Input::InputType::UP_ARROW_KEY ) )
    {
        playerSprite.move( 0, -10 );
    }
    else if( sgdi::Input::inst().isDown( sgdi::Input::InputType::A_KEY ) || sgdi::Input::inst().isDown( sgdi::Input::InputType::LEFT_ARROW_KEY ) )
    {
        playerSprite.move( -10, 0 );
    }
    else if( sgdi::Input::inst().isDown( sgdi::Input::InputType::S_KEY ) || sgdi::Input::inst().isDown( sgdi::Input::InputType::DOWN_ARROW_KEY ) )
    {
        playerSprite.move( 0, 10 );
    }
    else if( sgdi::Input::inst().isDown( sgdi::Input::InputType::D_KEY ) || sgdi::Input::inst().isDown( sgdi::Input::InputType::RIGHT_ARROW_KEY ) )
    {
        playerSprite.move( 10, 0 );
    }
}

void PlayerController::checkForCollision()
{

}

}
}