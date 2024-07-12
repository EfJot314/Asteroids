cmake_minimum_required(VERSION 3.10)

project(Asteroids)


#abstract files
file(GLOB abstract_src
    "./src/abstract/*.cpp"
)

#logic files
file(GLOB logic_src
    "./src/logic/*.cpp"
)

#visual files
file(GLOB visual_src
    "./src/visual/*.cpp"
)

#kinematic files
file(GLOB kinematic_src
    "./src/visual/kinematic/*.cpp"
)


#define includes
include_directories(./include)

#compile libraries
add_library(LogicLib ${logic_src})
add_library(ObjectsLib ${abstract_src} ${visual_src} ${kinematic_src})

#create executable
add_executable(Asteroids ./src/main.cpp)

#libraries
target_link_libraries(Asteroids PRIVATE LogicLib ObjectsLib) 

#SFML
find_package(SFML COMPONENTS system window graphics) 
target_link_libraries(Asteroids PRIVATE sfml-system sfml-graphics sfml-window) 

