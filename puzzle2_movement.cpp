//source code for puzzle 2
#include <iostream>
#include <unistd.h>
#include "puzzle2_movement.h" //contains declarations for this file

using namespace std;

/* printmap function prints the map of puzzle 2 element by element.
Arguments are, in order, the 2D map array, width of map, height of map, X position of player, Y position of player.
Void function has no return value, all outputs are done with cout */

int lives = 20;

void printmap(const char map[][width2], int w, int h, int Xpos2, int Ypos2) {
  //What it does: prints the map 
  //Inputs: takes in the map, the width and the height of the map, and the X and Y position of the map 
  //(XPos2 and YPos2 indicate that this is the position of the player for puzzle 2)
  //Outputs: does not return a value 
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      if (x == Xpos2 && y == Ypos2) {
        cout << 'P' << ' ';
      }
      else {
      cout << map[y][x] << ' ';
      }
    }
    cout << endl;
  }
}



char map_2_empty[height2][width2] = { //the map for puzzle 2 which is stored in an array with the path hidden
    { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
    { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#' },
    { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#' },
    { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#' },
    { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#' },
    { '#', 'E', '.', '.', '.', '.', '.', '.', '.', '.', '#' },
    { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#' },
    { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#' },
    { '#', '#', '#', '#', '#', '.', '#', '#', '#', '#', '#' }
  };
  char map_2_path[height2][width2] = { //the map for puzzle 2 which is stored in an array with the path shown
    { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
    { '#', '.', '.', 'O', 'O', 'O', '.', '.', '.', '.', '#' },
    { '#', '.', '.', 'O', '.', 'O', 'O', 'O', 'O', '.', '#' },
    { '#', '.', '.', 'O', '.', '.', '.', '.', 'O', '.', '#' },
    { '#', '.', '.', 'O', 'O', '.', '.', '.', 'O', '.', '#' },
    { '#', 'E', 'O', 'O', 'O', '.', '.', '.', 'O', '.', '#' },
    { '#', '.', '.', '.', '.', '.', '.', 'O', 'O', '.', '#' },
    { '#', '.', '.', '.', '.', 'O', 'O', 'O', '.', '.', '#' },
    { '#', '#', '#', '#', '#', 'O', '#', '#', '#', '#', '#' }
  };

int Xpos2 = 5;
int Ypos2 = 8;



void puzzle2(int &Xpos2, int &YPos2){
  /*The puzzle 2 function
  What it does: initiates puzzle 2 where the player has to memorize a path shown by 'O' to the end ('E'). The path will disappear 
  and the player has to move according to the path that they memorized, if they don't move according to the path, they will be sent back to the start
  and the path will be shown to them again until they can reach the end
  Inputs: takes in the position of the player in puzzle 2 (Xpos2 and Ypos2) 
  Outputs: does not have a return value */

  bool initiatePuzzle = false; //variable if to test if the puzzle has finished 
  char moveInput; //variable for the player input
  
  printmap(map_2_path, width2, height2, Xpos2, Ypos2); //show the map with the full path 
  cout << "5 seconds until the path disappears!" << endl; 
  sleep(5); 
  system("clear"); //wait 5 seconds before clearing screen
  
  initiatePuzzle = true;
  
  while(initiatePuzzle == true) {
    if (Xpos2 == 1 && Ypos2 == 5) { //if player reaches the end, then the puzzle ends 
      initiatePuzzle = false;
      break;
    }
    printmap(map_2_empty, width2, height2, Xpos2, Ypos2); //show the map with the hidden path
    cout << "Please enter your move (w/a/s/d):";
    cin >> moveInput; //ask for player input
    switch(moveInput) {
      case 'W': //if the player moves up
      case 'w':
        if (map_2_empty[Ypos2-1][Xpos2] == '.' || map_2_empty[Ypos2-1][Xpos2] == 'E') {
          if (map_2_path[Ypos2-1][Xpos2] == 'O' || map_2_path[Ypos2-1][Xpos2] == 'E') {
            Ypos2--;
          }
          else {
            cout << "Wrong path! Please try again" << endl; 
            lives -= 1; //if the player does not follow the correct path, reduce lives by 1.
            sleep(1);
            cout << "Here is the correct path:" << endl;
            Xpos2 = 5;
            Ypos2 = 8; 
            printmap(map_2_path, width2, height2, Xpos2, Ypos2); //reset the position of the player to the start and show the correct path
            cout << "5 seconds until the path disappears!" << endl;
            sleep(5);
            system("clear"); //wait 5 seconds before clearing screen
          }
        }
        break;
      case 'A': //if the player moves to the left 
      case 'a':
        if (map_2_empty[Ypos2][Xpos2-1] == '.' || map_2_empty[Ypos2][Xpos2-1] == 'E') {
          if (map_2_path[Ypos2][Xpos2-1] == 'O' || map_2_path[Ypos2][Xpos2-1] == 'E') {
            Xpos2--;
          }
          else {
            cout << "Wrong path! Please try again" << endl;
            lives -= 1; //if the player does not follow the correct path, reduce lives by 1.
            sleep(1);
            cout << "Here is the correct path:" << endl;
            Xpos2 = 5;
            Ypos2 = 8;
            printmap(map_2_path, width2, height2, Xpos2, Ypos2); //reset the position of the player to the start and show the correct path
            cout << "5 seconds until the path disappears!" << endl;
            sleep(5);
            system("clear"); //wait 5 seconds before clearing screen
          }
        }
        break;
      case 'S': //if the player moves down 
      case 's':
        if (map_2_empty[Ypos2+1][Xpos2] == '.' || map_2_empty[Ypos2+1][Xpos2] == 'E') {
          if (map_2_path[Ypos2+1][Xpos2] == 'O' || map_2_path[Ypos2+1][Xpos2] == 'E') {
            Ypos2++;
          }
          else {
            cout << "Wrong path! You've lost a life! Please try again." << endl;
            lives -= 1; //if the player does not follow the correct path, reduce lives by 1.
            sleep(1);
            cout << "Here is the correct path:" << endl; 
            Xpos2 = 5;
            Ypos2 = 8;
            printmap(map_2_path, width2, height2, Xpos2, Ypos2); //reset the position of the player to the start and show the correct path
            cout << "5 seconds until the path disappears!" << endl;
            sleep(5);
            system("clear"); //wait 5 seconds before clearing screen
          }
        }
        break;
      case 'D': //for moving to the right
      case 'd':
        if (map_2_empty[Ypos2][Xpos2+1] == '.' || map_2_empty[Ypos2][Xpos2+1] == 'E') {
          if (map_2_path[Ypos2][Xpos2+1] == 'O' || map_2_path[Ypos2][Xpos2+1] == 'E') {
            Xpos2++;
          }
          else {
            cout << "Wrong path! Please try again" << endl;
            lives -= 1; //if the player does not follow the correct path, reduce lives by 1.
            sleep(1);
            cout << "Here is the correct path:" << endl;
          
            Xpos2 = 5;
            Ypos2 = 8;
            printmap(map_2_path, width2, height2, Xpos2, Ypos2); //reset the position of the player to the start and show the correct path
            cout << "5 seconds until the path disappears!" << endl;
            sleep(5);
            system("clear"); //wait 5 seconds before clearing screen
          }
        }
        break;
    }
  }
}
