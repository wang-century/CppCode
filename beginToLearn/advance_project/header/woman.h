#ifndef ADVANCE_PROJECT_WOMAN_H
#define ADVANCE_PROJECT_WOMAN_H
#include <iostream>
using namespace std;

/* 第一种实现方式 */
template <class T1,class T2>
class Woman {
public:
    T1 name;
    T2 age;
    Woman(T1 name,T2 age);
    void show_info();
};




#endif //ADVANCE_PROJECT_WOMAN_H
