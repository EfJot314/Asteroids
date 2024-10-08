#include "interfaces.h"


Asteroid::Asteroid(){};

Asteroid::Asteroid(sf::RenderWindow* window, const sf::Color color){
    this->window = window;
    this->color = color;

    this->hp = 3;

    randomPlacement();
    shapeFormation();

    updatePositionOnWindow();
    updateKinematicProperties();
};

Asteroid::Asteroid(const Asteroid* const father, sf::RenderWindow* window, const sf::Color color){
    this->window = window;
    this->color = color;

    this->hp = 3;

    position.x = father->getPosition().x;
    position.y = father->getPosition().y;

    this->randomMovement(father->getVelocity());

    shapeFormation();

    updatePositionOnWindow();
    updateKinematicProperties();
}

Asteroid::~Asteroid(){};

void Asteroid::shapeFormation(){
    this->asteroidShapeFormation(asteroidShapeN, asteroidRadius);
}

void Asteroid::asteroidShapeFormation(int n, float radius){
    body.setPosition(position);

    float alpha = 0;
    const float deltaAlpha = 2 * M_PI / (float)n;
    shape.setPointCount(n);
    for(int i=0;i<n;i++){
        float r = radius;
        float deltaRFactor = (float)(rand() % 1000) / 1000.0f * 2 * asteroidMaxFactor - asteroidMaxFactor; 
        r += r * deltaRFactor;

        float xp = r * cos(alpha);
        float yp = r * sin(alpha);

        shape.setPoint(i, sf::Vector2f(xp, yp));
        body.addPoint({xp, yp});

        alpha += deltaAlpha;
    }
    shape.setFillColor(sf::Color::Transparent);
    shape.setOutlineThickness(asteroidLineThickness);
    shape.setOutlineColor(color);
    shape.scale(1/scaler, 1/scaler);
}

void Asteroid::randomPosition(){
    //window size
    const int width = window->getSize().x;
    const int height = window->getSize().y;
    //position on window
    //1 -> up
    //2 -> right
    //3 -> down
    //4 -> left
    const int side = rand() % 4;
    if(side == 0){
        this->position.x = (rand() % width) * scaler;
        this->position.y = -1 * (rand() % asteroidMargin) * scaler;
    }
    else if(side == 1){
        this->position.x = ((rand() % asteroidMargin) + width) * scaler;
        this->position.y = (rand() % height) * scaler;
    }
    else if(side == 2){
        this->position.x = (rand() % width) * scaler;
        this->position.y = ((rand() % asteroidMargin) + height) * scaler;
    }
    else if(side == 3){
        this->position.x = -1 * (rand() % asteroidMargin) * scaler;
        this->position.y = (rand() % height) * scaler;
    }
}

void Asteroid::randomMovement(Vector2D velocity){
    //velocity
    float v = (rand() % (int)(asteroidVelocityMax - asteroidVelocityMin)) + asteroidVelocityMin;
    float angle = (float)(rand() % 1000) / 1000.0f * 2 * M_PI;
    this->velocity.x = v * cos(angle) + velocity.x;
    this->velocity.y = v * sin(angle) + velocity.y;
    //rotation
    this->rotationSpeed = (rand() % asteroidMaxRotationSpeed);
}

void Asteroid::randomPlacement(){
    this->randomPosition();
    this->randomMovement({0, 0});
}

void Asteroid::updateKinematicProperties(){
    KinematicObject::updateKinematicProperties();
    //rotation
    float roatation = rotationSpeed * deltaTime;
    shape.rotate(rotation);
    body.rotate(rotation);
}

std::vector<Asteroid*> Asteroid::explode() const{
    return {};
}


