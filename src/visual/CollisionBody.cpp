#include "interfaces.h"

CollisionBody::CollisionBody() {};

CollisionBody::CollisionBody(Vector2D& position, std::vector<Vector2D>& points) {
    this->position = position;
    this->points = points;
    this->boundRadius = this->findBoundRadius();
}

CollisionBody::~CollisionBody() {};

void CollisionBody::setPosition(Vector2D position){
    this->position = position;
    this->boundRadius = this->findBoundRadius();
}

void CollisionBody::setPoints(std::vector<Vector2D>& points){
    this->points = points;
    this->boundRadius = this->findBoundRadius();
}

void CollisionBody::addPoint(Vector2D point){
    this->points.push_back(point);
    this->boundRadius = this->findBoundRadius();
}

void CollisionBody::rotate(float rotation){    
    this->rotation += rotation;
}

Vector2D CollisionBody::getPosition() const{
    return this->position;
}

int CollisionBody::getNoPoints() const{
    return this->points.size();
}

float CollisionBody::findBoundRadius() const{
    float brSq = 0.0f;
    for(int i=0;i<this->getNoPoints();i++){
        float rSq = (points[i].x)*(points[i].x) + (points[i].y)*(points[i].y);
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
    float x = position.x;
    float y = position.y;
    float radiansRotation = this->rotation * M_PI / 180.0f;
    for(int i=0;i<this->getNoPoints();i++){
        float xp = points[i].x;
        float yp = points[i].y;
        float r = std::sqrt((x-xp)*(x-xp) + (y-yp)*(y-yp));

        float sina = yp / r;
        float cosa = xp / r;
        float sinb = std::sin(radiansRotation);
        float cosb = std::cos(radiansRotation);

        float sinapb = sina*cosb + sinb*cosa;
        float cosapb = cosa*cosb - sina*sinb;

        xp = r * cosapb;
        yp = r * sinapb;

        this->points[i].x = xp;
        this->points[i].y = yp;
    }
    this->rotation = 0.0f;
}

std::vector<Vector2D> CollisionBody::getPoints() const{
    return this->points;
}

std::vector<std::array<Vector2D, 2>> CollisionBody::getSections() const{
    std::vector<std::array<Vector2D, 2>> sections = {};
    int n = this->getNoPoints();
    for(int i=0;i<n;i++){
        sections.push_back({points[i], points[(i+1) % n]});
    }
    return sections;
}

bool CollisionBody::checkIntersection(const std::array<Vector2D, 2>& AB, const std::array<Vector2D, 2>& CD) const{
    //TODO
    return true;
}

bool CollisionBody::checkCollision(CollisionBody other){
    this->updatePoints();
    other.updatePoints();

    float radiusSum = this->getBoundRadius() + other.getBoundRadius();
    Vector2D otherPosition = other.getPosition();
    float distanceSq = (position.x-otherPosition.x)*(position.x-otherPosition.x) + (position.y-otherPosition.y)*(position.y-otherPosition.y);
    if(distanceSq < radiusSum*radiusSum){

        auto mySections = this->getSections();
        auto otherSections = this->getSections();

        for(const auto& mySection : mySections){
            for(const auto& otherSection : otherSections){
                if(checkIntersection(mySection, otherSection)) return true;
            }
        }
    }
    return false;
}
