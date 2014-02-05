#ifndef EVENTS_EVENTROUTER_HPP
#define EVENTS_EVENTROUTER_HPP

#include <events/IEventBus.hpp>
#include <events/IReceiver.hpp>
#include <events/Event.hpp>

#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Events
{
    class EventRouter : public IEventBus
    {
    public:
                            EventRouter();
        virtual void        Register(std::string id, IReceiver* receiver);
        virtual void        UnRegister(std::string id, IReceiver* receiver);
        virtual void        UnRegister(IReceiver* receiver);
        virtual void        Broadcast(std::string id, Event* e);
        virtual             ~EventRouter();

    public:
        std::unordered_map<size_t, std::vector<IReceiver*>> mRegisteredReceivers;
    };
}
#endif // EVENTS_EVENTROUTER_HPP
