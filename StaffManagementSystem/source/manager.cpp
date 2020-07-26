#include "../header/manager.h"


Manager::Manager(int id,string name,int department_id){
    this->id = id;
    this->name = name;
    this->department_id = department_id;
}
void Manager::show_info(){
    cout << "职工编号：" << this->id
         << "\t职工姓名：" << this->name
         << "\t岗位：" << this->get_department_name()
         << "\t岗位职责：完成老板交给的任务，并下发任务给员工" << endl;
}
string Manager::get_department_name(){
    return string("经理");
}