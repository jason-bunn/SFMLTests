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
        T                       getValue();
        void                    setValue(T newValue);

    private:
        T                       mValue;

    };
}

#endif // TGD_PROPERTY_HPP
