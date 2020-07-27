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
        Student(NameType name,AgeType age){
            this->name = name;
            this->age = age;
        }
        void show_info(){
            cout << this->name << " " << this->age << endl;
        }
};


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
void test_4(){
    // 实例化类模板
    Student<string,int> p1("纳斯",20);    // 普通
    Student<> p2("你啊",10);    // 使用默认参数类型
    p1.show_info();
    p2.show_info();
}

int main() {
    // 模板的使用
    test_1();
    test_2();
    test_3();
    test_4();
    return 0;
}


