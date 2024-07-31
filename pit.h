#ifndef PIT_H
#define PIT_H

#include <iostream>
#include <vector>
#include "event.h"

class Pit : public Event {
    private:
    
    public:
        virtual void percept() override;
        virtual void encounter() override;
        virtual void drawDebug();
        virtual void drawNormal();
};

#endif