#ifndef TGD_CONTROLLERFACTORY_HPP
#define TGD_CONTROLLERFACTORY_HPP

#include <tgd/System.hpp>
namespace tgd
{


template <typename T>
class ControllerFactory
{

public:
                        ControllerFactory(tgd::System* system);
                        ~ControllerFactory();

    void                checkProperties(int eID);
    void                assignController(int eID);

private:
    tgd::System*        mSystemPtr;
    std::bitset<32>     mRequirements;
};
}
#include <tgd/ControllerFactory.inl>
#endif // TGD_CONTROLLERFACTORY_HPP
