#ifndef playermovement
#define playermovement

#include <iostream>
using namespace std;

const int width = 13; //setting the width of the map to be 13
const int height = 11; //setting the height of the map to be 11
extern int Xpos; //X position of the player 
extern int Ypos; //Y position of the player 


void printmap(const char map[][width], int w, int h, int Xpos, int Ypos); 
//declaration for the printmap function, definition in playermovement.cpp
//What it does: prints the map
//Input: takes in the map array, the width of the map, the height of the map and the position of the player which has coordinates Xpos and Ypos 
//Output: does not return a value

extern char map_1[height][width]; //declaration for the array and to show that the array is going to be defined externally.

void prepuzzle(int &Xpos, int &Ypos, char symbol); 
//prepuzzle function, initiates the start of the "prepuzzle" where the player moves around with W A S D until it reaches the symbol.
//input: takes in the X and Y position of the player by reference and a symbol that the player should go to
//output: does not return a value

#endif
