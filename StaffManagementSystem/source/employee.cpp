#include "../header/employee.h"

Employee::Employee(int id,string name,int department_id) {
    this->id = id;
    this->name = name;
    this->department_id = department_id;
}

void Employee::show_info() {
    cout << "职工编号：" << this->id
        << "\t职工姓名：" << this->name
        << "\t岗位：" << this->get_department_name()
        << "\t岗位职责：完成经理交给的任务" << endl;
}

string Employee::get_department_name() {
    return string("员工");
}
