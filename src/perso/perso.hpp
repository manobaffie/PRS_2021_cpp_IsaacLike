#ifndef __perso_HPP__
#define __perso_HPP__

#include "../sprite/texturing.hpp"

class perso : public texturing
{
    protected:
        std::string id;

    public:
        perso(std::map<std::string, type> c_perso);
        ~perso();
};

#endif
