#ifndef __conf_HPP__
#define __conf_HPP__

#include "../../lib/JsonPars/JsonPars.hpp"

class conf
{
    private:

    public:

        inline static std::map<std::string, type> config;
        conf(std::string p_conf) {
            JsonPars j(p_conf);
            config = j.getJson();
        };
        ~conf() = default;

        void reload() {
        }

};

#endif