// ievent.cpp
// Payload for messaging from a dispatcher to listeners

#include "ievent.h"

namespace StevensDev
{
namespace sgde
{

IEvent::IEvent()
{

}
IEvent::IEvent( IEvent& otherEvent )
{

}
IEvent::~IEvent()
{

}
IEvent& IEvent::operator=( IEvent& otherEvent )
{

}
const std::string IEvent::type() const
{

}

};
}
}