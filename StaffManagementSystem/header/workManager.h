#ifndef STAFFMANAGEMENTSYSTEM_WORKMANAGER_H
#define STAFFMANAGEMENTSYSTEM_WORKMANAGER_H
#include <iostream>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>  // 文件操作头

#define FILENAME "WorkerData.txt" // 设定数据保存文件路径
/*
 * 管理类
    管理类负责的内容如下:
        与用户的沟通菜单界面
        对职工增删改查的操作
        与文件的读写交互
 */
class WorkManager {
public:
    // 记录文件中的人数个数
    int worker_count;

    // 员工数组的指针
    Worker ** WorkerArray;

    // 用于判断数据保存文件是否为空
    bool data_file_empty;

    WorkManager();

    // 显示菜单
    void show_menu();

    // 添加职工
    void add_worker();

    // 保存文件
    void save();

    // 获取数据文件内的员工人数
    int get_worker_count();

    // 从数据文件添加成员到数组
    void init_worker();

    // 判断某id员工是否存在
    int id_worker_exists(int id);

    // 显示职工
    void show_worker();

    // 修改员工
    void update_worker();

    // 判断某姓名员工是否存在
    int * name_worker_exists(string name);

    // 查找职工
    void find_worker();

    // 删除员工
    void delete_worker();

    // 员工根据编号排序
    void sort_worker_by_id();

    // 清空文件
    void clean_data();
    ~WorkManager();
};



#endif //STAFFMANAGEMENTSYSTEM_WORKMANAGER_H
