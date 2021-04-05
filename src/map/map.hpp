#ifndef __map_HPP__
#define __map_HPP__

#include "../sprite/texturing.hpp"

class map : public texturing
{
    private:

    public:
        map(std::map<std::string, type> c_perso);
        ~map();
};

#endif