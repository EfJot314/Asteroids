#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include <unistd.h>
#include <cstdlib>
#include <cmath>
#include "constants.h"

//declare classes
class VisualObject;
class KinematicObject;
class Asteroid;
class Bullet;
class Game;
class GameEngine;
class Player;
class FireObject;
class Heart;
class Hearts;



class VisualObject{
    protected:
        int x;
        int y;
        sf::ConvexShape shape;
        sf::Color color;
        sf::RenderWindow* window;
    public:
        void draw();
};

class Heart : public VisualObject{
    private:
        void shapeFormation();
    public:
        Heart();
        Heart(sf::RenderWindow* window, sf::Color color, int x, int y);
        ~Heart();
        void makeEmpty();
        void makeFilled();
};

class Hearts : public VisualObject{
    private:
        int n;
        std::vector<Heart> hearts;
        void createHearts();
    public:
        Hearts();
        Hearts(sf::RenderWindow* window, sf::Color color, int n);
        Hearts(sf::RenderWindow* window, sf::Color color, int n, int x, int y);
        ~Hearts();
        void draw();
        void setHealth(int hp);
};

class KinematicObject : public VisualObject{
    protected:
        int hp = 1;
        int damage = 1;
        float position[2];
        float velocity[2];
        float boundR = 0;
        void updatePositionOnWindow();
        void borderJump();
    public:
        std::array<float, 2> getPosition();
        float getBoundRadius();
        int getDamage();
        int getHp();
        bool isDead();
        void updateKinematicProperties();
        void draw();
        void hit(int dmg);
};



class Asteroid : public KinematicObject{
    private:
        float rotation = 0;
        float rotationSpeed;
        void randomPlacement();
        void shapeFormation();
    public:
        Asteroid();
        Asteroid(sf::RenderWindow* window, sf::Color color);
        Asteroid(float positon[], float velocity[], float rotationSpeed, sf::RenderWindow* window, sf::Color color);
        ~Asteroid();
        void draw();
};



class Player : public KinematicObject{
    private:
        Hearts hearts;
        float acceleration[2];
        float rotation = 0;
        std::vector<FireObject*> fire;
        void shapeFormation();
        void addNewFire(FireObject* fireObject);
        void checkAndRemoveFire();
    public:
        Player();
        Player(sf::RenderWindow* window, sf::Color color);
        Player(float positon[], float velocity[], sf::RenderWindow* window, sf::Color color);
        ~Player();
        bool detectCollisions(std::vector<Asteroid*> asteroids);
        void accelerate(float acceleration);
        void rotate(int direction);
        void updateKinematicProperties();
        void updateFireKinematicProperties();
        void draw();
        void drawFire();
        void createFire();
        Bullet* shoot();
        std::array<float, 2> getEnginePosition();
        std::array<float, 2> getVelocity();
        void updateFire(int FPS);
};



class Bullet : public KinematicObject{
    private:
        float distance = 0.0f;
        Player* player;
        void shapeFormation();
    public:
        Bullet();
        Bullet(Player* player, float rotation, sf::RenderWindow* window, sf::Color color);
        ~Bullet();
        void updateKinematicProperties();
        bool detectCollisions(std::vector<Asteroid*> asteroids);
};



class FireObject : public KinematicObject{
    private:
        int durationCounter = 0;
        sf::Color fillingColor;
        Player* player;
        void shapeFormation();
    public:
        FireObject();
        FireObject(Player* player, float rotation, sf::RenderWindow* window, sf::Color color1, sf::Color color2);
        ~FireObject();
        bool incrementAndCheckDuration(int FPS);
};



class GameEngine{
    private:
        Player* player;
        std::vector<Asteroid*> asteroids;
        std::vector<Bullet*> bullets;
        void checkAndRemoveAsteroids();
        void checkAndRemoveBullets();
    public:
        GameEngine();
        GameEngine(Player* player);
        ~GameEngine();
        void addPlayer(Player* player);
        Player* getPlayer();
        void moveAll();
        void checkCollisions();
        void drawAll();
        void addAsteroid(Asteroid* asteroid);
        void addBullet(Bullet* bullet);
};



class Game{
    private:
        GameEngine ge;
        int FPS;
        int window_width;
        int window_height;
        bool gameFlag;
        sf::RenderWindow* window;
        void drawAll();
    public:
        Game();
        Game(int width, int height);
        ~Game();
        void run();
};

