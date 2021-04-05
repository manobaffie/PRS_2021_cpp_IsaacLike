#ifndef __texturing_HPP__
#define __texturing_HPP__

#include "../conf/conf.hpp"
#include <string>

struct part
{
    int scale;

    std::map<std::string, std::vector<int>> poses;
    std::vector<int> size;
};


class texturing
{
    protected:
        std::string p_texture;
        std::map<std::string, part> m_part;

    public:
        texturing(std::map<std::string, type> c_sprite) {

            this->p_texture = c_sprite["p_texture"].s;

            for (auto i : c_sprite["part"].tm) {
                m_part[i["id"].s].scale = i["scale"].i;
                m_part[i["id"].s].size = i["size"].ti;

                for (int y = 0; y < i["number"].ti[1]; y++) {
                    for (int x = 0; x < i["number"].ti[0]; x++) {
                        m_part[i["id"].s].poses[i["id"].s + "_" + std::to_string(((y + 1) * (x + 1)) - 1)] = {(x * i["switch"].ti[0]) + i["pose"].ti[0], (y * i["switch"].ti[1]) + i["pose"].ti[1]};
                    }
                }
            }

        };

        ~texturing() = default;
};

#endif