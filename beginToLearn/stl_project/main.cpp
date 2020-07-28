#include <iostream>
using namespace std;

/*
 * vector容器存放内置数据类型
 */
#include <vector>
#include <algorithm>    // 标准算法头文件

void print_value(int value){
    cout << value << " ";
}
/* vector存放内置数据类型 */
void use_vector_1(){
    // 创建一个vector容器，数组
    vector<int> v;
    // 向容器中插入数据
    v.push_back(10);
    v.push_back(30);
    v.push_back(20);
    // 通过迭代器访问容器中数据
    vector<int>::iterator it_begin = v.begin(); // 起始迭代器，指向容器中第一个元素
    vector<int>::iterator it_end = v.end();     // 结束迭代器，指向容器中最后一个元素的下一个位置
    // 第一种遍历方式
    while (it_begin!=it_end){
        cout << *it_begin << " ";
        it_begin++;
    }
    cout << endl;
    // 第二种遍历方式
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout << *it << " ";
    }
    cout << endl;
    // 第三种遍历方式
    for_each(v.begin(),v.end(),print_value);
    cout << endl;
}

class Person{
public:
    int age;
    string name;
    Person(int age,string name){
        this->age = age;
        this->name = name;
    }
};
/* vector存放自定义数据类型 Person */
void use_vector_2(){
    // 创建一个vector容器
    vector<Person>v;
    // 向容器中插入数据
    Person p1(10,"Lucy");
    Person p2(12,"Tom");
    Person p3(13,"Jake");
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    // 通过迭代器访问容器中数据
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++){
        cout << "姓名：" << (*it).name << " 年龄："  << (*it).age << endl;
        // 或使用
        // cout << "姓名：" << it->name << " 年龄："  << it->age << endl;
    }
}


/* vector存放自定义数据类型 指针 */
void use_vector_3(){
    // 创建一个vector容器
    vector<Person*>v;
    // 向容器中插入数据
    Person p1(10,"Lucy");
    Person p2(12,"Tom");
    Person p3(13,"Jake");
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    // 通过迭代器访问容器中数据
    for(vector<Person*>::iterator it=v.begin();it!=v.end();it++){
        cout << "姓名：" << (*it)->name << " 年龄："  << (*it)->age << endl;
    }
}

/* vector容器嵌套容器 */
void use_vector_4(){
    // 创建大容器
    vector<vector<int>>v;
    // 创建小容器
    vector<int>v1;
    vector<int>v2;
    vector<int>v3;
    // 向小容器插入数据
    for(int i=0;i<4;i++){
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
    }
    // 向小容器放入大容器
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    // 通过大容器遍历数据
    for(vector<vector<int>>::iterator i=v.begin();i!=v.end();i++){
        for(vector<int>::iterator j=i->begin();j!=i->end();j++){
            cout << *j << " ";
        }
        cout << endl;
    }
    cout << endl;
}


/* string构造函数 */
void use_string_1(){
    //创建一个空的字符串例如: string str;
    string string1; // 默认构造
    //使用字符串初始化
    const char * str = "Hello World";
    string string2(str);
    cout << "string2=" << string2 << endl;
    //使用一 个string对象初始化另 -个string对象
    string string3(string2);
    cout << "string3=" << string3 << endl;
    //使用n个字符初始化
    string string4(3,'*');
    cout << "string4=" << string4 << endl;
}


/* string赋值操作 */
void use_string_2(){
    // 1.
    string str1;
    str1 = "Hello World";
    cout << "str1=" << str1 << endl;
    // 2.
    string str2;
    str2 = str1;
    cout << "str2=" << str2 << endl;
    // 3.
    string str3;
    str3 = 'a';
    cout << "str3=" << str3 << endl;
    // 4.
    string str4;
    str4.assign("Hello World");
    cout << "str4=" << str4 << endl;
    // 5.
    string str5;
    str5.assign("Hello World",5);
    cout << "str5=" << str5 << endl;
    // 6.
    string str6;
    str6.assign(str5);
    cout << "str6=" << str6 << endl;
    // 7.
    string str7;
    str7.assign(10,'w');
    cout << "str7=" << str7 << endl;
}

/* string字符串拼接 */
void use_string_3(){


}

int main(){
    cout << "\tvector存放内置数据类型:" << endl;
    use_vector_1(); // vector存放内置数据类型
    cout << "\tvector存放自定义数据类型 Person:" << endl;
    use_vector_2(); // vector存放自定义数据类型 Person
    cout << "\tvector存放自定义数据类型 指针:" << endl;
    use_vector_3(); // vector存放自定义数据类型 指针
    cout << "\tvector容器嵌套容器:" << endl;
    use_vector_4(); // vector容器嵌套容器
    cout << "\tstring构造函数:" << endl;
    use_string_1(); // string构造函数
    cout << "\tstring赋值操作:" << endl;
    use_string_2(); // string赋值操作
    cout << "\tstring字符串拼接:" << endl;
    use_string_3(); // string字符串拼接
    return 0;
}
