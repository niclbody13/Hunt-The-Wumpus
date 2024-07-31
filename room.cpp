/******************************************************
** Program: room.cpp
** Author: Nicolas Haralambidis
** Date: 05/23/2021
** Description: functions for the room class
** Input: None
** Output: Prints the correct letter depending on the event
******************************************************/

#include <iostream>
#include <vector>
#include "room.h"

using namespace std;

/*********************************************************************
** Function: Room
** Description: default constructor for the room class
** Parameters: None
*********************************************************************/
Room::Room() {
    events = nullptr;
}

/*********************************************************************
** Function: ~Room
** Description: destructor for the room class
** Parameters: None
*********************************************************************/
Room::~Room() {
    deleteEvent();
}

/*********************************************************************
** Function: printDebug
** Description: calls the print functions for the event in the room for debug mode
** Parameters: None
*********************************************************************/
void Room::printDebug() {
    if(events == nullptr) {
        cout << " ";
    }
    else {
        events->drawDebug();
    }
}

/*********************************************************************
** Function: printNormal
** Description: calls the print functions for the event in the room for normal mode
** Parameters: None
*********************************************************************/
void Room::printNormal() {
    if(events == nullptr) {
        cout << " ";
    }
    else {
        events->drawNormal();
    }
}

/*********************************************************************
** Function: setWumpus
** Description: sets the event to a wumpus
** Parameters: None
*********************************************************************/
void Room::setWumpus() {
    events = new Wumpus;
}

/*********************************************************************
** Function: setBats
** Description: sets the event to bats
** Parameters: None
*********************************************************************/
void Room::setBats() {
    events = new Bats;
}

/*********************************************************************
** Function: setPit
** Description: sets the event to a bottomless pit
** Parameters: None
*********************************************************************/
void Room::setPit() {
    events = new Pit;
}

/*********************************************************************
** Function: setGold
** Description: sets the event to gold
** Parameters: None
*********************************************************************/
void Room::setGold() {
    events = new Gold;
}

/*********************************************************************
** Function: setLocation
** Description: sets the event to a player
** Parameters: None
*********************************************************************/
void Room::setLocation() {
    events = new Player;
}

/*********************************************************************
** Function: setRope
** Description: sets the event to a rope
** Parameters: None
*********************************************************************/
void Room::setRope() {
    events = new Rope;
}

/*********************************************************************
** Function: getEvent
** Description: returns the current event
** Parameters: None
*********************************************************************/
Event* Room::getEvent() {
    return events;
}

/*********************************************************************
** Function: setEvent
** Description: sets the event 
** Parameters: Event*
*********************************************************************/
void Room::setEvent(Event* event) {
    events = event;
}

/*********************************************************************
** Function: deleteEvent 
** Description: delets the event to free up the memory
** Parameters: None
*********************************************************************/
void Room::deleteEvent() {
     if(events != nullptr)
        delete events;
}