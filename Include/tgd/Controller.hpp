#ifndef TGD_CONTROLLER_HPP
#define TGD_CONTROLLER_HPP

#include <SFML/Graphics/RenderTarget.hpp>
namespace tgd
{
   class Controller
    {
    public:
                            Controller(int id, int eID);
        virtual             ~Controller();
        virtual int         getID();
        virtual int         getEntityID();
        virtual void        draw(sf::RenderTarget& target) = 0;

    private:
        int                 mID;
        int                 mEID;
    };
}

#endif // TGD_CONTROLLER_HPP
