#include "interfaces.h"

int Label::getWidth() const{
    return this->getLocalBounds().width;
}

int Label::getHeight() const{
    return this->getLocalBounds().height;
}

void Label::setFont(std::string font){
    if (!this->font.loadFromFile(font)){
        std::cout << "Font '" << font << "' not found!" << std::endl;
    }
    this->sf::Text::setFont(this->font);
}

void Label::setPosition(int x, int y){
    this->sf::Text::setPosition(x - getWidth()/2, y - getHeight()/2);
}

std::array<int, 2> Label::getPosition() const{
    int x = this->sf::Text::getPosition().x + getWidth()/2;
    int y = this->sf::Text::getPosition().y + getHeight()/2;
    return std::array<int, 2>{x, y};
}

std::array<int, 2> Label::getDimensions() const{
    return std::array<int, 2>{getWidth(), getHeight()};
}