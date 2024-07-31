#ifndef ROPE_H
#define ROPE_H

#include <iostream>
#include <vector>
#include "event.h"

class Rope : public Event{
    private:
    
    public:
        virtual void percept() override;
        virtual void encounter() override;
        virtual void drawDebug();
        virtual void drawNormal();
};

#endif