#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include "NetSock.h"
#include "SlotGame.h"
#include <stdint.h>

class GameController {
public:
    GameController(SlotGame& g);
    GameController(const GameController& orig);
    virtual ~GameController();
    bool HandleRequest(NetSock &s);
private:
    SlotGame& game;

    void flushTheRest(NetSock &s) {
        char c = 0;
        do {
            if (s.Read(&c, 1) != 1) {
            }
        } while ('\n' != c);
    }
};

#endif /* GAMECONTROLLER_H */

