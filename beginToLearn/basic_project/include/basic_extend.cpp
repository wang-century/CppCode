//
// Created by wsj on 2020/7/19.
//
#include <iostream>
#include "basic_extend.h"

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

// 全局变量
int global_a = 10;
int global_b = 10;
// const修饰的全局变量
const int const_global_a = 10;
const int const_global_b = 10;

void memeory_four_area() {
    /*
     * 总结：
     *  C++中在程序运行前分为全局区和代码区
     *  代码区特点为只读和共享
     *  全局区中存放全局变量、静态变量、常量
     *  常量区中存放const修饰的全局变量和字符串常量
     */

    // 内存四区：代码区、全局区、
    // 全局区：全局变量、静态变量、常量

    // 局部变量
    int a = 10;
    int b = 10;
    cout << "局部变量a的地址：" << (long) &a << endl;
    cout << "局部变量b的地址：" << (long) &b << endl;

    cout << "全局变量global_a的地址：" << (long) &global_a << endl;
    cout << "全局变量global_b的地址：" << (long) &global_b << endl;

    // 静态变量
    static int static_a = 10;
    static int static_b = 10;
    cout << "静态变量static_a的地址：" << (long) &static_a << endl;
    cout << "静态变量static_b的地址：" << (long) &static_b << endl;

    // 常量：字符串常量、const修饰的变量
    cout << "字符串常量地址：" << (long) &"Hello world!" << endl;

    // const修饰的全局变量
    cout << "全局常量const_global_a地址：" << (long) &const_global_a << endl;
    cout << "全局常量const_global_b地址：" << (long) &const_global_b << endl;
    // const修饰的局部变量
    const int const_local_a = 10;
    const int const_local_b = 10;
    cout << "局部常量const_local_a地址：" << (long) &const_local_a << endl;
    cout << "局部常量const_local_b地址：" << (long) &const_local_b << endl;

}


int *use_statk() {
    /*
     * 栈区
     * 栈区数据注意事项：不要返回局部变量的地址（栈区的数据由编译器管理开辟和释放）
     */
    // 错误示范
    int a = 10; // 局部变量
    return &a;  // 返回局部变量的地址
}

int *use_heap() {
    /*
     * 堆区
     *  由程序员分配释放，若程序员不释放，程序结束时由操作系统回收
     *  在c++中主要利用new在堆区开辟内存
     */
    // 开辟数据到堆区
    int *p = new int(10);  // 直接返回堆的地址到指针p
    return p;
}

void use_new() {
    /*
     * new操作符
     *  c++中利用new操作符在堆区开辟数据
     *  堆区数据由程序员手动使用new开辟，使用delete释放
     *  利用new创建的数据，会返回数据对应的类型的指针
     */
    int *p = use_heap();   // 获取在堆开辟的数据
    cout << "堆的数据：" << *p << endl;
    cout << "释放堆的数据..." << endl;
    delete p;   // 释放堆的数据

    // 开辟数组
    int *array_point = new int[10];    // 返回连续空间数组的首地址
    // 赋值
    for (int i = 0; i < 10; i++) {
        array_point[i] = i + 100;
    }
    // 打印
    for (int i = 0; i < 10; i++) {
        cout << array_point[i] << "\t";
    }
    cout << endl;
    delete[] array_point; // 释放数组,注意加中括号
}

void use_reference2(int &a, int &b) {
    // 使用别名代替指针操作原数据
    int temp = a;
    a = b;
    b = temp;
}

int &use_reference3() {
    /*
     * 引用做函数返回值
     * 注意：
     *      不要返回局部变量的引用
     *      函数的调用可以作为左值
     */
    static int a = 10;  // 静态变量，存在全局区
    return a;
}

void use_reference4() {
    /*
     * 常量引用
     * 使用场景：用来修饰形参，防止误操作
     */
    // 加上const之后 变为只可读 编译器将代码修改为 int temp = 10;   const int & ref = temp;
    const int &ref = 10;   // 引用必须引一块合法的内存空间

}

void use_reference() {
    /*
     * 引用：给变量起别名  引用的本质在c++内部实现是一个指针常量
     * 语法：数据类型 &别名 = 原名;
     * 注意：引用必须初始化；
     *      引用在初始化后，不可以改变（不能再作为别的别名）
     */
    int a = 10;
    int &b = a;
    b = 20;
    cout << "a的值" << a << endl;

    int number1 = 10;
    int number2 = 10;
    use_reference2(number1, number2);
    cout << "使用引用交换后的值：number1=" << number1 << "\tnumber2=" << number2 << endl;

    // 引用做函数返回值
    int &ref1 = use_reference3();
    cout << "引用做函数返回值 ref1=" << ref1 << endl;
    // 函数的调用可以作为左值
    use_reference3() = 30;
    cout << "函数的调用可以作为左值 ref1=" << ref1 << endl;

    // 常量引用
    use_reference4();
}

int function_default_argument(int a, int b,int c) {
    /*
     * 函数默认参数
     * 注：
     *      如果传入该参数，则使用传入的值，否则使用默认值
     *      如果某个位置已经有了默认参数，那么从该位置往右都必须有默认值
     *      如果函数声明有默认参数，函数实现就不能有默认参数
     */
    return a + b + c;
}

void func(int a,int){   // int 就是占位符
    /*
     * 函数占位参数
     * 说明：c++函数的形参列表可以有占位符，用来做占位，调用函数时必须填补该位置
     * 语法：返回值类型 函数名 (数据类型){}
     */
}

void func(){
    cout << "func结果" << endl;
}

void func(int a,int b,int c){
    cout << "func(int a,int b,int c)结果" << endl;
}


void function_overloading(){
    /*
     * 函数重载
     * 作用：函数名可以相同，提高复用性
     * 满足条件：
     *      同一作用域下
     *      函数名称相同
     *      函数参数类型不同 或者 个数不同 或 顺序不同
     * 注意：函数的返回值不可以作为函数重载的条件
     */
    func();
    func(1,2);
    func(1,2,3);
}
