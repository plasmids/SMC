#ifndef GA_MANAGER_H
#define GA_MANAGER_H

#include "../core/global_basic.h"
#include "../core/global_game.h"

namespace SMC {

class cGA_Run {
    cGA_Run();
    ~cGA_Run();
    float Score();

    std::vector<float> m_jumps;
    float m_progress;
    static const float PROGRESS_WEIGHT, JUMPS_WEIGHT;
};

class cGA_Manager {
public:
    cGA_Manager();
    ~cGA_Manager();

    float m_level_length;
    std::vector<cGA_Run> m_runs;
    int m_generation;

protected:
    bool compare_rank(cGA_Run a, cGA_Run b);
};

extern cGA_Manager *pGA_Manager;

} // namespace SMC

#endif // GA_MANAGER_H

