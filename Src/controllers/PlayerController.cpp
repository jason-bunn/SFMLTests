#include <controllers/PlayerController.hpp>
#include <SFML/Window/Keyboard.hpp>

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
    handleRealtimeInput();

    setVelocity(mMoveVector);
}

void PlayerController::handleRealtimeInput()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        mMoveVector.y += -5;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {

        mMoveVector.y += 5;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {

        mMoveVector.x += 5;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {

        mMoveVector.x += -5;
    }
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
