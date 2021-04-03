#include "core.hpp"

core::core(std::map<std::string, std::map<std::string, std::string>> setup) : perso(setup["perso"]), map(setup["map"])
{
    LoadLib<Igraph> lib(setup["conf"]["lib_g"]);
    this->lib_g = lib.init();
}

core::~core()
{
}

void core::init()
{
}

void core::loop_c()
{

    this->lib_g->setSprite("test", "./sprite/perso/Isaac.png", {10, 25}, {28, 25});

    while (this->lib_g->isOpen())
    {

        this->lib_g->clear();

        this->lib_g->draw("test");
        this->lib_g->display();
    }

}