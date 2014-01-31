#ifndef TGD_ENTITY_HPP
#define TGD_ENTITY_HPP

namespace tgd
{
    class Entity
    {
    public:
                        Entity(int id);
        virtual         ~Entity();
        virtual int     getEntityID();
        virtual int     retrieveAllProperties();

        int             mID;
    };
}

#endif // TGD_ENTITY_HPP
