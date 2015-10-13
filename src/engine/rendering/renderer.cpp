// renderer.cpp

#include "renderer.h"
#include <SFML/Window/VideoMode.hpp>

namespace StevensDev {
namespace sgdr {

Renderer::Renderer() {

}

Renderer::Renderer( Renderer& otherRenderer ) {
    if( this != &otherRenderer ) {
        window.setSize( otherRenderer.window.getSize() );
        d_sprites = otherRenderer.d_sprites;
        event = otherRenderer.event;
    }
}

Renderer::~Renderer() {
    window.~RenderWindow();
    d_sprites.~DynamicArray<RenderableSprite*>();
    textures.~Map<sf::Texture>();
    event.~Event();
}

Renderer& Renderer::operator = ( const Renderer &otherRenderer ) {
    if( this != &otherRenderer ) {
        window.setSize( otherRenderer.window.getSize() );
        d_sprites = otherRenderer.d_sprites;
        event = otherRenderer.event;
    }
    return *this;
}

void Renderer::draw() {
    window.clear( sf::Color( 0, 0, 0 ) );
    int i;
    for( i = 0; i < d_sprites.getLength(); i++ ) {
        window.draw( d_sprites[i]->sprite() );
    }
    window.display();
}

void Renderer::addSprite( RenderableSprite* sprite ) {
    d_sprites.push( sprite );
}

void Renderer::removeSprite( RenderableSprite* sprite ) {
     d_sprites.removeByValue( sprite );
}

void Renderer::setupWindow( int width, int height ) {
    window.create( sf::VideoMode( width, height ), "Video Games" );
}

bool Renderer::loadTexture( const std::string& name, const std::string& path ) {
    sf::Texture texture;
    if( !texture.loadFromFile( path + name ) ) {
        return false;
    }
    textures[name] = texture;
    return true;
}

const sf::Texture& Renderer::getTexture( const std::string& name ) {
    return textures[name];
}

bool Renderer::isActive() {
    if( event.type == sf::Event::LostFocus ) {
        return false;
    }
    return true;
}

}
}