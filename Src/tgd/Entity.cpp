#include <tgd/Entity.hpp>

tgd::Entity::Entity(int id)
: mID(id)
{

}

tgd::Entity::~Entity()
{

}

int tgd::Entity::getEntityID()
{
    return mID;
}

int tgd::Entity::retrieveAllProperties()
{

}
