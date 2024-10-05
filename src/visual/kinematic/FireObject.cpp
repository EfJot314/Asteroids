#include "interfaces.h"

FireObject::FireObject(){};

FireObject::FireObject(Player* player, float rotation, sf::RenderWindow* window, const sf::Color color1, const sf::Color color2){
    this->window = window;
    this->color = color1;
    this->fillingColor = color2;

    this->player = player;

    this->position = player->getEnginePosition();


    const float vxp = player->getVelocity().x;
    const float vyp = player->getVelocity().y;
    this->velocity.x = vxp - fireVelocity * sin(rotation * M_PI / 180.0f);
    this->velocity.y = vyp + fireVelocity * cos(rotation * M_PI / 180.0f);

    shapeFormation();

    this->shape.rotate(rotation);

    updatePositionOnWindow();
    updateKinematicProperties();
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


bool FireObject::incrementAndCheckDuration(int FPS){
    this->durationCounter++;
    if(this->durationCounter >= fireDuration * FPS){
        this->hp = 0;
        return true;
    }
    return false;
}