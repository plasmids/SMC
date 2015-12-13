#include "../core/ga_manager.h"

namespace SMC {

const float cGA_Run::PROGRESS_WEIGHT = 1.0f;
const float cGA_Run::JUMP_DENSITY = 1 / 300.0f;
const float cGA_Run::JUMPS_WEIGHT = 0.1f;
int cGA_Run::m_num_jumps = 0;

bool Compare_Rank(cGA_Run a, cGA_Run b)
{
    return a.m_score > b.m_score;
}

cGA_Run :: cGA_Run()
{
    // HACK / HARDCODE !!FIX!! For lvl_1
    m_jumps = std::vector<float>();
    m_level_length = 8290.0f;
    m_num_jumps = (int) m_level_length * JUMP_DENSITY;
    Randomize();
}

cGA_Run :: ~cGA_Run()
{

}

void cGA_Run :: Score(float progress)
{
    m_progress = progress;
    float progress_score = PROGRESS_WEIGHT * m_progress;
    float jump_score = JUMPS_WEIGHT * ( 1 - m_jumps.size() / m_num_jumps );
    m_score = progress_score + jump_score;
}

void cGA_Run :: Randomize()
{
    m_score = 0.0f;
    m_progress = 0.0f;
    m_jumps.clear();
    for (int i=0; i<m_num_jumps; i++)
    {
        float jump_x = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/m_level_length));
        m_jumps.push_back(jump_x);
    }
    std::sort(m_jumps.begin(), m_jumps.end(), std::greater<float>());
}

/*******************************************************************/

cGA_Manager :: cGA_Manager()
{
    srand(time(NULL));
    m_population_size = 10;
    m_generation = 0;
    m_current_run_index = 0;
    for(int i=0; i<m_population_size; i++)
    {
        m_runs.push_back(cGA_Run());
    }
    Begin_Run();
}

cGA_Manager :: ~cGA_Manager()
{

}

void cGA_Manager :: Update()
{
    Check_Jump();
    Check_Stuck();
    Check_Victory();
    m_last_pos_x = pLevel_Player->m_pos_x;
    m_last_pos_y = pLevel_Player->m_pos_y;
}

void cGA_Manager :: Check_Jump()
{
    if(m_current_run_jumps.size() > 0)
    {
        if(pLevel_Player->m_pos_x > m_current_run_jumps.back())
        {
            pLevel_Player->Start_Jump();
            m_current_run_jumps.pop_back();
        }
    }
}

void cGA_Manager :: Check_Stuck()
{
    if(pLevel_Player->m_pos_x == m_last_pos_x && pLevel_Player->m_pos_y == m_last_pos_y)
    {
        pLevel_Player->DownGrade_Player(0, 1);
    }
}

void cGA_Manager :: Check_Victory()
{
    if(pLevel_Player->m_pos_x > m_runs[m_current_run_index].m_level_length)
    {
        pLevel_Player->DownGrade_Player(0, 1);
    }
}

void cGA_Manager :: Begin_Run()
{
    m_current_run_jumps = m_runs[m_current_run_index].m_jumps;
}

void cGA_Manager :: End_Run()
{
    m_runs[m_current_run_index].Score(pLevel_Player->m_pos_x / m_runs[m_current_run_index].m_level_length);
    Print_Run();
    m_current_run_index++;
    if(m_current_run_index >= m_runs.size())
    {
        Breed();
    }
    Begin_Run();
}

void cGA_Manager :: Breed()
{
    std::sort(m_runs.begin(), m_runs.end(), Compare_Rank);
    m_current_run_index = 0;
    m_generation++;
}

void cGA_Manager :: Print_Run()
{
    std::cout << m_generation << "-" << m_current_run_index
              << " P:" << m_runs[m_current_run_index].m_progress << " J:"
              << m_runs[m_current_run_index].m_jumps.size() << " Score:"
              << m_runs[m_current_run_index].m_score << std::endl;
}

cGA_Manager *pGA_Manager = NULL;

} // namespace SMC
