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
    // 虚析构
    /*
    virtual ~MakeDrinks(){
        cout << "MakeDrinks纯析构函数调用" << endl;
    }*/
    // 纯虚析构 需要声明也需要实现
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
// 纯虚析构
MakeDrinks::~MakeDrinks(){
    cout << "MakeDrinks纯虚析构函数调用" << endl;
};

/*
 * 电脑组装
            描述：电脑主要组成部件为CPU、显卡、内存条
                将每个零件封装出抽象类，并且提供不同的厂商生产不同的零件，例如Intel厂商和Lenove厂商
                创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口
                测试时组装三台不同的电脑进行工作
 */
// 抽象CPU类
class CPU{
public:
    virtual void calculate() = 0;   // 纯虚函数
};
// 抽象显卡类
class GPU{
public:
    virtual void display() = 0;
};
// 抽象内存条类
class MemoryBank{
public:
    virtual void storage() = 0;
};
// 设计两个厂商的相关产品
class IntelCPU: public CPU{
public:
    void calculate() override{
        cout << "Intel CPU正在计算" << endl;
    }
};
class LenovoCPU: public CPU{
public:
    void calculate() override{
        cout << "Lenovo CPU正在计算" << endl;
    }
};
class IntelGPU: public GPU{
public:
    void display() override{
        cout << "Intel GPU正在计算画面" << endl;
    }
};
class LenovoGPU: public GPU{
public:
    void display() override{
        cout << "Lenovo GPU正在计算画面" << endl;
    }
};
class IntelMemoryBank: public MemoryBank{
public:
    void storage() override{
        cout << "Intel 内存条正在存储" << endl;
    }
};
class LenovoMemoryBank: public MemoryBank{
public:
    void storage() override{
        cout << "Lenovo 内存条正在存储" << endl;
    }
};
// 设计电脑类

class Computer{
public:
    CPU *cpu;
    GPU *gpu;
    MemoryBank *memoryBank;

    // 构造函数，传入三个零件的指针
    Computer(CPU *cpu,GPU *gpu,MemoryBank *memoryBank){
        this->cpu = cpu;
        this->gpu = gpu;
        this->memoryBank = memoryBank;
    }

    // 工作函数
    void work(){
        cpu->calculate();
        gpu->display();
        memoryBank->storage();
    }

    // 释放电脑零件
    ~Computer(){
        if(cpu!=NULL){
            delete cpu;
            cpu = NULL;
        }
        if(gpu!=NULL){
            delete gpu;
            gpu = NULL;
        }
        if(memoryBank!=NULL){
            delete cpu;
            memoryBank = NULL;
        }
    }

};

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

void use_polymorphism4(){
    // 电脑组装
    cout << "\n\t电脑组装" << endl;
    // 创建第一台电脑零件
    CPU * intel_cpu = new IntelCPU;
    GPU * intel_gpu = new IntelGPU;
    MemoryBank * intel_memory_bank = new IntelMemoryBank;
    // 创建第一台电脑
    Computer * computer1 = new Computer(intel_cpu,intel_gpu,intel_memory_bank);
    cout << "第一台电脑开始工作" << endl;
    computer1->work();
    cout << "第一台电脑停止工作" << endl;
    delete computer1;
    // 创建第二台电脑
    Computer * computer2 = new Computer(new LenovoCPU,new LenovoGPU,new LenovoMemoryBank);
    cout << "第二台电脑开始工作" << endl;
    computer2->work();
    cout << "第二台电脑停止工作" << endl;
    delete computer2;
    // 创建第三台电脑
    Computer * computer3 = new Computer(new LenovoCPU,new IntelGPU,new LenovoMemoryBank);
    cout << "第三台电脑开始工作" << endl;
    computer3->work();
    cout << "第三台电脑停止工作" << endl;
    delete computer3;
    cout << endl;
}