#include <World.hpp>

#include <entities/Player.hpp>

#include <SFML/Graphics/RenderTarget.hpp>

#include <iostream>



World::World(sf::RenderTarget& outputTarget, FontHolder& fonts, Events::EventRouter* eventRouter)
: mTarget(outputTarget)
, mFonts(fonts)
//, mWorldView(outputTarget.getDefaultView())
, mMapLoader("Media/Maps/")
, mWorldBounds(0.0f,0.0f, 1920, 1920)
//, mSpawnPosition(mWorldView.getSize().x / 2.0f, mWorldView.getSize().y / 2.0f)
, mEventRouter(eventRouter)
{
    mMapLoader.Load("TestArea.tmx");
    mClock.restart();


    //mySystem.createEntity<Player>();
}

void World::update(sf::Time dt)
{

}

void World::draw()
{
    mMapLoader.Draw(mTarget, 2);

    //mySystem.draw(mTarget);
}

sf::FloatRect World::getWorldBounds()
{
    return mWorldBounds;
}

//sf::RenderTarget& World::getRenderTarget()
//{
 ///   return mTarget;
//}
