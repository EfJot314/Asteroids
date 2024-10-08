#include "interfaces.h"


GameEngine::GameEngine(){};

GameEngine::GameEngine(Player& player){
    this->addPlayer(player);
};

GameEngine::~GameEngine(){};

bool isDead(KinematicObject *o){
    return o->isDead();
}

void GameEngine::asteroidExplosions(){
    std::vector<Asteroid*> newAsteroids = {};
    for(int i=0;i<this->asteroids.size();i++){
        if(asteroids[i]->isDead()){
            BigAsteroid* a = dynamic_cast<BigAsteroid*>(asteroids[i]);
            if(a){
                std::vector<Asteroid*> explosionAsteroids = a->explode();
                newAsteroids.insert(newAsteroids.end(), explosionAsteroids.begin(), explosionAsteroids.end());
            }
        }
    }
    asteroids.insert(asteroids.end(), newAsteroids.begin(), newAsteroids.end());
}

void GameEngine::checkAndRemoveAsteroids(){
    this->asteroids.erase(std::remove_if(this->asteroids.begin(), this->asteroids.end(), isDead), this->asteroids.end());
};

void GameEngine::checkAndRemoveBullets(){
    this->bullets.erase(std::remove_if(this->bullets.begin(), this->bullets.end(), isDead), this->bullets.end());
}

void GameEngine::moveAll(){
    //player
    player.updateKinematicProperties();
    //fire
    player.updateFireKinematicProperties();
    //asteroids
    for(int i=0;i<this->asteroids.size();i++){
        asteroids[i]->updateKinematicProperties();
    }
    //bullets
    for(int i=0;i<this->bullets.size();i++){
        bullets[i]->updateKinematicProperties();
    }
    //remove dead bullets
    checkAndRemoveBullets();
};

void GameEngine::drawAll(){
    //player
    player.draw();
    //asteroids
    for(int i=0;i<this->asteroids.size();i++){
        asteroids[i]->draw();
    }
    //bullets
    for(int i=0;i<this->bullets.size();i++){
        bullets[i]->draw();
    }
};

void GameEngine::addPlayer(Player& player){
    this->player = player;
}

Player& GameEngine::getPlayer(){
    return player;
}

void GameEngine::addAsteroid(Asteroid *asteroid){
    this->asteroids.push_back(asteroid);
}

void GameEngine::addBullet(Bullet *bullet){
    this->bullets.push_back(bullet);
}

void GameEngine::checkCollisions(){
    //player collisions
    if(this->player.detectCollisions(this->asteroids)){
        // std::cout<<"Player collision"<<std::endl;
        checkAndRemoveAsteroids();
    }
    //bullet collisions
    for(int i=0;i<this->bullets.size();i++){
        if(bullets[i]->detectCollisions(this->asteroids)){
            // std::cout<<"Bullet collision"<<std::endl;
            asteroidExplosions();
            checkAndRemoveAsteroids();
            checkAndRemoveBullets();
        }
    }
}

