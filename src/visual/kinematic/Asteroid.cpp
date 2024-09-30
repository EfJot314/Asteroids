#include "interfaces.h"


Asteroid::Asteroid(){};

Asteroid::Asteroid(sf::RenderWindow* window, const sf::Color color){
    this->window = window;
    this->color = color;

    this->hp = 3;

    randomPlacement();
    shapeFormation();
};

Asteroid::Asteroid(const Asteroid* const father, sf::RenderWindow* window, const sf::Color color){
    this->window = window;
    this->color = color;

    this->hp = 3;

    position[0] = father->getPosition()[0];
    position[1] = father->getPosition()[1];

    this->randomMovement(father->getVelocity());

    shapeFormation();
}

Asteroid::~Asteroid(){};

void Asteroid::shapeFormation(){
    this->asteroidShapeFormation(asteroidShapeN, asteroidRadius);
}

void Asteroid::asteroidShapeFormation(int n, float radius){
    //create collision body of the Asteroid
    this->body = new CollisionBody();
    this->body->setPosition({position[0], position[1]});

    boundR = 0;
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
        this->body->addPoint({xp, yp});

        alpha += deltaAlpha;

        //check bound radius
        if(r > boundR){
            boundR = r;
        }
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
}

void Asteroid::randomMovement(std::array<float, 2> velocity){
    //velocity
    float v = (rand() % (int)(asteroidVelocityMax - asteroidVelocityMin)) + asteroidVelocityMin;
    float angle = (float)(rand() % 1000) / 1000.0f * 2 * M_PI;
    this->velocity[0] = v * cos(angle) + velocity[0];
    this->velocity[1] = v * sin(angle) + velocity[1];
    //rotation
    this->rotationSpeed = (rand() % asteroidMaxRotationSpeed);
}

void Asteroid::randomPlacement(){
    this->randomPosition();
    this->randomMovement({0, 0});
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

std::vector<Asteroid*> Asteroid::explode() const{
    return {};
}


