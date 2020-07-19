#include <iostream>
#include "project1.h"
#include "project2.h"

using namespace std;

int main(){
    /*
     * 案例1
     */
    // 创建老师数组
    Teacher teacher_array[3];
    // 给老师赋值
    int teacher_array_len = sizeof(teacher_array)/sizeof(teacher_array[0]); // 数组长度
    allocate_space(teacher_array,teacher_array_len);    // 赋值函数
    print_all_info(teacher_array,teacher_array_len);    // 打印所有信息

    /*
     * 案例2
     */
    Hero hero_array[5] = {
            {"盖伦",40,"男"},
            {"拉克斯",20,"女"},
            {"金科斯",30,"男"},
            {"狗熊",240,"男"},
            {"Timo",16,"男"}
    };
    int hreo_array_len = sizeof(hero_array)/sizeof(hero_array[0]);
    bubble_sort(hero_array,hreo_array_len);
    print_hero_info(hero_array,hreo_array_len);
}

