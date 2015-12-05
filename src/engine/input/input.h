// input.h

#ifndef INPUT_H
#define INPUT_H

#include <scene/itickable.h>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Event.hpp>

namespace StevensDev {
namespace sgdi {
class Input : public sgds::ITickable {
  private:
      // CONSTRUCTORS //
    Input();
      // default constructor
    Input( Input& otherInput );
      // copy constructor
      // FREE OPERATORS //
    Input& operator = ( const Input &otherInput );
      // assignment operator
    void tick( float dtS );
    void postTick();
    sf::Event event;
  public:
    enum InputType {
        Q_KEY = sf::Keyboard::Q,
        W_KEY = sf::Keyboard::W,
        E_KEY = sf::Keyboard::E,
        R_KEY = sf::Keyboard::R,
        T_KEY = sf::Keyboard::T,
        Y_KEY = sf::Keyboard::Y,
        U_KEY = sf::Keyboard::U,
        I_KEY = sf::Keyboard::I,
        O_KEY = sf::Keyboard::O,
        P_KEY = sf::Keyboard::P,
        A_KEY = sf::Keyboard::A,
        S_KEY = sf::Keyboard::S,
        D_KEY = sf::Keyboard::D,
        F_KEY = sf::Keyboard::F,
        G_KEY = sf::Keyboard::G,
        H_KEY = sf::Keyboard::H,
        J_KEY = sf::Keyboard::J,
        K_KEY = sf::Keyboard::K,
        L_KEY = sf::Keyboard::L,
        Z_KEY = sf::Keyboard::Z,
        X_KEY = sf::Keyboard::X,
        C_KEY = sf::Keyboard::C,
        V_KEY = sf::Keyboard::V,
        B_KEY = sf::Keyboard::B,
        N_KEY = sf::Keyboard::N,
        M_KEY = sf::Keyboard::M,
        LEFT_ARROW_KEY = sf::Keyboard::Left,
        RIGHT_ARROW_KEY = sf::Keyboard::Right,
        UP_ARROW_KEY = sf::Keyboard::Up,
        DOWN_ARROW_KEY = sf::Keyboard::Down,
        ESCAPE_KEY = sf::Keyboard::Escape,
        MOUSE_1 = sf::Mouse::Left,
        MOUSE_2 = sf::Mouse::Right,
        MOUSE_3 = sf::Mouse::Middle,
        MOUSE_4 = sf::Mouse::XButton1,
        MOUSE_5 = sf::Mouse::XButton2
    };
      // different types of input controls
    bool isKey( InputType type );
      // Determines if InputType is a key
    ~Input();
      // destructor
      // ACCESSORS //
    static Input& inst();
      // get instance of Input
    bool isDown( InputType type );
      // Current state down
    bool isUp( InputType type );
      // Current state up
    bool wasPressed( InputType type );
      // Was down and now is up
    void preTick();
      // Poll input state at this point, setup internal state
};
}
}

#endif