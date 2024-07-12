cmake_minimum_required(VERSION 3.10)


project(Asteroids)


include_directories(./include)
add_executable(Asteroids ./src/main.cpp ./src/logic/Game.cpp ./src/logic/GameEngine.cpp ./src/visual/kinematic/Player.cpp ./src/visual/kinematic/Asteroid.cpp ./src/visual/kinematic/Bullet.cpp ./src/abstract/KinematicObject.cpp ./src/abstract/VisualObject.cpp ./src/visual/kinematic/FireObject.cpp ./src/visual/Heart.cpp ./src/visual/Hearts.cpp)

#SFML
find_package(SFML COMPONENTS system window graphics) 
target_link_libraries(Asteroids PRIVATE sfml-system sfml-graphics sfml-window ) 
