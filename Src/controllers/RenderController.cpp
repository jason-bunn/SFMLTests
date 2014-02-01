#include <controllers/RenderController.hpp>

RenderController::RenderController(int id, int eID, tgd::System& mSystem)
: Controller(id, eID)
, mBodySprite(nullptr)
{
    retrieveProperties(eID, mSystem);
}

RenderController::~RenderController()
{
    delete mBodySprite;
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
    auto sprPtr = std::dynamic_pointer_cast<tgd::Property<sf::Sprite>>(tempEnt->accessProperty(Properties::Visible));
    mBodySprite = sprPtr->getValue();
}

void RenderController::draw(sf::RenderTarget& target)
{
    target.draw(*mBodySprite);
}

