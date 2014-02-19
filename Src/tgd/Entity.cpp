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

std::bitset<32> tgd::Entity::retrieveAllProperties()
{

}

std::shared_ptr<tgd::BaseProperty> tgd::Entity::accessProperty(Properties::ID id)
{
}
