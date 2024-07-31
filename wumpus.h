#ifndef WUMPUS_H
#define WUMPUS_H

#include <iostream>
#include <vector>
#include "event.h"

class Wumpus : public Event {
    private:
        
    public:
        virtual void percept() override;
        virtual void encounter() override;
        virtual void drawDebug();
        virtual void drawNormal();
        void arrowEncounter();
};

#endif