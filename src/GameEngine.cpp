#include "interfaces.h"


GameEngine::GameEngine(){};

GameEngine::GameEngine(Player* player){
    this->addPlayer(player);
};

GameEngine::~GameEngine(){};

bool isDeadAsteroid(Asteroid* a){
    return a->isDead();
}

bool isDeadBullet(Bullet* b){
    return b->isDead();
}

void GameEngine::checkAndRemoveAsteroids(){
    std::remove_if(this->asteroids.begin(), this->asteroids.end(), isDeadAsteroid);
};

void GameEngine::checkAndRemoveBullets(){
    std::remove_if(this->bullets.begin(), this->bullets.end(), isDeadBullet);
}

void GameEngine::moveAll(){
    //player
    player->updateKinematicProperties();
    //asteroids
    for(int i=0;i<this->asteroids.size();i++){
        asteroids[i]->updateKinematicProperties();
    }
    //bullets
    for(int i=0;i<this->bullets.size();i++){
        bullets[i]->updateKinematicProperties();
    }
};

void GameEngine::drawAll(){
    //player
    player->draw();
    //asteroids
    for(int i=0;i<this->asteroids.size();i++){
        asteroids[i]->draw();
    }
    //bullets
    for(int i=0;i<this->bullets.size();i++){
        bullets[i]->draw();
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

void GameEngine::addBullet(Bullet* bullet){
    this->bullets.push_back(bullet);
}

void GameEngine::checkCollisions(){
    //player collisions
    if(this->player->detectCollisions(this->asteroids)){
        std::cout<<"Player collision"<<std::endl;
        checkAndRemoveAsteroids();
    }
    //bullet collisions
    for(int i=0;i<this->bullets.size();i++){
        if(bullets[i]->detectCollisions(this->asteroids)){
            std::cout<<"Bullet collision"<<std::endl;
            checkAndRemoveAsteroids();
            checkAndRemoveBullets();
        }
    }
}
