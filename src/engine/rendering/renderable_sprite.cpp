// renderable_sprite.h

#include "renderable_sprite.h"
#include <SFML/System/Vector2.hpp>
#include <iostream>

namespace StevensDev {
namespace sgdr {

RenderableSprite::RenderableSprite() {

}

RenderableSprite::RenderableSprite( RenderableSprite& otherSprite ) {
    if( this != &otherSprite ) {
        dsprite = otherSprite.sprite();
    }
}

RenderableSprite::~RenderableSprite() {
    dsprite.~Sprite();
}

RenderableSprite& RenderableSprite::operator = ( const RenderableSprite &otherSprite ) {
    if( this != &otherSprite ) {
        dsprite = otherSprite.sprite();
    }
    return *this;
}

void RenderableSprite::setPosition( float x, float y ) {
    dsprite.setPosition( x, y );

}

void RenderableSprite::move( float x, float y ) {
    dsprite.move( x, y );

}

const sf::Sprite& RenderableSprite::sprite() const {
    return dsprite;
}

float RenderableSprite::getPositionX() {
    return dsprite.getPosition().x;
}

float RenderableSprite::getPositionY() {
    return dsprite.getPosition().y;
}

void RenderableSprite::setTexture( sf::Texture texture ) {
    dsprite.setTexture( texture );
}

void RenderableSprite::setBasicTexture( int r, int g, int b, int a )
{
    sf::Texture texture;
    texture.create( 64, 64 ); 
    dsprite.setTexture( texture );
    dsprite.setColor( sf::Color( r, g, b, a ) );
}

}
}