#ifndef GA_MANAGER_H
#define GA_MANAGER_H

#include "../core/global_basic.h"
#include "../core/global_game.h"

namespace SMC {

class cGA_Run {
    cGA_Run();
    ~cGA_Run();
    float score();

    std::vector<float> jumps;
    float progress;
};

class cGA_Manager {
public:
    cGA_Manager();
    ~cGA_Manager();

    float m_level_length;
    std::vector<cGA_Run> runs;
    int generation;

protected:
    bool compare_rank(cGA_Run a, cGA_Run b);
};

extern cGA_Manager *pGA_Manager;

} // namespace SMC

#endif // GA_MANAGER_H

