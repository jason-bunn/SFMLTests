#ifndef CONTROLLERS_PLAYERCONTROLLER_HPP
#define CONTROLLERS_PLAYERCONTROLLER_HPP

#include <tgd/PropertyIdentifiers.hpp>
#include <tgd/Controller.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>

class PlayerController : public tgd::Controller
{
public:
                        PlayerController(int id);
                        ~PlayerController();

    void                update(sf::Time dt);
    void                handleRealtimeInput();
    int                 getRequirements();

    virtual int         getID();

    void                setVelocity(sf::Vector2f moveVector);
    //sf::Vector2f        getVelocity();

    private:
    sf::Vector2f        mMoveVector;
    sf::Sprite*         mSprite;

};
#endif // CONTROLLERS_PLAYERCONTROLLER_HPP
