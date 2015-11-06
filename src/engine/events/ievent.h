// ievent.h
// Payload for messaging from a dispatcher to listeners

#ifndef IEVENT_H
#define IEVENT_H

#include <string>

namespace StevensDev
{
namespace sgde
{
class IEvent
{
  private:
    std::string type;
  public:
      // CONSTRUCTORS //
    IEvent();
      // default constructor
    IEvent( IEvent& otherEvent );
      // copy constructor
    ~IEvent();
      // destructor
      // FREE OPERATORS //
    IEvent& operator=( IEvent& otherEvent );
      // assignment operator
      // ACCESSORS //
    const std::string type() const;
      // String or enum (if you want) to provide info
      // MUTATORS //
    void setType( std::string newType );
};
}
}

#endif