#include <entities/Player.hpp>
#include <iostream>


Player::Player(int id, TextureHolder& textures)
: Entity(id)
, mProperties()
, mIsAlive(true)
, mTextures(textures)
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
    std::cout << "Assigning player texture" << std::endl;


    //create sprite and assign it to a property
    sf::Sprite mySprite;
    mySprite.setTexture(mTextures.get(Textures::PlayerBoy));
    mySprite.setTextureRect(sf::IntRect(0,0,50, 66));
    centerOrigin(mySprite);
    mySprite.setPosition(100,100);

    auto temp = std::make_shared<tgd::Property<sf::Sprite>>(Properties::Visible, mySprite);

    sf::Vector2f tempPos(0,0);

    auto pos = std::make_shared<tgd::Property<sf::Vector2f>>(Properties::Position, tempPos);

    mProperties.push_back(temp);
    mProperties.push_back(pos);
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



