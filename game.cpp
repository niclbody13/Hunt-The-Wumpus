/******************************************************
** Program: game.cpp
** Author: Nicolas Haralambidis
** Date: 05/23/2021
** Description: functions for the game class, most of the game logic done here
** Input: user input for moving/firing arrows
** Output: prints a grid to represent the cave
******************************************************/

#include <iostream>
#include <vector>
#include "game.h"

using namespace std;

/*********************************************************************
** Function: Game
** Description: alternate constructor for the game class
** Parameters: int
*********************************************************************/
Game::Game(int size) {
    caveSize = size;
    goldTaken = false;
    gameOver = false;
    choiceNum = 0;
    numArrows = 3;
    wumpusDead = false;
    ropeSet = false;
}

/*********************************************************************
** Function: createBoard
** Description: creates the cave vector and resizes it
** Parameters: None
*********************************************************************/
void Game::createBoard() {
    cave.resize(caveSize);
    cout << cave.size() << endl;
    for(int i = 0; i < caveSize; i++) {
        cave[i].resize(caveSize);
        for(int j = 0; j < caveSize; j++) {
            //cave[i][j].setEvent();
        }
    }
}

/*********************************************************************
** Function: printCaveDebug
** Description: prints the cave in debug mode
** Parameters: None
*********************************************************************/
void Game::printCaveDebug() {
    for(int j = 0; j < caveSize; j++){
        cout << "+---+";
    }
    cout << endl;
    for(int i = 0; i < caveSize; i++){
        for(int j = 0; j < caveSize; j++){
            cout << "| ";
            cave.at(i).at(j).printDebug();   //  show the events in the cave
            cout << " |";
        }
        cout << endl;
        for(int j = 0; j < caveSize; j++){
            cout << "+---+";
        }
        cout << endl;
    }
}

/*********************************************************************
** Function: printCaveNormal
** Description: prints the cave in normal mode only showing the location of the player
** Parameters: None
*********************************************************************/
void Game::printCaveNormal() {
    for(int j = 0; j < caveSize; j++){
        cout << "+---+";
    }
    cout << endl;
    for(int i = 0; i < caveSize; i++){
        for(int j = 0; j < caveSize; j++){
            cout << "| ";
            cave.at(i).at(j).printNormal();   //  dont show the events just the location
            cout << " |";
        }
        cout << endl;
        for(int j = 0; j < caveSize; j++){
            cout << "+---+";
        }
        cout << endl;
    }
}

/*********************************************************************
** Function: setEvent
** Description: sets the events in the cave before the game starts
** Parameters: None
*********************************************************************/
void Game::setEvent() {
    setInitialLocation();
    setWumpus();
    setGold();
    for(int i = 0; i < 2; i++) {
        setBats();
        setPit();
    }
    callPercept();
}

/*********************************************************************
** Function: setWumpus
** Description: sets the wumpus in a random spot in the cave
** Parameters: None
*********************************************************************/
void Game::setWumpus() {
    int a = rand() % caveSize;
    int b = rand() % caveSize;
    wumpusX = a;
    wumpusY = b;
    if(cave.at(a).at(b).getEvent() == nullptr && (a != startingX && b != startingY)) {
        cave.at(a).at(b).setWumpus();
    }
    else {
        setWumpus();
    }
}

/*********************************************************************
** Function: setBats
** Description: sets the bats in a random spot in the cave
** Parameters: None
*********************************************************************/
void Game::setBats() {
    int a = rand() % caveSize;
    int b = rand() % caveSize;
    if(cave.at(a).at(b).getEvent() == nullptr) {
        cave.at(a).at(b).setBats();
    }
    else {
        setBats();
    }
}

/*********************************************************************
** Function: setGold
** Description: sets the gold in a random spot in the cave
** Parameters: None
*********************************************************************/
void Game::setGold() {
    int a = rand() % caveSize;
    int b = rand() % caveSize;
    goldX = a;
    goldY = b;
    if(cave.at(a).at(b).getEvent() == nullptr) {
        cave.at(a).at(b).setGold();
    }
    else {
        setGold();
    }
}

/*********************************************************************
** Function: setPit
** Description: sets the bottomless pit in a random spot in the cave
** Parameters: None
*********************************************************************/
void Game::setPit() {
    int a = rand() % caveSize;
    int b = rand() % caveSize;
    if(cave.at(a).at(b).getEvent() == nullptr) {
        cave.at(a).at(b).setPit();
    }
    else {
        setPit();
    }
}

