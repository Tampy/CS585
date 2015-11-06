// event_dispatcher.h
// Re-entrant wrapper around an event broadcasting system

#ifndef EVENT_DISPATCHER_H
#define EVENT_DISPATCHER_H

#include <containers/dynamic_array.h>
#include <functional>
#include "ievent.h"
#include <string>

namespace StevensDev
{
namespace sgde
{
class EventDispatcher : public ITickable
{
  private:
    DynamicArray< std::function<void( const IEvent& )>* > listeners;
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
    void dispatch( const IEvent& event );
      //  called as part of tick, synchronous
};
}
}

#endif