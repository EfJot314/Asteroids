#include "interfaces.h"

void VisualObject::shapeFormation(){
    this->shape.setPointCount(4);
    this->shape.setPoint(0, sf::Vector2f(defaultSize/2, -defaultSize/2));
    this->shape.setPoint(1, sf::Vector2f(defaultSize/2, defaultSize/2));
    this->shape.setPoint(2, sf::Vector2f(-defaultSize/2, defaultSize/2));
    this->shape.setPoint(3, sf::Vector2f(-defaultSize/2, -defaultSize/2));
    this->shape.scale(1/scaler, 1/scaler);
    this->shape.setFillColor(this->color);
}

void VisualObject::draw(){
    //drawing on the window
    window->draw(shape);
}