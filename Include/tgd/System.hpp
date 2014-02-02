#ifndef TGD_SYSTEM_HPP
#define TGD_SYSTEM_HPP


#include <ResourceHolder.hpp>
#include <ResourceIdentifiers.hpp>
#include <tgd/Entity.hpp>
#include <entities/Player.hpp>

#include <tgd/Controller.hpp>


#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include <unordered_map>
#include <map>
#include <vector>
#include <memory>

class RenderController;

namespace tgd
{
    class System
    {
    public:

                                    System(TextureHolder& textures, sf::RenderTarget& target);
                                    ~System();
        template <typename T>
        void                        registerEntity(std::shared_ptr<T> entity);
        void                        update(sf::Time dt);
        void                        draw();

        template <typename T>
        void                        createEntity();

        std::shared_ptr<Entity>     fetchEntity(int eID);

    public:
        TextureHolder&              textureHolder;
        sf::RenderTarget&           mTarget;

    private:
        void                        checkProperties(int id);
        void                        assignControllers(int id);
        template <typename T>
        void                        createFactory(int id);

    private:
        std::unordered_map<int, std::vector<Controller*>> controllerMap;
        std::map<unsigned int, std::shared_ptr<Entity>>   mEntities;
        std::vector<std::shared_ptr<Controller>>          mRenderControllers;
        unsigned int                                      mEntityCount;
    };

}
#include "System.inl"
#endif // TGD_SYSTEM_HPP

