#include <tgd/BaseProperty.hpp>

void tgd::BaseProperty::setID(Properties::ID id)
{
    mId = id;
}

Properties::ID tgd::BaseProperty::getID()
{
    return mId;
}
