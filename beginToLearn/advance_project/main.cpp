#include <iostream>

using namespace std;

// 函数模板
template<typename T>
// 声明一个模板，告诉编译器后面代码中的T不要报错，T是一个通用数据类型
void swap_two_number(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}


// 两个整型交换函数
void swap_two_int(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// 两个浮点型交换
void swap_two_double(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

/*
 * 案例描述
            利用函数模板封装一个排序的函数,可以对不同数据类型数组进行排序
            ·排序规则从大到小,排序算法为选择排序
            ·分别利用char数组和int数组进行测试
 */
template<typename T>
void sort_array_by_bubble(T &array) {
    // 获取数组长度
    int array_length = sizeof(array) / sizeof(array[0]);
    // 冒泡排序
    for (int i = 0; i < array_length - 1; i++) {
        for (int j = 0; j < array_length - 1 - i; j++) {
            if (array[j] < array[j + 1]) {
                auto temp = array[j];   // 自动类型
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}


/*
 * 模板的局限
 * 对比类
 */
class Person {
public:
    string name;
    int age;

    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }
};

// 对比模板
template<class T>
bool is_equal(T &a, T &b) {
    return a == b;
}

// 利用具体化Person的版本实现代码，具体化优先调用
template<>
bool is_equal(Person &p1, Person &p2) {
    return (p1.name == p2.name && p1.age == p2.age);
}


// 类模板
// 不使用默认参数类型  template<class NameType, class AgeType>
template<class NameType=string, class AgeType=int>  // 使用默认参数类型类型
class Student {
public:
    NameType name;
    AgeType age;

    Student(NameType name, AgeType age) {
        this->name = name;
        this->age = age;
    }

    void show_info() {
        cout << this->name << " " << this->age << endl;
    }
};


/*
 * 类模板对象做函数参数
        学习目标：
            ·类模板实例化出的对象,向函数传参的方式
        一共有三种传入方式:
            1.指定传入的类型 - 直接显示对象的数据类型
            2.参数模板化  - 将对象中的参数变为模板进行传递
            3.整个类模板化 - 将这个对象类型模板化进行传递
 */
template<class T1, class T2>
class Teacher {
public:
    T1 name;
    T2 age;

    Teacher(T1 name, T2 age) {
        this->name = name;
        this->age = age;
    }

    void show_info() {
        cout << this->name << " " << this->age << endl;
    }
};

// 1.指定传入的类型 - 直接显示对象的数据类型
void print_teacher_1(Teacher<string, int> &t) {
    t.show_info();
}

// 2.参数模板化
template<class T1, class T2>
void print_teacher_2(Teacher<T1, T2> &t) {
    t.show_info();
    cout << "T1的类型为：" << typeid(T1).name() << endl;
    cout << "T2的类型为：" << typeid(T2).name() << endl;
}

// 3.整个类模板化
template<class T>
void print_teacher_3(T &t) {
    t.show_info();
}


/*
 * 类模板与继承
 */
template<class T>
class Base {
public:
    T m;
};

// 当子类继承的父类是一个类模板时,子类在声明的时候,要指定出父类中T的类型
class Son : public Base<int> {

};

// 如果想灵活指定出父类中T的类型,子类也需变为类模板
template<class T1, class T2>
class Son2 : public Base<T2> {
    T1 obj;
};


/*
 * 类模板成员函数类外实现
 */
template<class T1, class T2>
class Human {
public:
    T1 name;
    T2 age;

    // 成员函数类内声明
    Human(T1 name, T2 age);

    void show_info();
};

// 类外实现
template<class T1, class T2>
Human<T1, T2>::Human(T1 name, T2 age) {
    this->name = name;
    this->age = age;
}

template<class T1, class T2>
void Human<T1, T2>::show_info() {
    cout << this->name << " " << this->age << endl;
}


// 模板使用
void test_1() {
    int a = 10;
    int b = 20;
    // 普通方式
    /*
    // 交换
    swap_two_int(a,b);
    cout << "a=" << a << " b=" << b << endl;

    double c = 2.3;
    double d = 4.3;
    // 交换
    swap_two_double(c,d);
    cout << "c=" << c << " d=" << d << endl;
     */

    /*
     * 模板方式交换数据
     * 两种使用方式
     *      1.自动类型推导
     *          swap_two_number(a,b);
     *      2.显示指定类型
     *          swap_two_number<int>(a,b);
     */
    swap_two_number(a, b);
    cout << "a=" << a << " b=" << b << endl;
}

// 模板案例
void test_2() {
    /* 模板案例 */
    // int类型
    int int_array[] = {2, 1, 5, 3, 7, 8, 4};
    // 排序
    sort_array_by_bubble(int_array);
    for (int i:int_array) {
        cout << i << "\t";
    }
    cout << endl;
    // char类型
    //char char_array[] = {'a','c','b','d','h','f'};
    char char_array[] = "helloworld";
    // 排序
    sort_array_by_bubble(char_array);
    for (char i:char_array) {
        cout << i << "\t";
    }
    cout << endl;
}

// 模板局限
void test_3() {
    Person p1("Jake", 19);
    Person p2("Tom", 18);
    Person p3("Tom", 18);
    cout << "p1和p2:" << is_equal(p1, p2) << endl;
    cout << "p2和p3:" << is_equal(p2, p3) << endl;
}

// 类模板
void test_4() {
    // 实例化类模板
    Student<string, int> p1("纳斯", 20);    // 普通
    Student<> p2("你啊", 10);    // 使用默认参数类型
    p1.show_info();
    p2.show_info();
}

// 类模板对象做函数参数
void test_5() {
    // 1.指定传入的类型
    Teacher<string, int> t1("消歧", 30);
    print_teacher_1(t1);
    // 2.参数模板化
    print_teacher_2(t1);
    // 3.整个类模板化
    print_teacher_3(t1);
}

// 类模板成员函数类外实现
void test_6() {
    Human<string, int> h("小其", 20);
    h.show_info();
}

// 分文件编写
#include "source/woman.cpp"    // 解决方式1
#include "header/man.hpp"      // 解决方式2

void test_7() {
    Woman<string, int> w("女阿", 20);
    Man<string, int> m("男阿", 20);
    w.show_info();
    m.show_info();
}

// 类模板与友元
#include "header/class_template_and_friend.hpp"


// 类模板案例
#include "header/MyArray.hpp"
// 测试自定义数据类型
class Cat {
public:
    string name;
    int age;
    Cat() {};

    Cat(string name, int age) {
        this->name = name;
        this->age = age;
    }
};

void print_info(MyArray<int>&array){
    cout << "数组大小：" << array.get_capacity() << " 数组元素个数：" << array.get_size() << endl;
    for(int i=0;i<array.get_size();i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

void print_info(MyArray<Cat>&array){
    cout << "数组大小：" << array.get_capacity() << " 数组元素个数：" << array.get_size() << endl;
    for(int i=0;i<array.get_size();i++){
        cout << "昵称：" << array[i].name << " 年龄：" << array[i].age << endl;
    }
}

void test_9() {
    MyArray<int> array(3);
    MyArray<int> array2(array); // 调用拷贝构造
    MyArray<int> array3(100);
    array3 = array2;
    // 测试尾插法
    array3.push(1);
    print_info(array3);
    array3.push(2);
    array3.push(3);
    array3.push(8);
    print_info(array3);
    int valaue1 = array3.pop();   // 测试尾删法
    cout << "尾删的元素：" << valaue1 << endl;
    print_info(array3);
    // 测试自定义数据类型
    MyArray<Cat>array4(3);
    Cat c1("小白",3);
    Cat c2("小黑",2);
    Cat c3("小红",1);
    // 将数据插入数组中
    array4.push(c1);
    array4.push(c2);
    array4.push(c3);
    print_info(array4);
}


int main() {
    // 模板的使用
    test_1();   // 模板使用
    test_2();   // 模板案例
    test_3();   // 模板局限
    test_4();   // 类模板
    test_5();   // 类模板对象做函数参数
    test_6();   // 类模板成员函数类外实现
    test_7();   // 分文件编写
    test_8();   // 类模板与友元
    test_9();   // 类模板案例
    return 0;
}


