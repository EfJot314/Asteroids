#include "interfaces.h"


Player::Player(){};

Player::Player(sf::RenderWindow* window, const sf::Color color){
    this->window = window;
    this->color = color;

    this->hp = 3;

    this->hearts = Hearts(this->window, RED, this->hp);

    this->position.x = window->getSize().x/2 * scaler;
    this->position.y = window->getSize().y/2 * scaler;
    this->velocity.x = 0;
    this->velocity.y = 0;
    this->acceleration.x = 0;
    this->acceleration.y = 0;

    shapeFormation();
};

Player::Player(Vector2D position, Vector2D velocity, sf::RenderWindow* window, const sf::Color color){
    this->window = window;
    this->color = color;

    this->hp = 3;

    this->hearts = Hearts(this->window, RED, this->hp);

    this->position = position;
    this->velocity = velocity;
    this->acceleration.x = 0;
    this->acceleration.y = 0;

    shapeFormation();
};

Player::~Player(){};


void Player::accelerate(float acceleration){
    this->acceleration.x = acceleration * sin(rotation * M_PI/ 180.0);
    this->acceleration.y = -1 * acceleration * cos(rotation * M_PI/ 180.0);
}

void Player::updateKinematicProperties(){
    float vx = velocity.x;
    float vy = velocity.y;

    vx += acceleration.x * deltaTime;
    vy += acceleration.y * deltaTime;

    //check max speed
    if(vx*vx + vy*vy <= playerMaxSpeed*playerMaxSpeed){
        velocity.x = vx;
        velocity.y = vy;
    }

    //update position
    KinematicObject::updateKinematicProperties();

    //reset acceleration
    this->acceleration.x = 0;
    this->acceleration.y = 0;

}

void Player::createFire(){
    const float fireRotation = this->rotation + (float)((rand() % (2*fireMaxAngleDeg)) - fireMaxAngleDeg);
    FireObject newFire(this, fireRotation, this->window, ORANGE, RED);
    addNewFire(newFire);
}

void Player::addNewFire(FireObject& fireObject){
    this->fire.push_back(fireObject);
}

bool isDeadObject(KinematicObject& o){
    return o.isDead();
}

void Player::checkAndRemoveFire(){
    this->fire.erase(std::remove_if(this->fire.begin(), this->fire.end(), isDeadObject), this->fire.end());
}

void Player::updateFireKinematicProperties(){
    for(int i=0;i<this->fire.size();i++){
        fire[i].updateKinematicProperties();
    }
    checkAndRemoveFire();
}

void Player::draw(){
    //draw player hearts
    this->hearts.draw();
    if(this->hitTimer < playerUntouchableTime){
        const int n = (int)(this->hitTimer / (playerUntouchableTime / (2.0f*(float)playerNoBlinks)));
        if(n % 2 == 0)  
            this->shape.setFillColor(TRANSPARENT);
        else            
            this->shape.setFillColor(this->color);
    }
    else{
        this->shape.setFillColor(this->color);
    }
    //draw fire
    this->drawFire();
    //draw player
    KinematicObject::draw();
}

void Player::drawFire(){
    for(int i=0;i<this->fire.size();i++){
        fire[i].draw();
    }
}

void Player::updateFire(int FPS){
    bool checkAndRemove = false;
    for(int i=0;i<this->fire.size();i++){
        if(fire[i].incrementAndCheckDuration(FPS)){
            checkAndRemove = true;
        }
    }
    if(checkAndRemove){
        checkAndRemoveFire();
    }
}

void Player::rotate(direction_e direction){
    float rotationDelta = direction * playerRotationSpeed;
    rotation += rotationDelta;
    shape.rotate(rotationDelta);
    body.rotate(rotationDelta);
}

void Player::shapeFormation(){
    //collision body
    this->body.setPosition(position);

    //factors
    const float body_len_factor = 7.0/8.0;
    const float body_width_factor = 2.0/3.0;
    const float engine_len_factor = 1.0/8.0;
    const float engine_width_factor_1 = 1.0/6.0;
    const float engine_width_factor_2 = 1.0/2.0;
    //real lengths
    const float body_len = body_len_factor * playerLen;
    const float body_width = body_width_factor * playerLen;
    const float engine_len = engine_len_factor * playerLen;
    const float engine_width_1 = engine_width_factor_1 * playerLen;
    const float engine_width_2 = engine_width_factor_2 * playerLen;
    //creating player shape
    shape.setPointCount(7);
    shape.setPoint(0, sf::Vector2f(0, -body_len*2/3));
    body.addPoint({0, -body_len*2/3});
    shape.setPoint(1, sf::Vector2f(body_width/2, body_len*1/3));
    body.addPoint({body_width/2, body_len*1/3});
    shape.setPoint(2, sf::Vector2f(engine_width_1/2, body_len*1/3));
    body.addPoint({engine_width_1/2, body_len*1/3});
    shape.setPoint(3, sf::Vector2f(engine_width_2/2, body_len*1/3 + engine_len));
    body.addPoint({engine_width_2/2, body_len*1/3 + engine_len});
    shape.setPoint(4, sf::Vector2f(-engine_width_2/2, body_len*1/3 + engine_len));
    body.addPoint({-engine_width_2/2, body_len*1/3 + engine_len});
    shape.setPoint(5, sf::Vector2f(-engine_width_1/2, body_len*1/3));
    body.addPoint({-engine_width_1/2, body_len*1/3});
    shape.setPoint(6, sf::Vector2f(-body_width/2, body_len*1/3));
    body.addPoint({-body_width/2, body_len*1/3});

    //shape properties
    shape.setFillColor(color);
    shape.scale(1/scaler, 1/scaler);
}


Bullet* Player::shoot(){
    Bullet* bullet = new Bullet(this, this->rotation, this->window, this->color);
    return bullet;
}


bool Player::detectCollisions(std::vector<Asteroid*>& asteroids){
    //check untouchability
    if(hitTimer < playerUntouchableTime)    return false;
    //check collisions
    bool collided = false;
    for(int i=0;i<asteroids.size();i++){
        if(this->body.checkCollision(asteroids[i]->getBody())){
            // asteroids[i]->hit(this->damage);
            this->hit(asteroids[i]->getDamage());
            hitTimer = 0;
            this->hearts.setHealth(this->hp);
            collided = true;
        }
    }
    return collided;
}


Vector2D Player::getEnginePosition() const{
    Vector2D enginePosition;
    enginePosition.x = position.x + sin(this->rotation);
    enginePosition.y = position.y + cos(this->rotation);
    return enginePosition;
}

Vector2D Player::getVelocity() const{
    return velocity;
}

void Player::updateTimer(int FPS){
    hitTimer += 1.0f / (float)FPS;
}

void Player::addToScore(int points){
    score += points;
}

int Player::getScore() const{
    return score;
}

