#include "interfaces.h"

CollisionBody::CollisionBody() {};

CollisionBody::CollisionBody(std::array<float, 2>& position, std::vector<std::array<float, 2>>& points) {
    this->position = position;
    this->points = points;
};

CollisionBody::~CollisionBody() {};

void CollisionBody::setPosition(std::array<float, 2>& position){
    this->position = position;
}

void CollisionBody::setPoints(std::vector<std::array<float, 2>>& points){
    this->points = points;
}

void CollisionBody::addPoint(std::array<float, 2>& point){
    this->points.push_back(point);
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

std::vector<std::array<float, 2>> CollisionBody::getPoints() const{
    return this->points;
}
