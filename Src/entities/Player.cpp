#include <entities/Player.hpp>
#include <iostream>


Player::Player(int id)
: Entity(id)
{
    mPropMask = Properties::PC | Properties::Visible;
    std::cout << "Player propmask in constructor: " << mPropMask << std::endl;
}

Player::~Player()
{

}

void Player::initializeProperties()
{

}

bool Player::hasProperty(Properties::ID id)
{

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

