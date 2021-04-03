#ifndef __texturing_HPP__
#define __texturing_HPP__

#include <iostream>
#include <map>

class texturing
{
    protected:
        std::string texture;
        std::string name;

    public:
        texturing(std::map<std::string, std::string> setup) : texture(setup["texture"]), name(setup["name"]) {};
        ~texturing() = default;
};

#endif