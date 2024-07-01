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
    ge.addPlayer(new Player(window, GRAY));
};

Game::~Game(){};


void Game::drawAll(){
    sf::RectangleShape background(sf::Vector2f(window_width, window_height));
    background.setFillColor(sf::Color::Black);

    window->clear();

    //draw background
    window->draw(background);

    //draw all
    ge.drawAll();

    //display results on window
    window->display();
};



void Game::run(){

    //player controll variables
    bool accelearate = false;
    bool rotateLeft = false;
    bool rotateRight = false;
    bool shoot = false;


    //main loop
    int asteroidCounter = 0;
    int bulletCounter = 0;
    int fireCounter = 0;
    std::chrono::high_resolution_clock::time_point frameStartTime = std::chrono::high_resolution_clock::now();
    while(gameFlag){

        //update widow size variables
        window_width = window->getSize().x;
        window_height = window->getSize().y;

        //drawing all
        drawAll();

        //moving all objects
        ge.moveAll();

        //collisions
        ge.checkCollisions();

        //increment counters
        asteroidCounter++;
        bulletCounter++;
        fireCounter++;

        //generate new asteroid every 3 sec
        if(asteroidCounter >= 3.0f * FPS){
            Asteroid* asteroid = new Asteroid(window, BLUE);
            ge.addAsteroid(asteroid);
            asteroidCounter = 0;
        }

        //rotating
        if(rotateRight){
            Player* player = ge.getPlayer();
            player->rotate(1);
        }
        if(rotateLeft){
            Player* player = ge.getPlayer();
            player->rotate(-1);
        }
        //acceleration
        if(accelearate){
            Player* player = ge.getPlayer();
            player->accelerate(playerAcceleration);
        }
        //shooting
        if(shoot && bulletCounter >= bulletDelay * FPS){
            Player* player = ge.getPlayer();
            ge.addBullet(player->shoot());
            bulletCounter = 0;
        }
        //fire
        if(fireCounter >= fireDelay * FPS){
            Player* player = ge.getPlayer();
            player->createFire();
            fireCounter = 0;
        }
        
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
                if(event.key.code == sf::Keyboard::W){
                    accelearate = true;
                }
                if(event.key.code == sf::Keyboard::D){
                    rotateRight = true;
                }
                if(event.key.code == sf::Keyboard::A){
                    rotateLeft = true;
                }
                if(event.key.code == sf::Keyboard::Space){
                    shoot = true;
                }
            }
            if (event.type == sf::Event::KeyReleased){
                if(event.key.code == sf::Keyboard::W){
                    accelearate = false;
                }
                if(event.key.code == sf::Keyboard::D){
                    rotateRight = false;
                }
                if(event.key.code == sf::Keyboard::A){
                    rotateLeft = false;
                }
                if(event.key.code == sf::Keyboard::Space){
                    shoot = false;
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