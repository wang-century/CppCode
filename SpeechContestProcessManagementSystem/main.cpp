#include <iostream>
#include "sources/speechManager.h"
using namespace std;


int main(){
    SpeechManager manager;  // 创建管理类对象

    int choice = 0;     // 存储用户输入
    while (true){
        manager.show_menu();    // 显示菜单
        cout << "请选择：";
        cin >> choice;
        switch (choice) {
            case 1:     // 开始演讲比赛
                manager.start_speech();
                break;
            case 2:     // 查看往届记录
            case 3:     // 清空比赛记录
                break;
            case 4:     // 退出比赛程序
                cout << "程序退出" << endl;
                return 0;
            default:
                cout << "输入错误!重新输入" << endl;
        }
    }
}
