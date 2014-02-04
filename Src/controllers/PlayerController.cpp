#include <controllers/PlayerController.hpp>
#include <SFML/Window/Keyboard.hpp>

PlayerController::PlayerController(int id, int eID, tgd::System& mSystem)
: Controller(id, eID)
, mMoveVector()
, mSprite(nullptr)
{
    retrieveProperties(eID, mSystem);
    mMoveVector = sf::Vector2f(0,0);
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
    mMoveVector = sf::Vector2f(0,0);

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

void PlayerController::retrieveProperties(int eID, tgd::System& system)
{
    std::shared_ptr<tgd::Entity> tempEnt;
    tempEnt = system.fetchEntity(eID);
    auto sprPtr = std::dynamic_pointer_cast<tgd::Property<sf::Sprite>>(tempEnt->accessProperty(Properties::Visible));
    mSprite = sprPtr->getValue();
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
