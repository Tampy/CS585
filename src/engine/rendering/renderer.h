// renderer.h

#ifndef RENDERER_H
#define RENDERER_H

#include "renderable_sprite.h"
#include <containers/map.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>

namespace StevensDev {
namespace sgdr {
class Renderer {
  private:
    sf::RenderWindow window;
    sgdc::DynamicArray<RenderableSprite*> d_sprites;
    sgdc::Map<sf::Texture> textures;
    sf::Event event;
  public:
      // CONSTRUCTORS //
    Renderer();
      // default constructor
    Renderer( Renderer& otherRenderer );
      // copy constructor
    ~Renderer();
      // destructor
      // FREE OPERATORS //
    Renderer& operator = ( const Renderer &otherRenderer );
      // assignment operator
      // MUTATORS //
    void draw();
    void addSprite( RenderableSprite* sprite );
    void removeSprite( RenderableSprite* sprite );
    void setupWindow( int width, int height );
    bool loadTexture( const std::string& name, const std::string& path );
      // ACCESSORS //
    const sf::Texture& getTexture( const std::string& name );
    bool isActive();
      // Returns false once the window is ready to be destroyed
};
}
}

#endif