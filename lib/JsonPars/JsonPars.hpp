#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <locale>
#include <type_traits>
#include <any>

struct Obj_s {
    template <class T>
    static std::map<std::string, T> map;
};

class JsonPars
{
    private:
        std::string path;
        std::ifstream file;

        Obj_s mapJ;
        int indx;

        template <class T>
        static T temp;

    public:
        JsonPars(std::string p);
        ~JsonPars();

        Obj_s parsingJson();

        // template <typename O, typename... Ts>
        // std::enable_if_t<sizeof...(Ts) == 0, O> getJson(std::vector<std::string> p) { 
        //     // return ("ERROR" + p[0]);
        // };

        // template <typename O, typename T, typename... Ts>
        Obj_s getJson(/*std::vector<std::string> p*/) {

            // std::cout << this->indx << " " << typeid(T).name() << std::endl;

            // if (this->indx == 0) {
            //     temp<T> = Obj_s::map<T>[p[this->indx]];
            //     // std::cout << " res : " << Obj_s::map<T>[p[this->indx]] << std::endl;
            // } else {
            //     // temp<T> = temp<T>.map<T>[p[this->indx]];
            // }

            // // std::cout << " res : " << Obj_s::map<T>[p[this->indx]] << std::endl;
            // // std::cout << " res : " << Obj_s::map<T>[p[this->indx]] << std::endl;

            // this->indx++;
            
            // this->getJson<Ts...>(p);
            // if (sizeof...(Ts) == 0) {
            //     return (temp<O>);
            // }

            return (this->mapJ);
        };
};

template<class T>
std::map<std::string, T> Obj_s::map;

template<class T>
T JsonPars::temp;
