#include <SFML/Graphics.hpp>

#include "../Igraph.hpp"

struct s_st {
    sf::Texture texture;
    sf::Sprite sprite;
};


class sfml : public Igraph
{
    private:
        sf::RenderWindow window;

        std::map<std::string, s_st> sprites;

    public:
        sfml(int x, int y, std::string name);
        ~sfml() override;

        void initWindow() override;

        void setSprite(std::string id, std::string t_path, int x, int y, int inx, int iny) override;

        void draw(std::string id) override;
        void display() override;
        bool isOpen() override;
        void clear() override;
};
