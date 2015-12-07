// ai_controller.cpp
// controls how the ghost characters move

#include "ai_controller.h"
#include <iostream>

namespace StevensDev
{
namespace mgc
{

AIController::AIController()
{
    vulnerabilityStartTime = std::clock();
    vulnerable = false;
}

AIController::AIController( AIController& otherController )
{
    aiSprite = otherController.aiSprite;
    vulnerabilityStartTime = std::clock();
    vulnerable = false;
}

AIController::AIController( float x, float y )
{
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
    float x;
    float y;

    // determine x movement
    if( aiSprite.getPositionX() > characterX )
    {
        x = -5;
    }
    else if( aiSprite.getPositionX() < characterX )
    {
        x = 5;
    }

    // determine y movement
    if( aiSprite.getPositionY() > characterY )
    {
        y = -5;
    }
    else if( aiSprite.getPositionY() < characterY )
    {
        y = 5;
    }

    aiSprite.move( x, y );
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

bool AIController::isVulnerable() {
    return vulnerable;
}

}
}