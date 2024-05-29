//This cpp file serves as the main file of this game
#include "playermovement.h" //headerfile for the prepuzzle part of puzzle 1
#include "puzzle2_movement.h" //headerfile for puzzle 2
#include "animations.h" //headerfile for the animations

#include <iostream>
#include <string>
#include <cstdlib> 
#include <iomanip>
#include <fstream> 
#include <ctime> //For the time feature, mainly the sleep() function
#include <vector> //For dynamic memory management 
#include <chrono>
#include <thread> //Both <chrono> and <thread> are used for the time feature as well
#include <unistd.h> 
using namespace std;


struct RobotSpeech{
    vector<string> RobotVector = {"         +---------------------------------------------+", //robot ascii art that is stored in a vector
                        "         | ",                                                              
                        "",
                        " |",         
                        "         +---------------------------------------------+",
                        "             /",
                        " [_|_/      /",
                        " _//    __",
                        "(_|)   |@@|",
                        " \\ \\__ \\--/ __",
                        "  \\o__|----|  |   __",
                        "      \\ }{ /\\ )_ / _\\",
                        "      /\\__/\\ \\__O (__",
                        "     (--/\\--)    \\__/",
                        "     _)(  )(_",
                        "    `---''---`",
                        };
    //^This vector will dynamically grow during runtime because the words from this robot are going to be outputted in a speech bubble that will get bigger 
};

void print_map_and_robot(RobotSpeech r, const char map[][width], int w, int h, int Xpos, int Ypos){ 
    //print_map_and_robot function - prints the map on the left and the robot with a speech bubble that contains "one frame" of an animation 
    //Input: takes in a RobotSpeech structure which is mainly just for the robot in an array, the map, the width of the map, the height of the map, the X position of the player and the Y position of the player.
    //Output: does not return a value 
    for (int i=0; i<5; i++){ //prints the top part of the robot first where the map isn't there.
        if (i==1){
            cout << "                         " << r.RobotVector[i]; //Here r is from robotspeech.h and is just the structure which contains the robot array.
        }
        else if (i==2){
            cout << left << setw(43) << r.RobotVector[i];
        }
        else if (i==3){ 
            cout << r.RobotVector[i] << endl;
        }
        else{
            cout << "                         " <<  r.RobotVector[i] << endl;
        }
    }

    for (int y = 0; y < h; y++) { //prints the map and the bottom part of the robot side by side 
        for (int x = 0; x < w; x++) {
            if (x == Xpos && y == Ypos) {
                cout << 'P' << ' '; //prints 'P' instead if there 'P' is at coordinates Xpos and Ypos
            }
            else {
                cout << map[y][x] << ' ';
            }
        }
        cout << "  " << r.RobotVector[y+5] << endl;
    }
}


void printWithDelay2(RobotSpeech r, string readString){ 
    //printWithDelay2 function
    //What it does: prints out the map and the robot side by side with an animation of the robot saying the line contained in the input "readstring"
    //Input: takes in a robot structure, and a string value that the robot is going to say in a speech bubble
    //Output: does not return a value 
    
    print_map_and_robot(r, map_1, 13, 11, Xpos, Ypos); //function call for printing one frame of the animation
    this_thread::sleep_for(chrono::milliseconds(54)); //delay 54 seconds between each letter that is said
    for (int i=0; i<readString.length(); i++){ //print out the rest of the animation
        r.RobotVector[2] += readString[i];
        print_map_and_robot(r, map_1, 13, 11, Xpos, Ypos);
        this_thread::sleep_for(chrono::milliseconds(54));
    }
    this_thread::sleep_for(chrono::milliseconds(330));
}

