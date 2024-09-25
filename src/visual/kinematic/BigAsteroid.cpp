#include "interfaces.h"



BigAsteroid::BigAsteroid() {}

BigAsteroid::BigAsteroid(sf::RenderWindow* window, const sf::Color color){
    this->window = window;
    this->color = color;

    this->hp = 3;

    randomPlacement();
    shapeFormation();
}

BigAsteroid::BigAsteroid(Asteroid* father, sf::RenderWindow* window, const sf::Color color){
    this->window = window;
    this->color = color;

    this->hp = 3;

    position[0] = father->getPosition()[0];
    position[1] = father->getPosition()[1];

    this->randomMovement();

    shapeFormation();
}

std::vector<Asteroid*> BigAsteroid::explode(){
    std::vector<Asteroid*> toReturn = {};
    for(int i=0;i<asteroidExplosionNumer;i++){
        SmallAsteroid* a = new SmallAsteroid(this, window, BLUE);
        toReturn.push_back(a);
    }
    return toReturn;
}