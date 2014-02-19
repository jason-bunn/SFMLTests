#ifndef TGD_BASEFACTORY_HPP
#define TGD_BASEFACTORY_HPP

namespace tgd
{
    class BaseFactory
    {
    public:
                            BaseFactory();

        virtual void        checkProperties(int eID);
        virtual void        assignController(int eID);
    };
}
#endif // TGD_BASEFACTORY_HPP
