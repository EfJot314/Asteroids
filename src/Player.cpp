#include "interfaces.h"


Player::Player(){};

Player::Player(sf::RenderWindow* window, sf::Color color){
    this->window = window;
    this->color = color;
    this->position[0] = window->getSize().x/2 * scaler;
    this->position[1] = window->getSize().y/2 * scaler;
    this->velocity[0] = 0;
    this->velocity[1] = 0;
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
};

Player::~Player(){};

void Player::updatePositionOnWindow(){
    //in the future here will be setting x,y connected with actual width, height and zoom of the window
    int width = window->getSize().x;
    int height = window->getSize().y;
    x = (int)position[0]/scaler;
    y = (int)position[1]/scaler;
};


std::array<float,2> Player::getPosition(){
    return std::array<float, 2>{position[0], position[1]};
}

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
    }
    //left
    else{
        rotation -= rotation_speed;
    }
}

void Player::draw(){
    //update position of player on window
    updatePositionOnWindow();

    //factors
    float body_len_factor = 7.0/8.0;
    float body_width_factor = 2.0/3.0;
    float engine_len_factor = 1.0/8.0;
    float engine_width_factor_1 = 1.0/6.0;
    float engine_width_factor_2 = 1.0/2.0;
    //real lengths
    float full_len = 170.0;
    float body_len = body_len_factor * full_len;
    float body_width = body_width_factor * full_len;
    float engine_len = engine_len_factor * full_len;
    float engine_width_1 = engine_width_factor_1 * full_len;
    float engine_width_2 = engine_width_factor_2 * full_len;
    //creating player shape
    sf::ConvexShape shape;
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
    shape.setPosition((int)(x), (int)(y));
    shape.rotate(rotation);

    //drawing on the window
    window->draw(shape);

}


