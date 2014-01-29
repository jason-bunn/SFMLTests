#ifndef TGD_BASEPROPERTY_HPP
#define TGD_BASEPROPERTY_HPP

#include <tgd/PropertyIdentifiers.hpp>

namespace tgd
{
    class BaseProperty
    {
    public:

         virtual void           setID(Properties::ID id);
         virtual Properties::ID getID();

    private:
        Properties::ID          mId;
};
}


#endif // TGD_BASEPROPERTY
