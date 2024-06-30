#include "interfaces.h"


void GameObject::updatePositionOnWindow(){
    //in the future here will be setting x,y connected with actual width, height and zoom of the window
    int width = window->getSize().x;
    int height = window->getSize().y;
    x = (int)position[0]/scaler;
    y = (int)position[1]/scaler;
};


std::array<float,2> GameObject::getPosition(){
    return std::array<float, 2>{position[0], position[1]};
}

void GameObject::borderJump(){
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


void GameObject::updateKinematicProperties(){
    //update position
    position[0] += velocity[0] * deltaTime;
    position[1] += velocity[1] * deltaTime;
}


void GameObject::draw(){
    //update position of player on window
    updatePositionOnWindow();

    //eventually border jump
    borderJump();

    //shape properties
    shape.setPosition((int)(x), (int)(y));

    //drawing on the window
    window->draw(shape);

}


float GameObject::getBoundRadius(){
    return boundR;
}

int GameObject::getDamage(){
    return damage;
}

int GameObject::getHp(){
    return this->hp;
}

bool GameObject::isDead(){
    return (this->hp <= 0);
}

void GameObject::hit(int dmg){
    this->hp -= dmg;
}
