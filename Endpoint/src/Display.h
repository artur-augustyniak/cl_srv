#ifndef DISPLAY_H
#define DISPLAY_H
#include <string>

class Display {
public:
    Display();
    Display(const Display& orig);
    virtual ~Display();
    virtual int display(std::string) = 0;
private:

};

#endif /* DISPLAY_H */

