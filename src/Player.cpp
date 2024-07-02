#include "interfaces.h"


Player::Player(){};

Player::Player(sf::RenderWindow* window, sf::Color color){
    this->window = window;
    this->color = color;

    this->hp = 100;

    this->position[0] = window->getSize().x/2 * scaler;
    this->position[1] = window->getSize().y/2 * scaler;
    this->velocity[0] = 0;
    this->velocity[1] = 0;
    this->acceleration[0] = 0;
    this->acceleration[1] = 0;

    shapeFormation();
};

Player::Player(float position[], float velocity[], sf::RenderWindow* window, sf::Color color){
    this->window = window;
    this->color = color;

    this->hp = 100;

    this->position[0] = position[0];
    this->position[1] = position[1];
    this->velocity[0] = velocity[0];
    this->velocity[1] = velocity[1];
    this->acceleration[0] = 0;
    this->acceleration[1] = 0;

    shapeFormation();
};

Player::~Player(){};


void Player::accelerate(float acceleration){
    this->acceleration[0] = acceleration * sin(rotation * M_PI/ 180.0);
    this->acceleration[1] = -1 * acceleration * cos(rotation * M_PI/ 180.0);
}

void Player::updateKinematicProperties(){
    //update position
    velocity[0] += acceleration[0] * deltaTime;
    velocity[1] += acceleration[1] * deltaTime;

    GameObject::updateKinematicProperties();

    //reset acceleration
    this->acceleration[0] = 0;
    this->acceleration[1] = 0;

}

void Player::createFire(){
    float fireRotation = this->rotation + (float)((rand() % (2*fireMaxAngleDeg)) - fireMaxAngleDeg);
    FireObject* newFire = new FireObject(this, fireRotation, this->window, ORANGE, RED);
    addNewFire(newFire);
}

void Player::addNewFire(FireObject* fireObject){
    this->fire.push_back(fireObject);
}

bool isDeadObject(GameObject* o){
    return o->isDead();
}

void Player::checkAndRemoveFire(){
    this->fire.erase(std::remove_if(this->fire.begin(), this->fire.end(), isDeadObject), this->fire.end());
}

void Player::updateFireKinematicProperties(){
    for(int i=0;i<this->fire.size();i++){
        fire[i]->updateKinematicProperties();
    }
    checkAndRemoveFire();
}

void Player::drawFire(){
    for(int i=0;i<this->fire.size();i++){
        fire[i]->draw();
    }
}

void Player::updateFire(int FPS){
    bool checkAndRemove = false;
    for(int i=0;i<this->fire.size();i++){
        if(fire[i]->incrementAndCheckDuration(FPS)){
            checkAndRemove = true;
        }
    }
    if(checkAndRemove){
        checkAndRemoveFire();
    }
}

void Player::rotate(int direction){
    float rotation_speed = 7.0;
    //right
    if(direction > 0){
        rotation += rotation_speed;
        shape.rotate(rotation_speed);
    }
    //left
    else{
        rotation -= rotation_speed;
        shape.rotate(-rotation_speed);
    }
}

void Player::shapeFormation(){
    //factors
    float body_len_factor = 7.0/8.0;
    float body_width_factor = 2.0/3.0;
    float engine_len_factor = 1.0/8.0;
    float engine_width_factor_1 = 1.0/6.0;
    float engine_width_factor_2 = 1.0/2.0;
    //real lengths
    float body_len = body_len_factor * playerLen;
    float body_width = body_width_factor * playerLen;
    float engine_len = engine_len_factor * playerLen;
    float engine_width_1 = engine_width_factor_1 * playerLen;
    float engine_width_2 = engine_width_factor_2 * playerLen;
    //creating player shape
    shape.setPointCount(7);
    shape.setPoint(0, sf::Vector2f(0, -body_len*2/3));    
    shape.setPoint(1, sf::Vector2f(body_width/2, body_len*1/3));
    shape.setPoint(2, sf::Vector2f(engine_width_1/2, body_len*1/3));
    shape.setPoint(3, sf::Vector2f(engine_width_2/2, body_len*1/3 + engine_len));
    shape.setPoint(4, sf::Vector2f(-engine_width_2/2, body_len*1/3 + engine_len));
    shape.setPoint(5, sf::Vector2f(-engine_width_1/2, body_len*1/3));
    shape.setPoint(6, sf::Vector2f(-body_width/2, body_len*1/3));

    //shape properties
    shape.setFillColor(color);
    shape.scale(1/scaler, 1/scaler);

    //bound radius
    boundR = sqrt(playerLen*playerLen + body_width*body_width) / 2;
}


Bullet* Player::shoot(){
    return new Bullet(this, this->rotation, this->window, this->color);
}


bool Player::detectCollisions(std::vector<Asteroid*> asteroids){
    bool collided = false;
    for(int i=0;i<asteroids.size();i++){
        //check if objects are close enough to each other
        std::array<float, 2> asteroid_position = asteroids[i]->getPosition();
        float center_distance = std::pow(asteroid_position[0] - this->position[0], 2) + std::pow(asteroid_position[1] - this->position[1], 2);
        float radius_sum = std::pow(asteroids[i]->getBoundRadius() + this->boundR, 2);
        //if they are close enough, then check collision
        if(center_distance < radius_sum){
            //TODO
            collided = true;
        }
    }
    return collided;
}


std::array<float, 2> Player::getEnginePosition(){
    float xp = position[0] + sin(this->rotation);
    float yp = position[1] + cos(this->rotation);
    return std::array<float, 2>{xp, yp};
}

std::array<float, 2> Player::getVelocity(){
    return std::array<float, 2>{velocity[0], velocity[1]};
}

