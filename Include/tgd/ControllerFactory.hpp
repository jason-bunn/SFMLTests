#ifndef TGD_CONTROLLERFACTORY_HPP
#define TGD_CONTROLLERFACTORY_HPP


#include <tgd/BaseFactory.hpp>
#include <bitset>
namespace tgd
{

class System;

template <typename T>
class ControllerFactory : public BaseFactory
{

public:
                        ControllerFactory(System* system);
                        ~ControllerFactory();

    void                checkProperties(int eID);
    void                assignController(int eID);

private:
    System*             mSystemPtr;
    std::bitset<32>     mRequirements;

};
}
#include "ControllerFactory.inl"
#endif // TGD_CONTROLLERFACTORY_HPP
