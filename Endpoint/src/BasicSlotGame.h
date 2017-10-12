/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BasicSlotGame.h
 * Author: aaugustyniak
 *
 * Created on 5 sierpnia 2017, 09:44
 */

#ifndef BASICSLOTGAME_H
#define BASICSLOTGAME_H

#include "SlotGame.h"
#include "Display.h"
#include <random>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <iostream>

typedef std::mt19937 Rng;
typedef std::uniform_int_distribution<uint32_t> IntUniDist;
typedef std::vector<int> Result;

class BasicSlotGame : public SlotGame{
public:
    BasicSlotGame(Display& d, uint32_t rngSeed, uint32_t range);
    BasicSlotGame(const BasicSlotGame& orig);
    virtual ~BasicSlotGame();
    Outcome run_round();
private:
    uint32_t max_range;
    Display& display;
    Rng rng;
    IntUniDist pool;
    Result draw_result;
    void resetResult();
};

#endif /* BASICSLOTGAME_H */

