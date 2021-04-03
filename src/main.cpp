#include "core/core.hpp"

int main()
{

    std::map<std::string, std::map<std::string, std::string>> setup;

    setup["conf"].insert(std::make_pair("lib_g", "./libGraph/sfml/sfml.so"));

    setup["perso"].insert(std::make_pair("texture", "./sprite/perso/Isaac.png"));
    setup["perso"].insert(std::make_pair("name", "Isaac_0"));

    setup["map"].insert(std::make_pair("texture", "./sprite/map/Cellar.png"));
    setup["map"].insert(std::make_pair("name", "Cellar_0"));

    core c(setup);

    // c.loop_c();

    return 0;
}


