#include "interfaces.h"

CollisionBody::CollisionBody() {};

CollisionBody::CollisionBody(std::array<float, 2>& position, std::vector<std::array<float, 2>>& points) {
    this->position = position;
    this->points = points;
    this->boundRadius = this->findBoundRadius();
}

CollisionBody::~CollisionBody() {};

void CollisionBody::setPosition(std::array<float, 2>& position){
    this->position = position;
    this->boundRadius = this->findBoundRadius();
}

void CollisionBody::setPoints(std::vector<std::array<float, 2>>& points){
    this->points = points;
    this->boundRadius = this->findBoundRadius();
}

void CollisionBody::addPoint(std::array<float, 2>& point){
    this->points.push_back(point);
    this->boundRadius = this->findBoundRadius();
}

void CollisionBody::rotate(float rotation){    
    this->rotation += rotation;
}

std::array<float, 2> CollisionBody::getPosition() const{
    return this->position;
}

int CollisionBody::getNoPoints() const{
    return this->points.size();
}

float CollisionBody::findBoundRadius() const{
    float brSq = 0.0f;
    for(int i=0;i<this->getNoPoints();i++){
        float rSq = (points[i][0]-position[0])*(points[i][0]-position[0]) + (points[i][1]-position[1])*(points[i][1]-position[1]);
        if(rSq > brSq){
            brSq = rSq;
        }
    }
    return std::sqrt(brSq);
}

float CollisionBody::getBoundRadius() const{
    return this->boundRadius;
}

void CollisionBody::updatePoints(){
    float x = position[0];
    float y = position[1];
    float radiansRotation = this->rotation * M_PI / 180.0f;
    for(int i=0;i<this->getNoPoints();i++){
        float xp = points[i][0];
        float yp = points[i][1];
        float r = std::sqrt((x-xp)*(x-xp) + (y-yp)*(y-yp));

        float sina = yp / r;
        float cosa = xp / r;
        float sinb = std::sin(radiansRotation);
        float cosb = std::cos(radiansRotation);

        float sinapb = sina*cosb + sinb*cosa;
        float cosapb = cosa*cosb - sina*sinb;

        xp = r * cosapb;
        yp = r * sinapb;

        this->points[i][0] = xp;
        this->points[i][1] = yp;
    }
    this->rotation = 0.0f;
}

std::vector<std::array<float, 2>> CollisionBody::getPoints() const{
    return this->points;
}

bool CollisionBody::checkCollision(CollisionBody* other) const{
    float radiusSum = this->getBoundRadius() + other->getBoundRadius();
    std::array<float, 2> otherPosition = other->getPosition();
    float distanceSq = (position[0]-otherPosition[0])*(position[0]-otherPosition[0]) + (position[1]-otherPosition[1])*(position[1]-otherPosition[1]);
    if(distanceSq < radiusSum*radiusSum){
        //TODO - actually really basic
        return true;
    }
    return false;
}
