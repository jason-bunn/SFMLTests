template <typename T>
tgd::Property<T>::Property(Properties::ID id, T typeValue)
: BaseProperty(id)
, mValue(typeValue)
{

}

template <typename T>
tgd::Property<T>::~Property()
{

}

template <typename T>
void tgd::Property<T>::setValue(T newValue)
{
    mValue = newValue;
}

template <typename T>
T* tgd::Property<T>::getValue()
{
    return &mValue;
}

template <typename T>
Properties::ID tgd::Property<T>::getID()
{
    return tgd::BaseProperty::mId;
}
