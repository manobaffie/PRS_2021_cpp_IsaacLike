#include <iostream>
#include <functional>
#include <vector>
#include <map>

class MapFunc {
    private:
        template<class T>
        static std::map<std::string, T> vecFunc;

    public:
        MapFunc() = default;
        ~MapFunc() = default;

        template<class T>
        void addFunc(std::string name, const T &f) {
            vecFunc<T>.insert(std::pair<std::string, T>(name, f));
        };

        template<class fo, class f, typename... Args>
        fo exeFunc(std::string name, Args... args) {
            return(vecFunc<f>.find(name)->second(args...));
        };
};

template<class T>
std::map<std::string, T> MapFunc::vecFunc;
