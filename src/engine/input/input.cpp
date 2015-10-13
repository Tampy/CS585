// input.cpp

#include "input.h"

namespace StevensDev {
namespace sgdi {

Input::Input() {

}

Input::Input( Input& otherInput ) {
    if( this != &otherInput ) {
        event = otherInput.event;
    }
}

Input& Input::operator = ( const Input &otherInput ) {
    if( this != &otherInput ) {
        event = otherInput.event;
    }
    return *this;
}

Input::~Input() {
    event.~Event();
}

Input& Input::inst() {
    static Input instance;
    return instance;
}

bool Input::isDown( InputType type ) {
    if( !isKey( type ) ) {
        return sf::Mouse::isButtonPressed( static_cast<sf::Mouse::Button>( type ) );
    }
    return sf::Keyboard::isKeyPressed( static_cast<sf::Keyboard::Key>( type ) );
}

bool Input::isUp( InputType type ) {
    return !isDown( type );
}

bool Input::wasPressed( InputType type ) {
    if( isKey( type ) ) {
        if( static_cast<int>( event.key.code ) != static_cast<int>( type ) ) {
            return false;
        }
        return true;
    }
    else {
        if ( static_cast<int>( event.mouseButton.button ) != static_cast<int>( type ) ) {
            return false;
        }
        return true;
    }
}

bool Input::isKey( InputType type ) {
    switch( type ) {
        case InputType::MOUSE_1:
        case InputType::MOUSE_2:
        case InputType::MOUSE_3:
        case InputType::MOUSE_4:
        case InputType::MOUSE_5:
            return false;
            break;
        default:
            return true;
            break;
    }
}

void Input::preTick() {
    if( event.key.code ) {
        isDown( event.key.code );
    }
    else if( event.mouseButton.button ) {
        isDown( event.mouseButton.button );
    }
}

void Input::tick( float dtS ) {

}

void Input::postTick() {

}

}
}