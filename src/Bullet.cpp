#include "interfaces.h"


Bullet::Bullet(){};

Bullet::Bullet(Player* player, float rotation, sf::RenderWindow* window, sf::Color color){
    this->window = window;
    this->color = color;

    this->player = player;

    this->position[0] = player->getPosition()[0];
    this->position[1] = player->getPosition()[1];
    
    this->velocity[0] = bulletVelocity * sin(rotation * M_PI / 180.0f);
    this->velocity[1] = -1 * bulletVelocity * cos(rotation * M_PI / 180.0f);

    shapeFormation();

    this->shape.rotate(rotation);
};

Bullet::~Bullet(){};

void Bullet::shapeFormation(){
    this->shape.setPointCount(4);
    float width = bulletSize * bulletWidthFactor;
    this->shape.setPoint(0, sf::Vector2f(width/2, -bulletSize/2));
    this->shape.setPoint(1, sf::Vector2f(width/2, bulletSize/2));
    this->shape.setPoint(2, sf::Vector2f(-width/2, bulletSize/2));
    this->shape.setPoint(3, sf::Vector2f(-width/2, -bulletSize/2));
    this->shape.scale(1/scaler, 1/scaler);
    this->shape.setFillColor(this->color);
}


bool Bullet::detectCollisions(std::vector<Asteroid*> asteroids){
    return false;
}



