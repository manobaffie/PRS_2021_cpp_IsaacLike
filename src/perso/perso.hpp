#ifndef __perso_HPP__
#define __perso_HPP__

#include "../texturing/texturing.hpp"

class perso : public texturing
{
    private:
    public:
        perso(std::map<std::string, std::string> setup);
        ~perso();
};

#endif
