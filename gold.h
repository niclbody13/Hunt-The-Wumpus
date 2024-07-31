#ifndef GOLD_H
#define GOLD_H

#include <iostream>
#include <vector>
#include "event.h"

class Gold : public Event {
    private:
   
    public:
        virtual void percept() override;
        virtual void encounter() override;
        virtual void drawDebug();
        virtual void drawNormal();
        Gold();
};

#endif