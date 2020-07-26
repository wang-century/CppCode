#ifndef STAFFMANAGEMENTSYSTEM_EMPLOYEE_H
#define STAFFMANAGEMENTSYSTEM_EMPLOYEE_H
#include "worker.h"

/* 员工类 */
class Employee: public Worker {
public:
    Employee(int id,string name,int department_id);
    void show_info();
    string get_department_name();
};


#endif //STAFFMANAGEMENTSYSTEM_EMPLOYEE_H
