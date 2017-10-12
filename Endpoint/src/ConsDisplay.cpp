#include "ConsDisplay.h"

ConsDisplay::ConsDisplay() {
}

ConsDisplay::ConsDisplay(const ConsDisplay& orig) {
}

ConsDisplay::~ConsDisplay() {
}

int ConsDisplay::display(std::string s) {
    std::cout << s << std::endl;
}

