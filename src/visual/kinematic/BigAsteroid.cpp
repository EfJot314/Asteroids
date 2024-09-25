#include "interfaces.h"



BigAsteroid::BigAsteroid() {}

BigAsteroid::BigAsteroid(sf::RenderWindow* window, const sf::Color color){
    this->window = window;
    this->color = color;

    this->hp = 3;

    randomPlacement();
    shapeFormation();
}

std::vector<Asteroid> BigAsteroid::explode(){
    std::vector<Asteroid> toReturn = {};
    for(int i=0;i<3;i++){
        SmallAsteroid a(window, BLUE);
        toReturn.push_back(a);
    }
    return toReturn;
}