// renderer.cpp

#include "renderer.h"

Renderer::Renderer() {

}

Renderer::Renderer( Renderer& otherRenderer ) {

}

Renderer::~Renderer() {

}

Renderer& Renderer::operator = ( const Renderer &otherRenderer ) {

}

void Renderer::draw() {

}

void Renderer::addSprite( RenderableSprite* sprite ) {

}

void Renderer::removeSprite( RenderableSprite* sprite ) {

}

void Renderer::setupWindow( int width, int height ) {

}

bool Renderer::loadTexture( const std::string& name, const std::string& path ) {

}

const sf::Texture& Renderer::getTexture( const std::string& name) {

}

bool Renderer::isActive() {
    
}

