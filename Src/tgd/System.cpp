#include <tgd/System.hpp>
#include <iostream>


tgd::System::System(TextureHolder& textures, sf::RenderTarget& target)
: controllerMap()
, mRenderControllers()
, mEntityCount(0)
, mEntities()
, textureHolder(textures)
, mTarget(target)

{
    //textureHolder = textures;
    //mTarget = target;
}

tgd::System::~System()
{

}

/*template <typename T>
void tgd::System::createEntity()
{
    T entity = new T(mEntityCount);
    T *entPtr = &entity;
    registerEntity(entity);
    mEntityCount++;m
}

void tgd::System::registerEntity(std::shared_ptr<Entity> entity)
{
    //at some point you might want to check for empty portions of the list (ie if an entity is destroyed)

    mEntities.insert(std::pair<unsigned int, std::shared_ptr<Entity>>(mEntityCount, entity));
    checkProperties(entity->getEntityID());

}*/

void tgd::System::update(sf::Time dt)
{

}

void tgd::System::draw()
{
    //access the player entity directly and access the visible property to draw directly. for testing only
    for(auto itr = mRenderControllers.begin(); itr != mRenderControllers.end(); ++itr)
    {
        (*itr)->draw(mTarget);
    }
}

void tgd::System::checkProperties(int id)
{
    int propertyMask = mEntities[id]->retrieveAllProperties();
    std::cout << "Player prop mask in System::checkProperties: " << propertyMask << std::endl;
}

void tgd::System::assignControllers(int id)
{

}

template <typename T>
void tgd::System::createFactory(int id)
{

}

std::shared_ptr<tgd::Entity> tgd::System::fetchEntity(int eID)
{
    return mEntities[eID];
}


