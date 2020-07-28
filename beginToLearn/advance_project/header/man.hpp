//
// Created by wsj on 2020/7/27.
//

#ifndef ADVANCE_PROJECT_MAN_HPP
#define ADVANCE_PROJECT_MAN_HPP
#include <iostream>
using namespace std;

/* 第二种实现方式 */
template <class T1,class T2>
class Man {
public:
    T1 name;
    T2 age;
    Man(T1 name,T2 age);
    void show_info();
};
template <class T1,class T2>
Man<T1,T2>::Man(T1 name,T2 age){
    this->name = name;
    this->age = age;
}

template <class T1,class T2>
void Man<T1,T2>::show_info(){
    cout << this->name << " " << this->age << endl;
}

#endif //ADVANCE_PROJECT_MAN_HPP
