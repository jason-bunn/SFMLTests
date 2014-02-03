#ifndef TGD_PROPERTY_HPP
#define TGD_PROPERTY_HPP

#include <tgd/BaseProperty.hpp>

namespace tgd
{
    template <typename T>
    class Property : public BaseProperty
    {
    public:
                                Property(Properties::ID id, T typeValue);
                                ~Property();
        T*                       getValue();
        void                    setValue(T newValue);
        virtual Properties::ID  getID();
    public:
        T                       mValue;

    };
}
#include "Property.inl"
#endif // TGD_PROPERTY_HPP
