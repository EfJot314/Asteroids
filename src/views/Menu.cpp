#include "interfaces.h"
#include <chrono>
#include <thread>




Menu::Menu(){};

Menu::Menu(int width, int height){
    window_width = width;
    window_height = height;

    //create window
    window = new sf::RenderWindow(sf::VideoMode(window_width, window_height), "Asteroids", sf::Style::Titlebar | sf::Style::Close);

    //create title label
    title_label.setFont(starFontPath);
    title_label.setText("Asteroids");
    title_label.setSize(70);
    title_label.setColor(sf::Color::Yellow);

};

Menu::~Menu(){};


void Menu::drawAll(){
    window->clear();

    //draw background
    sf::RectangleShape background(sf::Vector2f(window_width, window_height));
    background.setFillColor(sf::Color::Black);
    window->draw(background);

    //labels
    // title_label.setPosition(window_width/2, window_height/10);
    title_label.draw(window);

    //display results on window
    window->display();
};



void Menu::run(){
    std::chrono::high_resolution_clock::time_point frameStartTime = std::chrono::high_resolution_clock::now();
    while(menuFlag){

        //update widow size variables
        window_width = window->getSize().x;
        window_height = window->getSize().y;

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
            //player controll
            if (event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::W){
                    
                }
            }
            if (event.type == sf::Event::KeyReleased){
                if(event.key.code == sf::Keyboard::W){
                    
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