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

void cGA_Run :: Score(float progress)
{
    m_progress = progress;
    m_score = PROGRESS_WEIGHT * m_progress +  JUMPS_WEIGHT / m_jumps.size();
}

cGA_Manager :: cGA_Manager()
{

}

cGA_Manager :: ~cGA_Manager()
{

}

bool cGA_Manager :: Compare_Rank(cGA_Run a, cGA_Run b)
{
    return a.m_score > b.m_score;
}

cGA_Manager *pGA_Manager = NULL;

} // namespace SMC
