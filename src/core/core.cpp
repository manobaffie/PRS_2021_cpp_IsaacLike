#include "core.hpp"

core::core() : perso(conf::config["entity"].m["perso"].m), map(conf::config["entity"].m["map"].m)
{
    LoadLib<Igraph> lib(conf::config["game"].m["p_lib"].s);
    this->lib_g = lib.init();
}

core::~core()
{
}

void core::perso_init()
{
    this->lib_g->setTexture(perso::name, perso::p_texture);

    for (auto i : perso::m_Tpart) {
        for (auto j : i.second.poses) {
            this->lib_g->setSprite(perso::name, j.first, j.second, i.second.size);
            this->lib_g->setScale(perso::name, j.first, {float(i.second.scale), float(i.second.scale)});
        }
    }
}

void core::start_animation(std::map<std::string, a_data> &frames, std::vector<int> coord, std::string idT)
{
    for (auto &i : frames) {
        if (this->lib_g->getClock(i.first) == -1) {
            this->lib_g->startClock(i.first);
            std::string id = i.second.m_frame.begin()->first;
            this->v_disp[id].id_texture = idT;
            this->v_disp[id].id_sprite = id;
            this->v_disp[id].pose = {
                coord[0] + (perso::m_Tpart[i.first].scale * i.second.m_frame[id][0]),
                coord[1] + (perso::m_Tpart[i.first].scale * i.second.m_frame[id][1])
            };
        }
    }
    for (auto &i : frames) {
        if (this->lib_g->getClock(i.first) > i.second.time) {
            std::string id = std::next(i.second.m_frame.begin(), i.second.nb_frame)->first;
            if (this->v_disp.find(id) != this->v_disp.end()) {
                this->v_disp.erase(id);
            }
            i.second.nb_frame++;
            if (i.second.nb_frame >= int(i.second.m_frame.size())) {
                i.second.nb_frame = 0;
            }
            id = std::next(i.second.m_frame.begin(), i.second.nb_frame)->first;
            this->v_disp[id].id_texture = idT;
            this->v_disp[id].id_sprite = id;
            this->v_disp[id].pose = {
                coord[0] + (perso::m_Tpart[i.first].scale * i.second.m_frame[id][0]), // segfault here
                coord[1] + (perso::m_Tpart[i.first].scale * i.second.m_frame[id][1])
            };
            this->lib_g->restartClock(i.first);
        }
    }
}

void core::disp_s()
{
    for (auto &i : this->v_disp) {
        this->lib_g->setPosition(i.second.id_texture, i.second.id_sprite, i.second.pose);
        this->lib_g->draw(i.second.id_texture, i.second.id_sprite);
    }
}

void core::loop_c()
{
    while (this->lib_g->isOpen())
    {
        this->lib_g->clear();

        auto k = this->lib_g->getKey();

        if (std::find(k.begin(), k.end(), 's' - 'a') != k.end()) {
            this->start_animation(perso::m_Apart["down"].frames, perso::coord, perso::name);
        } else if (std::find(k.begin(), k.end(), 'd' - 'a') != k.end()) {
            this->start_animation(perso::m_Apart["right"].frames, perso::coord, perso::name);
        } else {
            this->start_animation(perso::m_Apart["base"].frames, perso::coord, perso::name);
        }

        this->disp_s();
        this->lib_g->display();
    }
}
