#include <tgd/System.hpp>
#include <iostream>


tgd::System::System(TextureHolder& textures, sf::RenderTarget& target)
: controllerMap()
//, mRenderControllers()
, mEntityCount(0)
, mEntities()
, textureHolder(textures)
, mTarget(target)

{
    //textureHolder = textures;
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
    for(auto itr = controllerMap.begin(); itr != controllerMap.end(); ++itr)
    {
        for(auto iitr = itr->second.begin(); iitr != itr->second.end(); ++iitr)
        {
            mTarget.draw(*(*iitr));
        }
    }
}

void tgd::System::checkProperties(int id)
{
    int propertyMask = mEntities[id]->retrieveAllProperties();
    std::bitset<32> newBits(propertyMask);
    //now we need to sort through the properties to see what controllers need to be assigned
    //convert to bitset first, then start checking property requirements

    if(newBits.any())
    {
        assignControllers(id, newBits);
    }

}

void tgd::System::assignControllers(int id, std::bitset<32> newBits)
{
    if(newBits[0] == 1 && newBits[1] == 1 && newBits[3] == 1 && newBits[4] == 1)
    {
        //these should be all requirements for the player controller, also includes render controller
        //NOTE: shared or unique pointers will have to be used in the controller vector
       std::vector<std::shared_ptr<Controller>> newControllers;

       auto PC = std::make_shared<PlayerController>(0, id);
       auto RC = std::make_shared<RenderController>(1, id, *(this));

       newControllers.push_back(PC);
       newControllers.push_back(RC);

       controllerMap.emplace(id, newControllers);
       std::cout << "Player Controller and Render Controller assigned" << std::endl;
    }
}

template <typename T>
void tgd::System::createFactory(int id)
{

}

std::shared_ptr<tgd::Entity> tgd::System::fetchEntity(int eID)
{
    return mEntities[eID];
}


