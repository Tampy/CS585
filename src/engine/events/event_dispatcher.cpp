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
	listeners = otherEvent.listeners;

}

EventDispatcher::~EventDispatcher()
{
	listeners.~DynamicArray< std::function<void( const IEvent& )>* >();
}

EventDispatcher& EventDispatcher::operator=( EventDispatcher& otherEvent )
{
	listeners = otherEvent.listeners;
}

void EventDispatcher::add( const std::string& type, 
    std::function<void( const IEvent& )>* listener )
{
	listeners.push( listener );
}

void EventDispatcher::remove( const std::string& type, 
    std::function<void( const IEvent& )>* listener )
{
	listeners.removeByValue( listener );
}

void EventDispatcher::dispatch( const IEvent& event )
{
	int i;
	for( i = 0; i < listeners.getLength(); i++ )
	{
		listeners[i]( event );
	}
}

void preTick() {}

void tick( float dtS ) {}

void postTick()
{
	
}
    
};
}
}