/*********************************************************************
** Function: setInitialLocation
** Description: sets the player's initial location randomly in the cave
** Parameters: None
*********************************************************************/
void Game::setInitialLocation() {
    startingX = rand() % caveSize;
    startingY = rand() % caveSize;
    curX = startingX;
    curY = startingY;
    if(cave.at(startingX).at(startingY).getEvent() == nullptr) {
        cave.at(startingX).at(startingY).setLocation();
    }
    else {
        setInitialLocation();
    }
}

/*********************************************************************
** Function: setRope
** Description: sets the rope where the starting location is
** Parameters: None
*********************************************************************/
void Game::setRope() {
    if(ropeSet == false) {
        if(((curX != startingX) || (curY != startingY))) {
            cave.at(startingX).at(startingY).setRope();
            ropeSet = true;
        }
    }
}

/*********************************************************************
** Function: changeLocation
** Description: changes the players location in the cave
** Parameters: None
*********************************************************************/
void Game::changeLocation() {
    if(cave.at(curX).at(curY).getEvent() == nullptr) {
        cave.at(curX).at(curY).setLocation();
        setRope();
        callPercept();
    }
    else {
        cave.at(curX).at(curY).getEvent()->encounter();  
        checkGold();
        if(cave.at(curX).at(curY).getEvent()->isDead() == true) {
            gameOver = true;
        } 
        checkBats();
        if(cave.at(curX).at(curY).getEvent()->isRopeRoom() == true) {
            cave.at(curX).at(curY).deleteEvent();
            cave.at(curX).at(curY).setEvent(nullptr);
            cave.at(curX).at(curY).setLocation();
            ropeSet = false;
            setRope();
            callPercept();
        }
        cave.at(curX).at(curY).deleteEvent();
        cave.at(curX).at(curY).setEvent(nullptr);
        cave.at(curX).at(curY).setLocation();
        setRope();
    }
}

/*********************************************************************
** Function: getDirection
** Description: gets the direction of move/arrow from the user
** Parameters: None
*********************************************************************/
void Game::getDirection() {
     cout << "Number of Arrows: " << numArrows << endl;
    if(numArrows > 0) {
        cout << "To fire an arrow, enter a space followed by the direction.\n";
    }
    cout << "Choose direction(w, a, s, d): ";
    getline(cin, choice);
}

/*********************************************************************
** Function: turn
** Description: runs through a turn of the player calling the functions based on direction
** Parameters: None
*********************************************************************/
void Game::turn() {
    getDirection();
    convertToNum();
    switch (choiceNum) {
    case 1:
        up();
        break;
    case 2:
        left();
        break;
    case 3:
        down();
        break;
    case 4:
        right();
        break;
    case 5:
        fireUp();
        callPercept();
        break;
    case 6:
        fireLeft();
        callPercept();
        break;
    case 7:
        fireDown();
        callPercept();
        break;
    case 8:
        fireRight();
        callPercept();
    default:
        break;
    }
}

/*********************************************************************
** Function: up
** Description: move the player up if possible
** Parameters: None
*********************************************************************/
void Game::up() {
    if(curX == 0) {
        cout << "You can't move up, try another direction.\n";
        turn();
    }
    else {
        cave.at(curX).at(curY).deleteEvent();
        cave.at(curX).at(curY).setEvent(nullptr);
        curX = curX - 1;
        changeLocation();
    }
}

/*********************************************************************
** Function: left
** Description: move the player left if possible
** Parameters: None
*********************************************************************/
void Game::left() {
    if(curY == 0) {
        cout << "You can't move left, try another direction.\n";
        turn();
    }
    else {
        cave.at(curX).at(curY).deleteEvent();   //have to delete the event before setting it to a nullptr
        cave.at(curX).at(curY).setEvent(nullptr);
        curY = curY - 1;
        changeLocation();
        
    }
}

/*********************************************************************
** Function: right
** Description: move the player right if possible
** Parameters: None
*********************************************************************/
void Game::right() {
    if(curY == (caveSize - 1)) {
        cout << "You can't move right, try another direction.\n";
        turn();
    }
    else {
        cave.at(curX).at(curY).deleteEvent();
        cave.at(curX).at(curY).setEvent(nullptr);
        curY = curY + 1;
        changeLocation();
    }
}

/*********************************************************************
** Function: down
** Description: move the player down if possible
** Parameters: None
*********************************************************************/
void Game::down() {
    if(curX == (caveSize - 1)) {
        cout << "You can't move down, try another direction.\n";
        turn();
    }
    else {
        cave.at(curX).at(curY).deleteEvent();
        cave.at(curX).at(curY).setEvent(nullptr);
        curX = curX + 1;
        changeLocation();
    }
}

