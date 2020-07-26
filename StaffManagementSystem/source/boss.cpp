#include "../header/boss.h"


Boss::Boss(int id,string name,int department_id) {
    this->id = id;
    this->name = name;
    this->department_id = department_id;
}

void Boss::show_info() {
    cout << "职工编号：" << this->id
         << "\t职工姓名：" << this->name
         << "\t岗位：" << this->get_department_name()
         << "\t岗位职责：管理公司所有事务" << endl;
}

string Boss::get_department_name() {
    return string("老板");
}
