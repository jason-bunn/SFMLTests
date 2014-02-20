#include <controllers/RenderController.hpp>

extern sf::Clock mGameClock;

RenderController::RenderController(int id, int eID, tgd::System& mSystem)
: Controller(id, eID)
, mBodySprite()
, mPreviousPosition()
, mHFrame(0)
, mVFrame(0)
, mCurrentDirection(Down)
{
    retrieveProperties(eID, mSystem);
}

RenderController::~RenderController()
{

}

int RenderController::getID()
{
    return Controller::getID();
}

int RenderController::getEntityID()
{
    return Controller::getEntityID();
}

void RenderController::retrieveProperties(int eID, tgd::System& system)
{
    std::shared_ptr<tgd::Entity> tempEnt;
    tempEnt = system.fetchEntity(eID);

    //get sprite pointer
    auto sprPtr = std::dynamic_pointer_cast<tgd::Property<sf::Sprite>>(tempEnt->accessProperty(Properties::Visible));
    mBodySprite = sprPtr->getValue();
    mPreviousPosition = mBodySprite->getPosition();
}

void RenderController::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

    target.draw(*mBodySprite, states);
}

void RenderController::update(sf::Time dt)
{
    sf::Vector2f currentPosition = mBodySprite->getPosition();
    if(currentPosition.y < mPreviousPosition.y)
    {
        //sprite moved up
        mBodySprite->setTextureRect(sf::IntRect(300, 100 * mVFrame, 50,66));
        mCurrentDirection = Up;
    }
    if(currentPosition.y > mPreviousPosition.y)
    {
        //sprite moved down
        mBodySprite->setTextureRect(sf::IntRect(200, 100 * mVFrame, 50,66));
        mCurrentDirection = Down;
    }
    if(currentPosition.x < mPreviousPosition.x)
    {
        //sprite moved left
        mBodySprite->setTextureRect(sf::IntRect(0, 100 * mHFrame, 50,66));
        mCurrentDirection = Left;
    }
    if(currentPosition.x > mPreviousPosition.x)
    {
        //sprite moved right
        mBodySprite->setTextureRect(sf::IntRect(100, 100 * mHFrame, 50,66));
        mCurrentDirection = Right;
    }

    //if the player has stopped moving, down play animations
    if(mPreviousPosition == currentPosition)
        {
            mHFrame = 0;
            mVFrame = 0;
            switch(mCurrentDirection)
            {
            case Up:
                mBodySprite->setTextureRect(sf::IntRect(300, 100 * mVFrame, 50,66));
                break;
            case Down:
                 mBodySprite->setTextureRect(sf::IntRect(200, 100 * mVFrame, 50,66));
                break;
            case Left:
                mBodySprite->setTextureRect(sf::IntRect(0, 100 * mHFrame, 50,66));
                break;
            case Right:
                mBodySprite->setTextureRect(sf::IntRect(100, 100 * mHFrame, 50,66));
                break;

            default:
                break;
            }
        }
    //switch animation frame after animation frame timer has elasped
    if(mGameClock.getElapsedTime() > mFrameTimer)
    {
        //change the animation frame
        switch (mCurrentDirection)
        {
        case Up:
        case Down:
            mVFrame++;
            break;
        case Left:
        case Right:
            mHFrame++;
            break;

        default:
            break;

        }

        if(mHFrame > 6)
        {
            mHFrame = 1;
        }
        if(mVFrame > 4)
        {
            mVFrame = 1;
        }


        mPreviousPosition = mBodySprite->getPosition();

        mFrameTimer = mGameClock.getElapsedTime() + sf::seconds(0.1f);
    }



}

std::bitset<32> RenderController::getRequirements()
{

    return (Properties::Position | Properties::Velocity);

}

