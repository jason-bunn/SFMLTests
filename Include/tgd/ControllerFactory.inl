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
    if(mRequirements == mSystemPtr->mEntities[eID]->retrieveAllProperties())
    {
        assignController(eID);
    }

}
template <typename T>
void tgd::ControllerFactory<T>::assignController(int eID)
{


}
