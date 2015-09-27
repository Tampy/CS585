// stack_guard.h

#ifndef STACK_GUARD_H
#define STACK_GUARD_H

namespace StevensDev {
namespace sgdm {
template<typename T> class StackGuard {
  private:
    T* pointer;
    StackGuard( StackGuard<T> &otherGuard ) { }
      // copy constructor. Disabled
  public:
      // CONSTRUCTORS //
    StackGuard( T* rawPointer ) {
        if ( rawPointer ) {
            pointer = rawPointer;
        }
    }
      // default constructor
    ~StackGuard() {
      pointer = ~T();
    }
      // destructor
      // FREE OPERATORS //
    StackGuard &operator = ( const StackGuard &otherGuard );
      // assignment operator
    T* operator -> ();
      // arrow operator
    bool const operator == ( bool rhs );
      // equality operator
    bool const operator != ( bool rhs ) {
        return !( *this == rhs )
    }
      // inequality operator
    bool const operator ! ();
      // not operator
};
}
}

#endif