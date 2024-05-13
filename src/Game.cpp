#include "interfaces.h"
#include <chrono>
#include <thread>




Game::Game(){};

Game::Game(int width, int height){
    gameFlag = true;
    window_width = width;
    window_height = height;
    FPS = 60;

    //create window
    window = new sf::RenderWindow(sf::VideoMode(window_width, window_height), "Asteroids", sf::Style::Titlebar | sf::Style::Close);

    //create game engine
    ge = GameEngine();

    //add player
    ge.addPlayer(new Player(window, sf::Color::Red));
};

Game::~Game(){};


void Game::drawAll(){
    sf::RectangleShape background(sf::Vector2f(window_width, window_height));
    background.setFillColor(sf::Color::Black);

    window->clear();

    //draw background
    window->draw(background);

    //draw player
    Player* player = ge.getPlayer();
    player->draw();

    //display results on window
    window->display();
};



void Game::run(){

    //main loop
    std::chrono::high_resolution_clock::time_point frameStartTime = std::chrono::high_resolution_clock::now();
    while(gameFlag){

        //update widow size variables
        window_width = window->getSize().x;
        window_height = window->getSize().y;

        //drawing all
        drawAll();

        //moving all objects
        ge.moveAll();
        
        //handle events
        sf::Event event;
        while (window->pollEvent(event)) {
            //closing window
            if (event.type == sf::Event::Closed) {
                gameFlag = false;
                window->close();
            }
            //player controll
            if (event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::D){
                    //rotate right
                    Player* player = ge.getPlayer();
                    player->rotate(1);
                }
                if(event.key.code == sf::Keyboard::A){
                    //rotate left
                    Player* player = ge.getPlayer();
                    player->rotate(-1);
                }
            }
        }

        //clock and FPS control
        std::chrono::high_resolution_clock::time_point frameEndTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> frameDuration = frameEndTime - frameStartTime;
        std::chrono::duration<float> sleepDuration = std::chrono::duration<float, std::milli>(1000.0f / FPS) - frameDuration;
        std::this_thread::sleep_for(sleepDuration);
        frameStartTime = std::chrono::high_resolution_clock::now();


    }

    window->close();


};