void print_map_and_robot2(RobotSpeech r, const char map[][width2], int w, int h, int Xpos2, int Ypos2){ 
    //print_map_and_robot2 function - prints the map on the left and the robot with a speech bubble that contains "one frame" of an animation
    //This one is different from the print_map_and_robot function in that it is specifically catered to puzzle 2
    //Input: takes in a RobotSpeech structure which is mainly just for the robot in an array, the map, the width of the map, the height of the map, the X position of the player and the Y position of the player.
    //Output: does not return a value 
    for (int i=0; i<7; i++){ //prints the top part of the robot first where the map isn't there.
        if (i==1){
            cout << "                         " << r.RobotVector[i]; //Here r is from robotspeech.h and is just the structure which contains the robot array.
        }
        else if (i==2){
            cout << left << setw(43) << r.RobotVector[i];
        }
        else if (i==3){ 
            cout << r.RobotVector[i] << endl;
        }
        else{
            cout << "                         " <<  r.RobotVector[i] << endl;
        }
    }

    for (int y = 0; y < h; y++) { //prints the map and the bottom part of the robot side by side 
        for (int x = 0; x < w; x++) {
            if (x == Xpos2 && y == Ypos2) {
                cout << 'P' << ' ';
            }
            else {
                cout << map[y][x] << ' ';
            }
        }
        cout << "    " << r.RobotVector[y+7] << endl;
    }
}

void printWithDelay3(RobotSpeech r, string readString){ 
    //printWithDelay2 function 
    //This is different from the printWithDelay2 function in that it is specifically catered towards puzzle 2
    //What it does: prints out the map and the robot side by side with an animation of the robot saying the line contained in the input "readstring"
    //Input: takes in a robot structure, and a string value that the robot is going to say in the speech bubble 
    //Output: does not return a value 
    
    print_map_and_robot2(r, map_2_path, 11, 9, Xpos2, Ypos2); //function call for printing one frame of the animation
    this_thread::sleep_for(chrono::milliseconds(54)); //delay 54 seconds between each letter that is said
    for (int i=0; i<readString.length(); i++){ //print out the rest of the animation
        r.RobotVector[2] += readString[i];
        print_map_and_robot2(r, map_2_path, 11, 9, Xpos2, Ypos2);
        this_thread::sleep_for(chrono::milliseconds(54));
    }
    this_thread::sleep_for(chrono::milliseconds(330));
}

