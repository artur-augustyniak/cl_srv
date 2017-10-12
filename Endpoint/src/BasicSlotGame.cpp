#include "BasicSlotGame.h"

BasicSlotGame::BasicSlotGame(Display& d, uint32_t rngSeed, uint32_t range) : display(d), max_range(range) {
    rng.seed(rngSeed);
    pool = IntUniDist(0, max_range);
    resetResult();
}

BasicSlotGame::BasicSlotGame(const BasicSlotGame& orig) : display(orig.display) {
}

BasicSlotGame::~BasicSlotGame() {
}

Outcome BasicSlotGame::run_round() {
    resetResult();
    draw_result.push_back(pool(rng));
    draw_result.push_back(pool(rng));
    draw_result.push_back(pool(rng));

    std::ostringstream oss;
    std::copy(draw_result.begin(), draw_result.end() - 1,
            std::ostream_iterator<uint32_t>(oss, ","));
    oss << draw_result.back();

    if (std::adjacent_find(
            draw_result.begin(),
            draw_result.end(),
            std::not_equal_to<uint32_t>()) == draw_result.end()) {
        display.display("You won! " + oss.str());
        return WIN;
    } else {
        display.display("You loose! " + oss.str());
        return LOSS;
    }
}

void BasicSlotGame::resetResult() {
    draw_result.clear();
}
