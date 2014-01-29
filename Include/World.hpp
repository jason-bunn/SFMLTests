#ifndef WORLD_HPP
#define WORLD_HPP

#include <ResourceHolder.hpp>
#include <ResourceIdentifiers.hpp>
#include <tmx/MapLoader.h>

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/View.hpp>


//Forward Declaration
namespace sf
{
    class RenderTarget;

}
class World : private sf::NonCopyable
{
public:
                                World(sf::RenderTarget& outputTarget, FontHolder& fonts);
    void                        update(sf::Time dt);
    void                        draw();

private:

    sf::RenderTarget&           mTarget;
    sf::View                    mWorldView;
    sf::FloatRect               mWorldBounds;
    sf::Vector2f                mSpawnPosition;

    FontHolder&                 mFonts;
    tmx::MapLoader              mMapLoader;

};
#endif // WORLD_HPP
