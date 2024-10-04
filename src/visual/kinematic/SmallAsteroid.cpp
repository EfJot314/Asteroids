#include "interfaces.h"



SmallAsteroid::SmallAsteroid() {}

SmallAsteroid::SmallAsteroid(sf::RenderWindow* window, const sf::Color color){
    this->window = window;
    this->color = color;

    this->hp = 3;

    randomPlacement();
    shapeFormation();

    updatePositionOnWindow();
}

SmallAsteroid::SmallAsteroid(const Asteroid* const father, sf::RenderWindow* window, const sf::Color color){
    this->window = window;
    this->color = color;

    this->hp = 3;

    position = father->getPosition();

    this->randomMovement(father->getVelocity());

    shapeFormation();

    updatePositionOnWindow();
}

void SmallAsteroid::shapeFormation(){
    this->Asteroid::asteroidShapeFormation(asteroidShapeN, asteroidRadius * asteroidSmallRadius);
}

std::vector<Asteroid*> SmallAsteroid::explode() const{
    return this->Asteroid::explode();
}