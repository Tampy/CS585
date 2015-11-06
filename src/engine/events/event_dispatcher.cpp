// event_dispatcher.cpp
// Re-entrant wrapper around an event broadcasting system

#include "event_dispatcher.h"

namespace StevensDev
{
namespace sgde
{

EventDispatcher::EventDispatcher()
{

}

EventDispatcher::EventDispatcher( EventDispatcher& otherEvent )
{

}

EventDispatcher::~EventDispatcher()
{

}

EventDispatcher& EventDispatcher::operator=( EventDispatcher& otherEvent )
{

}

void EventDispatcher::add( const std::string& type, 
    std::function<void( const IEvent& )>* listener )
{

}

void EventDispatcher::remove( const std::string& type, 
    std::function<void( const IEvent& )>* listener )
{

}

void EventDispatcher::dispatch( const IEvent& )
{

}
    
};
}
}