#include <iostream>

using namespace std;

#include "header/workManager.h"
#include "header/worker.h"
#include "header/boss.h"
#include "header/manager.h"
#include "header/employee.h"

void test() {
    Worker *worker = NULL;
    worker = new Employee(1, "章三", 1);
    worker->show_info();
    delete worker;

    worker = new Manager(2, "里斯i", 2);
    worker->show_info();
    delete worker;

    worker = new Boss(3, "王五", 3);
    worker->show_info();
    delete worker;
}


int main() {
    int choice; // 选择输入
    WorkManager work_manager;

    while (true) {
        work_manager.show_menu();   // 显示菜单
        cout << "请选择：";
        cin >> choice;
        switch (choice) {
            case 0: // 退出管理系统
                cout << "退出系统，感谢使用！" << endl;
                return 0;
            case 1: // 增加职工信息
                work_manager.add_worker();
                break;
            case 2: // 显示职工信息
                work_manager.show_worker();
                break;
            case 3: // 删除离职职工
                work_manager.delete_worker();
                break;
            case 4: // 修改职工信息
                work_manager.update_worker();
                break;
            case 5: // 查找职工信息
                work_manager.find_worker();
                break;
            case 6: // 按照编号排序
                work_manager.sort_worker_by_id();
                break;
            case 7: // 清空所有文档
                work_manager.clean_data();
                break;
            default:
                cout << "输入错误，请重新输入！" << endl;
                break;
        }
        int continue_flag = 1;
        cout << "是否继续？(1.是 0.否)";
        cin >> continue_flag;
        if (continue_flag == 0) {
            printf("\033[2J");  // 清屏
            cout << "退出系统，感谢使用！" << endl;
            return 0;
        }
        printf("\033[2J");  // 清屏
    }
    return 0;
}