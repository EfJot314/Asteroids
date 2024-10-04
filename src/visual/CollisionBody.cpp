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
    // return;
    // float x = position.x;
    // float y = position.y;
    float x = 0.0f;
    float y = 0.0f;
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

std::vector<std::array<Vector2D, 2>> CollisionBody::getSectionsRel() const{
    std::vector<std::array<Vector2D, 2>> sections = {};
    int n = this->getNoPoints();
    for(int i=0;i<n;i++){
        sections.push_back({points[i], points[(i+1) % n]});
    }
    return sections;
}

std::vector<std::array<Vector2D, 2>> CollisionBody::getSectionsGlob() const{
    auto sections = this->getSectionsRel();
    for(int i=0;i<this->getNoPoints();i++){
        sections[i][0].x += position.x;
        sections[i][0].y += position.y;
        sections[i][1].x += position.x;
        sections[i][1].y += position.y;
    }
    return sections;
}

bool CollisionBody::checkIntersection(const std::array<Vector2D, 2>& AB, const std::array<Vector2D, 2>& CD) const{
    //vector v = AB
    Vector2D v;
    v.x = AB[1].x - AB[0].x;
    v.y = AB[1].y - AB[0].y;
    //vector a = AC
    Vector2D a;
    a.x = CD[0].x - AB[0].x;
    a.y = CD[0].y - AB[0].y;
    //vector b = AD
    Vector2D b;
    b.x = CD[1].x - AB[0].x;
    b.y = CD[1].y - AB[0].y;

    //results of vector multiplications
    float zva = v.x*a.y - v.y*a.x;
    float zvb = v.x*b.y - v.y*b.x;

    //return boolean value
    if(zva * zvb < 0){
        return true;
    }
    return false;
}

bool CollisionBody::checkCollision(CollisionBody other){
    this->updatePoints();
    other.updatePoints();

    float radiusSum = this->getBoundRadius() + other.getBoundRadius();
    Vector2D otherPosition = other.getPosition();
    float distanceSq = (position.x-otherPosition.x)*(position.x-otherPosition.x) + (position.y-otherPosition.y)*(position.y-otherPosition.y);
    if(distanceSq < radiusSum*radiusSum){

        auto mySections = this->getSectionsGlob();
        auto otherSections = other.getSectionsGlob();

        for(const auto& mySection : mySections){
            for(const auto& otherSection : otherSections){
                if(checkIntersection(mySection, otherSection)) return true;
            }
        }
    }
    return false;
}
