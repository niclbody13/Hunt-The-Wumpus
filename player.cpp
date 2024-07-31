/******************************************************
** Program: player.cpp
** Author: Nicolas Haralambidis
** Date: 05/23/2021
** Description: functions for the player class
** Input: None
** Output: prints a star that represents the player's location
******************************************************/

#include <iostream>
#include <vector>
#include "player.h"

using namespace std;

/*********************************************************************
** Function: percept
** Description: percept function for player class does nothing
** Parameters: None
*********************************************************************/
void Player::percept() {

}

/*********************************************************************
** Function: encounter
** Description: does nothing for player class
** Parameters: None
*********************************************************************/
void Player::encounter() {

}

/*********************************************************************
** Function: drawDebug
** Description: draws a star to show location
** Parameters: None
*********************************************************************/
void Player::drawDebug() {
    cout << "*";
}

/*********************************************************************
** Function: drawNormal
** Description: draws a star to show location
** Parameters: None
*********************************************************************/
void Player::drawNormal() {
    cout << "*";
}