#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector>
#include "event.h"
#include "wumpus.h"
#include "gold.h"
#include "bats.h"
#include "pit.h"
#include "player.h"
#include "rope.h"

class Room {
    private:
        Event *events;
    public:
        Room();
        ~Room();
        void printDebug();
        void printNormal();
        void setRope();
        void setWumpus();
        void setBats();
        void setPit();
        void setGold();
        Event* getEvent();
        void setLocation();
        void setEvent(Event*);
        void deleteEvent();
};

#endif