int main(){
    //initializing basic variables in the main function
    char MainMenuOption = '0'; //variable for the main menu choice of the user
    char AnyKey; //variable if the player goes into the credits screen and wants to go back 
    main_menu(); //prints the main menu 
    cout << "Enter your choice (1/2/3): ";
    cin >> MainMenuOption;

    while (MainMenuOption != '1'){
        if (MainMenuOption == '2'){ //if player chooses credits 
            cout << "CREDITS:" << endl;
            cout << endl;
            cout << "Melwani Buxani Divesh (3036080018)" << endl;
            cout << "Khanna Abhinav (3036180545)" << endl;
            cout << "Wan Ka Yuet (3036223854)" << endl;
            cout << "Abdul Rafay Asim (3036224901)" << endl;
            cout << "Woo Tsz Ying Jeanie (3035917836)" << endl; 

            cout << endl;
            cout << "Press any key to go back to the main menu: ";
            cin >> AnyKey;
            main_menu();
        }
        else if (MainMenuOption == '3'){ // if the player chooses to exit
            exit(1);
        }
        cout << "Enter your choice (1/2/3): ";
        cin >> MainMenuOption;
    }


    char firstchar;
    new_game_animation();
    srand(time(NULL)); //setting the seed to the time to ensure every run is random
    RobotSpeech r1;
    string readString; //readString initialized for robot speech bubble 
    string repeatMonologue = "yes";
    string skipIntro = "no";
    string enterToContinue; 
    int lives = 5; //number of lives that the player gets for PUZZLE 1
    //lives for puzzle 2 are contained in the file puzzle2_movement.cpp

    while (repeatMonologue == "yes"){ //while loop if the player wants to skip intro or not.
        while (skipIntro != "yes" && skipIntro != "no"){
            cout << "Please enter a valid response!" << endl;
            cout << "Skip introduction? (yes/no): ";
            cin >> skipIntro;
        }
        if (skipIntro == "yes"){ //if the player chooses to skip the introduction, then break out of this while loop
            break;
        }

        //For this next part: 
        //readString is what the robot will say in a speech bubble
        //printWithDelay2 function is for the animated text that will come out in the speech bubble
        //this_thread::sleep_for(chrono::milliseconds()) is the function for setting delay between sentences that the robot says
        readString = "Welcome Knight! I see you've come to find"; 
        printWithDelay2(r1, readString);

        readString = "the gemstones!";
        printWithDelay2(r1, readString);
        this_thread::sleep_for(chrono::milliseconds(1000));

        readString = "As you probably know, you need these";
        printWithDelay2(r1, readString);
        
        readString = "gemstones in order to cure the king's";
        printWithDelay2(r1, readString);

        readString = "daughter's curse";
        printWithDelay2(r1, readString);
        this_thread::sleep_for(chrono::milliseconds(1000));

        

        readString = "These gemstones are going to be";
        printWithDelay2(r1, readString);
        
        readString = "scattered across different puzzles";
        printWithDelay2(r1, readString);
        this_thread::sleep_for(chrono::milliseconds(1000));

        readString = "and it is your job to find them!";
        printWithDelay2(r1, readString);
        this_thread::sleep_for(chrono::milliseconds(1000));
        
        readString = "As you can see, there's a map over here";
        printWithDelay2(r1, readString);

        readString = "and you, the knight, are represented by 'P'";
        printWithDelay2(r1, readString);
        this_thread::sleep_for(chrono::milliseconds(1000));

        readString = "Try walking around using the W A S D keys";
        printWithDelay2(r1, readString);
        this_thread::sleep_for(chrono::milliseconds(1000));

        readString = "And when you're ready, go to the $ symbol";
        printWithDelay2(r1, readString);

        readString = "which is located at the center of the map";
        printWithDelay2(r1, readString);

        cout << "\nRepeat what the robot just said? (yes/no): "; 
        cin >> repeatMonologue; //variable for if the player wants to repeat what the robot just said
        while (repeatMonologue != "yes" && repeatMonologue != "no"){
            cout << "Please enter a valid response!" << endl; 
            cout << "Repeat what the robot just said? (yes/no): ";
            cin >> repeatMonologue; //repeat while loop if the player doesnt choose to enter yes or no
        }


    }

    //giving instructions to the player for the prepuzzle part:
    readString = "For now, just walk around with W A S D keys"; 
    printWithDelay2(r1, readString);
    this_thread::sleep_for(chrono::milliseconds(1000));

    readString = "until you reach the $ sign";
    printWithDelay2(r1, readString);
    
    prepuzzle(Xpos, Ypos, '$'); //function that initates the "prepuzzle" part where the player walks until he reaches the '$' sign
    //prepuzzle part contained in the playermovement.cpp file 
    
    
    readString = "Great Work!";
    printWithDelay2(r1, readString);
    this_thread::sleep_for(chrono::milliseconds(1000));

    //instructions for the first actual puzzle
    readString = "Now, the first puzzle goes like this:";
    printWithDelay2(r1, readString);

    readString = "It's essentially a memory game so I hope";
    printWithDelay2(r1, readString);

    readString = "that are good with remembering things!";
    printWithDelay2(r1, readString);
    this_thread::sleep_for(chrono::milliseconds(1000));

    string repeatPuzzle1 = "yes"; 
    while (repeatPuzzle1 == "yes"){ //this will repeat as long as the player chooses to repeat the instructions for puzzle 1
        //giving instructions for puzzle 1
        readString = "letters will appear on the map";
        printWithDelay2(r1, readString);

        readString = "and you have to remember them in order";
        printWithDelay2(r1, readString); 
        this_thread::sleep_for(chrono::milliseconds(1000));

        readString = "Afterwards, you'll be prompted to write";
        printWithDelay2(r1, readString);

        readString = "down the word that the letters spell out";
        printWithDelay2(r1, readString);
        this_thread::sleep_for(chrono::milliseconds(1000));

        string FlushBufferVariable; //variable for flushing the input buffer 
        getline(cin, FlushBufferVariable);
        cout << "Repeat the instructions for puzzle 1? (yes/no): ";
        cin >> repeatPuzzle1; //variable for if the player wants to repeat the instructions for puzzle 1
        while (repeatPuzzle1 != "yes" && repeatPuzzle1 != "no"){ //while loop if the player chooses to repeat instructions for puzzle 1
            cout << "Please enter a valid response!" << endl;
            cout << "Repeat the instructions for puzzle 1? (yes/no): ";
            cin >> repeatPuzzle1;
        }
    }
        

    readString = "ready? 3....... 2...... 1....... GO!"; 
    this_thread::sleep_for(chrono::milliseconds(500));
    printWithDelay2(r1, readString); 

    //puzzle 1 starts here:
    string wordinput; //variable that stores the player's response to what word it is
    string Wordlist[] = {"crocodile","apple","robot","giraffes","pandas","pear","orange","mouse","lion"}; //A list of random words that the program will iterate through 
    //In each iteration, a word will be chosen and the letters of the word will be scattered across the map with a delay between each letter 
    //The player will have to look at the letters and write down the word that the letters form
    for (int j=0; j<5; j++){ //Iterates through the list of words
        int randomnum = rand() % 9; 
        string randomword = Wordlist[randomnum]; //chooses a random word
        for (int i=0; i<randomword.length(); i++){ //iterating through each letter of the word chosen
            int randXpos = rand() % width; 
            int randYpos = rand() % height; //choosing random x and y position of the letter
            while (randXpos == 0 || randXpos == 12 || randYpos == 0 || randYpos == 10 || (randXpos == 6 && randYpos == 5)){ 
                //while the letter is on the edge or at the center, choose a new position
                randXpos = rand() % width;
                randYpos = rand() % height;
            }
            map_1[randYpos][randXpos] = randomword[i]; //set that position on the map to the letter 
            printmap(map_1, width, height, 1000, 1000);
            cout << endl;
            this_thread::sleep_for(chrono::milliseconds(900));
            map_1[randYpos][randXpos] = '.'; //set it back to '.'
        }
        cout << "What was the word?: ";
        cin >> wordinput; //ask the player to write down the word 
        if (wordinput == randomword){
            cout << "Correct!" << endl;
        }
        else{
            cout << "Incorrect! You've lost a life! Please try again!" << endl; 
            lives -= 1; //A life is lost if the word the player writes down is incorrect
        }
        if (lives == 0){
            cout << "You ran out of lives!" << endl;
            game_over_animation(); //player the game over animation if the player runs out of lives 
            exit;
        }
        this_thread::sleep_for(chrono::milliseconds(1500));


    }

    //After the player has completed puzzle 1
    Xpos = 6;
    Ypos = 5; //set the coordinates of 'P' to the center of the map
    map_1[5][6] = '.'; 
    map_1[5][11] = 'G'; //put a gemstone on the right side of the map
    readString = "Awesome!";
    printWithDelay2(r1, readString);
    this_thread::sleep_for(chrono::milliseconds(1000));
    
    //instructions for the player to go to the gemstone 
    readString = "Look a gemstone has appeared on the right!";
    printWithDelay2(r1, readString);
    this_thread::sleep_for(chrono::milliseconds(1000));

    readString = "It's represented by the letter G";
    printWithDelay2(r1, readString);
    this_thread::sleep_for(chrono::milliseconds(1000));

    readString = "Try walking towards it with the W A S D keys";
    printWithDelay2(r1, readString);
    
    //using the same prepuzzle function in playermovement.cpp to go to the gemstone 
    prepuzzle(Xpos, Ypos, 'G');
    this_thread::sleep_for(chrono::milliseconds(100));
    //play the gemstone1 animation once the player reaches the gemstone
    gemstone1();
    string FlushBufferVariable; //variable for flushing the input buffer
    getline(cin, FlushBufferVariable); //flushing the buffer
    cout << "Congrats! you've beat puzzle 1!" << endl;
    cout << "Continue to puzzle 2? (yes/no): ";
    string continueToPuzzle2; //variable for choosing if the player wants to continue to puzzle 2
    cin >> continueToPuzzle2;
    while (continueToPuzzle2 != "yes" && continueToPuzzle2 != "no"){ //while loop if the player doesn't choose 'yes' or 'no'
        cout << "Please enter a valid response!" << endl;
        cout << "Continue to puzzle 2? (yes/no): ";
        cin >> continueToPuzzle2;
    }
    if (continueToPuzzle2 == "yes"){ //if the player chooses to continue to puzzle 2
        string repeatPuzzle2 = "yes";
        while (repeatPuzzle2 == "yes"){ //This while loop will repeat as long as the player chooses to repeat the instructions
            //instructions for puzzle 2
            this_thread::sleep_for(chrono::milliseconds(300));
            readString = "Welcome Knight!";
            printWithDelay3(r1, readString);
            this_thread::sleep_for(chrono::milliseconds(1000));

            readString = "This is the map for puzzle 2";
            printWithDelay3(r1, readString);
            this_thread::sleep_for(chrono::milliseconds(500));

            readString = "Like puzzle 1, you will also have to";
            printWithDelay3(r1, readString);
            this_thread::sleep_for(chrono::milliseconds(300));

            readString = "use your memory in this puzzle";
            printWithDelay3(r1, readString);
            this_thread::sleep_for(chrono::milliseconds(1000));
        
            readString = "This is how puzzle 2 works: ";
            printWithDelay3(r1, readString);
            this_thread::sleep_for(chrono::milliseconds(400));

            readString = "On the map on the left, there is";
            printWithDelay3(r1, readString);
            this_thread::sleep_for(chrono::milliseconds(400));

            readString = "A path represented by a bunch of 'O'";
            printWithDelay3(r1, readString);
            this_thread::sleep_for(chrono::milliseconds(400));

            readString = "and you, as the letter 'P' will have to";
            printWithDelay3(r1, readString);
            this_thread::sleep_for(chrono::milliseconds(400));

            readString = "make it to the letter 'E' ";
            printWithDelay3(r1, readString);
            this_thread::sleep_for(chrono::milliseconds(500));

            readString = "using the W A S D keys on the path";
            printWithDelay3(r1, readString);
            this_thread::sleep_for(chrono::milliseconds(1000));

            readString = "However, once you start, you will need";
            printWithDelay3(r1, readString);
            this_thread::sleep_for(chrono::milliseconds(400));

            readString = "to memorize the path to the end.";
            printWithDelay3(r1, readString);
            this_thread::sleep_for(chrono::milliseconds(1000));

            readString = "If you don't follow the path, then";
            printWithDelay3(r1, readString);
            this_thread::sleep_for(chrono::milliseconds(400));

            readString = "you will lose a life and ";
            printWithDelay3(r1, readString);
            this_thread::sleep_for(chrono::milliseconds(400));

            readString = "the full path will be shown to you again";
            printWithDelay3(r1, readString);
            this_thread::sleep_for(chrono::milliseconds(500));

            readString = "and you'll be sent back to the start";
            printWithDelay3(r1, readString);
            this_thread::sleep_for(chrono::milliseconds(500));

            cout << "repeat the instructions for puzzle 2? (yes/no): ";
            cin >> repeatPuzzle2; //variable for the player's choice to repeat the instructions for puzzle 2 or not
            while (repeatPuzzle2 != "yes" && repeatPuzzle2 != "no"){
                cout << "Please enter a valid response"; 
                cout << "repeat the instructions for puzzle 2? (yes/no): ";
                cin >> repeatPuzzle2;
            }
        }

        //3 2 1 timer for player to start puzzle 2
        cout << "ready?" << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "3..." << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "2..." << endl;
        this_thread::sleep_for(chrono::milliseconds(1000)); 
        cout << "1..." << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        system("clear"); //clearing the screen afterwards
        

        puzzle2(Xpos2, Ypos2); //function for initiating puzzle2
        //code for puzzle 2 contained in the puzzle2_movement.cpp file
        gemstone2(); //play the gemstone 2 animation contained in the animations.cpp file 
        cout << "Enter any character to continue: "; //ask player to input any character to continue
        cin >> firstchar; 

        system("clear"); //clear the screen after input
        final_cutscene(); //shows the final cutscene when the game finishes 
    }
    else if (continueToPuzzle2 == "no"){ //if the player chooses not to continue to puzzle 2
        cout << "See you next time... ";
    }

    return 0;
}
