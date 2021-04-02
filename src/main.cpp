#include "core/core.hpp"
#include "perso/perso.hpp"


#include "../lib/LoadLib/LoadLib.hpp"
#include "../libGraph/Igraph.hpp"

int main()
{
    perso p();

    LoadLib<Igraph> Ig("./libGraph/sfml/sfml.so");

    Igraph *graph = Ig.init();

    graph->setSprite("test", "./sprite/perso/Isaac.png", 10, 25, 28, 25);

    while (graph->isOpen())
    {

        graph->clear();

        graph->draw("test");
        graph->display();
    }

    return 0;
}


