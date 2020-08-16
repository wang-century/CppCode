#ifndef SPEECHCONTESTPROCESSMANAGEMENTSYSTEM_SPEECHMANAGER_H
#define SPEECHCONTESTPROCESSMANAGEMENTSYSTEM_SPEECHMANAGER_H

#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "speaker.h"
#include <algorithm>
#include <deque>
#include <numeric>
#include <fstream>
using namespace std;

class SpeechManager {
public:

    vector<int>v1;  // 第一轮比赛选手编号
    vector<int>v2;  // 第一轮晋级选手编号
    vector<int>victory_v;       // 前三名选手编号
    map<int,Speaker>speaker_m;  // 编号及对应选手
    int turn_count; // 比赛轮次
    bool data_file_empty;   // 用于判断数据文件是否为空
    map<int,vector<string>>history_m;    // 存放往届成绩记录


    SpeechManager();
    void show_menu();
    void init_speech();     // 初始化容器和属性
    void create_speaker();  // 创建选手
    void start_speech();    // 开始比赛
    void random_draw();     // 随机抽签
    void sppech_contest();  // 比赛
    void show_score();      // 显示得分
    void save_data();       // 保存数据到文件
    void show_history();    // 查看记录
    void clear_data();      // 清空记录
    ~SpeechManager();
};


#endif //SPEECHCONTESTPROCESSMANAGEMENTSYSTEM_SPEECHMANAGER_H
