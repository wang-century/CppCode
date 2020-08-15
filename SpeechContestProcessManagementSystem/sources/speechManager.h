#ifndef SPEECHCONTESTPROCESSMANAGEMENTSYSTEM_SPEECHMANAGER_H
#define SPEECHCONTESTPROCESSMANAGEMENTSYSTEM_SPEECHMANAGER_H

#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "speaker.h"
using namespace std;

class SpeechManager {
public:

    vector<int>v1;  // 第一轮比赛选手编号
    vector<int>v2;  // 第一轮晋级选手编号
    vector<int>victory_v;       // 前三名选手编号
    map<int,Speaker>speaker_m;  // 编号及对应选手
    int turn_count; // 比赛轮次

    SpeechManager();
    void show_menu();
    void init_speech();     // 初始化容器和属性
    void create_speaker();  // 创建选手
    void start_speech();    // 开始比赛

    ~SpeechManager();
};


#endif //SPEECHCONTESTPROCESSMANAGEMENTSYSTEM_SPEECHMANAGER_H
