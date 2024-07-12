#include "interfaces.h"

Hearts::Hearts(){}

Hearts::Hearts(sf::RenderWindow* window, int n){
    this->n = n;
    this->window = window;

    this->x = this->window->getSize().x / 2;
    this->y = heartsMargin + heartSize/2;

    createHearts();
}

Hearts::Hearts(sf::RenderWindow* window, int n, int x, int y){
    this->n = n;
    this->window = window;

    this->x = x;
    this->y = y;

    createHearts();
}

Hearts::~Hearts(){}

void Hearts::createHearts(){
    float width = this->n * heartSize + (this->n - 1) * heartsMargin;
    float dx = -width / 2;

    for(int i=0;i<this->n;i++){
        int hx = this->x + dx + i * (heartSize + heartsMargin) + heartSize / 2;
        int hy = this->y;
        this->hearts.push_back(Heart(this->window, hx, hy));
    }
}

void Hearts::draw(){
    for(int i=0;i<this->hearts.size();i++){
        this->hearts[i].draw();
    }
}