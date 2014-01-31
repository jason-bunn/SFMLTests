#include <World.hpp>

#include <entities/Player.hpp>

#include <SFML/Graphics/RenderTarget.hpp>

#include <iostream>



World::World(sf::RenderTarget& outputTarget, FontHolder& fonts)
: mTarget(outputTarget)
, mFonts(fonts)
, mWorldView(outputTarget.getDefaultView())
, mMapLoader("Media/Maps/")
, mWorldBounds(0.0f,0.0f, 1920, 1920)
, mSpawnPosition(mWorldView.getSize().x / 2.0f, mWorldView.getSize().y / 2.0f)
{
    mMapLoader.Load("TestArea.tmx");
    mClock.restart();


    mySystem.createEntity<Player>();
}

void World::update(sf::Time dt)
{

}

void World::draw()
{
    mTarget.draw(mMapLoader);
    mySystem.draw(mTarget);
}