/*********************************************************************
** Function: checkGold
** Description: checks if the player is in the room with the gold
** Parameters: None
*********************************************************************/
void Game::checkGold() {
    if(curX == goldX && curY == goldY) {
        goldTaken = true;
        callPercept();
    }
}

/*********************************************************************
** Function: isGoldTaken
** Description: checks if the player took the gold(entered the gold room)
** Parameters: None
*********************************************************************/
bool Game::isGoldTaken() {
    if(goldTaken == true) {
        return true;
    }
    return false;
}

/*********************************************************************
** Function: gameOver
** Description: checks to see if the player made it to the rope with the gold or if they died
** Parameters: None
*********************************************************************/
bool Game::isGameOver() {
    if(goldTaken == true && curX == startingX && curY == startingY) {
        cout << "You found the rope and escaped!\n";
        cout << "You win!\n";
        return true;
    }
    if(gameOver == true) {
        cout << "Game over!\n";
        return true;
    }
    return false;
}

/*********************************************************************
** Function: setRandomLocation
** Description: sets the player to a random spot in the cave
** Parameters: None
*********************************************************************/
void Game::setRandomLocation() {
    curX = rand() % caveSize;
    curY = rand() % caveSize;
    changeLocation();
}

/*********************************************************************
** Function: checkBats
** Description: checks to see if the player is in a room with bats
** Parameters: None
*********************************************************************/
void Game::checkBats() {
    if(cave.at(curX).at(curY).getEvent()->isBatRoom() == true) {
        setRandomLocation();
    }
}

/*********************************************************************
** Function: callPercept
** Description: calls the correct percept from adjacent rooms
** Parameters: None
*********************************************************************/
void Game::callPercept() {
    if(curX != 0) {
        if(cave.at(curX-1).at(curY).getEvent() != nullptr) {
            cave.at(curX-1).at(curY).getEvent()->percept();
        }
    }
    if(curX != (caveSize - 1)) {
        if(cave.at(curX+1).at(curY).getEvent() != nullptr) {
            cave.at(curX+1).at(curY).getEvent()->percept();
        }
    }
    if(curY != 0) {
        if(cave.at(curX).at(curY-1).getEvent() != nullptr) {
            cave.at(curX).at(curY-1).getEvent()->percept();
        }
    }
    if(curY != (caveSize - 1)) {
        if(cave.at(curX).at(curY+1).getEvent() != nullptr) {
            cave.at(curX).at(curY+1).getEvent()->percept();
        }
    }
}

/*********************************************************************
** Function: convertToNum
** Description: converts the players input to numbers so they can be used in switch statement
** Parameters: None
*********************************************************************/
void Game::convertToNum() {
    if(choice == "w") {
       choiceNum = 1;
    }
    else if(choice == "a") {
        choiceNum = 2;
    }
    else if(choice == "s") {
        choiceNum = 3;
    }
    else if(choice == "d") {
        choiceNum = 4;
    }
    else if(choice == " w") {
        choiceNum = 5;
    }
    else if(choice == " a") {
        choiceNum = 6;
    }
    else if(choice == " s") {
        choiceNum = 7;
    }
    else if(choice == " d") {
        choiceNum = 8;
    }
}

/*********************************************************************
** Function: fireUp
** Description: fire an arrow up if they have at least one
** Parameters: None
*********************************************************************/
void Game::fireUp() {
    if(numArrows < 1) {
        cout << "You don't have any more arrows.\n";
    }
    else {
        arrowX = (curX - 1);
        arrowY = curY;
        if(curX > 2) {
            while((curX - 3) != (arrowX + 1)) {
                if(arrowX == wumpusX && arrowY == wumpusY) { 
                    cout << "You killed the Wumpus!\n";
                    wumpusDead = true;
                    cave.at(wumpusX).at(wumpusY).deleteEvent();
                    cave.at(wumpusX).at(wumpusY).setEvent(nullptr);
                    break;
                }
                else {
                    arrowX--;
                }
            }
        }
        else {
            while((arrowX + 1) != 0) {
                if(arrowX == wumpusX && arrowY == wumpusY) { 
                    cout << "You killed the Wumpus!\n";
                    wumpusDead = true;
                    cave.at(wumpusX).at(wumpusY).deleteEvent();
                    cave.at(wumpusX).at(wumpusY).setEvent(nullptr);
                    break;
                }
                else {
                    arrowX--;
                }
            }
        }
        numArrows--;
        moveWumpus();
    }
}

