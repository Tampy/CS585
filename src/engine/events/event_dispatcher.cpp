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
	listenersToAdd.~DynamicArray< std::function<void( const IEvent& )>* >();
	listenersToRemove.~DynamicArray< std::function<void( const IEvent& )>* >();
}

EventDispatcher& EventDispatcher::operator=( EventDispatcher& otherEvent )
{
	listeners = otherEvent.listeners;
}

void EventDispatcher::add( const std::string& type, 
    std::function<void( const IEvent& )>* listener )
{
	listenersToAdd.push( listener );
}

void EventDispatcher::remove( const std::string& type, 
    std::function<void( const IEvent& )>* listener )
{
	listenersToRemove.push( listener );
}

void EventDispatcher::dispatch( const IEvent& event )
{
	int i;	
	for( i = 0; i < listeners.getLength(); i++ )
	{
		std::function< void( const IEvent& ) > functionListener = *listeners[i];
		functionListener( event );
	}
}

void EventDispatcher::preTick() {}

void EventDispatcher::tick( float dtS ) {}

void EventDispatcher::postTick()
{
	int i;
	unsigned int addLength = listenersToAdd.getLength();
	unsigned int removeLength = listenersToRemove.getLength();
	for( i = 0; i < addLength; i++ )
	{
		listeners.push( listenersToAdd.pop() );
	}
	for( i = 0; i < removeLength; i++ ) {
		//listeners.removeByValue( listenersToRemove.pop() );
	}
}
    
}
}