#ifndef BATS_H
#define BATS_H

#include <iostream>
#include <vector>
#include "event.h"

class Bats : public Event {
    private:
        
    public:
        virtual void percept() override;
        virtual void encounter() override;
        virtual void drawDebug();
        virtual void drawNormal();
};

#endif