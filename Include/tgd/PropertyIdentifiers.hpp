#ifndef TGD_PROPERTYIDENTIFIERS_HPP
#define TGD_PROPERTYIDENTIFIERS_HPP

namespace Properties
{
    enum ID
    {
        Position = 1 << 0,
        Velocity = 1 << 1,
        Collider = 1 << 2,
        Visible = 1 << 3,       //visible but static
        PC = 1 << 4,            //player controlled
        Animation = 1 << 5,    //visible but animated
    };
}
#endif // TGD_PROPERTYIDENTIFIERS_HPP
