#include <entities/Player.hpp>
#include <iostream>


Player::Player(int id)
: Entity(id)
, mProperties()
, mIsAlive(true)
{
    mPropMask = Properties::PC | Properties::Visible | Properties::Velocity | Properties::Position;
    std::cout << "Player propmask in constructor: " << mPropMask << std::endl;
    initializeProperties();
}

Player::~Player()
{

}

void Player::initializeProperties()
{
    //setup sprite test here, should be moved later to renderer controller
    sf::Texture playerTexture;
    playerTexture.loadFromFile("Media/Images/boy_sheet.png");

    sf::Sprite mySprite;
    mySprite.setTexture(playerTexture);
    mySprite.setTextureRect(sf::IntRect(0,0,50,66));
    centerOrigin(mySprite);
    mySprite.setPosition(50,50);

    mProperties.push_back(std::make_shared<tgd::Property<sf::Sprite>>(Properties::Visible, std::move(mySprite)));
    mProperties.push_back(std::make_shared<tgd::Property<sf::Vector2f>>(Properties::Position, sf::Vector2f(0,0)));
}

std::shared_ptr<tgd::BaseProperty> Player::accessProperty(Properties::ID id)
{

    for(auto itr = mProperties.begin(); itr != mProperties.end(); ++itr)
    {
        if(id == (*itr)->getID())
        {
            return (*itr);
        }
    }
    return nullptr;
}

bool Player::hasProperty(Properties::ID id)
{
    return false;
}

int Player::retrieveAllProperties()
{
    return mPropMask;
}

int Player::getEntityID()
{
    return Entity::mID;
}

bool Player::isAlive() const
{
    return mIsAlive;
}



