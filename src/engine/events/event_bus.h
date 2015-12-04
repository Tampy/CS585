// event_bus.h
// Singleton wrapper around an EventDispatcher instance

#ifndef EVENT_BUS_H
#define EVENT_BUS_H

#include "event_dispatcher.h"

namespace StevensDev
{
namespace sgde
{
class EventBus : public EventDispatcher
{
  private:
      // CONSTRUCTORS //
    EventBus();
      // default constructor
    EventBus( EventBus& otherBus );
      // copy constructor
      // FREE OPERATORS //
    EventBus& operator=( EventBus& otherBus );
      // assignment operator
  public:
    ~EventBus();
    static EventBus& inst();
};
}
}
#endif