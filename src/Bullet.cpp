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

    this->shape.setPointCount(4);
    float width = bulletSize * bulletWidthFactor;
    this->shape.setPoint(0, sf::Vector2f(width/2, -bulletSize/2));
    this->shape.setPoint(1, sf::Vector2f(width/2, bulletSize/2));
    this->shape.setPoint(2, sf::Vector2f(-width/2, bulletSize/2));
    this->shape.setPoint(3, sf::Vector2f(-width/2, -bulletSize/2));
    this->shape.rotate(rotation);
    this->shape.scale(1/scaler, 1/scaler);
    this->shape.setFillColor(this->color);

};

Bullet::~Bullet(){};

void Bullet::updatePositionOnWindow(){
    //in the future here will be setting x,y connected with actual width, height and zoom of the window
    int width = window->getSize().x;
    int height = window->getSize().y;
    x = (int)position[0]/scaler;
    y = (int)position[1]/scaler;
};

std::array<float,2> Bullet::getPosition(){
    return std::array<float, 2>{position[0], position[1]};
}

void Bullet::borderJump(){
    //window size
    int width = window->getSize().x;
    int height = window->getSize().y;
    //OX
    if(x < 0 && velocity[0] < 0){
        position[0] = width * scaler;
    }
    else if(x > width && velocity[0] > 0){
        position[0] = 0;
    }
    //OY
    if(y < 0 && velocity[1] < 0){
        position[1] = height * scaler;
    }
    else if(y > height && velocity[1] > 0){
        position[1] = 0;
    }
}


void Bullet::updateKinematicProperties(){
    //update position
    position[0] += velocity[0] * deltaTime;
    position[1] += velocity[1] * deltaTime;
}


void Bullet::draw(){
    //update position of player on window
    updatePositionOnWindow();

    //eventually border jump
    borderJump();

    //shape properties
    shape.setPosition((int)(x), (int)(y));

    //drawing on the window
    window->draw(shape);

}


