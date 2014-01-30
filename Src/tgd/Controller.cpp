#include <tgd/Controller.hpp>

tgd::Controller::Controller(int id)
: mID(id)
{

}

int tgd::Controller::getID()
{
    return mID;
}

