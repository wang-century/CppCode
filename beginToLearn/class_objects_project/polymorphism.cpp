#include <iostream>
#include "head/polymorphism.h"
using namespace std;

/*
 * 多态
 */

class Animal{
public:
    virtual void speak(){
        cout << "动物说话"  << endl;
    }
};

class Cat: public Animal{
public:
    void speak(){
        cout << "喵～～喵～" << endl;
    }
};

class Dog: public Animal{
public:
    void speak(){
        cout << "汪～汪～汪～" << endl;
    }
};


// 地址早绑定
// 在编译阶段已确定函数地址
// 动态多态的使用
// 父类的指针或者引用 指向子类对象
void do_speak(Animal &animal){
    animal.speak();
}


// 多态实现计算器
// 抽象计算器类
class AbstractCalculator{
public:
    int number1;
    int number2;
    // 虚函数
    /*
    virtual int get_result(){
        return 0;
    }*/
    // 纯虚函数
    virtual int get_result() = 0;
};

// 加法计算器类
class AddCalculator: public AbstractCalculator{
public:
    int get_result() override{
        return number1+number2;
    }
};

// 减法计算器类
class SubCalculator: public AbstractCalculator{
public:
    int get_result() override{
        return number1-number2;
    }
};

// 乘法计算器类
class MulCalculator: public AbstractCalculator{
public:
    int get_result() override{
        return number1*number2;
    }
};


/*
 * 制作饮品
    描述：制作饮品的大致流程为：煮水->冲泡->倒入杯中->加入辅料
        利用多态实现本例，提供抽象制作饮品基类，提供子类制作咖啡和茶叶
        咖啡（煮水->冲泡咖啡->倒入杯中->加糖和牛奶）
        冲茶叶(煮水->冲泡茶叶->倒入杯中->加柠檬)
 */
// 抽象类
class MakeDrinks{
public:
    virtual void heat_water() = 0;  // 煮水
    virtual void brewing() = 0; // 冲泡
    virtual void pour_into_cup() = 0;   // 倒入杯中
    virtual void add_ingredients() = 0;  // 加入辅料
    // 制作饮品
    virtual void make_drinks() {
        heat_water();
        brewing();
        pour_into_cup();
        add_ingredients();
    }
    // 纯虚析构
    virtual ~MakeDrinks()=0;
};
// 制作咖啡
class MakeCoffee: public MakeDrinks{
    void heat_water(){
        cout << "煮水" << endl;
    }
    void brewing(){
        cout << "冲泡咖啡" << endl;
    }
    void pour_into_cup(){
        cout << "倒入杯中" << endl;
    }
    void add_ingredients(){
        cout << "加糖和牛奶" << endl;
    }
};
// 冲茶叶
class MakeTea: public MakeDrinks{
    void heat_water(){
        cout << "煮水" << endl;
    }
    void brewing(){
        cout << "冲泡茶叶" << endl;
    }
    void pour_into_cup(){
        cout << "倒入杯中" << endl;
    }
    void add_ingredients(){
        cout << "加柠檬" << endl;
    }
};
// 制作函数
void do_make_drinks(MakeDrinks *makeDrinks){
    makeDrinks->make_drinks();
    delete makeDrinks;
}




void use_polymorphism1(){
    cout << "\n\t动态多态" << endl;
    Cat cat;
    Dog dog;
    do_speak(cat);
    do_speak(dog);
    cout << endl;
}

void use_polymorphism2(){
    // 多态实现计算器
    cout << "\n\t多态实现计算器" << endl;
    // 加法运算
    AbstractCalculator * calculator = new AddCalculator;
    calculator->number1 = 10;
    calculator->number2 = 20;
    cout << calculator->number1 << "+" << calculator->number2 << "=" << calculator->get_result() << endl;
    delete calculator;  // 释放
    // 减法运算
    calculator = new SubCalculator;
    calculator->number1 = 10;
    calculator->number2 = 20;
    cout << calculator->number1 << "-" << calculator->number2 << "=" << calculator->get_result() << endl;
    delete calculator;  // 释放
    // 乘法运算
    calculator = new MulCalculator;
    calculator->number1 = 10;
    calculator->number2 = 20;
    cout << calculator->number1 << "*" << calculator->number2 << "=" << calculator->get_result() << endl;
    delete calculator;  // 释放

    cout << endl;
}

void use_polymorphism3(){
    // 制作饮品
    cout << "\n\t制作饮品" << endl;
    MakeDrinks * makeDrinks = new MakeCoffee;
    do_make_drinks(makeDrinks);
    makeDrinks = new MakeTea;
    do_make_drinks(makeDrinks);
    cout << endl;
}