#ifndef ADVANCE_PROJECT_CLASS_TEMPLATE_AND_FRIEND_HPP
#define ADVANCE_PROJECT_CLASS_TEMPLATE_AND_FRIEND_HPP

#include <iostream>

using namespace std;
/* 模板与友元 */

// 类外实现
template <class T1,class T2>
class Dog;
template <class T1,class T2>
void show_info2(Dog<T1,T2>d);


template<class T1, class T2>
class Dog {
    // 全局函数 类内实现
    friend void show_info(Dog<T1,T2>d){
        cout << "狗  名字：" << d.name << " 年纪："  << d.age << endl;
    }
    // 全局函数 类外实现
    friend void show_info2<>(Dog<T1,T2>d);
private:
    T1 name;
    T2 age;
public:
    Dog(T1 name, T2 age) {
        this->name = name;
        this->age = age;
    }
};
// 类外实现
template <class T1,class T2>
void show_info2(Dog<T1,T2>d){
    cout << "类外实现： 狗  名字：" << d.name << " 年纪："  << d.age << endl;
}


void test_8(){
    // 类内实现
    Dog<string,int>d("大黄",6);
    show_info(d);
    // 类外实现
    Dog<string,int>d2("大白",7);
    show_info2(d2);
}


#endif //ADVANCE_PROJECT_CLASS_TEMPLATE_AND_FRIEND_HPP
