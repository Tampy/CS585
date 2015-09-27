// stack_guard.h

#ifndef STACK_GUARD_H
#define STACK_GUARD_H

namespace StevensDev {
namespace sgdm {
template<typename T> class StackGuard {
  private:
    T* pointer;
    StackGuard( StackGuard<T>& guard ) { }
      // copy constructor. Disabled
  public:
      // CONSTRUCTORS //
    StackGuard( T* guarded ) {
        if ( guarded ) {
            pointer = guarded;
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
    T* operator -> () {
      return pointer;
    }
      // arrow operator
    bool const operator == ( bool rhs ) {
      bool isNull = ( pointer == nullptr );
      if ( isNull == rhs ) {
        return true;
      }
      return false;
    }
      // equality operator
    bool const operator != ( bool rhs ) {
        return !( *this == rhs );
    }
      // inequality operator
    bool const operator ! () {
        return !( pointer == nullptr );
    }
      // not operator
};
}
}

#endif