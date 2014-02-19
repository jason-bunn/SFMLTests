#ifndef CONTROLLERS_RENDERCONTROLLER_HPP
#define CONTROLLERS_RENDERCONTROLLER_HPP

#include <tgd/Entity.hpp>
#include <tgd/Property.hpp>
#include <tgd/PropertyIdentifiers.hpp>
#include <tgd/System.hpp>
#include <tgd/Controller.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Clock.hpp>
#include <memory>

class RenderController : public tgd::Controller, public sf::Drawable
{
public:
    enum Direction
    {
        Up,
        Down,
        Left,
        Right
    };

public:
                    RenderController(int id, int eID, tgd::System& mSystem);
                    ~RenderController();
    virtual int     getID();
    virtual int     getEntityID();

    void            retrieveProperties(int eID, tgd::System& mSystem);
    virtual void    draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void    update(sf::Time dt);
    static std::bitset<8> getRequirements();

public:


private:
    int             mID;
    int             mEID;
    sf::Sprite*     mBodySprite;
    sf::Vector2f    mPreviousPosition;
    sf::Time        mFrameTimer;
    int             mHFrame;
    int             mVFrame;
    Direction       mCurrentDirection;

};
#endif // CONTROLLERS_RENDERCONTROLLER_HPP
