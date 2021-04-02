#include <iostream>

#include "ILib.hpp"

class hello : public ILib
{
    private:
        std::string from;

    public:
        hello(std::string f);
        ~hello() override;

        void printHello() override;
};
