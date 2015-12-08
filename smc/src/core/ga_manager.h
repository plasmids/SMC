#ifndef GA_MANAGER_H
#define GA_MANAGER_H

#include "../core/global_basic.h"
#include "../core/global_game.h"

namespace SMC {

class cGA_Manager {
public:
    cGA_Manager();
    ~cGA_Manager();
};

extern cGA_Manager *pGA_Manager;

} // namespace SMC

#endif // GA_MANAGER_H

