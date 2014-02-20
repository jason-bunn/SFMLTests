#ifndef TGD_CONTROLLERFACTORY_HPP
#define TGD_CONTROLLERFACTORY_HPP


#include <tgd/BaseFactory.hpp>
#include <bitset>
#include <memory>
namespace tgd
{

class System;

template <typename T>
class ControllerFactory : public BaseFactory
{

public:
                                ControllerFactory(System* system);
    virtual                    ~ControllerFactory();

    virtual bool                checkProperties(std::bitset<32> propMask);

    virtual std::shared_ptr<Controller>  assignController(int cID, int eID);
    std::string                 displayRequirements();
private:
    System*             mSystemPtr;
    std::bitset<32>     mRequirements;

};
}
#include "ControllerFactory.inl"
#endif // TGD_CONTROLLERFACTORY_HPP
