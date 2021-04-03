#include <iostream>

#include "../../lib/LoadLib/LoadLib.hpp"
#include "../../libGraph/Igraph.hpp"

#include "../perso/perso.hpp"
#include "../map/map.hpp"

class core : public perso, public map
{
    private:
        Igraph *lib_g;

    public:
        core(std::map<std::string, std::map<std::string, std::string>> setup);
        ~core();

        void init();
        void loop_c();
};

