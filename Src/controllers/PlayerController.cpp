#include <controllers/PlayerController.hpp>

PlayerController::PlayerController(int id)
: Controller(id)
, mMoveVector()
, mSprite(nullptr)
{

}

PlayerController::~PlayerController()
{
    delete mSprite;
}

void PlayerController::update(sf::Time dt)
{

}

void PlayerController::handleRealtimeInput()
{

}

int PlayerController::getRequirements()
{

    //this will return the requirements for the controller
    return 0;
}

int PlayerController::getID()
{
    return Controller::getID();
}

void PlayerController::setVelocity(sf::Vector2f moveVector)
{
    mSprite->move(moveVector);
}
