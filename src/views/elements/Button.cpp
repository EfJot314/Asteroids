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

void Button::prepareBackgroundRectangle(){
    this->background.setFillColor(sf::Color::Transparent);

    float x = this->getPosition()[0] - this->width/2 + this->getLocalBounds().left;
    float y = this->getPosition()[1] - this->height/2 + this->getLocalBounds().top;

    this->background.setPosition(x, y);
    this->background.setSize(sf::Vector2f(this->width, this->height));
}

void Button::setDimensions(){
    this->width = getWidth();
    this->height = getHeight();

    this->prepareBackgroundRectangle();
}

void Button::setDimensions(int width, int height){
    this->width = width;
    this->height = height;

    this->prepareBackgroundRectangle();
}

std::array<int, 2> Button::getDimensions() const{
    return std::array<int, 2>{this->width, this->height};
}

void Button::setBackgrounds(const sf::Color b1, const sf::Color b2){
    this->background_color1 = b1;
    this->background_color2 = b2;
}

void Button::hover(int mouseX, int mouseY){
    setDimensions();
    if(checkOver(mouseX, mouseY)){
        this->background.setFillColor(this->background_color2);
    }
    else{
        this->background.setFillColor(this->background_color1);
    }
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(background, states);
    Label label = *dynamic_cast<const Label*>(this);
    target.draw(label, states);
};

bool Button::checkOver(int mouseX, int mouseY) const{
    int xp = getPosition()[0] - width/2 + this->getLocalBounds().left;
    int yp = getPosition()[1] - height/2 + this->getLocalBounds().top;
    if(mouseX <= xp || mouseX >= xp + width)  return false;
    if(mouseY <= yp || mouseY >= yp + height) return false;
    return true;
}



