#include "interfaces.h"

Hearts::Hearts(){}

Hearts::Hearts(sf::RenderWindow* window, sf::Color color, int n){
    this->n = n;
    this->window = window;
    this->color = color;

    this->x = this->window->getSize().x / 2;
    this->y = heartsMargin + heartSize/2;

    shapeFormation();
}

Hearts::Hearts(sf::RenderWindow* window, sf::Color color, int n, int x, int y){
    this->n = n;
    this->window = window;
    this->color = color;

    this->x = x;
    this->y = y;

    shapeFormation();
}

Hearts::~Hearts(){}

void Hearts::shapeFormation(){
    const float width = this->n * heartSize + (this->n - 1) * heartsMargin;
    const float dx = -width / 2;

    for(int i=0;i<this->n;i++){
        int hx = this->x + dx + i * (heartSize + heartsMargin) + heartSize / 2;
        int hy = this->y;
        this->hearts.push_back(Heart(this->window, this->color, hx, hy));
    }
}

void Hearts::draw(){
    for(int i=0;i<this->hearts.size();i++){
        this->hearts[i].draw();
    }
}

void Hearts::setHealth(int hp){
    //hp validation
    if(hp < 0) return;
    if(hp > this->n) return;

    //make last hearts empty
    for(int i=this->n-1;i>=hp;i--){
        this->hearts.at(i).makeEmpty();
    }

}