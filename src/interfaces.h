#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include <unistd.h>
#include <cstdlib>
#include <math.h>
#include "constants.h"


class Player{
    private:
        int x;
        int y;
        float position[2];
        float velocity[2];
        float rotation = 0;
        sf::Color color;
        sf::RenderWindow* window;
        void updatePositionOnWindow();
    public:
        Player();
        Player(sf::RenderWindow* window, sf::Color color);
        Player(float positon[], float velocity[], sf::RenderWindow* window, sf::Color color);
        ~Player();
        std::array<float, 2> getPosition();
        void updateKinematicProperties();
        void rotate(int direction);
        void draw();
};



class GameEngine{
    private:
        Player* player;
    public:
        GameEngine();
        GameEngine(Player* player);
        ~GameEngine();
        void addPlayer(Player* player);
        Player* getPlayer();
        void moveAll();
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

