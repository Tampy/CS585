// ievent.cpp
// Payload for messaging from a dispatcher to listeners

#include "ievent.h"

namespace StevensDev
{
namespace sgde
{

IEvent::IEvent() { }

IEvent::IEvent( IEvent& otherEvent )
{
	eventType = otherEvent.type();
}

IEvent::~IEvent() { }

IEvent& IEvent::operator=( IEvent& otherEvent )
{
	eventType = otherEvent.type();
}

const std::string IEvent::type() const
{
	return eventType;
}

void IEvent::setType( std::string newType )
{
	eventType = newType;
}

}
}