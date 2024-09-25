#include "interfaces.h"



SmallAsteroid::SmallAsteroid() {}

SmallAsteroid::SmallAsteroid(sf::RenderWindow* window, const sf::Color color){
    this->window = window;
    this->color = color;

    this->hp = 3;

    randomPlacement();
    shapeFormation();
}

void SmallAsteroid::shapeFormation(){
    this->Asteroid::asteroidShapeFormation(asteroidShapeN, asteroidRadius * 1.0f/2.0f);
}

std::vector<Asteroid*> SmallAsteroid::explode(){
    return this->Asteroid::explode();
}