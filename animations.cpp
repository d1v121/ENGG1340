//source code for the animations 
#include <iostream> 
#include <fstream> 
#include <unistd.h> //For using time feature, mainly the sleep() function.
#include <stdlib.h> 
#include "animations.h" //header file which contains declarations
using namespace std;

//Prints out the final cutscene of the game, has no arguments or input
void final_cutscene(){
    string line;
    ifstream file("endgame.txt"); //reading in from file "gamename.txt"
    while (getline(file, line))
    {
        cout << line << endl; 
        usleep(40000); //0.02 seconds delay between each line
    }
    file.close();
}

//Prints out the name of the game, has no arguments or input, outputs the game name
void game_name(){
    string line;
    ifstream file("gamename.txt"); //reading in from file "gamename.txt"
    while (getline(file, line))
    {
        cout << line << endl; 
        usleep(20000); //0.02 seconds delay between each line
    }
    file.close();
}
//No Input arguments, just prints out the main menu
void main_menu(){
    string line;
    ifstream file("mainmenu.txt"); //reading in from file "mainmenu.txt"
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
}

//No Input arguments, just prints out the 2nd gemstone animation
void gemstone2(){
    string line;
    ifstream file("gemstone2.txt"); //reading in from the file "gemstone2.txt"
    while (getline(file, line))
    {
        cout << line << endl;
        usleep(50000); //0.05 seconds delay between each line 
    }
    file.close();
}
//No Input arguments, just prints out the first gemstone animation
void gemstone1(){
    string line;
    ifstream file("gemstone1.txt"); //reading in from the file "gemstone1.txt"
    while (getline(file, line))
    {
        cout << line << endl;
        usleep(50000); //0.05 seconds delay between each line 
    }
    file.close();
}
//No Input arguments, just prints out the game over animation
void game_over_animation(){
    string line;
    ifstream file("gameover.txt"); //reading in from the file "gameover.txt"
    if (file.is_open())
    {
        while (getline(file, line))
        {
            cout << line << endl; 
            sleep(1); //1 second delay between each line 
        }
    }
    file.close();
}
//No Input arguments, just prints out the beginning story cutscenes
void new_game_animation(){
    ifstream file("ascii_1.txt");
    int linenumber = 0; //serves as a counter for the line in the file
    if (file.is_open())
    {
        string line,_;
        while (getline(file, line)) {
            cout << line << endl;
            linenumber += 1; 
            if (linenumber==104||linenumber==212||linenumber==397){ //asks user to enter any character if linenumber is equal to these values
                cout << "(Enter a character to continue): ";
                cin >> _;
                system("clear");
            }
            //Alternates between 0.045 seconds delay and 0.12 seconds delay between each line
            //If the text is a picture/animation then it uses the 0.045 seconds delay
            //If the text is just text, then it uses the 0.12 seconds delay
            if (linenumber < 83){
                usleep(45000);
            }
            else if (linenumber >= 83 && linenumber < 107){
                usleep(120000);
            }
            else if (linenumber >= 107 && linenumber < 184){
                usleep(45000);
            }
            else if (linenumber >= 184 && linenumber < 216){
                usleep(120000);
            }
            else if (linenumber >= 216 && linenumber < 313){
                usleep(45000);
            }
            else if (linenumber >= 313){
                usleep(120000);
            }
        }
        file.close();
    }
}
