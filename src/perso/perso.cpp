#include "perso.hpp"

perso::perso(std::map<std::string, type> c_perso) : texturing(c_perso["sprite"].m), animation(c_perso["animation"].m)
{
    this->name = c_perso["id"].s;

    this->coord = {500, 500};
}

perso::~perso()
{
}
