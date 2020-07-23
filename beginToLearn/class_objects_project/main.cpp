#include <iostream>
#include <tgmath.h>

using namespace std;

/*
 * 设计一个圆类，求圆的周长
 */

const double PI = 3.14;  //圆周率

class Circle1 {
public: // 访问权限
    // 属性
    double r;   // 半径

    // 获取圆的周长
    double get_perimeter() {
        return 2 * PI * r;  // 圆的周长公式：2 * PI * 半径
    }
};

/*
 * 设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号
 * */
class Student {
private:
    // 成员属性设置为私有
    // 1.可以控制读写权限
    // 2.可以检测写入数据有效性
    string name;
    string id;

public:
    void set_name(string stu_name) {
        name = stu_name;
    }

    void set_id(string stu_id) {
        id = stu_id;
    }

    void print_info() {
        // 打印学生的姓名和学号
        cout << "姓名：" << name << "\t学号：" << id << endl;
    }

};


/*
 * 设计立方体(Cube)，求出立方体的面积和体积，分别用全局函数和成员函数判断两个立方体是否相等
 */
class Cube {
public:
    // 长宽高属性
    double length;
    double width;
    double height;

//    // 获取属性
//    double get_length(){
//        return length;
//    }
//    double get_width(){
//        return width;
//    }
//    double get_height(){
//        return height;
//    }

    // 设置立方体长宽高
    void set_property(double cube_length, double cube_width, double cube_height) {
        length = cube_length;
        width = cube_width;
        height = cube_height;
    }

    // 获取立方体面积和体积
    double get_area() {
        return 2 * length * width + 2 * length * height + 2 * width * height;
    }

    // 获取立方体体积
    double get_volume() {
        return length * height * width;
    }

    // 利用成员函数判断立方体是否相等
    double is_same(Cube cube) {
        if (cube.length == length && cube.width == width && cube.height == height) {
            return true;
        }
        return false;
    }

};

// 设置全局函数用于判断立方体是否相等
bool cube_is_same(Cube a, Cube b) {
    if (a.length == b.length && a.width == b.width && a.height == b.height) {
        return true;
    }
    return false;
}


/*
 * 4.设计一个圆形类(Circle)，和一个点类(Point)，计算点和圆的关系(通过点和圆心的距离判断：点在圆内、圆上、圆外)
 */
// 引入自定义点类
#include "head/point.h"

// 圆类
class Circle2 {
public:
    double r;   // 半径
    Point center;   // 圆心

};

// 判断点和圆的关系
void where_point_in_circle(Circle2 &circle, Point point) {
    double x_length = (point.x - circle.center.x) * (point.x - circle.center.x);
    double y_length = (point.y - circle.center.y) * (point.y - circle.center.y);
    double center_point_length = sqrt(x_length + y_length); // 计算点到圆心的距离

    // 若点到圆心的距离大于半径 则点在圆外
    if (center_point_length > circle.r) {
        cout << "点在圆外" << endl;
    } else {
        // 若点到圆心的距离相同 则点在圆上
        if (center_point_length == circle.r) {
            cout << "点在圆上" << endl;
        } else {  // 若点到圆心的距离小于半径 则点在圆内
            cout << "点在圆内" << endl;
        }
    }
}


// 构造函数和析构函数
// 对象的初始化和清理
class Person {
private:
    int age{};
public:
    Person() {
        cout << "Person初始化" << endl;
    }

    // 有参构造
    Person(int per_age) {
        age = per_age;
        cout << "Person的有参构造" << endl;
    }

    // 拷贝构造函数
    Person(const Person &p) {
        // 拷贝该实例的所有属性
        age = p.age;
        cout << "Person的拷贝构造" << endl;
    }

    ~Person() {
        cout << "清理Person" << endl;
    }
};

/*
 * 深拷贝和浅拷贝：
 *      浅拷贝：简单的赋值拷贝操作
 *      深拷贝：在堆区重新申请空间，进行拷贝操作
 */
class Person2 {
public:
    int *age;
    double height;

    Person2() {
        cout << "Person2构造函数" << endl;
    }

