#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <locale>
#include <type_traits>
#include <any>

struct type
{
    int i;
    bool b;
    std::string s;
    std::map<std::string, type> m;

    std::vector<int> ti;
    std::vector<bool> tb;
    std::vector<std::string> ts;
    std::vector<std::map<std::string, type>> tm;
};


class JsonPars
{
    private:
        std::string path;
        std::ifstream file;

        std::map<std::string, type> map;


    public:
        JsonPars(std::string p);
        ~JsonPars();

        std::map<std::string, type> parsingJson();

        std::map<std::string, type> getJson() {
            return (this->map);
        };

        void printObjs() {
            for (auto i : this->map) {
                std::cout << i.first << std::endl;

                std::cout << i.second.i << std::endl;

            }
        };
};
