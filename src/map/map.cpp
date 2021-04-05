#include "map.hpp"

map::map(std::map<std::string, type> c_perso) : texturing(c_perso["sprite"].m)
{
}

map::~map()
{
}
