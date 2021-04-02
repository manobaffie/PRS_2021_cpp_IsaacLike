#include "hello.hpp"

hello::hello(std::string f) : from(f)
{
}

hello::~hello()
{
    std::cout << "good bye" << std::endl;
}

void hello::printHello()
{
    std::cout << "hello from : " << this->from << std::endl;
}

extern "C" {
    ILib* create() {
        return new hello("default");
    }

    void destroy(hello* obj) {
        delete obj;
    }
}