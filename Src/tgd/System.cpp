#include <tgd/System.hpp>

tgd::System::System()
: controllerMap()
, mEntityCount(0)
, mEntities()
{

}

tgd::System::~System()
{

}

template <typename T>
void tgd::System::createEntity()
{
    T entity = new T(mEntityCount);
    T *entPtr = &entity;
    registerEntity(entity);
    mEntityCount++;
}

void tgd::System::registerEntity(Entity* entity)
{
    //at some point you might want to check for empty portions of the list (ie if an entity is destroyed)

    mEntities.insert(std::pair<unsigned int, Entity*>(mEntityCount, entity));
    checkProperties(entity->getEntityID());

}

void tgd::System::update(sf::Time dt)
{

}

void tgd::System::draw()
{

}

void tgd::System::checkProperties(int id)
{
    int propertyMask = mEntities[id]->retrieveAllProperties();

}

void tgd::System::assignControllers(int id)
{

}

template <typename T>
void tgd::System::createFactory(int id)
{

}
