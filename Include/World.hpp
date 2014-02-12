#ifndef WORLD_HPP
#define WORLD_HPP

#include <ResourceHolder.hpp>
#include <ResourceIdentifiers.hpp>
#include <tmx/MapLoader.h>
#include <tgd/System.hpp>

#include <events/EventRouter.hpp>

#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/View.hpp>


//Forward Declaration
namespace sf
{
    class RenderTarget;

}
class World : private sf::NonCopyable
{
public:
                                World(sf::RenderTarget& outputTarget, FontHolder& fonts, Events::EventRouter* eventRouter);
    void                        update(sf::Time dt);
    void                        draw();
    sf::FloatRect              getWorldBounds();

    void                        cleanup();

public:
    sf::Clock                   mClock;
    tmx::MapLoader              mMapLoader;

private:

    sf::RenderTarget&           mTarget;
    //sf::View                    mWorldView;
    sf::FloatRect               mWorldBounds;
    //sf::Vector2f                mSpawnPosition;
    FontHolder&                 mFonts;

    Events::EventRouter*        mEventRouter;

};
#endif // WORLD_HPP
