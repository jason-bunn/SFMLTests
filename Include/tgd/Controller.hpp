#ifndef TGD_CONTROLLER_HPP
#define TGD_CONTROLLER_HPP
namespace tgd
{
   class Controller
    {
    public:
                            Controller(int id, int eID);
        virtual             ~Controller();
        virtual int         getID();
        virtual int         getEntityID();
    private:
        int                 mID;
        int                 mEID;
    };
}

#endif // TGD_CONTROLLER_HPP
