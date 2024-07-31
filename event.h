#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <vector>


class Event { 
    protected:
        bool dead;
        bool batRoom;
        bool wumpusRoom;
        bool wumpusDead;
        bool ropeRoom;

    public:
        virtual void percept() = 0;
        virtual void encounter() = 0;
        virtual void drawDebug();
        virtual void drawNormal();
        void arrowEncounter();
        Event();
        bool isDead();
        bool isBatRoom();
        bool isWumpus();
        void setWumpusDead(bool);
        bool isWumpusDead();
        bool isRopeRoom();
};

#endif 