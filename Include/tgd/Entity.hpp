#ifndef TGD_ENTITY_HPP
#define TGD_ENTITY_HPP

namespace tgd
{
    class Entity
    {
    public:
                        Entity(int id);

        virtual int     getEntityID();
        virtual int     retrieveAllProperties();
    private:
        int             mID;
    };
}

#endif // TGD_ENTITY_HPP
