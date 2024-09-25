#include "interfaces.h"



BigAsteroid::BigAsteroid() {}

BigAsteroid::BigAsteroid(sf::RenderWindow* window, const sf::Color color){
    this->window = window;
    this->color = color;

    this->hp = 3;

    randomPlacement();
    shapeFormation();
}

std::vector<Asteroid*> BigAsteroid::explode(){
    std::cout << "HH" << std::endl;
    std::vector<Asteroid*> toReturn = {};
    for(int i=0;i<asteroidExplosionNumer;i++){
        SmallAsteroid* a = new SmallAsteroid(window, BLUE);
        toReturn.push_back(a);
    }
    return toReturn;
}