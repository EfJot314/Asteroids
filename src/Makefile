main:
	g++ -c main.cpp Game.cpp Player.cpp GameEngine.cpp
	g++ Player.o -o Player GameEngine.o -o GameEngine Game.o -o Game main.o -o main -lsfml-graphics -lsfml-window -lsfml-system


clean:
	rm -f main main.o Vector2d Vector2d.o Player Player.o Game Game.o GameEngine GameEngine.o

all:
	make clean
	make main



