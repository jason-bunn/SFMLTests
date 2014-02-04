#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <entities/Player.hpp>
#include <World.hpp>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Time.hpp>

#include <iostream>

class Camera
{
public:
                            Camera(World& world, tgd::System& system, sf::RenderTarget& target);
                            ~Camera();

    void                    setWorldPointer(World& world);
    void                    setPlayerPointer();
    void                    update(sf::Time dt);
    void                    draw();

    void                    start();
    bool                    isTargetSet();

private:
    World&                  mWorld;
    tgd::System&            mSystem;
    sf::Sprite*             mPlayerSprite;
    sf::FloatRect          mWorldBounds;
    sf::View                mWorldView;
    sf::RenderTarget&       mOutputTarget;
    bool                    mTargetSet;
    float                   mVLimit;
    float                   mHLimit;
    sf::Vector2f            mNewCenter;
};


#endif // CAMERA_HPP
