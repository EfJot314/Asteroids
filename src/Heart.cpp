#include "interfaces.h"

Heart::Heart(){}

Heart::Heart(int x, int y){
    this->x = x;
    this->y = y;
    this->color = RED;

    shapeFormation();
}

Heart::~Heart(){}

void Heart::shapeFormation(){
    float halfSize = heartSize / 2;

    shape.setPointCount(4);
    shape.setPoint(0, sf::Vector2f(halfSize, -halfSize));
    shape.setPoint(0, sf::Vector2f(halfSize, halfSize));
    shape.setPoint(0, sf::Vector2f(-halfSize, halfSize));
    shape.setPoint(0, sf::Vector2f(-halfSize, -halfSize));

    shape.setFillColor(this->color);
    shape.scale(1/scaler, 1/scaler);
}

void Heart::makeEmpty(){
    //TODO
}