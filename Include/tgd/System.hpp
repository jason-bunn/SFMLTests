#ifndef TGD_SYSTEM_HPP
#define TGD_SYSTEM_HPP

#include <tgd/Entity.hpp>
#include <tgd/Controller.hpp>

#include <SFML/System/Time.hpp>

#include <unordered_map>
#include <map>
#include <vector>

namespace tgd
{
    class System
    {
    public:

                                    System();
                                    ~System();

        void                        registerEntity(Entity* entity);
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
        std::map<unsigned int, Entity*>       mEntities;
        unsigned int                 mEntityCount;
    };
}
#endif // TGD_SYSTEM_HPP
