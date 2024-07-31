/******************************************************
** Program: bats.cpp
** Author: Nicolas Haralambidis
** Date: 05/23/2021
** Description: functions for the bats class
** Input: None
** Output: prints the correct letter/percept for the bats
******************************************************/

#include <iostream>
#include <vector>
#include "bats.h"

using namespace std;

/*********************************************************************
** Function: percept
** Description: prints message for bats
** Parameters: None
*********************************************************************/
void Bats::percept() {
    cout << "You hear wings flapping." << endl;
}

/*********************************************************************
** Function: encounter
** Description: handles when player is in bats room
** Parameters: None
*********************************************************************/
void Bats::encounter() {
    cout << "You were grabbed by super bats!\n";
    batRoom = true;
}

/*********************************************************************
** Function: drawDebug
** Description: draws a b for bats in debug mode
** Parameters: None
*********************************************************************/
void Bats::drawDebug() {
    cout << "B";
}

/*********************************************************************
** Function: drawNormal
** Description: draws a space for normal mode
** Parameters: None
*********************************************************************/
void Bats::drawNormal() {
    cout << " ";
}