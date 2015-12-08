// ai_controller.cpp
// controls how the ghost characters move

#include "ai_controller.h"
#include <containers/dynamic_array.h>
#include <scene/scene.h>
#include <iostream>

namespace StevensDev
{
namespace mgc
{

AIController::AIController()
{
    collider.bounds().setPosition( aiSprite.getPositionX(), aiSprite.getPositionY() );
    collider.bounds().setDimensions( 64, 64 );
    vulnerabilityStartTime = std::clock();
    vulnerable = false;
}

AIController::AIController( AIController& otherController )
{
    collider.bounds().setPosition( aiSprite.getPositionX(), aiSprite.getPositionY() );
    collider.bounds().setDimensions( 64, 64 );
    aiSprite = otherController.aiSprite;
    vulnerabilityStartTime = std::clock();
    vulnerable = false;
}

AIController::AIController( float x, float y )
{
    collider.bounds().setPosition( aiSprite.getPositionX(), aiSprite.getPositionY() );
    collider.bounds().setDimensions( 64, 64 );
    aiSprite.setPosition( x, y );
    vulnerabilityStartTime = std::clock();
    vulnerable = false;
}

AIController::~AIController()
{

}

AIController& AIController::operator=( AIController& otherController )
{
    aiSprite = otherController.aiSprite;
}

void AIController::moveAI( float characterX, float characterY )
{
    float x = 0;
    float y = 0;
    float originalX = aiSprite.getPositionX();
    float originalY = aiSprite.getPositionY();

    if( sgds::Scene::inst().getSceneGraph().find( &collider ).getLength() == 0 )
    {

    // determine x movement
    if( originalX > characterX )
    {
        x = -5;
    }
    else if( originalX < characterX )
    {
        x = 5;
    }

    // determine y movement
    if( originalY > characterY )
    {
        y = -5;
    }
    else if( originalY < characterY )
    {
        y = 5;
    }

    aiSprite.move( x, y );
    collider.bounds().setPosition( originalX + x, originalY + y );
    }
}

void AIController::modifyVulnerability()
{
    if( vulnerable )
    {
        if( ( ( std::clock() - vulnerabilityStartTime ) / (double) CLOCKS_PER_SEC ) >= .1 )
        {
            vulnerable = false;
            vulnerabilityStartTime = std::clock();
            aiSprite.setBasicTexture( 0, 255, 0 );
        }
    }
    else
    {
        if( ( ( std::clock() - vulnerabilityStartTime ) / (double) CLOCKS_PER_SEC ) >= .3 )
        {
            vulnerable = true;
            vulnerabilityStartTime = std::clock();
            aiSprite.setBasicTexture( 132, 122, 255 );
        }
    }
}

sgdr::RenderableSprite& AIController::getSprite()
{
    return aiSprite;
}

sgds::ICollider& AIController::getCollider()
{
    return collider;
}

bool AIController::isVulnerable() {
    return vulnerable;
}

}
}