#ifndef ENTITIES_PLAYER_HPP
#define ENTITIES_PLAYER_HPP

#include <tgd/Entity.hpp>
#include <tgd/Property.hpp>
#include <tgd/PropertyIdentifiers.hpp>
#include <Utility.hpp>

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

#include <vector>
#include <memory>
#include <bitset>

class Player : public tgd::Entity
{
public:
                            Player(int id);
                            ~Player();
    bool                    hasProperty(Properties::ID);
    int                     retrieveAllProperties();
    int                     getEntityID();
    bool                    isAlive() const;


    void                    initializeProperties();

    virtual std::shared_ptr<tgd::BaseProperty>  accessProperty(Properties::ID id);

private:

    std::vector<std::shared_ptr<tgd::BaseProperty>>   mProperties;
    bool                    mIsAlive;
    int                     mPropMask;
};

#endif // ENTITIES_PLAYER_HPP
