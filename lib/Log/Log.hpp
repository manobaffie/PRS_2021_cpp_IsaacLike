#include <iostream>

#include "ILog.hpp"

class LogDebug : public ILog
{
    public:
        LogDebug() {};

    private:
        virtual void write() {
            std::cout << "test" << std::endl;
        }
};
