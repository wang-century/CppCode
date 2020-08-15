#include "speechManager.h"

SpeechManager::SpeechManager(){
    this->init_speech();    // 初始化容器和属性
    this->create_speaker(); // 创建选手
}

SpeechManager::~SpeechManager(){

}

void SpeechManager::show_menu(){
    /* 显示菜单 */
    cout << string(20,'*') << endl;
    cout << "\t演讲比赛流程管理系统" << endl;
    cout << "\t1.开始演讲比赛" << endl;
    cout << "\t2.查看往届记录" << endl;
    cout << "\t3.清空比赛记录" << endl;
    cout << "\t4.退出比赛程序" << endl;
    cout << string(20,'*') << endl;
}

void SpeechManager::init_speech(){
    /* 初始化容器和属性 */
    this->v1.clear();
    this->v2.clear();
    this->victory_v.clear();
    this->speaker_m.clear();
    this->turn_count = 1;
}

void SpeechManager::create_speaker(){
    /* 创建选手 */
    string speaker_names = "ABCDEFGHIJKL";
    for(int i=0;i<12;i++){
        // 创建选手，放入容器
        string name = "选手";
        name += speaker_names[i];
        int id = i+1001;
        Speaker speaker;
        speaker.name = name;
        speaker.score[0] = 0;
        speaker.score[1] = 0;
        this->v1.push_back(id);
        this->speaker_m.insert(make_pair(id,speaker));
    }
}

void SpeechManager::start_speech(){
    /* 开始比赛 */
    // 第一轮开始比赛
    // 1、抽签
    // 2、比赛
    // 3、显示晋级结果
    // 第二轮开始比赛
    // 1、抽签
    // 2、比赛
    // 3、显示晋级结果
    // 4.保存分数到文件中


}
