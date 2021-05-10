#include <SFML/Graphics.hpp>
#include <iostream>

#include "../Igraph.hpp"

struct s_st {
    sf::Texture texture;
    std::map<std::string, sf::Sprite> sprite;
};


class sfml : public Igraph
{
    private:
        sf::RenderWindow window;
        sf::Event event;
        
        std::vector<int> key;
        std::map<std::string, s_st> sprites;
        std::map<std::string, sf::Clock> clock;

    public:
        sfml(int x, int y, std::string name);
        sfml() = default;
        ~sfml() override;

        void setWindow(int fps, std::string title, std::vector<int> size) override;

        void setTexture(std::string idT, std::string t_path) override;
        void setSprite(std::string idT, std::string idS, std::vector<int> pose, std::vector<int> size) override;
        
        void startClock(std::string id) override;
        void restartClock(std::string id) override;
        float getClock(std::string id) override;

        void draw(std::string idT, std::string idS) override;
        void display() override;
        bool isOpen() override;
        void clear() override;
        void setPosition(std::string idT, std::string idS, std::vector<int> pose) override;
        void setScale(std::string idT, std::string idS, std::vector<float> size) override;

        std::vector<int> getKey() override;
};

