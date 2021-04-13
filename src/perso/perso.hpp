#ifndef __perso_HPP__
#define __perso_HPP__

#include "../sprite/texturing.hpp"
#include "../sprite/animation.hpp"

class perso : public texturing, public animation
{
    protected:
        std::string name;

        std::vector<int> coord;

    public:
        perso(std::map<std::string, type> c_perso);
        ~perso();
};

#endif
