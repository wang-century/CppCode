#ifndef STAFFMANAGEMENTSYSTEM_WORKER_H
#define STAFFMANAGEMENTSYSTEM_WORKER_H
#include <iostream>
using namespace std;

/*
 * 职工抽象类
    职工的分类为:普通员工、经理、老板
    将三种职工抽象到一个类( worker)中利用多态管理不同职工种类
    职工的属性为:职工编号、职工姓名、职工所在部门编号
    职工的行为为:岗位职责信息描述,获取岗位名称
 */
class Worker{
public:
    int id;         // 编号
    string name;    // 姓名
    int department_id;  // 所在部门名称编号
    // 显示信息
    virtual void show_info()=0;
    // 获取岗位名称
    virtual string get_department_name() = 0;
};



#endif //STAFFMANAGEMENTSYSTEM_WORKER_H
