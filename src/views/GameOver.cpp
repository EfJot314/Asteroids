#include "interfaces.h"
#include <chrono>
#include <thread>




GameOver::GameOver(){};

GameOver::GameOver(sf::RenderWindow *window){

    this->window = window;

    window_width = window->getSize().x;
    window_height = window->getSize().y;

    //game over label
    game_over_label.setFont(starFontPath);
    game_over_label.setString("Game over");
    game_over_label.setCharacterSize(70);
    game_over_label.setFillColor(sf::Color::Yellow);

    //play button
    play_button.setFont(starFontPath);
    play_button.setString("Play");
    play_button.setCharacterSize(50);
    play_button.setFillColor(sf::Color::Red);
    play_button.setDimensions();

    //menu button
    menu_button.setFont(starFontPath);
    menu_button.setString("Main menu");
    menu_button.setCharacterSize(50);
    menu_button.setFillColor(sf::Color::Red);
    menu_button.setDimensions();

    //exit button
    exit_button.setFont(starFontPath);
    exit_button.setString("Exit");
    exit_button.setCharacterSize(50);
    exit_button.setFillColor(sf::Color::Red);
    exit_button.setDimensions();


};

GameOver::~GameOver(){};


void GameOver::drawAll(){
    window->clear();

    //draw background
    sf::RectangleShape background(sf::Vector2f(window_width, window_height));
    background.setFillColor(sf::Color::Black);
    window->draw(background);

    //labels and buttons
    game_over_label.setPosition(window_width/2, window_height/10);
    window->draw(game_over_label);

    play_button.setPosition(window_width/2, window_height*2/5);
    window->draw(play_button);

    menu_button.setPosition(window_width/2, window_height*3/5);
    window->draw(menu_button);

    exit_button.setPosition(window_width/2, window_height*4/5);
    window->draw(exit_button);

    //display results on window
    window->display();
};



int GameOver::run(){
    //mouse click variables
    bool play_click = false;
    bool menu_click = false;
    bool exit_click = false;

    //main loop
    std::chrono::high_resolution_clock::time_point frameStartTime = std::chrono::high_resolution_clock::now();
    while(gameOverFlag){

        //update widow size variables
        window_width = window->getSize().x;
        window_height = window->getSize().y;
        
        //mouse position
        mousePosition = sf::Mouse::getPosition(*window);

        //drawing all
        drawAll();
                

        //handle events  
        sf::Event event;
        while (window->pollEvent(event)) {
            //closing window
            if (event.type == sf::Event::Closed) {
                gameOverFlag = false;
                window->close();
            }
            //keyboard
            else if (event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Escape){
                    gameOverFlag = false;
                    window->close();
                }
            }
            //mouse
            else if (event.type == sf::Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if(play_button.checkOver(mousePosition.x, mousePosition.y)){
                        play_click = true;
                    }
                    else if(menu_button.checkOver(mousePosition.x, mousePosition.y)){
                        menu_click = true;
                    }
                    else if(exit_button.checkOver(mousePosition.x, mousePosition.y)){
                        exit_click = true;
                    }
                }
            }
            else if (event.type == sf::Event::MouseButtonReleased){
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if(play_click && play_button.checkOver(mousePosition.x, mousePosition.y)){
                        return 2;
                    }
                    else if(menu_click && menu_button.checkOver(mousePosition.x, mousePosition.y)){
                        return 0;
                    }
                    else if(exit_click && exit_button.checkOver(mousePosition.x, mousePosition.y)){
                        gameOverFlag = false;
                        return 1;
                    }
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

    this->clean_memory();

    return 0;
};