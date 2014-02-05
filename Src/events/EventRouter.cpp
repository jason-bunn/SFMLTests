#include <events/EventRouter.hpp>

Events::EventRouter::EventRouter()
: mRegisteredReceivers()
{

}

Events::EventRouter::~EventRouter()
{

}

void Events::EventRouter::Register(std::string id, IReceiver* receiver)
{
    //if the event type is found, push it to the receiver vector
    //use hash function to convert string to size_t
    std::hash<std::string> hash_fn;
    std::size_t str_hash = hash_fn(id);
    auto itr = mRegisteredReceivers.find(str_hash);
    if(itr != mRegisteredReceivers.end())
    {
        itr->second.push_back(receiver);
    }//otherwise create the key
    else
    {
        std::vector<IReceiver*> newVector;
        newVector.push_back(receiver);
        mRegisteredReceivers.emplace(str_hash, newVector);
    }
}

void Events::EventRouter::UnRegister(std::string id, IReceiver* receiver)
{
    //this is potential the least efficient way of handling this because of the vector class

    //use hash function to convert string to size_t
    std::hash<std::string> hash_fn;
    std::size_t str_hash = hash_fn(id);

    for(auto itr = mRegisteredReceivers[str_hash].begin(); itr != mRegisteredReceivers[str_hash].end(); ++itr)
    {
        if(*itr == receiver)
        {
            mRegisteredReceivers[str_hash].erase(itr);
        }
    }
}

void Events::EventRouter::UnRegister(IReceiver* receiver)
{
    //again, this can be potentially time consuming if the number of registered events and receivers is large
    for(auto itr = mRegisteredReceivers.begin(); itr != mRegisteredReceivers.end(); ++itr)
    {
        for(auto vitr = itr->second.begin(); vitr != itr->second.end(); vitr++)
        {
            if (*vitr == receiver)
            {
                itr->second.erase(vitr);
            }
        }
    }

}

void Events::EventRouter::Broadcast(std::string id, Event* e)
{
    //this could potentially be improved by using std::function as the receiver objects, though I have no idea how

    //use hash function to convert string to size_t
    std::hash<std::string> hash_fn;
    std::size_t str_hash = hash_fn(id);

    for(auto itr = mRegisteredReceivers[str_hash].begin(); itr != mRegisteredReceivers[str_hash].end(); ++itr)
    {
        (*itr)->OnReceive(id, e);
    }
}
