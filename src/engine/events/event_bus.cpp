// event_bus.cpp
// Singleton wrapper around an EventDispatcher instance

#include "event_bus.h"

namespace StevensDev
{
namespace sgde
{
EventBus::EventBus() { }

EventBus::EventBus( EventBus& otherBus ) { }

EventBus& EventBus::operator=( EventBus& otherBus ) { }

EventBus::~EventBus() { }

EventBus& EventBus::inst()
{
    static EventBus instance;
    return instance;
}

}
}