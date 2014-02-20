#ifndef TGD_BASEFACTORY_HPP
#define TGD_BASEFACTORY_HPP

#include <string>

namespace tgd
{
    class BaseFactory
    {
    public:
                            BaseFactory();
        virtual             ~BaseFactory();
        virtual void        checkProperties(int eID);
        virtual void        assignController(int eID);
        virtual std::string      displayRequirements();
    };
}
#endif // TGD_BASEFACTORY_HPP
