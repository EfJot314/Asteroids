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
    const float halfSize = heartSize / 2;

    shape.setPointCount(10);
    shape.setPoint(0, sf::Vector2f(0, 1.7f*heartSize));
    shape.setPoint(1, sf::Vector2f(1.5f*heartSize, 0));
    shape.setPoint(2, sf::Vector2f(1.5f*heartSize, -0.5f*heartSize));
    shape.setPoint(3, sf::Vector2f(heartSize, -heartSize));
    shape.setPoint(4, sf::Vector2f(0.5f*heartSize, -heartSize));
    shape.setPoint(5, sf::Vector2f(0, -0.3f*heartSize));
    shape.setPoint(6, sf::Vector2f(-0.5f*heartSize, -heartSize));
    shape.setPoint(7, sf::Vector2f(-heartSize, -heartSize));
    shape.setPoint(8, sf::Vector2f(-1.5f*heartSize, -0.5f*heartSize));
    shape.setPoint(9, sf::Vector2f(-1.5f*heartSize, 0));

    shape.setOutlineThickness(heartLineThickness);
    shape.setOutlineColor(this->color);

    makeFilled();
}

void Heart::makeEmpty(){
    shape.setFillColor(sf::Color::Transparent);
}

void Heart::makeFilled(){
    shape.setFillColor(this->color);
}
