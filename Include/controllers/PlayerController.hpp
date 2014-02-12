#ifndef CONTROLLERS_PLAYERCONTROLLER_HPP
#define CONTROLLERS_PLAYERCONTROLLER_HPP

#include <tgd/Entity.hpp>
#include <tgd/PropertyIdentifiers.hpp>
#include <tgd/Controller.hpp>
#include <tgd/System.hpp>
#include <tmx/MapObject.h>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>

#include <memory>



class PlayerController : public tgd::Controller
{
public:
                        PlayerController(int id, int eID, tgd::System& mSystem, tmx::MapLoader* mapLoader);
                        ~PlayerController();

    void                update(sf::Time dt);
    void                handleRealtimeInput();
    int                 getRequirements();

    virtual int         getID();
    virtual int         getEntityID();
    void                retrieveProperties(int eID, tgd::System& mSystem);

    virtual void        draw(sf::RenderTarget&, sf::RenderStates states) const;

    void                setVelocity(sf::Vector2f moveVector, sf::Time dt);
    std::bitset<8>         checkCollisions();

public:
    sf::Vector2f        collisionPoints[8] {}; //represents four corners of sprite

private:
    sf::Vector2f        mMoveVector;
    sf::Sprite*         mSprite;
    tmx::MapLoader*     mMapPtr;
    std::bitset<8>         mColFlag;
};
#endif // CONTROLLERS_PLAYERCONTROLLER_HPP
