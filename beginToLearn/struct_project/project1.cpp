#include "project1.h"
#include <iostream>
#include "ctime"
using namespace std;


// 给老师和学生赋值函数
void allocate_space(struct Teacher teacher_array[],int len){

    string teacher_name = "ABCDEFG";
    // 随机数种子
    srand((unsigned int)time(NULL));

    for (int i=0;i<len;i++){
        // 给老师赋值
        teacher_array[i].name = "Teacher ";
        teacher_array[i].name += teacher_name[i];
        for (int j=0;j<5;j++){
            // 给学生赋值
            teacher_array[i].stu[j].name = "Student ";
            teacher_array[i].stu[j].name += teacher_name[j];
            double random_score = rand() % 60 + 40;
            teacher_array[i].stu[j].score = random_score;
        }
    }
}

// 打印信息
void print_all_info(struct Teacher teacher_array[],int len){
    for (int i=0;i<len;i++){
        cout << "老师姓名："<<teacher_array[i].name<<endl;
        cout << "\t所带学生及成绩：\n";
        for (int j=0;j<5;j++){
            cout << "\t\t" << teacher_array[i].stu[j].name << "\t" << teacher_array[i].stu[j].score << endl;
        }
    }
}