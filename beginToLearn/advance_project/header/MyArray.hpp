#ifndef ADVANCE_PROJECT_MYARRAY_HPP
#define ADVANCE_PROJECT_MYARRAY_HPP

#endif //ADVANCE_PROJECT_MYARRAY_HPP
#include <iostream>
using namespace std;
/* 类模板案例
    案例描述:实现一个通用的数组类,要求如下
        ·可以对内置数据类型以及自定义数据类型的数据进行存储
        ·将数组中的数据存储到堆区
        ·构造函数中可以传入数组的容量
        ·提供对应的拷贝构造函数以及 operator=防止浅拷贝问题
        ·提供尾插法和尾删法对数组中的数据进行增加和删除
        ·可以通过下标的方式访问数组中的元素
        ·可以获取数组中当前元素个数和数组的容量
*/
template <class T>
class MyArray{
private:
    T * array_address;  // 指针指向堆区开辟的真实数组
    int capacity;       // 数组容量
    int size;           // 数组大小

public:
    // 构造函数  参数：容量
    MyArray(int capacity){
        //cout << "MyArray构造函数调用" << endl;
        this->capacity = capacity;
        this->size = 0;
        this->array_address = new T[this->capacity];    // 根据传入的容量开辟空间
    }

    // 拷贝构造
    MyArray(const MyArray& array){
        //cout << "MyArray拷贝构造函数调用" << endl;
        this->capacity = array.capacity;
        this->size = array.size;
        // 深拷贝 开辟新的空间
        this->array_address = new T[array.capacity];
        // 拷贝数据
        for(int i=0;i<this->size;i++){
            this->array_address[i] = array.array_address[i];
        }
    }

    // 重载 = 号
    MyArray & operator=(const MyArray& array){
        //cout << "MyArray operator = 函数调用" << endl;
        // 先判断原来堆区是否有数据，如果有先释放
        if(this->array_address!=NULL){
            delete [] this->array_address;
            this->array_address = NULL;
            this->capacity = 0;
            this->size = 0;
        }
        // 深拷贝
        this->capacity = array.capacity;
        this->size = array.size;
        // 深拷贝 开辟新的空间
        this->array_address = new T[array.capacity];
        // 拷贝数据
        for(int i=0;i<this->size;i++){
            this->array_address[i] = array.array_address[i];
        }
        return * this;
    }

    // 尾插法
    void push(const T & value){
        // 判断容量是否等于大小
        if(this->capacity == this->size){
            cout << "数组已满！插入失败" << endl;
            return;
        }
        this->array_address[this->size] = value;    // 在数据末尾插入数据
        this->size++;   // 更新数组大小
    }

    // 尾删法 (删除最后一个数据并返回)
    T pop(){
        // 让用户访问不到最后一个元素（逻辑删除）
        if(this->size==0){
            cout << "删除失败！数组无数据" << endl;
            return -1;
        }else{
            this->size--;
            return this->array_address[size]; // 返回最后一个元素
        }
    }

    // 通过下标方式访问数组元素
    T & operator[](int index){
        return this->array_address[index];
    }

    // 返回数组容量
    int get_capacity(){
        return this->capacity;
    }

    // 返回数组大小
    int get_size(){
        return this->size;
    }

    // 析构函数
    ~MyArray(){
        if(this->array_address!=NULL){
            //cout << "MyArray析构函数调用" << endl;
            delete [] this->array_address;
            this->array_address = NULL;
        }
    }
};

