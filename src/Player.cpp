#include "interfaces.h"


Player::Player(){};

Player::Player(sf::RenderWindow* window, sf::Color color){
    this->window = window;
    this->color = color;
    this->position[0] = window->getSize().x/2 * scaler;
    this->position[1] = window->getSize().y/2 * scaler;
    this->velocity[0] = 0;
    this->velocity[1] = 0;
    shapeFormation();
};

Player::Player(float position[], float velocity[], sf::RenderWindow* window, sf::Color color){
    this->window = window;
    this->color = color;
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
    position[0] += velocity[0] * deltaTime;
    position[1] += velocity[1] * deltaTime;

    //reset acceleration
    this->acceleration[0] = 0;
    this->acceleration[1] = 0;
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
        float distance_sq = (asteroid_position[0] - this->position[0])*(asteroid_position[0] - this->position[0]) + (asteroid_position[1] - this->position[1])*(asteroid_position[1] - this->position[1]);
        float radius_sum_sq = (asteroids[i]->getBoundRadius() + this->boundR) * (asteroids[i]->getBoundRadius() + this->boundR);
        //if they are close enough, then check collision
        if(distance_sq < radius_sum_sq){
            //TODO
            collided = true;
        }
    }
    return collided;
}