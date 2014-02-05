#ifndef EVENTS_IRECEIVER_HPP
#define EVENTS_IRECEIVER_HPP

#include <events/Event.hpp>

#include <functional>
#include <string>

namespace Events
{
    class IReceiver
    {
    public:
        virtual void        OnReceive(std::string id, Event* e) = 0;
        virtual             ~IReceiver();
    };
}
#endif // EVENTS_IRECEIVER_HPP
