#include <controllers/PlayerController.hpp>
#include <SFML/Window/Keyboard.hpp>

PlayerController::PlayerController(int id, int eID)
: Controller(id, eID)
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

void PlayerController::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

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

int PlayerController::getEntityID()
{
    return Controller::getEntityID();
}

void PlayerController::setVelocity(sf::Vector2f moveVector)
{
    mSprite->move(moveVector);
}
