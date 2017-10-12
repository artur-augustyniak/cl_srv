#include "GameController.h"

GameController::GameController(SlotGame& g) : game(g) {
}

GameController::GameController(const GameController& orig) : game(orig.game) {
}

GameController::~GameController() {
}

bool GameController::HandleRequest(NetSock& s) {
    
    uint8_t packet_id;

    int ret = s.Read(&packet_id, 1);
    if (ret == 0) {
        puts("disconnected");
        return false;
    }

    switch (packet_id) {
        case 'T': // terminate
        {
            puts("Terminating");
            return false;
        }
        case 'M': // msg
        {
            char c = 0;
            while ('\n' != c) {
                if (s.Read(&c, 1) != 1) {
                    puts("disconnected");
                    return false;
                }
                printf("%c", c);
            }
        }
            break;
        case 'R': // run
        {
            if (WIN == game.run_round()) {
                s.WriteAll("user won\n", 9);
            }else{
                s.WriteAll("user loose\n", 11);
            }
            flushTheRest(s);
        }
            break;
        default:
            puts("invalid packet ID");
            flushTheRest(s);

    }
    return true;

}

