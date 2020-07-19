//
// Created by wsj on 2020/7/19.
//
#include <iostream>
#include "swap.h"

using namespace std;

int return_max_number(int a, int b) {
    // 返回两者最大值
    return a > b ? a : b;
}

void use_point() {
    // 使用指针
    int a = 10;
    // 创建指针 指向a
    int *p = &a;
    cout << "a的地址为：" << &a << endl;
    cout << "a的地址为：" << p << endl;
    cout << "p指向的数据：" << *p << endl;
    cout << "指针所占内存空间：" << sizeof(p) << endl;   // 无论任何数据类型的指针 32位操作系统占用4个字节  64位8个字节

    // 空指针和野指针
    // 空指针：指针变量指向内存中编号为0的空间  用途：初始化指针变量  注意：空指针指向的内存不可访问 (0~255为系统占用内存，不允许用户访问)
    int *p2 = NULL;
    // 野指针：指针变量指向非法的内存空间
    // 在程序中尽量避免出现野指针
    int *p3 = (int *) 0x1100;

    // const 修饰指针
    int num1 = 10;
    int num2 = 20;
    // 1.修饰指针：常量指针      特点：指针的指向可以修改，指向的值不可以修改
    const int *p4 = &a;
    // 2.修饰常量：指针常量      特点：指针的指向不可以修改，指针指向的值可该
    int *const p5 = &a;
    // 3.既修饰指针又修饰常量     特点：都不可以修改
    const int *const p6 = &a;

    // 利用指针访问数组中元素
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int *point1 = array;
//    cout << "array第一个元素：" << *point1 << endl;
//    point1++;   // 指针后移
//    cout << "array第二个元素：" << *point1 << endl;
    // 访问所有元素
    for (int i = 0; i < 10; i++) {
        cout << *point1 << "\t";
        point1++;
    }
    cout << endl;

}

void point_and_function(int *point1, int *point2) {
    // 指针和函数  交换两数值(修改原数值)
    cout << "a,b的值原为：" << *point1 << "\t" << *point2 << endl;
    int temp = *point1;
    *point1 = *point2;
    *point2 = temp;
}

void bubble_sort2(int *array, int len) {
    // 冒泡排序，实现对整形数组的升序排序
//    int array[] = {1,4,0,3,7,8,6,4,2};

    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}


