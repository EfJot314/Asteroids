#include "interfaces.h"
#include <chrono>
#include <thread>




Menu::Menu(){};

Menu::Menu(int width, int height){
    window_width = width;
    window_height = height;

    //create window
    window = new sf::RenderWindow(sf::VideoMode(window_width, window_height), "Asteroids", sf::Style::Titlebar | sf::Style::Close);

    //title label
    title_label.setFont(starFontPath);
    title_label.setString("Asteroids");
    title_label.setCharacterSize(70);
    title_label.setFillColor(sf::Color::Yellow);

    //play button
    play_button.setFont(starFontPath);
    play_button.setString("Play");
    play_button.setCharacterSize(50);
    play_button.setFillColor(sf::Color::Red);
    play_button.setDimensions();

    //quit button
    exit_button.setFont(starFontPath);
    exit_button.setString("Exit");
    exit_button.setCharacterSize(50);
    exit_button.setFillColor(sf::Color::Red);
    exit_button.setDimensions();


};

Menu::~Menu(){};


void Menu::drawAll(){
    window->clear();

    //draw background
    sf::RectangleShape background(sf::Vector2f(window_width, window_height));
    background.setFillColor(sf::Color::Black);
    window->draw(background);

    //labels and buttons
    title_label.setPosition(window_width/2, window_height/10);
    window->draw(title_label);

    play_button.setPosition(window_width/2, window_height/2);
    window->draw(play_button);

    exit_button.setPosition(window_width/2, window_height*3/4);
    window->draw(exit_button);

    //display results on window
    window->display();
};



void Menu::run(){
    //mouse click variables
    bool play_click = false;
    bool exit_click = false;

    //main loop
    std::chrono::high_resolution_clock::time_point frameStartTime = std::chrono::high_resolution_clock::now();
    while(menuFlag){

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
                menuFlag = false;
                window->close();
            }
            //keyboard
            else if (event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Escape){
                    menuFlag = false;
                    window->close();
                }
            }
            //mouse
            else if (event.type == sf::Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if(play_button.checkOver(mousePosition.x, mousePosition.y)){
                        play_click = true;
                    }
                    else if(exit_button.checkOver(mousePosition.x, mousePosition.y)){
                        exit_click = true;
                    }
                }
            }
            else if (event.type == sf::Event::MouseButtonReleased){
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if(play_click && play_button.checkOver(mousePosition.x, mousePosition.y)){
                        //TODO
                    }
                    else if(exit_click && exit_button.checkOver(mousePosition.x, mousePosition.y)){
                        menuFlag = false;
                        window->close();
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
};


void Menu::clean_memory(){
    delete window;
}