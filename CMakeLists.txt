cmake_minimum_required(VERSION 3.10)


project(Asteroids)


include_directories(./include)
add_executable(Asteroids ./src/main.cpp ./src/Game.cpp ./src/GameEngine.cpp ./src/Player.cpp ./src/Asteroid.cpp ./src/Bullet.cpp)

#SFML
find_package(SFML COMPONENTS system window graphics) 
target_link_libraries(Asteroids PRIVATE sfml-system sfml-graphics sfml-window ) 