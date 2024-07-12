cmake_minimum_required(VERSION 3.10)

project(Asteroids)


#define includes
include_directories(./include)

#compile libraries
add_library(LogicLib ./src/logic/Game.cpp ./src/logic/GameEngine.cpp)
add_library(ObjectsLib ./src/abstract/VisualObject.cpp ./src/abstract/KinematicObject.cpp ./src/visual/Heart.cpp ./src/visual/Hearts.cpp ./src/visual/kinematic/Player.cpp ./src/visual/kinematic/Asteroid.cpp ./src/visual/kinematic/Bullet.cpp ./src/visual/kinematic/FireObject.cpp)

#create executable
add_executable(Asteroids ./src/main.cpp)

#libraries
target_link_libraries(Asteroids PRIVATE LogicLib ObjectsLib) 

#SFML
find_package(SFML COMPONENTS system window graphics) 
target_link_libraries(Asteroids PRIVATE sfml-system sfml-graphics sfml-window) 

