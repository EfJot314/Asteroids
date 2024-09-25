#include "interfaces.h"



SmallAsteroid::SmallAsteroid() {}

SmallAsteroid::SmallAsteroid(sf::RenderWindow* window, const sf::Color color){
    this->window = window;
    this->color = color;

    this->hp = 3;

    randomPlacement();
    shapeFormation();
}

SmallAsteroid::SmallAsteroid(const Asteroid* const father, sf::RenderWindow* window, const sf::Color color){
    this->window = window;
    this->color = color;

    this->hp = 3;

    position[0] = father->getPosition()[0];
    position[1] = father->getPosition()[1];

    this->randomMovement(father->getVelocity());

    shapeFormation();
}

void SmallAsteroid::shapeFormation(){
    this->Asteroid::asteroidShapeFormation(asteroidShapeN, asteroidRadius * 1.0f/2.0f);
}

std::vector<Asteroid*> SmallAsteroid::explode() const{
    return this->Asteroid::explode();
}