#include "interfaces.h"


GameEngine::GameEngine(){};

GameEngine::GameEngine(Player* player){
    this->addPlayer(player);
};

GameEngine::~GameEngine(){};

void GameEngine::moveAll(){
    //player
    player->updateKinematicProperties();
    //asteroids
    for(int i=0;i<this->asteroids.size();i++){
        asteroids[i]->updateKinematicProperties();
    }
};

void GameEngine::drawAll(){
    //player
    player->draw();
    //asteroids
    for(int i=0;i<this->asteroids.size();i++){
        asteroids[i]->draw();
    }
};

void GameEngine::addPlayer(Player* player){
    this->player = player;
}

Player* GameEngine::getPlayer(){
    return player;
}

void GameEngine::addAsteroid(Asteroid* asteroid){
    this->asteroids.push_back(asteroid);
}

