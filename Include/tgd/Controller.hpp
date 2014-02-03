#ifndef TGD_CONTROLLER_HPP
#define TGD_CONTROLLER_HPP

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Drawable.hpp>

namespace tgd
{
   class Controller : public sf::Drawable
    {
    public:
                            Controller(int id, int eID);
        virtual             ~Controller();
        virtual int         getID();
        virtual int         getEntityID();
        virtual void        draw(sf::RenderTarget& target, sf::RenderStates states);

    private:
        int                 mID;
        int                 mEID;
    };
}

#endif // TGD_CONTROLLER_HPP
