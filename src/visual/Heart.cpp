#include "interfaces.h"

Heart::Heart(){}

Heart::Heart(sf::RenderWindow* window, sf::Color color, int x, int y){
    this->window = window;
    this->x = x;
    this->y = y;
    this->color = color;

    shapeFormation();

    this->shape.setPosition(x, y);
}

Heart::~Heart(){}

void Heart::shapeFormation(){
    float halfSize = heartSize / 2;

    shape.setPointCount(4);
    shape.setPoint(0, sf::Vector2f(halfSize, -halfSize));
    shape.setPoint(1, sf::Vector2f(halfSize, halfSize));
    shape.setPoint(2, sf::Vector2f(-halfSize, halfSize));
    shape.setPoint(3, sf::Vector2f(-halfSize, -halfSize));
    makeFilled();
}

void Heart::makeEmpty(){
    shape.setFillColor(sf::Color::Transparent);
}

void Heart::makeFilled(){
    shape.setFillColor(this->color);
}
