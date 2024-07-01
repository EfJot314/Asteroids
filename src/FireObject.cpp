#include "interfaces.h"

FireObject::FireObject(){};

FireObject::FireObject(Player* player, float rotation, sf::RenderWindow* window, sf::Color color){
    this->window = window;
    this->color = color;

    this->player = player;

    this->position[0] = player->getPosition()[0];
    this->position[1] = player->getPosition()[1];
    
    this->velocity[0] = -1 * fireVelocity * sin(rotation * M_PI / 180.0f);
    this->velocity[1] = fireVelocity * cos(rotation * M_PI / 180.0f);

    shapeFormation();

    this->shape.rotate(rotation);
};

FireObject::~FireObject(){};

void FireObject::shapeFormation(){
    this->shape.setPointCount(4);
    this->shape.setPoint(0, sf::Vector2f(fireSize/2, fireSize/2));
    this->shape.setPoint(1, sf::Vector2f(fireSize/2, -fireSize/2));
    this->shape.setPoint(2, sf::Vector2f(-fireSize/2, -fireSize/2));
    this->shape.setPoint(3, sf::Vector2f(-fireSize/2, fireSize/2));
    this->shape.scale(1/scaler, 1/scaler);
    this->shape.setFillColor(this->color);
};

void FireObject::updateKinematicProperties(){
    GameObject::updateKinematicProperties();
}