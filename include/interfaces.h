#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include <unistd.h>
#include <cstdlib>
#include <cmath>
#include "constants.h"


class Asteroid{
    private:
        int x;
        int y;
        float position[2];
        float velocity[2];
        float rotation = 0;
        float rotationSpeed;
        sf::Color color;
        sf::RenderWindow* window;
        void updatePositionOnWindow();
        void borderJump();
        void randomPlacement();
    public:
        Asteroid();
        Asteroid(sf::RenderWindow* window, sf::Color color);
        Asteroid(float positon[], float velocity[], float rotationSpeed, sf::RenderWindow* window, sf::Color color);
        ~Asteroid();
        std::array<float, 2> getPosition();
        void updateKinematicProperties();
        void draw();
};

class Player{
    private:
        int x;
        int y;
        float position[2];
        float velocity[2];
        float acceleration[2];
        float rotation = 0;
        sf::Color color;
        sf::RenderWindow* window;
        void updatePositionOnWindow();
        void borderJump();
    public:
        Player();
        Player(sf::RenderWindow* window, sf::Color color);
        Player(float positon[], float velocity[], sf::RenderWindow* window, sf::Color color);
        ~Player();
        std::array<float, 2> getPosition();
        void accelerate(float acceleration);
        void updateKinematicProperties();
        void rotate(int direction);
        void draw();
};



class GameEngine{
    private:
        Player* player;
        std::vector<Asteroid*> asteroids;
    public:
        GameEngine();
        GameEngine(Player* player);
        ~GameEngine();
        void addPlayer(Player* player);
        Player* getPlayer();
        void moveAll();
        void drawAll();
        void addAsteroid(Asteroid* asteroid);
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

