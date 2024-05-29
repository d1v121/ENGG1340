flags = -pedantic-errors -std=c++11

playermovement.o: playermovement.cpp playermovement.h
	g++ $(flags) -c playermovement.cpp

puzzle2_movement.o: puzzle2_movement.cpp puzzle2_movement.h
	g++ $(flags) -c puzzle2_movement.cpp

animations.o: animations.cpp animations.h
	g++ $(flags) -c animations.cpp

main.o: main.cpp playermovement.h puzzle2_movement.h animations.h
	g++ $(flags) -c main.cpp

main: playermovement.o puzzle2_movement.o animations.o main.o 
	g++ $^ -o $@

runexec: main
	./main


