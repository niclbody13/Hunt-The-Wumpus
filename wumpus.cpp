/******************************************************
** Program: wumpus.cpp
** Author: Nicolas Haralambidis
** Date: 05/23/2021
** Description: functions for the wumpus class
** Input: None
** Output: prints the correct letter/percept for the wumpus
******************************************************/

#include <iostream>
#include <vector>
#include "wumpus.h"

using namespace std;

/*********************************************************************
** Function: percept
** Description: prints message for wumpus
** Parameters: None
*********************************************************************/
void Wumpus::percept() {
    cout << "You smell a terrible stench." << endl;
}

/*********************************************************************
** Function: encounter
** Description: handles when player is in wumpus room
** Parameters: None
*********************************************************************/
void Wumpus::encounter() {
    if(wumpusDead == false) {
        cout << "You were eaten by the Wumpus!\n";
        dead = true;
    }
}

/*********************************************************************
** Function: drawDebug
** Description: draws a W for wumpus in debug mode
** Parameters: None
*********************************************************************/
void Wumpus::drawDebug() {
    cout << "W";
}

/*********************************************************************
** Function: drawNormal
** Description: draws a space for normal mode
** Parameters: None
*********************************************************************/
void Wumpus::drawNormal() {
    cout << " ";
}

/*********************************************************************
** Function: arrowEncounter
** Description: if arrow goes into wumpus room set it to true
** Parameters: None
*********************************************************************/
void Wumpus::arrowEncounter() {
    wumpusRoom = true;
}