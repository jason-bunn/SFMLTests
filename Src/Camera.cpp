
#include <Camera.hpp>

Camera::Camera(World& world, tgd::System& system, sf::RenderTarget& target)
: mWorld(world)
, mWorldBounds()
, mWorldView()
, mPlayerSprite(nullptr)
, mSystem(system)
, mOutputTarget(target)
{

    start();
}

Camera::~Camera()
{
    delete mPlayerSprite;
}

void Camera::start()
{
    mWorldBounds = mWorld.getWorldBounds();
    std::cout << mWorldBounds.width << " " << mWorldBounds.height << std::endl;
}

void Camera::setWorldPointer(World& world)
{

}

void Camera::setPlayerPointer()
{

}

void Camera::update(sf::Time dt)
{

}
