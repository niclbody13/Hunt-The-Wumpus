#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "room.h"

using namespace std;

class Game {
    private:
        int caveSize;
        std::vector<std::vector<Room> > cave;
        int startingX;
        int startingY;
        int curX;
        int curY;
        std::string choice;
        int choiceNum;
        int goldX;
        int goldY;
        bool goldTaken;
        bool gameOver;
        bool inBatRoom;
        int numArrows;
        int arrowX;
        int arrowY;
        int wumpusX;
        int wumpusY;
        bool wumpusDead;
        bool ropeSet;
        bool debugMode;

    public:
        Game(int); 
        void createBoard();
        void printCaveDebug();
        void printCaveNormal();
        void setEvent();
        void setWumpus();
        void setBats();
        void setGold();
        void setPit();
        void setInitialLocation();
        void getDirection();
        void turn();
        void changeLocation();
        void up();
        void left();
        void right();
        void down();
        bool isGoldTaken();
        bool isGameOver();
        void checkGold();
        void setRandomLocation();
        void checkBats();
        void callPercept();
        void convertToNum();
        void fireUp();
        void fireLeft();
        void fireDown();
        void fireRight();
        void moveWumpus();
        void setRope();
};

#endif