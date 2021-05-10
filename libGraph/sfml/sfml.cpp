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
    size = size;
    // this->window.setSize((sf::Vector2u){size[0], size[1]});
}

void sfml::setTexture(std::string idT, std::string t_path)
{
    this->sprites[idT].texture.loadFromFile(t_path);
}

void sfml::setSprite(std::string idT, std::string idS, std::vector<int> pose, std::vector<int> size)
{
    std::cout << "setSprite : " << idT << " - " << idS << std::endl;
    this->sprites[idT].sprite[idS].setTexture(this->sprites[idT].texture);
    this->sprites[idT].sprite[idS].setTextureRect(sf::IntRect(pose[0], pose[1], size[0], size[1]));
    this->sprites[idT].sprite[idS].setOrigin(sf::Vector2f({float(size[0] / 2), float(size[1] / 2)}));
}

void sfml::startClock(std::string id)
{
    // std::cout << "[clock start] : " << id << std::endl;

    sf::Clock c;
    this->clock[id] = c;
}

void sfml::restartClock(std::string id)
{
    // std::cout << "[clock restart] : " << id << std::endl;
    this->clock[id].restart();
}

float sfml::getClock(std::string id)
{
    if (this->clock.find(id) != this->clock.end()) {
        return (sf::Time(this->clock[id].getElapsedTime()).asSeconds());
    } else {
        return (-1);
    }
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

std::vector<int> sfml::getKey()
{
    while (this->window.pollEvent(this->event)) {
        if (this->event.type == sf::Event::KeyPressed && 
        !(std::find(this->key.begin(), this->key.end(), this->event.key.code) != this->key.end())) {
            this->key.push_back(this->event.key.code);
        } else if (this->event.type == sf::Event::KeyReleased) {
            this->key.erase(std::find(this->key.begin(), this->key.end(), this->event.key.code));
        }
    }
    return (this->key);
}

extern "C" {
    Igraph* create() {
        return new sfml(1920, 1080, "IsaacLike");
    }

    void destroy(Igraph* obj) {
        delete obj;
    }
}