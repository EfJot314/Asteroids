#include "interfaces.h"


GameEngine::GameEngine(){};

GameEngine::GameEngine(Player* player){
    this->addPlayer(player);
};

GameEngine::~GameEngine(){};

void GameEngine::moveAll(){
    player->updateKinematicProperties();
};

void GameEngine::addPlayer(Player* player){
    this->player = player;
}

Player* GameEngine::getPlayer(){
    return player;
}

