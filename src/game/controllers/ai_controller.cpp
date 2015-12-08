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
    collider.setFlags( 2 );
    vulnerabilityStartTime = std::clock();
    vulnerable = false;
}

AIController::AIController( AIController& otherController )
{
    collider.bounds().setPosition( aiSprite.getPositionX(), aiSprite.getPositionY() );
    collider.bounds().setDimensions( 64, 64 );
    collider.setFlags( 2 );
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

bool AIController::moveAI( float characterX, float characterY )
{
    float x = 0;
    float y = 0;
    float originalX = aiSprite.getPositionX();
    float originalY = aiSprite.getPositionY();
    bool doesCollide = ( sgds::Scene::inst().getSceneGraph().find( &collider ).getLength() != 0 );

    if( !doesCollide )
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
        while ( sgds::Scene::inst().getSceneGraph().find( &collider ).getLength() != 0 ) {
            aiSprite.move( -x, -y );
            collider.bounds().setPosition( originalX - x, originalY - y );
        }
        return true;
    }
    else
    {
        if( vulnerable )
        {
            if( sgds::Scene::inst().getSceneGraph().find( &collider ).at(0)->flags() == 1 )
            {
                aiSprite.setPosition( -100, -100 );
                collider.bounds().setPosition( -100, -100 );
                return false;
            }
        }
    }
    return true;
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
            collider.setFlags( 2 );
        }
    }
    else
    {
        if( ( ( std::clock() - vulnerabilityStartTime ) / (double) CLOCKS_PER_SEC ) >= .05 )
        {
            vulnerable = true;
            vulnerabilityStartTime = std::clock();
            aiSprite.setBasicTexture( 132, 122, 255 );
            collider.setFlags( 3 );
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