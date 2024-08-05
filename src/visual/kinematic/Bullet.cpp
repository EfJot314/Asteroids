#include "interfaces.h"


Bullet::Bullet(){};

Bullet::Bullet(Player* player, float rotation, sf::RenderWindow* window, const sf::Color color){
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

    //set bound radius
    this->boundR = width/2;
}

void Bullet::updateKinematicProperties(){
    KinematicObject::updateKinematicProperties();
    this->distance += std::sqrt(std::pow(this->velocity[0] * deltaTime , 2) + std::pow(this->velocity[1] * deltaTime , 2));
    //destroy bullet after max distance
    if(this->distance > bulletMaxDistance){
        this->hp = 0;
    }
}


bool Bullet::detectCollisions(std::vector<Asteroid>& asteroids){
    bool collided = false;
    for(int i=0;i<asteroids.size();i++){
        //check if objects are close enough to each other
        const std::array<float, 2> asteroid_position = asteroids[i].getPosition();
        const float center_distance = std::sqrt(std::pow(asteroid_position[0] - this->position[0], 2) + std::pow(asteroid_position[1] - this->position[1], 2));
        const float radius_sum = asteroids[i].getBoundRadius() + this->boundR;
        //if they are close enough, then check collision
        if(center_distance < radius_sum){
            asteroids[i].hit(this->damage);
            this->hit(1);
            collided = true;
        }
    }
    return collided;
}


