#include "interfaces.h"


Asteroid::Asteroid(){};

Asteroid::Asteroid(sf::RenderWindow* window, sf::Color color){
    this->window = window;
    this->color = color;
    randomPlacement();
    shapeFormation();
};

Asteroid::Asteroid(float position[], float velocity[], float rotationSpeed, sf::RenderWindow* window, sf::Color color){
    this->window = window;
    this->color = color;
    this->position[0] = position[0];
    this->position[1] = position[1];
    this->velocity[0] = velocity[0];
    this->velocity[1] = velocity[1];
    this->rotationSpeed = rotationSpeed;
    shapeFormation();
};

Asteroid::~Asteroid(){};

void Asteroid::shapeFormation(){
    boundR = 0;
    float alpha = 0;
    float deltaAlpha = 2 * M_PI / (float)asteroidShapeN;
    shape.setPointCount(asteroidShapeN);
    for(int i=0;i<asteroidShapeN;i++){
        float r = asteroidRadius;
        float deltaRFactor = (float)(rand() % 1000) / 1000.0f * 2 * asteroidMaxFactor - asteroidMaxFactor; 
        r += r * deltaRFactor;
        shape.setPoint(i, sf::Vector2f(r * cos(alpha), r * sin(alpha)));
        alpha += deltaAlpha;

        //check bound radius
        if(r > boundR){
            boundR = r;
        }
    }
    shape.setFillColor(sf::Color::Transparent);
    shape.setOutlineThickness(lineThickness);
    shape.setOutlineColor(color);
    shape.scale(1/scaler, 1/scaler);
}

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
    //rotation
    this->rotationSpeed = (rand() % asteroidMaxRotationSpeed);
}

void Asteroid::draw(){
    //update position of player on window
    updatePositionOnWindow();

    //eventually border jump
    borderJump();

    //shape properties
    shape.setPosition((int)(x), (int)(y));
    shape.rotate(rotationSpeed * deltaTime);

    //drawing on the window
    window->draw(shape);

}


