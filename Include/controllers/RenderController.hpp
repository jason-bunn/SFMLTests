#ifndef CONTROLLERS_RENDERCONTROLLER_HPP
#define CONTROLLERS_RENDERCONTROLLER_HPP

#include <tgd/Entity.hpp>
#include <tgd/Property.hpp>
#include <tgd/PropertyIdentifiers.hpp>
#include <tgd/System.hpp>
#include <tgd/Controller.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include <memory>

class RenderController : public tgd::Controller
{
public:
                    RenderController(int id, int eID, tgd::System& mSystem);
                    ~RenderController();
    virtual int     getID();
    virtual int     getEntityID();

    void            retrieveProperties(int eID, tgd::System& mSystem);
    void            draw(sf::RenderTarget& target);

    private:
    int             mID;
    int             mEID;
    sf::Sprite*     mBodySprite;


};
#endif // CONTROLLERS_RENDERCONTROLLER_HPP
