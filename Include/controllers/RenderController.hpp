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

#include <memory>

class RenderController : public tgd::Controller, public sf::Drawable
{
public:
                    RenderController(int id, int eID, tgd::System& mSystem);
                    ~RenderController();
    virtual int     getID();
    virtual int     getEntityID();

    void            retrieveProperties(int eID, tgd::System& mSystem);
    virtual void    draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
    int             mID;
    int             mEID;
    sf::Sprite*     mBodySprite;


};
#endif // CONTROLLERS_RENDERCONTROLLER_HPP
