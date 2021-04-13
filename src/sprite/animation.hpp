#ifndef __animation_HPP__
#define __animation_HPP__

#include "../conf/conf.hpp"
#include <string>

struct a_data
{
    float time;
    int nb_frame;

    std::map<std::string, std::vector<int>> m_frame;
};

struct a_part
{
    std::string keyboard;

    std::map<std::string, a_data> frames;
};

class animation
{
    protected:
        std::map<std::string, a_part> m_Apart;

    public:
        animation(std::map<std::string, type> c_sprite) {
            for (auto i : c_sprite["part"].tm) {
                this->m_Apart[i["id"].s].keyboard = i["keyboard"].s;

                for (auto j : i["frames"].tm) {
                    this->m_Apart[i["id"].s].frames[j["id"].s].time = std::stod(j["time"].s);
                    this->m_Apart[i["id"].s].frames[j["id"].s].nb_frame = 0;

                    for (int k = j["frame"].ti[0]; k < j["frame"].ti[1]; k++) {
                        std::cout << i["id"].s << " - " << j["id"].s << " - " << j["id"].s + "_" + std::to_string(k) << std::endl;
                        this->m_Apart[i["id"].s].frames[j["id"].s].m_frame[j["id"].s + "_" + std::to_string(k)] = j["pose"].ti;
                    }
                }
            }
        };

        ~animation() = default;

        animation *getAnimation() {
            return (this);
        }
};

#endif
