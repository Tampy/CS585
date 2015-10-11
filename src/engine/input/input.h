// input.h

#ifndef INPUT_H
#define INPUT_H

namespace StevensDev {
namespace sgdi {
class Input : public ITickable {
  private:
    enum InputType {
        1_KEY, 2_KEY, 3_KEY, 4_KEY, 5_KEY, 6_KEY, 7_KEY, 8_KEY, 9_KEY, 0_KEY,
        Q_KEY, W_KEY, E_KEY, R_KEY, T_KEY, Y_KEY, U_KEY, I_KEY, O_KEY, P_KEY,
           A_KEY, S_KEY, D_KEY, F_KEY, G_KEY, H_KEY, J_KEY, K_KEY, L_KEY,
                 Z_KEY, X_KEY, C_KEY, V_KEY, B_KEY, N_KEY, M_KEY,
        LEFT_MOUSE, RIGHT_MOUSE, MIDDLE_MOUSE, MOUSE_4, MOUSE_5
    };
      // CONSTRUCTORS //
    Input();
      // default constructor
    Input( Input& otherInput );
      // copy constructor
      // FREE OPERATORS //
    Input& operator = ( const Input &otherInput );
      // assignment operator
  public:
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