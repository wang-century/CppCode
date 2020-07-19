//
// Created by wsj on 2020/7/19.
//

#ifndef CPPCODE_PROJECT2_H
#define CPPCODE_PROJECT2_H

#endif //CPPCODE_PROJECT2_H

#include <iostream>
using namespace std;

// 案例2结构体
// 英雄
struct Hero{
    string name;
    int age;
    string sex;
};

void bubble_sort(Hero hero_array[],int len);
void print_hero_info(Hero hero_array[],int len);