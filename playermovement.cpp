//source code for the prepuzzle part
#include "playermovement.h"
// assuming WASD for up/left/down/right movement
//setting the inital coordinates of 'P', the player.
int Xpos = 6;
int Ypos = 10;


void printmap(const char map[][width], int w, int h, int Xpos, int Ypos) { 
    //printmap function
    //Input: map for puzzle 1, width of the map, height of the map, X position of the player, Y position of the player
    //output: does not return a value, instead simply prints the map. 
for (int y = 0; y < h; y++) {         
    for (int x = 0; x < w; x++) {
      if (x == Xpos && y == Ypos) {
        cout << 'P' << ' '; //if x and y are equal to the position of the player, it prints the position of the player instead.
      }
      else {
      cout << map[y][x] << ' '; //else prints what is in the map
      }
    }
    cout << endl;
  }
}


char map_1[height][width] = { //array for the map that stores game status about the player
  { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
  { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#' },
  { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#' },
  { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#' },
  { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#' },
  { '#', '.', '.', '.', '.', '.', '$', '.', '.', '.', '.', '.', '#' },
  { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#' },
  { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#' },
  { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#' },
  { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#' },
  { '#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '#', '#', '#' }
};


  

void prepuzzle(int &Xpos, int &Ypos, char symbol){
    //prepuzzle function, initiates the start of the "prepuzzle" where the player moves around with W A S D until it reaches the symbol.
    //input: takes in the X and Y position of the player by reference and a symbol that the player should go to
    //output: does not return a value

  bool initiatePuzzle = false; //This value remains false if the $ symbol hasn't been reached yet

  char moveInput;
  while(initiatePuzzle == false) {
    printmap(map_1, width, height, Xpos, Ypos); 
    cout << "Enter your move (w/a/s/d): ";
    cin >> moveInput;
    switch(moveInput) {
      case 'W': //For moving up
      case 'w':
        if (map_1[Ypos-1][Xpos] == '.' || map_1[Ypos-1][Xpos] == symbol) { //if the player encounters a '.' or the symbol
          if (map_1[Ypos-1][Xpos] == '.') {
            Ypos--;
          }
          else {
            initiatePuzzle = true;
          }
        }
        break;
      case 'A': //For moving left
      case 'a':
        if (map_1[Ypos][Xpos-1] == '.' || map_1[Ypos][Xpos-1] == symbol) { //if the player encounters a '.' or the symbol
          if (map_1[Ypos][Xpos-1] == '.') {
            Xpos--;
          }
          else {
            initiatePuzzle = true;
          }
        }
        break;
      case 'S': //For moving down
      case 's':
        if (map_1[Ypos+1][Xpos] == '.' || map_1[Ypos+1][Xpos] == symbol) { //if the player encounters a '.' or the symbol
          if (map_1[Ypos+1][Xpos] == '.') {
            Ypos++;
          }
          else {
            initiatePuzzle = true;
          }
        }
        break;
      case 'D': //For moving right
      case 'd':
        if (map_1[Ypos][Xpos+1] == '.' || map_1[Ypos][Xpos+1] == symbol) { //if the player encounters a '.' or the symbol
          if (map_1[Ypos][Xpos+1] == '.') {
            Xpos++;
          }
          else {
            initiatePuzzle = true;
          }
        }
        break;
    }
  }
  map_1[5][6] = 'P'; //when 'prepuzzle' is complete, puts 'P' in the center of the map.
  Xpos = 1000; Ypos = 1000; //set the actual position of P to some irrelevant value to prevent any unwanted behaviour. 
  printmap(map_1, width, height, Xpos, Ypos); //prints the map
}
