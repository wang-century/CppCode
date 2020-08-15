#ifndef SPEECHCONTESTPROCESSMANAGEMENTSYSTEM_SPEAKER_H
#define SPEECHCONTESTPROCESSMANAGEMENTSYSTEM_SPEAKER_H

#pragma once
#include <iostream>
using namespace std;

/* 选手 */
class Speaker {
public:
    string name;        // 姓名
    double score[2];    // 得分(最多两轮)
};


#endif //SPEECHCONTESTPROCESSMANAGEMENTSYSTEM_SPEAKER_H
