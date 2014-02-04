
#include <Camera.hpp>

Camera::Camera(World& world, tgd::System& system, sf::RenderTarget& target)
: mWorld(world)
, mWorldBounds()
, mWorldView(target.getDefaultView())
, mPlayerSprite(nullptr)
, mSystem(system)
, mOutputTarget(target)
, mTargetSet(false)
, mVLimit(192.0f)
, mHLimit(256.0f)
, mNewCenter(0,0)
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
        mNewCenter = sf::Vector2f(0,0);


        if(mPlayerSprite->getPosition().x > mWorldView.getCenter().x + mHLimit)
        {
            mNewCenter.x = 5;
        }

        if(mPlayerSprite->getPosition().x < mWorldView.getCenter().x - mHLimit)
        {
            mNewCenter.x = -5;
        }
        if(mPlayerSprite->getPosition().y > mWorldView.getCenter().y + mVLimit)
        {
            mNewCenter.y = 5;
        }
        if(mPlayerSprite->getPosition().y < mWorldView.getCenter().y - mVLimit)
        {
            mNewCenter.y = -5;
        }

        //check to see that the view doesn't go out of bounds
        sf::Vector2f viewCenter = mWorldView.getCenter();
        if(viewCenter.x - (mHLimit * 2) + mNewCenter.x <= mWorldBounds.left
           || viewCenter.x + (mHLimit * 2) + mNewCenter.x >= mWorldBounds.width)
        {
            mNewCenter.x = 0;

        }
        if(viewCenter.y - (mVLimit *2) + mNewCenter.y <= mWorldBounds.top
           || viewCenter.y + (mVLimit *2) + mNewCenter.y >= mWorldBounds.height)
        {
            mNewCenter.y = 0;
        }

        //finally move the view
         mWorldView.move(mNewCenter);



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
