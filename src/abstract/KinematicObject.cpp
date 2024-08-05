#include "interfaces.h"


void KinematicObject::updatePositionOnWindow(){
    //in the future here will be setting x,y connected with actual width, height and zoom of the window
    int width = window->getSize().x;
    int height = window->getSize().y;
    x = (int)position[0]/scaler;
    y = (int)position[1]/scaler;
};


std::array<float,2> KinematicObject::getPosition() const{
    return std::array<float, 2>{position[0], position[1]};
}

void KinematicObject::borderJump(){
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


void KinematicObject::updateKinematicProperties(){
    //update position
    position[0] += velocity[0] * deltaTime;
    position[1] += velocity[1] * deltaTime;
}


void KinematicObject::draw(){
    //update position of player on window
    updatePositionOnWindow();

    //eventually border jump
    borderJump();

    //shape properties
    shape.setPosition((int)(x), (int)(y));

    //drawing on the window
    VisualObject::draw();
}


float KinematicObject::getBoundRadius() const{
    return boundR;
}

int KinematicObject::getDamage() const{
    return damage;
}

int KinematicObject::getHp() const{
    return this->hp;
}

bool KinematicObject::isDead() const{
    return (this->hp <= 0);
}

void KinematicObject::hit(int dmg){
    this->hp -= dmg;
    if(this->hp < 0){
        this->hp = 0;
    }
}
