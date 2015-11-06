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
	type = otherEvent.type();
}

IEvent::~IEvent() { }

IEvent& IEvent::operator=( IEvent& otherEvent )
{
	type = otherEvent.type();
}

const std::string IEvent::type() const
{
	return type;
}

void setType( std::string newType )
{
	type = newType;
}

};
}
}