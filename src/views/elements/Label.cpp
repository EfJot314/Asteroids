#include "interfaces.h"

Label::Label() {};

Label::Label(std::string font, std::string text){
    setFont(font);

    this->text.setString(text);
}

Label::Label(std::string font, std::string text, int size){
    setFont(font);

    this->text.setString(text);
    this->text.setCharacterSize(size);
}


Label::Label(std::string font, std::string text, int size, sf::Color color){
    setFont(font);
    
    this->text.setString(text);
    this->text.setCharacterSize(size);
    this->text.setFillColor(color);
}

Label::~Label() {}


int Label::getWidth() const{
    return this->text.getLocalBounds().width;
}

int Label::getHeight() const{
    return this->text.getLocalBounds().height;
}

void Label::draw(sf::RenderWindow *window) const{
    window->draw(this->text);
    std::cout << "XD" << std::endl;
}

void Label::setFont(std::string font){
    if (!this->font.loadFromFile(font)){
        std::cout << "Font '" << font << "' not found!" << std::endl;
    }
}

sf::Font Label::getFont() const{
    return this->font;
}

void Label::setText(std::string text){
    this->text.setString(text);
}

std::string Label::getText() const{
    return this->text.getString();
}

void Label::setSize(int size){
    this->text.setCharacterSize(size);
}

int Label::getSize() const{
    return this->text.getCharacterSize();
}

void Label::setColor(sf::Color color){
    this->text.setFillColor(color);
}

sf::Color Label::getColor() const{
    return this->text.getFillColor();
}

void Label::setPosition(int x, int y){
    this->text.setPosition(x - getWidth()/2, y - getHeight()/2);
}

std::array<int, 2> Label::getPosition() const{
    int x = this->text.getPosition().x + getWidth()/2;
    int y = this->text.getPosition().y + getHeight()/2;
    return std::array<int, 2>{x, y};
}

std::array<int, 2> Label::getDimensions() const{
    return std::array<int, 2>{getWidth(), getHeight()};
}