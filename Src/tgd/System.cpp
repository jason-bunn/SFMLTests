#include <tgd/System.hpp>
#include <iostream>


tgd::System::System(TextureHolder& textures, sf::RenderTarget& target, Events::EventRouter* eventRouter, tmx::MapLoader* mapLoader)
: controllerMap()
//, mRenderControllers()
, mEntityCount(0)
, mControllerCount(0)
, mEntities()
, textureHolder(textures)
, mTarget(target)
, mEntityTags()
, mPlayerCreated(false)
, mEventRouter(eventRouter)
, mMapPtr(mapLoader)
, mFactories()
{
    //textureHolder = textures;
    createFactory<PlayerController>(this);
    createFactory<RenderController>(this);

    //std::cout << mFactories[0]->displayRequirements() << std::endl;
    //std::cout << mFactories[1]->displayRequirements() << std::endl;
}

tgd::System::~System()
{

}


void tgd::System::update(sf::Time dt)
{
    //access the player entity directly and access the visible property to draw directly. for testing only
    for(auto itr = controllerMap.begin(); itr != controllerMap.end(); ++itr)
    {
        for(auto iitr = itr->second.begin(); iitr != itr->second.end(); ++iitr)
        {
            (*iitr)->update(dt);
        }
    }
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
    //int propertyMask = mEntities[id]->retrieveAllProperties();
    std::bitset<32> newBits(mEntities[id]->retrieveAllProperties());
    //now we need to sort through the properties to see what controllers need to be assigned
    //convert to bitset first, then start checking property requirements

    if(newBits.any())
    {
        assignControllers(id, newBits);
    }

}

void tgd::System::assignControllers(int id, std::bitset<32> newBits)
{
    std::vector<std::shared_ptr<Controller>> newControllers;
    /*if(newBits[0] == 1 && newBits[1] == 1 && newBits[3] == 1 && newBits[4] == 1)
    {
        //these should be all requirements for the player controller, also includes render controller
        //NOTE: shared or unique pointers will have to be used in the controller vector


       auto PC = std::make_shared<PlayerController>(assignControllerID(), id, this);
       auto RC = std::make_shared<RenderController>(assignControllerID(), id, this);

       newControllers.push_back(PC);
       newControllers.push_back(RC);

       controllerMap.emplace(id, newControllers);


       mEntityTags.insert(std::pair<unsigned int, std::string>(id, "Player"));
       mPlayerCreated = true;


    }*/

    for(int i=0; i<mFactories.size(); i++)
    {
        if(mFactories[i]->checkProperties(newBits))
        {
            newControllers.push_back(mFactories[i]->assignController(assignControllerID(), id));
        }
    }
    controllerMap.emplace(id, newControllers);


    mEntityTags.insert(std::pair<unsigned int, std::string>(id, "Player"));
    mPlayerCreated = true;
}



std::shared_ptr<tgd::Entity> tgd::System::fetchEntity(int eID)
{
    return mEntities[eID];
}

std::shared_ptr<tgd::Entity> tgd::System::findEntityByName(std::string tag)
{
    for(auto itr = mEntityTags.begin(); itr != mEntityTags.end(); ++ itr)
    {
        if(itr->second.compare(tag) == 0)
        {
            return mEntities[itr->first];
        }

    }

    return nullptr;
}

bool tgd::System::isPlayerCreated()
{
    return mPlayerCreated;
}

void tgd::System::cleanup()
{

}

int tgd::System::assignControllerID()
{
    //return the current count to be used as a unique controller id and increment count
    int temp = mControllerCount;
    mControllerCount++;
    return temp;
}

