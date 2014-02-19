template <typename T>
tgd::ControllerFactory<T>::ControllerFactory(tgd::System* system)
: mSystemPtr(system)
, mRequirements(T::getRequirements())
{
    //mRequirements = T::getRequirements();

}

template <typename T>
tgd::ControllerFactory<T>::~ControllerFactory()
{

}

template <typename T>
void tgd::ControllerFactory<T>::checkProperties(int eID)
{
    //check the properties of the entity to see if there is a match for factory requirements

}
template <typename T>
void tgd::ControllerFactory<T>::assignController(int eID)
{
    //must have someway of getting shared pointer back to system to be placed onto controller map

}
