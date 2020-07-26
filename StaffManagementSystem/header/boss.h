#ifndef STAFFMANAGEMENTSYSTEM_BOSS_H
#define STAFFMANAGEMENTSYSTEM_BOSS_H

#include "worker.h"

class Boss : public Worker {
public:
    Boss(int id, string name, int department_id);
    void show_info();
    string get_department_name();
};


#endif //STAFFMANAGEMENTSYSTEM_BOSS_H
