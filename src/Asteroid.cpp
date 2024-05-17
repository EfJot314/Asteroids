#include "interfaces.h"


Asteroid::Asteroid(){};

Asteroid::Asteroid(sf::RenderWindow* window, sf::Color color){
    this->window = window;
    this->color = color;
    randomPlacement();
};

Asteroid::Asteroid(float position[], float velocity[], float rotationSpeed, sf::RenderWindow* window, sf::Color color){
    this->window = window;
    this->color = color;
    this->position[0] = position[0];
    this->position[1] = position[1];
    this->velocity[0] = velocity[0];
    this->velocity[1] = velocity[1];
    this->rotationSpeed = rotationSpeed;
};

Asteroid::~Asteroid(){};

void Asteroid::randomPlacement(){
    //window size
    int width = window->getSize().x;
    int height = window->getSize().y;
    //position on window
    //1 -> up
    //2 -> right
    //3 -> down
    //4 -> left
    int side = rand() % 4;
    if(side == 0){
        this->position[0] = (rand() % width) * scaler;
        this->position[1] = -1 * (rand() % asteroidMargin) * scaler;
    }
    else if(side == 1){
        this->position[0] = ((rand() % asteroidMargin) + width) * scaler;
        this->position[1] = (rand() % height) * scaler;
    }
    else if(side == 2){
        this->position[0] = (rand() % width) * scaler;
        this->position[1] = ((rand() % asteroidMargin) + height) * scaler;
    }
    else if(side == 3){
        this->position[0] = -1 * (rand() % asteroidMargin) * scaler;
        this->position[1] = (rand() % height) * scaler;
    }
    //velocity
    float v = (rand() % (int)(asteroidVelocityMax - asteroidVelocityMin)) + asteroidVelocityMin;
    float angle = (float)(rand() % 1000) / 1000.0f * 2 * M_PI;
    this->velocity[0] = v * cos(angle);
    this->velocity[1] = v * sin(angle);
}

void Asteroid::updatePositionOnWindow(){
    //in the future here will be setting x,y connected with actual width, height and zoom of the window
    int width = window->getSize().x;
    int height = window->getSize().y;
    x = (int)position[0]/scaler;
    y = (int)position[1]/scaler;
};


std::array<float,2> Asteroid::getPosition(){
    return std::array<float, 2>{position[0], position[1]};
}

void Asteroid::borderJump(){
    //window size
    int width = window->getSize().x;
    int height = window->getSize().y;
    //OX
    if(x < 0 && velocity[0] < 0){
        position[0] = width * scaler;
    }
    else if(x > width && velocity[0] > 0){
        position[0] = 0;
    }
    //OY
    if(y < 0 && velocity[1] < 0){
        position[1] = height * scaler;
    }
    else if(y > height && velocity[1] > 0){
        position[1] = 0;
    }
}


void Asteroid::updateKinematicProperties(){
    //update position
    position[0] += velocity[0] * deltaTime;
    position[1] += velocity[1] * deltaTime;
}


void Asteroid::draw(){
    //update position of player on window
    updatePositionOnWindow();

    //eventually border jump
    borderJump();

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


