#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include <unistd.h>
#include <cstdlib>
#include <cmath>
#include "constants.h"

//declare classes
class Asteroid;
class Bullet;
class Game;
class GameEngine;
class Player;



class GameObject{
    protected:
        int x;
        int y;
        float position[2];
        float velocity[2];
        float boundR = 0;
        sf::ConvexShape shape;
        sf::Color color;
        sf::RenderWindow* window;
        void updatePositionOnWindow();
        void borderJump();
    public:
        std::array<float, 2> getPosition();
        float getBoundRadius();
        void updateKinematicProperties();
        void draw();
};


class Asteroid : public GameObject{
    private:
        int hp = 3;
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



class Player : public GameObject{
    private:
        float acceleration[2];
        float rotation = 0;
        void shapeFormation();

    public:
        Player();
        Player(sf::RenderWindow* window, sf::Color color);
        Player(float positon[], float velocity[], sf::RenderWindow* window, sf::Color color);
        ~Player();
        void accelerate(float acceleration);
        void updateKinematicProperties();
        void rotate(int direction);
        Bullet* shoot();
};



class Bullet : public GameObject{
    private:
        float distance = 0.0f;
        Player* player;
        void shapeFormation();
    public:
        Bullet();
        Bullet(Player* player, float rotation, sf::RenderWindow* window, sf::Color color);
        ~Bullet();
};






class GameEngine{
    private:
        Player* player;
        std::vector<Asteroid*> asteroids;
        std::vector<Bullet*> bullets;
    public:
        GameEngine();
        GameEngine(Player* player);
        ~GameEngine();
        void addPlayer(Player* player);
        Player* getPlayer();
        void moveAll();
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

