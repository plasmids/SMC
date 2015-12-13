#ifndef GA_MANAGER_H
#define GA_MANAGER_H

#include "../core/global_basic.h"
#include "../core/global_game.h"
#include "../level/level_player.h"
#include <stdlib.h>
#include <time.h>
#include <algorithm>

namespace SMC {

class cGA_Run {
public:
    cGA_Run();
    ~cGA_Run();
    void Score(float progress);
    float Get_Rand_X();
    void Randomize();
    std::vector<cGA_Run> Mate(cGA_Run partner);

    float m_level_length;
    float m_score;
    std::vector<float> m_jumps;
    float m_progress;

    static int m_num_jumps;
    static const float PROGRESS_WEIGHT, JUMPS_WEIGHT, JUMP_DENSITY;
};

class cGA_Manager {
public:
    cGA_Manager();
    ~cGA_Manager();

    void Update();
    void Check_Jump();
    void Check_Stuck();
    void Check_Victory();
    void Begin_Run();
    void End_Run();
    void Breed();
    void Print_Run();

    std::vector<cGA_Run> m_runs;
    std::vector<float> m_current_run_jumps;
    int m_current_run_index;
    int m_generation;
    int m_population_size;

    float m_last_pos_x;
    float m_last_pos_y;
};

extern cGA_Manager *pGA_Manager;

} // namespace SMC

#endif // GA_MANAGER_H