/*********************************************************************
** Function: fireLeft
** Description: fire an arrow to the left if they have one
** Parameters: None
*********************************************************************/
void Game::fireLeft() {
    if(numArrows < 1) {
        cout << "You don't have any more arrows.\n";
    }
    else {
        arrowX = curX;
        arrowY = (curY - 1);
        if(curY > 2) {
            while((curY - 3) != (arrowY + 1)) {
                if(arrowX == wumpusX && arrowY == wumpusY) { 
                    cout << "You killed the Wumpus!\n";
                    wumpusDead = true;
                    cave.at(wumpusX).at(wumpusY).deleteEvent();
                    cave.at(wumpusX).at(wumpusY).setEvent(nullptr);
                    break;
                }
                else {
                    arrowY--;
                }
            }
        }
        else {
            while((arrowY + 1) != 0) {
                if(arrowX == wumpusX && arrowY == wumpusY) { 
                    cout << "You killed the Wumpus!\n";
                    wumpusDead = true;
                    cave.at(wumpusX).at(wumpusY).deleteEvent();
                    cave.at(wumpusX).at(wumpusY).setEvent(nullptr);
                    break;
                }
                else {
                    arrowY--;
                }
            }
        }
        numArrows--;
        moveWumpus();
    }
}

/*********************************************************************
** Function: fireDown
** Description: fire an arrow down if they have one
** Parameters: None
*********************************************************************/
void Game::fireDown() {
    if(numArrows < 1) {
        cout << "You don't have any more arrows.\n";
    }
    else {
        arrowX = (curX + 1);
        arrowY = curY;
        if(curX < (caveSize - 3)) {
            while((curX + 3) != (arrowX - 1)) {
                if(arrowX == wumpusX && arrowY == wumpusY) { 
                    cout << "You killed the Wumpus!\n";
                    wumpusDead = true;
                    cave.at(wumpusX).at(wumpusY).deleteEvent();
                    cave.at(wumpusX).at(wumpusY).setEvent(nullptr);
                    break;
                }
                else {
                    arrowX++;
                }
            }
        }
        else {
            while((arrowX - 1) != (caveSize - 1)) {
                if(arrowX == wumpusX && arrowY == wumpusY) { 
                    cout << "You killed the Wumpus!\n";
                    wumpusDead = true;
                    cave.at(wumpusX).at(wumpusY).deleteEvent();
                    cave.at(wumpusX).at(wumpusY).setEvent(nullptr);
                    break;
                }
                else {
                    arrowX++;
                }
            }
        }
        numArrows--;
        moveWumpus();
    }
}

/*********************************************************************
** Function: fireRight
** Description: fire an arrow to the right if they have one
** Parameters: None
*********************************************************************/
void Game::fireRight() {
    if(numArrows < 1) {
        cout << "You don't have any more arrows.\n";
    }
    else {
        arrowX = curX;
        arrowY = (curY + 1);
        if(curY < (caveSize - 3)) {
            while((curY + 3) != (arrowY - 1)) {
                if(arrowX == wumpusX && arrowY == wumpusY) { 
                    cout << "You killed the Wumpus!\n";
                    wumpusDead = true;
                    cave.at(wumpusX).at(wumpusY).deleteEvent();
                    cave.at(wumpusX).at(wumpusY).setEvent(nullptr);
                    break;
                }
                else {
                    arrowY++;
                }
            }
        }
        else {
            while((arrowY - 1) != (caveSize - 1)) {
                if(arrowX == wumpusX && arrowY == wumpusY) { 
                    cout << "You killed the Wumpus!\n";
                    wumpusDead = true;
                    cave.at(wumpusX).at(wumpusY).deleteEvent();
                    cave.at(wumpusX).at(wumpusY).setEvent(nullptr);
                    break;
                }
                else {
                    arrowY++;
                }
            }
        }
        numArrows--;
        moveWumpus();
    }
}

/*********************************************************************
** Function: moveWumpus
** Description: moves the wumpus to a random spot if they miss an arrow
** Parameters: None
*********************************************************************/
void Game::moveWumpus() {
    int a = rand() % 4;  //rand num 0-3
    if(wumpusDead == false) {
        if(a != 3) {    //75% chance that a = 0, 1, or 2
            cave.at(wumpusX).at(wumpusY).deleteEvent();
            cave.at(wumpusX).at(wumpusY).setEvent(nullptr);
            setWumpus();
        }
    }
}