#include "sfml.hpp"

sfml::sfml(int x, int y, std::string name) : window(sf::VideoMode(x, y), name)
{
}

sfml::~sfml()
{
}

void sfml::initWindow()
{
}

void sfml::setSprite(std::string id, std::string t_path,  std::vector<int> p, std::vector<int> s)
{
    this->sprites[id].texture.loadFromFile(t_path);
    this->sprites[id].sprite.setTexture(this->sprites[id].texture);
    this->sprites[id].sprite.setTextureRect(sf::IntRect(p[0], p[1], s[0], s[1]));
}

void sfml::draw(std::string id)
{
    this->window.draw(this->sprites[id].sprite);
}

void sfml::display()
{
    this->window.display();
}

bool sfml::isOpen()
{
    return (this->window.isOpen());
}

void sfml::clear()
{
    this->window.clear();
}

void sfml::setScale(std::string id, std::vector<float> size)
{
    this->sprites[id].sprite.setScale(size[0], size[1]);
}

extern "C" {
    Igraph* create() {
        return new sfml(1920, 1080, "IsaacLike");
    }

    void destroy(Igraph* obj) {
        delete obj;
    }
}