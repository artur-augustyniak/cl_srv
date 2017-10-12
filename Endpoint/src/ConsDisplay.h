#ifndef CONSDISPLAY_H
#define CONSDISPLAY_H

#include "Display.h"
#include<iostream>

class ConsDisplay : public Display {
public:
    ConsDisplay();
    ConsDisplay(const ConsDisplay& orig);
    virtual ~ConsDisplay();
    int display(std::string);
private:

};

#endif /* CONSDISPLAY_H */

