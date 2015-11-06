// event_dispatcher.h
// Re-entrant wrapper around an event broadcasting system

#ifndef EVENT_DISPATCHER_H
#define EVENT_DISPATCHER_H

#include <functional>
#include "ievent.h"
#include <string>

namespace StevensDev
{
namespace sgde
{
class EventDispatcher : public ITickable
{
  public:
      // CONSTRUCTORS //
    EventDispatcher();
      // default constructor
    EventDispatcher( EventDispatcher& otherEvent );
      // copy constructor
    ~EventDispatcher();
      // destructor
      // FREE OPERATORS //
    EventDispatcher& operator=( EventDispatcher& otherEvent );
      // assignment operator
    void add( const std::string& type, std::function<void( const IEvent& )>* listener );
    void remove( const std::string& type, std::function<void( const IEvent& )>* listener );
    void dispatch( const IEvent& );
      //  called as part of tick, synchronous
};
}
}

#endif