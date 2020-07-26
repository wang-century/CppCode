#ifndef STAFFMANAGEMENTSYSTEM_MANAGER_H
#define STAFFMANAGEMENTSYSTEM_MANAGER_H
#include "worker.h"

/* 经理类 */
class Manager: public Worker{
public:
    Manager(int id,string name,int department_id);
    void show_info();
    string get_department_name();
};


#endif //STAFFMANAGEMENTSYSTEM_MANAGER_H
