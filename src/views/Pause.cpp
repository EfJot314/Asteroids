#include "interfaces.h"
#include <chrono>
#include <thread>




Pause::Pause(){};

Pause::Pause(sf::RenderWindow *window){

    this->window = window;

    window_width = window->getSize().x;
    window_height = window->getSize().y;

    //pause label
    pause_label.setFont(starFontPath);
    pause_label.setString("pause");
    pause_label.setCharacterSize(70);
    pause_label.setFillColor(sf::Color::Yellow);

    //resume button
    resume_button.setFont(starFontPath);
    resume_button.setString("resume");
    resume_button.setCharacterSize(50);
    resume_button.setFillColor(sf::Color::Red);
    resume_button.setDimensions();

    //menu button
    menu_button.setFont(starFontPath);
    menu_button.setString("main menu");
    menu_button.setCharacterSize(50);
    menu_button.setFillColor(sf::Color::Red);
    menu_button.setDimensions();

    //exit button
    exit_button.setFont(starFontPath);
    exit_button.setString("exit");
    exit_button.setCharacterSize(50);
    exit_button.setFillColor(sf::Color::Red);
    exit_button.setDimensions();


};

Pause::~Pause(){};


void Pause::drawAll(){
    window->clear();

    //draw background
    sf::RectangleShape background(sf::Vector2f(window_width, window_height));
    background.setFillColor(sf::Color::Black);
    window->draw(background);

    //labels and buttons
    pause_label.setPosition(window_width/2, window_height/10);
    window->draw(pause_label);

    resume_button.setPosition(window_width/2, window_height*2/5);
    window->draw(resume_button);

    menu_button.setPosition(window_width/2, window_height*3/5);
    window->draw(menu_button);

    exit_button.setPosition(window_width/2, window_height*4/5);
    window->draw(exit_button);

    //display results on window
    window->display();
};



int Pause::run(){
    //mouse click variables
    bool resume_click = false;
    bool menu_click = false;
    bool exit_click = false;

    //main loop
    std::chrono::high_resolution_clock::time_point frameStartTime = std::chrono::high_resolution_clock::now();
    while(pauseFlag){

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
                pauseFlag = false;
                window->close();
            }
            //keyboard
            else if (event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Escape){
                    return PLAY_STATUS_CODE;
                }
            }
            //mouse
            else if (event.type == sf::Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if(resume_button.checkOver(mousePosition.x, mousePosition.y)){
                        resume_click = true;
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
                    if(resume_click && resume_button.checkOver(mousePosition.x, mousePosition.y)){
                        return PLAY_STATUS_CODE;
                    }
                    else if(menu_click && menu_button.checkOver(mousePosition.x, mousePosition.y)){
                        return MENU_STATUS_CODE;
                    }
                    else if(exit_click && exit_button.checkOver(mousePosition.x, mousePosition.y)){
                        return EXIT_STATUS_CODE;
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

    return 0;
};