    // 传统初始化
    Person2(int p_age) {
        age = new int(p_age);   // 将年龄放置在堆区
    }

    // 初始化列表    用来初始化属性
    Person2(double p_height) : height(p_height) {

    }

    Person2(Person2 &p) {
        // 拷贝构造函数
        age = new int(*p.age);  // 深拷贝：在堆区开辟新的空间保存年龄信息
    }

    ~Person2() {
        if (age != NULL) {
            cout << "Person2析构函数，释放堆区age" << endl;
            delete age;
        }
    }

};

/*
 * 静态变量
 */
class Person3{
public:
    static int age; // 静态成员变量   类内声明

    // 静态成员函数
    static void print_info(){
        cout << "Person3年龄:" << age << endl;
    }

private:
    static double height;   // 静态成员变量有访问权限
};

int Person3::age = 20;  // 静态成员变量 类外初始化
double Person3::height = 150;

int main() {
    // 1.设计一个圆类，求圆的周长
    // 通过圆类 创建具体的圆
    Circle1 circle1;
    // 赋予属性
    circle1.r = 10;
    // 获取圆的周长
    cout << "圆的周长" << circle1.get_perimeter() << endl;


    // 2.设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号
    Student student1;
    student1.set_id("J1701505");
    student1.set_name("century");
    student1.print_info();

    // 3.设计立方体(Cube)，求出立方体的面积和体积，分别用全局函数和成员函数判断两个立方体是否相等
    Cube cube1;
    cube1.set_property(10, 10, 10);
    cout << "立方体的面积为:" << cube1.get_area() << endl;
    cout << "立方体的体积为:" << cube1.get_volume() << endl;
    Cube cube2;
    cube2.set_property(10, 10, 10);
    Cube cube3;
    cube3.set_property(10, 10, 11);
    // 用全局函数判断两个立方体是否相等
    if (cube_is_same(cube1, cube2)) {  // 判断立方体是否相同
        cout << "立方体cube1和cube2相同" << endl;
    } else {
        cout << "立方体cube1和cube2不相同" << endl;
    }
    // 用成员函数判断两个立方体是否相等
    if (cube1.is_same(cube3)) {  // 判断立方体是否相同
        cout << "立方体cube1和cube3相同" << endl;
    } else {
        cout << "立方体cube1和cube3不相同" << endl;
    }

    // 4.设计一个圆形类(Circle)，和一个点类(Point)，计算点和圆的关系(通过点和圆心的距离判断：点在圆内、圆上、圆外)
    Point p1;   // 设置点
    p1.set_property(10, 0);
    Circle2 circle2;    // 设置圆
    circle2.r = 10;
    circle2.center.set_property(10, 9);
    where_point_in_circle(circle2, p1);

    // 对象的初始化的清理
    // 三种调用方式
    // 1.括号法
    Person person1; // 默认构造函数调用
    Person person2(10); // 有参构造
    Person person3(person2);    // 拷贝构造函数
    // 2.显式法
    // 注意不要利用拷贝构造函数初始化匿名对象  编译器会认为 Person (p_2) 等价于 Person p_2;
//    Person p_1;
//    Person p_2 = Person(10);    // 等号右边叫匿名对象，特点：当前行执行结束后，系统会立即回收掉匿名对象
//    Person p_3 = Person(p_2);
    // 3.隐式转换法
//    Person p_4 = 10;    // 相当于 Person p_4 = Person(10);
//    Person p_5 = p_4;   // 拷贝构造


    // 深拷贝与浅拷贝
    Person2 p__1(10);
    Person2 p__2(p__1);


    // 静态成员
    cout << "\n静态成员" << endl;
    Person3 person3_1;
    Person3 person3_2;
    person3_1.age = 20;
    cout << "静态成员变量age：" << person3_1.age << endl;  // 通过实例访问
    person3_2.age = 30;
    cout << "静态成员变量age：" << person3_2.age << endl;
    cout << "通过类名访问静态成员变量age：" << Person3::age << endl;   // 通过类名访问
    // 静态函数
    person3_2.print_info();
    Person3::print_info();
    cout << endl;



    return 0;
}