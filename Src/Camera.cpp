
#include <Camera.hpp>

Camera::Camera(World& world, tgd::System& system, sf::RenderTarget& target)
: mWorld(world)
, mWorldBounds()
, mWorldView(target.getDefaultView())
, mPlayerSprite(nullptr)
, mSystem(system)
, mOutputTarget(target)
, mTargetSet(false)
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
    //setPlayerPointer();

}

void Camera::setWorldPointer(World& world)
{

}

void Camera::setPlayerPointer()
{
    auto tempEnt = mSystem.findEntityByName("Player");
    if(tempEnt == nullptr)
    {
        std::cout << "Entity not found" << std::endl;
    }
    else
    {
        auto sprPtr = std::dynamic_pointer_cast<tgd::Property<sf::Sprite>>(tempEnt->accessProperty(Properties::Visible));
        mPlayerSprite = sprPtr->getValue();
        mTargetSet = true;
        std::cout << "Target Assigned" << std::endl;

    }

}

void Camera::update(sf::Time dt)
{
    if(mTargetSet)
    {

        //mWorldView.setCenter(mPlayerSprite->getPosition());
        mWorldView.setCenter(mPlayerSprite->getPosition());

    }

}

void Camera::draw()
{
    mOutputTarget.setView(mWorldView);
}

bool Camera::isTargetSet()
{
    return mTargetSet;
}
