#include "interfaces.h"



BigAsteroid::BigAsteroid() {}

BigAsteroid::BigAsteroid(sf::RenderWindow* window, const sf::Color color){
    this->window = window;
    this->color = color;

    this->hp = 3;
    this->points = 20;

    randomPlacement();
    shapeFormation();
}

BigAsteroid::BigAsteroid(const Asteroid* const father, sf::RenderWindow* window, const sf::Color color){
    this->window = window;
    this->color = color;

    this->hp = 3;
    this->points = 20;

    position = father->getPosition();

    this->randomMovement(father->getVelocity());

    shapeFormation();
}

std::vector<Asteroid*> BigAsteroid::explode() const{
    std::vector<Asteroid*> toReturn = {};
    int n = asteroidMinExplosionNumer + rand() % (asteroidMaxExplosionNumer - asteroidMinExplosionNumer + 1);
    for(int i=0;i<n;i++){
        SmallAsteroid* a = new SmallAsteroid(this, window, BLUE);
        toReturn.push_back(a);
    }
    return toReturn;
}