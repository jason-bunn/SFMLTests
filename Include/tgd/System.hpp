#ifndef TGD_SYSTEM_HPP
#define TGD_SYSTEM_HPP

#include <tgd/Entity.hpp>
#include <entities/Player.hpp>

#include <tgd/Controller.hpp>

#include <SFML/System/Time.hpp>

#include <unordered_map>
#include <map>
#include <vector>
#include <memory>

class Player;

namespace tgd
{
    class System
    {
    public:

                                    System();
                                    ~System();
        template <typename T>
        void                        registerEntity(std::shared_ptr<T> entity);
        void                        update(sf::Time dt);
        void                        draw();

        template <typename T>
        void                        createEntity();

    private:
        void                        checkProperties(int id);
        void                        assignControllers(int id);
        template <typename T>
        void                        createFactory(int id);

    private:
        std::unordered_map<int, std::vector<Controller*>> controllerMap;
        std::map<unsigned int, std::shared_ptr<Entity>>   mEntities;
        unsigned int                 mEntityCount;
    };
#include "System.inl"
#endif // TGD_SYSTEM_HPP




}
