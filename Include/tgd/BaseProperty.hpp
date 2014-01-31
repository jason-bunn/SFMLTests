#ifndef TGD_BASEPROPERTY_HPP
#define TGD_BASEPROPERTY_HPP

#include <tgd/PropertyIdentifiers.hpp>

namespace tgd
{
    class BaseProperty
    {
    public:

                    BaseProperty(Properties::ID id);
         virtual    Properties::ID getID();



        Properties::ID          mId;
};
}


#endif // TGD_BASEPROPERTY
