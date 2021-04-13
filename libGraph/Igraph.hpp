#include <vector>

class Igraph
{
    private:
    public:
        Igraph(int x, int y, std::string name);
        Igraph() = default;
        virtual ~Igraph() = default;

        virtual void setWindow(int fps, std::string title, std::vector<int> size) = 0;
        virtual void setTexture(std::string idT, std::string t_path) = 0;
        virtual void setSprite(std::string idT, std::string idS, std::vector<int> pose, std::vector<int> size) = 0;

        virtual void startClock(std::string id) = 0;
        virtual void restartClock(std::string id) = 0;
        virtual float getClock(std::string id) = 0;

        virtual void draw(std::string idT, std::string idS) = 0;
        virtual void display() = 0;
        virtual bool isOpen() = 0;
        virtual void clear() = 0;
        virtual void setPosition(std::string idT, std::string idS, std::vector<int> pose) = 0;
        virtual void setScale(std::string idT, std::string idS, std::vector<float> size) = 0;

         virtual void getKey() = 0;

};
