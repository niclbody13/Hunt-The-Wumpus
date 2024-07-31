/******************************************************
** Program: pit.cpp
** Author: Nicolas Haralambidis
** Date: 05/23/2021
** Description: functions for the pit class
** Input: None
** Output: prints the correct letter/percept for the bottomless pit
******************************************************/

#include <iostream>
#include <vector>
#include "pit.h"

using namespace std;

/*********************************************************************
** Function: percept
** Description: prints message for pit
** Parameters: None
*********************************************************************/
void Pit::percept() {
    cout << "You feel a breeze." << endl;
}

/*********************************************************************
** Function: encounter
** Description: handles when player is in pit room
** Parameters: None
*********************************************************************/
void Pit::encounter() {
    cout << "You fell into a bottomless pit.\n";
    dead = true;
}

/*********************************************************************
** Function: drawDebug
** Description: draws a P for bottomless pit in debug mode
** Parameters: None
*********************************************************************/
void Pit::drawDebug() {
    cout << "P";
}

/*********************************************************************
** Function: drawNormal
** Description: draws a space for normal mode
** Parameters: None
*********************************************************************/
void Pit::drawNormal() {
    cout << " ";
}