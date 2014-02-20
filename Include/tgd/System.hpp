#ifndef TGD_SYSTEM_HPP
#define TGD_SYSTEM_HPP


#include <ResourceHolder.hpp>
#include <ResourceIdentifiers.hpp>
#include <tgd/Entity.hpp>
#include <entities/Player.hpp>

#include <events/EventRouter.hpp>
#include <tgd/Controller.hpp>
#include <tgd/BaseFactory.hpp>
#include <tgd/ControllerFactory.hpp>

#include <tmx/MapLoader.h>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>



#include <unordered_map>
#include <map>
#include <vector>
#include <memory>
#include <bitset>
#include <string>

class RenderController;
class Camera;


namespace tgd
{


    class System
    {
    public:

                                    System(TextureHolder& textures, sf::RenderTarget& target, Events::EventRouter* eventRouter, tmx::MapLoader* mMapLoader);
                                    ~System();
        template <typename T>
        void                        registerEntity(std::shared_ptr<T> entity);
        void                        update(sf::Time dt);
        void                        draw();

        template <typename T>
        void                        createEntity();
        bool                        isPlayerCreated();

        int                assignControllerID();

        std::shared_ptr<Entity>     fetchEntity(int eID);
        std::shared_ptr<Entity>     findEntityByName(std::string tag);

        void                        cleanup();

    public:
        TextureHolder&              textureHolder;
        sf::RenderTarget&           mTarget;
        tmx::MapLoader*             mMapPtr;
    private:
        void                        checkProperties(int id);
        void                        assignControllers(int id, std::bitset<32> newBits);
        template <typename T>
        void                        createFactory(System* system);

    private:
        std::unordered_map<int, std::vector<std::shared_ptr<Controller>>> controllerMap;
        std::map<unsigned int, std::shared_ptr<Entity>>   mEntities;
        std::map<unsigned int, std::string>               mEntityTags;
        unsigned int                                      mEntityCount;
        int                                               mControllerCount;
        bool                                              mPlayerCreated;
        Events::EventRouter*                              mEventRouter;
        std::vector<std::shared_ptr<tgd::BaseFactory>>    mFactories;


    };

}
#include "System.inl"
#include <controllers/RenderController.hpp>
#include <controllers/PlayerController.hpp>


#endif // TGD_SYSTEM_HPP

