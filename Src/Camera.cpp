
#include <Camera.hpp>

Camera::Camera(World& world, tgd::System& system, sf::RenderTarget& target, Events::EventRouter* eventRouter)
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
, mEventRouter(eventRouter)
{


    start();
}

Camera::~Camera()
{
    delete mPlayerSprite;
}

void Camera::start()
{

    registerListeners();

    mWorldBounds = mWorld.getWorldBounds();
    //std::cout << mWorldBounds.width << " " << mWorldBounds.height << std::endl;
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
            mNewCenter.x = 200;
        }

        if(mPlayerSprite->getPosition().x < mWorldView.getCenter().x - mHLimit)
        {
            mNewCenter.x = -200;
        }
        if(mPlayerSprite->getPosition().y > mWorldView.getCenter().y + mVLimit)
        {
            mNewCenter.y = 200;
        }
        if(mPlayerSprite->getPosition().y < mWorldView.getCenter().y - mVLimit)
        {
            mNewCenter.y = -200;
        }

        //check to see that the view doesn't go out of bounds
        sf::Vector2f viewCenter = mWorldView.getCenter();
        if(viewCenter.x - (mHLimit * 1.5f) + mNewCenter.x <= mWorldBounds.left
           || viewCenter.x + (mHLimit * 1.5f) + mNewCenter.x >= mWorldBounds.width)
        {
            mNewCenter.x = 0;

        }
        if(viewCenter.y - (mVLimit * 1.5f) + mNewCenter.y <= mWorldBounds.top
           || viewCenter.y + (mVLimit * 1.5f) + mNewCenter.y >= mWorldBounds.height)
        {
            mNewCenter.y = 0;
        }

        mNewCenter *= dt.asSeconds();

        //finally move the view
         mWorldView.move(mNewCenter);

        sf::Vector2f viewSize(mWorldView.getSize());
        //mWorld.mMapLoader.UpdateQuadTree(mWorldView.getViewport());
        mWorld.mMapLoader.UpdateQuadTree(sf::FloatRect(mWorldView.getCenter().x - viewSize.x * 0.5f,
                                                       mWorldView.getCenter().y - viewSize.y * 0.5f,
                                                       viewSize.x ,
                                                       viewSize.y ));
    }

}

void Camera::draw()
{
    mOutputTarget.setView(mWorldView);
    mWorld.mMapLoader.Draw(mOutputTarget, 0);
    mWorld.mMapLoader.Draw(mOutputTarget, 1);
    //mWorld.mMapLoader.Draw(mOutputTarget, tmx::MapLayer::Debug);
}

bool Camera::isTargetSet()
{
    return mTargetSet;
}

void Camera::registerListeners()
{
    mEventRouter->Register("playerCreated", [this] () {
                            this->setPlayerPointer();
                           });
}
