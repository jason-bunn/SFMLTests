#ifndef ENTITIES_PLAYER_HPP
#define ENTITIES_PLAYER_HPP

#include <tgd/Property.hpp>
#include <tgd/PropertyIdentifiers.hpp>



class Player
{
public:
                            Player(int id);
    template<typename T>
    void                    setProperty(Properties::ID id, T propValue);
    bool                    hasProperty(Properties::ID);
    int                     retrieveAllProperties();
    int                     getEntityID();
    bool                    isAlive() const;
private:
    int                     mID;
    std::vector<Property>   mProperties;
    bool                    mIsAlive;
};

#endif // ENTITIES_PLAYER_HPP
