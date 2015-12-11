#include "../core/ga_manager.h"

namespace SMC {

const float cGA_Run::PROGRESS_WEIGHT = 0.5f;
const float cGA_Run::JUMPS_WEIGHT = 0.5f;

cGA_Run :: cGA_Run()
{

}

cGA_Run :: ~cGA_Run()
{

}

float cGA_Run :: Score(float progress)
{
    m_progress = progress;
    m_score = m_progress * PROGRESS_WEIGHT +  JUMPS_WEIGHT / m_jumps.size();
}

cGA_Manager :: cGA_Manager()
{

}

cGA_Manager :: ~cGA_Manager()
{

}

bool cGA_Manager :: Compare_Rank(cGA_Run a, cGA_Run b)
{
    return a.score > b.score;
}

cGA_Manager *pGA_Manager = NULL;

} // namespace SMC
