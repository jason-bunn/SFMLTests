#include <tgd/BaseProperty.hpp>

tgd::BaseProperty::BaseProperty(Properties::ID id)
{
    mId = id;
}

Properties::ID tgd::BaseProperty::getID()
{
    return mId;
}
