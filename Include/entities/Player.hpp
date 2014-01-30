#ifndef ENTITIES_PLAYER_HPP
#define ENTITIES_PLAYER_HPP

#include <tgd/Entity.hpp>
#include <tgd/Property.hpp>
#include <tgd/PropertyIdentifiers.hpp>



class Player : public Entity
{
public:
                            Player(int id);
    template<typename T>
    void                    setProperty(Properties::ID id, T propValue);
    bool                    hasProperty(Properties::ID);
    virtual int             retrieveAllProperties();
    virtual int             getEntityID();
    bool                    isAlive() const;



private:

    std::vector<Property>   mProperties;
    bool                    mIsAlive;
};

#endif // ENTITIES_PLAYER_HPP
