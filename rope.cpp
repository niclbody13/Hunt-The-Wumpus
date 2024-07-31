/******************************************************
** Program: rope.cpp
** Author: Nicolas Haralambidis
** Date: 05/23/2021
** Description: functions for the rope class
** Input: None
** Output: prints a letter to show the rope on the map
******************************************************/

#include <iostream>
#include <vector>
#include "rope.h"

using namespace std;

/*********************************************************************
** Function: percept
** Description: percept for the rope class which is none
** Parameters: None
*********************************************************************/
void Rope::percept() {

}

/*********************************************************************
** Function: encounter
** Description: enocunter for the rope sets the ropeRoom to true
** Parameters: None
*********************************************************************/
void Rope::encounter() {
    ropeRoom = true;
}

/*********************************************************************
** Function: drawDebug
** Description: draws the letter for the rope in debug mode
** Parameters: None
*********************************************************************/
void Rope::drawDebug() {
    cout << "R";
}

/*********************************************************************
** Function: drawNormal
** Description: draws a space in normal mode so nothing shows
** Parameters: None
*********************************************************************/
void Rope::drawNormal() {
    cout << " ";
}