#include "interfaces.h"



BigAsteroid::BigAsteroid() {}

BigAsteroid::BigAsteroid(sf::RenderWindow* window, const sf::Color color){
    this->window = window;
    this->color = color;

    this->hp = 3;

    randomPlacement();
    shapeFormation();
}

void BigAsteroid::shapeFormation(){
    this->Asteroid::asteroidShapeFormation(asteroidShapeN, asteroidRadius);
}