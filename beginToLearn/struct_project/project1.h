//
// Created by wsj on 2020/7/19.
//

#ifndef CPPCODE_PROJECT1_H
#define CPPCODE_PROJECT1_H

#endif //CPPCODE_PROJECT1_H
#include <iostream>
using namespace std;

void allocate_space(struct Teacher teacher_array[],int len);
void print_all_info(struct Teacher teacher_array[],int len);

// 案例1结构体
// 学生
struct Student{
    string name;
    double score=0;
};
// 老师
struct Teacher{
    string name;
    Student stu[5];
};