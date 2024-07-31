/******************************************************
** Program: gold.cpp
** Author: Nicolas Haralambidis
** Date: 05/23/2021
** Description: functions for the gold class
** Input: None
** Output: prints the correct letter/percept for the gold
******************************************************/

#include <iostream>
#include <vector>
#include "gold.h"

using namespace std;

/*********************************************************************
** Function: Gold
** Description: default constructor for gold class
** Parameters: None
*********************************************************************/
Gold::Gold() {

}

/*********************************************************************
** Function: percept
** Description: prints message for gold
** Parameters: None
*********************************************************************/
void Gold::percept() {
    cout << "You see a glimmer nearby." << endl;
}

/*********************************************************************
** Function: encounter
** Description: handles when a player is in the gold room
** Parameters: None
*********************************************************************/
void Gold::encounter() {
    cout << "You found and grabbed the gold!\n";
}

/*********************************************************************
** Function: drawDebug
** Description: draws a g for gold
** Parameters: None
*********************************************************************/
void Gold::drawDebug() {
    cout << "G";
}

/*********************************************************************
** Function: drawNormal
** Description: draws a space because normal mode
** Parameters: None
*********************************************************************/
void Gold::drawNormal() {
    cout << " ";
}