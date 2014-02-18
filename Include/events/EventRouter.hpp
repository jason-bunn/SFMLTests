#ifndef EVENTS_EVENTROUTER_HPP
#define EVENTS_EVENTROUTER_HPP

#include <events/IEventBus.hpp>
#include <events/IReceiver.hpp>
#include <events/Event.hpp>

#include <functional>
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

namespace Events
{
    class EventRouter : public IEventBus
    {
    public:
        typedef std::function<void(void)>   DesiredEvent;

                            EventRouter();
        virtual void        Register(std::string id, DesiredEvent desiredEvent);
        //virtual void        UnRegister(std::string id, DesiredEvent desiredEvent);
        //virtual void        UnRegister(DesiredEvent desiredEvent);
        virtual void        Broadcast(std::string id);
        virtual             ~EventRouter();
        void                RemoveAllReceivers();

    public:
        std::unordered_map<size_t, std::vector<DesiredEvent>> mRegisteredReceivers;
    };
}
#endif // EVENTS_EVENTROUTER_HPP
