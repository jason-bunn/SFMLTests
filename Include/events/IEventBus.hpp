#ifndef EVENTS_IEVENTBUS_HPP
#define EVENTS_IEVENTBUS_HPP

#include <events/IReceiver.hpp>
#include <events/Event.hpp>

#include <functional>
#include <string>

namespace Events
{
    class IEventBus
    {
    public:
        typedef std::function<void(void)>   DesiredEvent;

        virtual void        Register(std::string id, DesiredEvent desiredEvent) = 0;
        //virtual void        UnRegister(std::string id, IReceiver* receiver) = 0;
        //virtual void        UnRegister(IReceiver* receiver) = 0;
        virtual void        Broadcast(std::string id) = 0;
        virtual             ~IEventBus();
    };
}

#endif // EVENTS_IEVENTBUS_HPP


