#include "core/core.hpp"

int main()
{
    conf config("./config/conf.json");

    core Core;

    Core.perso_init();
    Core.loop_c();

    return 0;
}


