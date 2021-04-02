#include <iostream>

class ILog
{
    private:
        static ILog *load;

        virtual void write();

    public:
    //    ILog() = default;
        ~ILog() {};

        static void setLog(ILog *l);

        static void log();
};
