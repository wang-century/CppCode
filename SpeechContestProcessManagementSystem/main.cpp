#include <iostream>
#include "sources/speechManager.h"
using namespace std;


int main(){
    SpeechManager manager;  // 创建管理类对象
//    for(map<int,Speaker>::iterator it=manager.speaker_m.begin();it!=manager.speaker_m.end();it++){
//        cout << it->first << it->second.name << it->second.score[0] << it->second.score[1] << endl;
//    }

    int choice = 0;     // 存储用户输入
    while (true){
        manager.show_menu();    // 显示菜单
        cout << "请选择：";
        cin >> choice;
        switch (choice) {
            case 1:     // 开始演讲比赛
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
    return 0;
}
