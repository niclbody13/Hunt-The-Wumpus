#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include "event.h"

class Player : public Event {
    private:
       
    public:
        virtual void percept() override;
        virtual void encounter() override;
        virtual void drawDebug();
        virtual void drawNormal();
};

#endif