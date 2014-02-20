#ifndef TGD_BASEFACTORY_HPP
#define TGD_BASEFACTORY_HPP

#include <tgd/Controller.hpp>

#include <string>
#include <bitset>
#include <memory>
namespace tgd
{
    class BaseFactory
    {
    public:
                            BaseFactory();
        virtual             ~BaseFactory();
        virtual bool        checkProperties(std::bitset<32> newBits);

        virtual std::shared_ptr<Controller>        assignController(int cID, int eID)=0;
        virtual std::string      displayRequirements();
    };
}



#endif // TGD_BASEFACTORY_HPP
