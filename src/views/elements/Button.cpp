#include "interfaces.h"

Button::Button() {}

Button::Button(int width, int height){
    setDimensions(width, height);
}

Button::~Button() {}


void Button::setString(const sf::String &string){
    this->sf::Text::setString(string);
}

void Button::setPosition(int x, int y){
    this->Label::setPosition(x, y);
}

void Button::setDimensions(){
    this->width = getWidth();
    this->height = getHeight();
}

void Button::setDimensions(int width, int height){
    this->width = width;
    this->height = height;
}

std::array<int, 2> Button::getDimensions() const{
    return std::array<int, 2>{this->width, this->height};
}

void Button::setBackgrounds(sf::Color b1, sf::Color b2){
    this->background1 = b1;
    this->background2 = b2;
}

bool Button::checkOver(int mouseX, int mouseY){
    int xp = getPosition()[0] - width/2;
    int yp = getPosition()[1] - height/2 + this->getLocalBounds().top;
    if(mouseX <= xp || mouseX >= xp + width)  return false;
    if(mouseY <= yp || mouseY >= yp + height) return false;
    return true;
}



