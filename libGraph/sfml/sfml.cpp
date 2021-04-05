#include "sfml.hpp"

sfml::sfml(int x, int y, std::string name) : window(sf::VideoMode(x, y), name)
{
}

sfml::~sfml()
{
}

void sfml::setWindow(int fps, std::string title, std::vector<int> size)
{
    this->window.setFramerateLimit(fps);
    this->window.setTitle(title);
    this->window.setSize({size[0], size[1]});
}

void sfml::setTexture(std::string idT, std::string t_path)
{
    this->sprites[idT].texture.loadFromFile(t_path);
}

void sfml::setSprite(std::string idT, std::string idS, std::vector<int> pose, std::vector<int> size)
{
    this->sprites[idT].sprite[idS].setTexture(this->sprites[idT].texture);
    this->sprites[idT].sprite[idS].setTextureRect(sf::IntRect(pose[0], pose[1], size[0], size[1]));
}

void sfml::draw(std::string idT, std::string idS)
{
    this->window.draw(this->sprites[idT].sprite[idS]);
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

void sfml::setPosition(std::string idT, std::string idS, std::vector<int> pose)
{
    this->sprites[idT].sprite[idS].setPosition(pose[0], pose[1]);
}

void sfml::setScale(std::string idT, std::string idS, std::vector<float> size)
{
    this->sprites[idT].sprite[idS].setScale(size[0], size[1]);
}

extern "C" {
    Igraph* create() {
        return new sfml(1920, 1080, "IsaacLike");
    }

    void destroy(Igraph* obj) {
        delete obj;
    }
}