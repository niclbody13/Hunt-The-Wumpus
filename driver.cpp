/******************************************************
** Program: driver.cpp
** Author: Nicolas Haralambidis
** Date: 05/23/2021
** Description: This is a program that plays a game called Hunt the Wumpus, this is the driver file that runs the game
** Input: user input throughout the game to move and shoot arrows
** Output: a map of the cave to show the player's location
******************************************************/

#include <iostream>
#include <vector>
#include <cstdlib>
#include "event.h"
#include "room.h"
#include "bats.h"
#include "gold.h"
#include "pit.h"
#include "wumpus.h"
#include "game.h"

using namespace std;

void checkArgs(bool&, string&);

/*********************************************************************
** Function: main
** Description: main function to run the game and handle the command line arguments
** Parameters: int, char**
*********************************************************************/
int main(int argc, char *argv[]) {    
    srand(time(NULL));
    bool a;
    string s = argv[2];
     if(argc != 3) {
        cout << "Invalid number of arguments.\n";
        return 0;
    }
    if(atoi(argv[1]) < 4) {
        cout << "Invalid size.\n";
        return 0;
    }
    checkArgs(a, s);
    Game g1(atoi(argv[1]));
    g1.createBoard();
    g1.setEvent();
    if(a == true) {
         g1.printCaveDebug();
        while(g1.isGameOver() == false) {
            g1.turn();
            g1.printCaveDebug();
        }
    }
    else if(a == false) {
       g1.printCaveNormal();
        while(g1.isGameOver() == false) {
            g1.turn();
            g1.printCaveNormal();
        }
    }
    return 0;
}

/*********************************************************************
** Function: checkArgs
** Description: converts the command line argument to a bool
** Parameters: bool, string
*********************************************************************/
void checkArgs(bool &a, string &s) {
    if(s == "false") {
        a = false;
    }
    else if(s == "true") {
        a = true;
    }
}

/*********************************************************************
** Function: 
** Description: 
** Parameters: None
*********************************************************************/



