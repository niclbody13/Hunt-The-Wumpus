/******************************************************
** Program: event.cpp
** Author: Nicolas Haralambidis
** Date: 05/23/2021
** Description: functions for the event class
** Input: None
** Output: None
******************************************************/

#include <iostream>
#include <vector>
#include "event.h"
#include "room.h"

using namespace std;

/*********************************************************************
** Function: drawDebug
** Description: draws nothing because there is never an instance of event
** Parameters: None
*********************************************************************/
void Event::drawDebug() {
    //cout << " ";
}

/*********************************************************************
** Function: drawNormal
** Description: draws nothing because there is never an instance of event
** Parameters: None
*********************************************************************/
void Event::drawNormal() {

}

/*********************************************************************
** Function: Event
** Description: default constructor for event class
** Parameters: None
*********************************************************************/
Event::Event() {
    dead = false;
    batRoom = false;
    wumpusRoom = false;
    wumpusDead = false;
    ropeRoom = false;
}

/*********************************************************************
** Function: isDead
** Description: checks to see if the player is dead
** Parameters: None
*********************************************************************/
bool Event::isDead() {
    if(dead == true) {
        return true;
    }
    return false;
}

/*********************************************************************
** Function: isBatRoom
** Description: checks to see if the player is in a bat room
** Parameters: None
*********************************************************************/
bool Event::isBatRoom() {
    if(batRoom == true) {
        return true;
    }
    return false;
}

/*********************************************************************
** Function: isWumpus
** Description: checks to see if the player is in the wumpus room
** Parameters: None
*********************************************************************/
bool Event::isWumpus() {
    if(wumpusRoom == true) {
        return true;
    }
    return false;
}

/*********************************************************************
** Function: arrowEncounter
** Description: function that will get overrided in wumpus class
** Parameters: None
*********************************************************************/
void Event::arrowEncounter() {
    
}

/*********************************************************************
** Function: isRopeRoom
** Description: checks to see if the player is in the rope room
** Parameters: None
*********************************************************************/
bool Event::isRopeRoom() {
    if(ropeRoom == true) {
        return true;
    }
    return false;
}

/*********************************************************************
** Function: setWumpusDead
** Description: sets the wumpus to be dead 
** Parameters: bool
*********************************************************************/
void Event::setWumpusDead(bool a) {
    if(a == true) {
        wumpusDead = true;
    }
}

/*********************************************************************
** Function: isWumpusDead
** Description: checks to see if the wumpus is dead
** Parameters: None
*********************************************************************/
bool Event::isWumpusDead() {
    if(wumpusDead == true) {
        return true;
    }
    return false;
}