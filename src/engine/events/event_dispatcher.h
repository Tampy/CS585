// event_dispatcher.h
// Re-entrant wrapper around an event broadcasting system

#ifndef EVENT_DISPATCHER_H
#define EVENT_DISPATCHER_H

#include <containers/dynamic_array.h>
#include <functional>
#include "ievent.h"
#include <scene/itickable.h>
#include <string>

namespace StevensDev
{
namespace sgde
{
class EventDispatcher : public sgds::ITickable
{
  private:
    sgdc::DynamicArray< std::function<void( const IEvent& )>* > listeners;
    sgdc::DynamicArray< std::function<void( const IEvent& )>* > listenersToAdd;
    sgdc::DynamicArray< std::function<void( const IEvent& )>* > listenersToRemove;
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
    void preTick();
    void tick( float dtS );
    void postTick();
};
}
}

#endif