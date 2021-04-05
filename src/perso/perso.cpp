#include "perso.hpp"

perso::perso(std::map<std::string, type> c_perso) : texturing(c_perso["sprite"].m)
{
    this->id = c_perso["id"].s;
}

perso::~perso()
{
}
