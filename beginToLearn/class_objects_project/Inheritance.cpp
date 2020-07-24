#include "head/Inheritance.h"
#include <iostream>

using namespace std;
/*
 * 继承练习
 * 继承好处：减少重复代码
 * 语法：class 子类:继承方式 父类
 */

// 公共页面
class BasePage {
public:
    void header() {
        cout << "公共头部" << endl;
    }

    void footer() {
        cout << "公共尾部" << endl;
    }

    void left() {
        cout << "公共左边栏" << endl;
    }
};


// Java页面
class JavaPage : public BasePage {
public:
    void content() {
        cout << "Java相关页面内容" << endl;
    }
};

// c++页面
class CppPage : public BasePage {
public:
    void content() {
        cout << "C++相关页面内容" << endl;
    }
};

/*
 * 继承同名成员处理方式：
    访问子类同名成员 直接访问即可
    访问父类同名成员 需要添加作用域
 */

class Father {
public:
    int age;
    static string address;  // 声明静态成员

    Father() {
        age = 40;
    }

    void func() {
        cout << "Father-func()调用" << endl;
    }

    void func(int a) {
        cout << "Father-func(int a)调用" << endl;
    }
    static void show_info(){
        cout << "Father-show_info()调用" << endl;
    }
};
string Father::address = "山东";

class Son : public Father {
public:
    int age;
    static string address;  // 声明静态成员

    Son() {
        age = 20;
    }

    // 当子类与父类拥有同名的成员函数，子类会隐藏父类中所有版本的同名成员函数
    // 如果项访问父类中被隐藏的同名成员函数，需要添加父类的作用域
    void func() {
        cout << "Son-func()调用" << endl;
    }
    static void show_info(){
        cout << "Son-show_info()调用" << endl;
    }
};

string Son::address = "山东";

/*
 * 菱形继承
 */
// 动物类
class Animal{
public:
    int age;
};
// 羊类
// 继承之前加上关键字virtual变为虚继承
// Animal类称为 虚基类
class Sheep: virtual public Animal{

};
// 骆驼类
class Camel: virtual public Animal{

};

class Alpaca: public Sheep, public Camel{

};



void use_inheritance1() {
    // 继承的使用
    cout << "\n\t继承的使用" << endl;
    JavaPage javaPage;
    CppPage cppPage;
    javaPage.header();
    javaPage.content();
    javaPage.footer();

    cppPage.header();
    cppPage.content();
    cppPage.footer();
    cout << endl;
}

void use_inheritance2() {
    // 继承同名成员处理方式
    cout << "\n\t继承同名成员处理方式" << endl;
    Son s;
    // 调用同名成员变量
    cout << "Son下的age=" << s.age << endl;
    cout << "Father下的age=" << s.Father::age << endl;
    // 调用同名成员函数
    s.func();
    s.Father::func();
    s.Father::func(20);
    // 调用同名静态成员
    // 通过对象的方式
    cout << "Son下的address=" << s.address << endl;
    cout << "Father下的address=" << s.Father::address << endl;
    // 通过类名的方式
    cout << "Son下的address=" << Son::address << endl;
    cout << "Father下的address=" << Son::Father::address << endl;
    // 调用静态成员函数
    s.show_info();
    s.Father::show_info();
    Son::show_info();
    Son::Father::show_info();

    cout << endl;
}

void use_inheritance3(){
    // 菱形继承
    cout << "\n\t菱形继承" << endl;
    Alpaca alpaca;
    alpaca.Sheep::age = 20;
    alpaca.Camel::age = 18;
    cout << "alpaca.Sheep::age = " << alpaca.Sheep::age << endl;
    cout << "alpaca.Camel::age = " << alpaca.Camel::age << endl;
    cout << "alpaca.age = " << alpaca.age << endl;
    cout << endl;
}
