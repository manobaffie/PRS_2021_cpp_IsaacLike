#include "core.hpp"

core::core() : perso(conf::config["entity"].m["perso"].m), map(conf::config["entity"].m["map"].m)
{
    LoadLib<Igraph> lib(conf::config["game"].m["p_lib"].s);
    this->lib_g = lib.init();

    // this->lib_g->setWindow(30, "IsaacLike", {1920, 1080});
}

core::~core()
{
}

void core::perso_init()
{
    this->lib_g->setTexture(perso::id, perso::p_texture);

    for (auto i : perso::m_part) {
        for (auto j : i.second.poses) {
            this->lib_g->setSprite(perso::id, j.first, j.second, i.second.size);
        }
    }

    this->v_disp["0"] = {perso::id, "head_0", {10, 10}};
    this->v_disp["1"] = {perso::id, "body_up_0", {10, 40}};
}

void core::disp_s()
{
    for (auto i : this->v_disp) {
        this->lib_g->setPosition(i.second.id_texture, i.second.id_sprite, i.second.pose);
        this->lib_g->draw(i.second.id_texture, i.second.id_sprite);
    }
}

void core::loop_c()
{
    while (this->lib_g->isOpen())
    {
        this->lib_g->clear();
        this->disp_s();
        this->lib_g->display();
    }
}
