// player_controller.cpp
// controls how the player character moves

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

void PlayerController::UpdatePosition()
{
    if( input.isDown( sgdi::InputType::W_KEY ) || input.isDown( sgdi::InputType::UP_ARROW_KEY ) )
    {

    }
    else if( input.isDown( sgdi::InputType::A_KEY ) || input.isDown( sgdi::InputType::LEFT_ARROW_KEY ) )
    {

    }
    else if( input.isDown( sgdi::InputType::S_KEY ) || input.isDown( sgdi::InputType::DOWN_ARROW_KEY ) )
    {

    }
    else if( input.isDown( sgdi::InputType::D_KEY ) || input.isDown( sgdi::InputType::RIGHT_ARROW_KEY ) )
    {

    }
}

void PlayerController::CheckForCollision()
{

}

}
}