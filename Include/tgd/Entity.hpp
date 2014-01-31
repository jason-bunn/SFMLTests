#ifndef TGD_ENTITY_HPP
#define TGD_ENTITY_HPP

#include <tgd/BaseProperty.hpp>

#include <memory>
namespace tgd
{
    class Entity
    {
    public:
                        Entity(int id);
        virtual         ~Entity();
        virtual int     getEntityID();
        virtual int     retrieveAllProperties();

        virtual std::shared_ptr<BaseProperty>  accessProperty(Properties::ID id) = 0;

    public:
        int             mID;
    };
}

#endif // TGD_ENTITY_HPP
