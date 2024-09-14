#include "interfaces.h"
#include <chrono>
#include <thread>




Game::Game(){};

Game::Game(sf::RenderWindow *window){

    this->window = window;

    window_width = window->getSize().x;
    window_height = window->getSize().y;

    //create game engine
    ge = GameEngine();

    //add player
    Player player(window, GRAY);
    ge.addPlayer(player);
};

Game::~Game(){};


void Game::drawAll(){
    window->clear();

    //draw background
    sf::RectangleShape background(sf::Vector2f(window_width, window_height));
    background.setFillColor(sf::Color::Black);
    window->draw(background);

    //draw all
    ge.drawAll();

    //display results on window
    window->display();
};



int Game::run(){

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
            Asteroid asteroid(window, BLUE);
            ge.addAsteroid(asteroid);
            asteroidCounter = 0;
        }

        //get player
        Player& player = ge.getPlayer();

        //rotating
        if(rotateRight){
            player.rotate(right);
        }
        if(rotateLeft){
            player.rotate(left);
        }
        //acceleration
        if(accelearate){
            player.accelerate(playerAcceleration);
        }
        //shooting
        if(shoot && bulletCounter >= bulletDelay * FPS){
            ge.addBullet(player.shoot());
            bulletCounter = 0;
        }
        //fire creation
        if(fireCounter >= fireDelay * FPS){
            player.createFire();
            fireCounter = 0;
        }
        //fire update
        player.updateFire(FPS);
        //timers update
        player.updateTimer(FPS);

        //game over
        if(player.isDead()){
            gameFlag = false;
        }
        
        
        //handle events  
        sf::Event event;
        while (window->pollEvent(event)) {
            //closing window
            if (event.type == sf::Event::Closed) {
                return EXIT_STATUS_CODE;
            }
            //player controll
            else if (event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::W){
                    accelearate = true;
                }
                else if(event.key.code == sf::Keyboard::D){
                    rotateRight = true;
                }
                else if(event.key.code == sf::Keyboard::A){
                    rotateLeft = true;
                }
                else if(event.key.code == sf::Keyboard::Space){
                    shoot = true;
                }
                else if(event.key.code == sf::Keyboard::Escape){
                    Pause pauseMenu(this->window);
                    int status = pauseMenu.run();
                    if(status != PLAY_STATUS_CODE){
                        return status;
                    }
                }
            }
            else if (event.type == sf::Event::KeyReleased){
                if(event.key.code == sf::Keyboard::W){
                    accelearate = false;
                }
                else if(event.key.code == sf::Keyboard::D){
                    rotateRight = false;
                }
                else if(event.key.code == sf::Keyboard::A){
                    rotateLeft = false;
                }
                else if(event.key.code == sf::Keyboard::Space){
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

    //return value from game over menu
    GameOver gameOverMenu(this->window);
    return gameOverMenu.run();
};

