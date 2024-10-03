#include "interfaces.h"


void KinematicObject::updatePositionOnWindow(){
    //in the future here will be setting x,y connected with actual width, height and zoom of the window
    int width = window->getSize().x;
    int height = window->getSize().y;
    x = (int)position.x/scaler;
    y = (int)position.y/scaler;
};


Vector2D KinematicObject::getPosition() const{
    return position;
}

Vector2D KinematicObject::getVelocity() const{
    return velocity;
}

void KinematicObject::borderJump(){
    //window size
    int width = window->getSize().x;
    int height = window->getSize().y;
    //OX
    if(x < 0 && velocity.x < 0){
        position.x = width * scaler;
    }
    else if(x > width && velocity.x > 0){
        position.x = 0;
    }
    //OY
    if(y < 0 && velocity.y < 0){
        position.y = height * scaler;
    }
    else if(y > height && velocity.y > 0){
        position.y = 0;
    }
}


void KinematicObject::updateKinematicProperties(){
    //update position
    position.x += velocity.x * deltaTime;
    position.y += velocity.y * deltaTime;
    //eventually border jump
    borderJump();
    //shape properties
    shape.setPosition((int)(x), (int)(y));
    //collision body position update
    body.setPosition(position);
}


void KinematicObject::draw(){
    //update position of player on window
    updatePositionOnWindow();

    //drawing on the window
    VisualObject::draw();
}


CollisionBody KinematicObject::getBody() const{
    return body;
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

bool KinematicObject::hit(int dmg){
    this->hp -= dmg;
    if(this->hp < 0){
        this->hp = 0;
    }
    return isDead();
}

int KinematicObject::getPoints() const{
    return this->points;
}