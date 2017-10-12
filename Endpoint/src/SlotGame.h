#ifndef SLOTGAME_H
#define SLOTGAME_H

enum Outcome {
    WIN,
    LOSS,
};

class SlotGame {
public:
    SlotGame();
    SlotGame(const SlotGame& orig);
    virtual ~SlotGame() = 0;
    virtual Outcome run_round() = 0;
private:

};

#endif /* SLOTGAME_H */

