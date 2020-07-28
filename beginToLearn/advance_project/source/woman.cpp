#include "../header/woman.h"

/*
 * 第一种实现方式
 */
template <class T1,class T2>
Woman<T1,T2>::Woman(T1 name,T2 age){
    this->name = name;
    this->age = age;
}

template <class T1,class T2>
void Woman<T1,T2>::show_info(){
    cout << this->name << " " << this->age << endl;
}