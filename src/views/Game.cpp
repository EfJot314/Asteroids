#include "interfaces.h"
#include <chrono>
#include <thread>




Game::Game(){};

Game::Game(sf::RenderWindow *window){

    this->window = window;

    window_width = window->getSize().x;
    window_height = window->getSize().y;

    //score label
    score_label.setFont(starFontPath);
    score_label.setString("Score: 240");
    score_label.setCharacterSize(20);
    score_label.setFillColor(YELLOW);

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

    //score label
    int score = ge.getPlayer().getScore();
    score_label.setString("Score: " + std::to_string(score));
    score_label.setPosition(15 + score_label.getDimensions()[0]/2, window_height - 15 - score_label.getDimensions()[1]/2);
    window->draw(score_label);

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
    int asteroidTimeCounter = 0;
    int bulletTimeCounter = 0;
    int fireTimeCounter = 0;
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
        asteroidTimeCounter++;
        bulletTimeCounter++;
        fireTimeCounter++;

        //generate new asteroid every 3 sec
        if(asteroidTimeCounter >= 3.0f * FPS){
            BigAsteroid* a = new BigAsteroid(window, BLUE);
            ge.addAsteroid(a);
            asteroidTimeCounter = 0;
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
        if(shoot && bulletTimeCounter >= bulletDelay * FPS){
            ge.addBullet(player.shoot());
            bulletTimeCounter = 0;
        }
        //fire creation
        if(fireTimeCounter >= fireDelay * FPS){
            player.createFire();
            fireTimeCounter = 0;
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

