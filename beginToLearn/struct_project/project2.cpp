#include "project2.h"
#include <iostream>
using namespace std;

void bubble_sort(Hero hero_array[],int len){
    for (int i=0;i<len-1;i++){
        for (int j=0;j<len-1-i;j++){
            if(hero_array[j].age>hero_array[j+1].age){
                Hero temp = hero_array[j];
                hero_array[j] = hero_array[j+1];
                hero_array[j+1] = temp;
            }
        }
    }
}

void print_hero_info(Hero hero_array[],int len){
    for(int i=0;i<len;i++){
        cout << "英雄信息：" << "\t姓名：" << hero_array[i].name << "\t性别：" << hero_array[i].sex << "\t年龄：" << hero_array[i].age <<  endl;
    }
}

