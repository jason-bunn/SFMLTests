#ifndef ENTITIES_PLAYER_HPP
#define ENTITIES_PLAYER_HPP

#include <tgd/Entity.hpp>
#include <tgd/Property.hpp>
#include <tgd/PropertyIdentifiers.hpp>

#include <vector>

class Player : public tgd::Entity
{
public:
                            Player(int id);
                            ~Player();
    bool                    hasProperty(Properties::ID);
    int             retrieveAllProperties();
    int             getEntityID();
    bool                    isAlive() const;

    void                    initializeProperties();

private:

    std::vector<tgd::BaseProperty>   mProperties;
    bool                    mIsAlive;
    int                     mPropMask;
};

#endif // ENTITIES_PLAYER_HPP
