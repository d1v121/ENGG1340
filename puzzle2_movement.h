//conains declarations for puzzle_movement.cpp
#ifndef puzzle2_movement
#define puzzle2_movement

#include <iostream>
using namespace std;

const int width2 = 11; //width of the map for puzzle 2
const int height2 = 9; //height of the map for puzzle 2 

void printmap(const char map[][width2], int w, int h, int Xpos, int Ypos); //declaration for the printmap function
void puzzle2(int &Xpos2, int &YPos2); //declaration for the puzzle2 function

extern char map_2_empty[height2][width2]; //declaration for the puzzle 2 map that has the path hidden 

extern char map_2_path[height2][width2]; //declaration for the puzzle 2 map that has the path shown


extern int Xpos2; //declaration for the x position of the player in puzzle 2 
extern int Ypos2; //declaration for the y position of the player in puzzle 2

#endif 
