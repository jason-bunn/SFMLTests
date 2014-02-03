#include <tgd/Controller.hpp>

tgd::Controller::Controller(int id, int eID)
: mID(id)
, mEID(eID)
{

}

tgd::Controller::~Controller()
{

}

int tgd::Controller::getID()
{
    return mID;
}

int tgd::Controller::getEntityID()
{
    return mEID;
}

void tgd::Controller::draw(sf::RenderTarget& target, sf::RenderStates states)
{

}

