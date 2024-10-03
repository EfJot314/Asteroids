#include "interfaces.h"


Bullet::Bullet(){};

Bullet::Bullet(Player* player, float rotation, sf::RenderWindow* window, const sf::Color color){
    this->window = window;
    this->color = color;

    this->player = player;

    this->position = player->getPosition();
    
    this->velocity.x = bulletVelocity * sin(rotation * M_PI / 180.0f);
    this->velocity.y = -1 * bulletVelocity * cos(rotation * M_PI / 180.0f);

    shapeFormation();

    this->shape.rotate(rotation);
};

Bullet::~Bullet(){};

void Bullet::shapeFormation(){
    this->body.setPosition(position);

    this->shape.setPointCount(4);
    float width = bulletSize * bulletWidthFactor;
    this->shape.setPoint(0, sf::Vector2f(width/2, -bulletSize/2));
    this->body.addPoint({width/2, -bulletSize/2});
    this->shape.setPoint(1, sf::Vector2f(width/2, bulletSize/2));
    this->body.addPoint({width/2, bulletSize/2});
    this->shape.setPoint(2, sf::Vector2f(-width/2, bulletSize/2));
    this->body.addPoint({-width/2, bulletSize/2});
    this->shape.setPoint(3, sf::Vector2f(-width/2, -bulletSize/2));
    this->body.addPoint({-width/2, -bulletSize/2});

    this->shape.scale(1/scaler, 1/scaler);
    this->shape.setFillColor(this->color);
}

void Bullet::updateKinematicProperties(){
    KinematicObject::updateKinematicProperties();
    this->distance += std::sqrt(std::pow(this->velocity.x * deltaTime , 2) + std::pow(this->velocity.y * deltaTime , 2));
    //destroy bullet after max distance
    if(this->distance > bulletMaxDistance){
        this->hp = 0;
    }
}


bool Bullet::detectCollisions(std::vector<Asteroid*>& asteroids){
    bool collided = false;
    for(int i=0;i<asteroids.size();i++){
        if(this->body.checkCollision(asteroids[i]->getBody())){
            //hit and increment score
            if(asteroids[i]->hit(this->damage)){
                this->player->addToScore(asteroids[i]->getPoints());
            }
            this->hit(1);
            collided = true;
        }
    }
    return collided;
}


