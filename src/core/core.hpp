#ifndef __core_HPP__
#define __core_HPP__

#include <iostream>

#include "../../lib/LoadLib/LoadLib.hpp"
#include "../../libGraph/Igraph.hpp"

#include "../perso/perso.hpp"
#include "../map/map.hpp"

struct s_disp
{
    std::string id_texture;
    std::string id_sprite;
    std::vector<int> pose;
};

class core : public perso, public map
{
    private:
        Igraph *lib_g;
        std::map<std::string, s_disp> v_disp;

    public:
        core();
        ~core();

        void perso_init();
        void map_init();
        void disp_s();
        void loop_c();
};

#endif