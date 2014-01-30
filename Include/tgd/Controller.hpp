#ifndef TGD_CONTROLLER_HPP
#define TGD_CONTROLLER_HPP
namespace tgd
{
   class Controller
    {
    public:
                            Controller(int id);

        virtual int         getID();

    private:
        int                 mID;
    };
}

#endif // TGD_CONTROLLER_HPP
