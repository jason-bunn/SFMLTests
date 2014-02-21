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
bool tgd::ControllerFactory<T>::checkProperties(std::bitset<32> propMask)
{
    //check the properties of the entity to see if there is a match for factory requirements
    bool temp = false;
    for(int i=0; i<mRequirements.size(); i++)
    {
        if(mRequirements[i] == 1 && propMask[i] == 1)
        {
            temp = true;
        }
        else
        {
            if(mRequirements[i] == 1 && propMask[i] != 1)
            {
                temp = false;
                break;
            }

        }
    }
    return temp;
}
template <typename T>
std::shared_ptr<tgd::Controller> tgd::ControllerFactory<T>::assignController(int cID, int eID)
{
    //must have someway of getting shared pointer back to system to be placed onto controller map
    auto temp = std::make_shared<T>(cID, eID, mSystemPtr);
    return temp;
}

template <typename T>
std::string tgd::ControllerFactory<T>::displayRequirements()
{
    return (mRequirements.to_string());
}
