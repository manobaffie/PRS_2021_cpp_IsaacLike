#ifndef __map_HPP__
#define __map_HPP__

#include "../texturing/texturing.hpp"

class map : public texturing
{
    private:

    public:
        map(std::map<std::string, std::string> setup);
        ~map();
};

#endif