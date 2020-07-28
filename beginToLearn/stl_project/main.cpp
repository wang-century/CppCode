#include <iostream>

using namespace std;

/*
 * vector容器存放内置数据类型
 */
#include <vector>
#include <algorithm>    // 标准算法头文件

void print_value(int value) {
    cout << value << " ";
}

/* vector存放内置数据类型 */
void use_vector_1() {
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
    while (it_begin != it_end) {
        cout << *it_begin << " ";
        it_begin++;
    }
    cout << endl;
    // 第二种遍历方式
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    // 第三种遍历方式
    for_each(v.begin(), v.end(), print_value);
    cout << endl;
}

class Person {
public:
    int age;
    string name;

    Person(int age, string name) {
        this->age = age;
        this->name = name;
    }
};

/* vector存放自定义数据类型 Person */
void use_vector_2() {
    // 创建一个vector容器
    vector<Person> v;
    // 向容器中插入数据
    Person p1(10, "Lucy");
    Person p2(12, "Tom");
    Person p3(13, "Jake");
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    // 通过迭代器访问容器中数据
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
        cout << "姓名：" << (*it).name << " 年龄：" << (*it).age << endl;
        // 或使用
        // cout << "姓名：" << it->name << " 年龄："  << it->age << endl;
    }
}


/* vector存放自定义数据类型 指针 */
void use_vector_3() {
    // 创建一个vector容器
    vector<Person *> v;
    // 向容器中插入数据
    Person p1(10, "Lucy");
    Person p2(12, "Tom");
    Person p3(13, "Jake");
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    // 通过迭代器访问容器中数据
    for (vector<Person *>::iterator it = v.begin(); it != v.end(); it++) {
        cout << "姓名：" << (*it)->name << " 年龄：" << (*it)->age << endl;
    }
}

/* vector容器嵌套容器 */
void use_vector_4() {
    // 创建大容器
    vector<vector<int>> v;
    // 创建小容器
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    // 向小容器插入数据
    for (int i = 0; i < 4; i++) {
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
    }
    // 向小容器放入大容器
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    // 通过大容器遍历数据
    for (vector<vector<int>>::iterator i = v.begin(); i != v.end(); i++) {
        for (vector<int>::iterator j = i->begin(); j != i->end(); j++) {
            cout << *j << " ";
        }
        cout << endl;
    }
    cout << endl;
}


/* string构造函数 */
void use_string_1() {
    //创建一个空的字符串例如: string str;
    string string1; // 默认构造
    //使用字符串初始化
    const char *str = "Hello World";
    string string2(str);
    cout << "string2=" << string2 << endl;
    //使用一 个string对象初始化另 -个string对象
    string string3(string2);
    cout << "string3=" << string3 << endl;
    //使用n个字符初始化
    string string4(3, '*');
    cout << "string4=" << string4 << endl;
}


/* string赋值操作 */
void use_string_2() {
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
    str5.assign("Hello World", 5);
    cout << "str5=" << str5 << endl;
    // 6.
    string str6;
    str6.assign(str5);
    cout << "str6=" << str6 << endl;
    // 7.
    string str7;
    str7.assign(10, 'w');
    cout << "str7=" << str7 << endl;
}

/* string字符串拼接 */
void use_string_3() {
    string str1 = "I ";
    str1 += "love you"; // 1.
    cout << "str1=" << str1 << endl;
    str1 += ';';    // 2.
    cout << "str1=" << str1 << endl;
    string str2 = " you? ";
    str1 += str2;   // 3.
    cout << "str1=" << str1 << endl;
    string str3 = "I";
    str3.append(" love");   // 4.
    cout << "str3=" << str3 << endl;
    str3.append(" play game", 5);    // 5.把字符串s的前n个字符连接到当前字符串结尾
    cout << "str3=" << str3 << endl;
    str3.append(str2);  // 6.
    cout << "str3=" << str3 << endl;
    str3.append(str1, 11, 5); // 7.字符串s中从pos开始的n个字符连接到字符串结尾
    cout << "str3=" << str3 << endl;
}

/* string查找和替换 */
void use_string_4() {
    // 查找
    string str1 = "abcdefg";
    int pos1 = str1.find("de"); // 1.
    cout << pos1 << endl;
    // find 和 rfind的区别：rfind从右往左查  find从左往右查
    pos1 = str1.rfind("de");    // 2.
    cout << pos1 << endl;

    // 替换
    str1.replace(1, 3, "1111");    // 从下标1到3的字符替换为111
    cout << "str1=" << str1 << endl;
}

/* string字符串比较 */
void use_string_5() {
    string string1 = "hello world";
    string string2 = "hello world";
    string string3 = "hello World";
    cout << "string1与string2比较结果：" << string1.compare(string2) << endl;
    cout << "string1与string3比较结果：" << string1.compare(string3) << endl;
}

/* string字符存取 */
void use_string_6() {
    string str = "hello";
    // 通过[]访问单个字符
    for (int i = 0; i < str.size(); i++) {
        cout << str[i] << " ";
    }
    cout << endl;
    // 通过at方式访问单个字符
    for (int i = 0; i < str.size(); i++) {
        cout << str.at(i) << " ";
    }
    cout << endl;

    // 修改单个字符
    str[0] = 'x';
    cout << str << endl;

    str.at(1) = 'x';
    cout << str << endl;
}

/* string插入和删除 */
void use_string_7() {
    string str = "hello";
    // 插入
    str.insert(1, "111");
    cout << str << endl;
    // 删除
    str.erase(1, 3);
    cout << str << endl;
}

/* string子串 */
void use_string_8() {
    string str = "abcdefg";
    string sub_str = str.substr(1, 3);
    cout << sub_str << endl;
    // 从邮件地址中获取用户名信息
    // 例如：wsj@centuryw.cn  获取wsj
    string email_address = "wsj@centuryw.cn";
    int index = email_address.find('@');
    string name = email_address.substr(0, index);
    cout << name << endl;
}

/* vector容器 */
void print_vector(vector<int>&v){
    for (vector<int>::iterator i=v.begin(); i!=v.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}
// vector容器构造
void use_vector_5() {
    vector<int> v1;  // 1.默认构造 无参构造
    // 插入数据
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    print_vector(v1);   // 打印内容

    // 2.区间方式构造
    vector<int>v2(v1.begin(),v1.end()); // 将v1传入v2
    print_vector(v2);

    // 3.n个elem方式构造
    vector<int>v3(10,100);  // 传入10个100
    print_vector(v3);

    // 4.拷贝构造
    vector<int>v4(v3);
    print_vector(v4);
}

/* vector赋值操作 */
void use_vector_6() {
    vector<int>v1;
    // 插入数据
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    print_vector(v1);
    // 赋值
    // 1.=号
    vector<int>v2=v1;
    print_vector(v2);
    // 2.assign
    vector<int>v3;
    v3.assign(v1.begin(),v1.end());
    print_vector(v3);
    // 3.n个elem方式
    vector<int>v4;
    v4.assign(10,100);
    print_vector(v4);
}

/* vector容量和大小 */
void use_vector_7() {
    vector<int>v1;
    // 插入数据
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    print_vector(v1);
    // 判断容器是否为空
    if(v1.empty()){
        cout << "vector容器为空" << endl;
    }else{
        cout << "容器的大小为：" << v1.size() <<"\t容器的容量为：" << v1.capacity() << endl;
    }
    // 重新指定大小
    v1.resize(15);  // 如果重新指定的比原来长，默认使用0填充
    cout << "容器的大小为：" << v1.size() <<"\t容器的容量为：" << v1.capacity() << endl;
    print_vector(v1);
    v1.resize(16,100);  // 可以指定填充值
    cout << "容器的大小为：" << v1.size() <<"\t容器的容量为：" << v1.capacity() << endl;
    print_vector(v1);
    // 指定大小比原来短 超出的部分会删除
    v1.resize(10);
    cout << "容器的大小为：" << v1.size() <<"\t容器的容量为：" << v1.capacity() << endl;
    print_vector(v1);
}


/* vector插入和删除 */
void use_vector_8(){
    vector<int>v1;
    // 插入数据
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);    // 尾插法
    }
    print_vector(v1);
    v1.pop_back();  // 尾删法
    print_vector(v1);
    // 指定位置插入元素
    v1.insert(v1.begin(),100);
    print_vector(v1);
    // 指定位置插入多个元素
    v1.insert(v1.begin(),2,80);
    print_vector(v1);
    // 删除指定位置元素
    v1.erase(v1.begin());   // 删除头部元素
    print_vector(v1);
    // 删除区间元素
    v1.erase(v1.begin(),v1.begin()+3);  // 删除头部3个元素
    print_vector(v1);
    // 清空
    v1.clear();
    print_vector(v1);
}

/* vector数据存取 */
void use_vector_9(){
    vector<int>v1;
    // 插入数据
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);    // 尾插法
    }
    // 通过[]访问元素
    cout << v1[0] << endl;
    // 通过at访问元素
    cout << v1.at(1) << endl;
    // 通过front访问第一个元素
    cout << v1.front() << endl;
    // 通过front访问最后一个元素
    cout << v1.back() << endl;
}

/* vector互换容器 */
void use_vector_10(){
    vector<int>v1;
    // 插入数据
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);    // 尾插法
    }
    // vector互换容器
    vector<int>v2;
    // 插入数据
    for (int i = 0; i < 10; i++) {
        v2.push_back(i*3);    // 尾插法
    }
    print_vector(v1);
    print_vector(v2);
    v1.swap(v2);    // 互换元素
    print_vector(v1);
    print_vector(v2);

    // 实际用途
    // 使用swap可以收缩内存空间
    vector<int>v3;
    for(int i=0;i<100000;i++){
        v3.push_back(i);
    }
    cout << "容器的大小为：" << v3.size() <<"\t容器的容量为：" << v3.capacity() << endl;  // 容器的大小为：100000	容器的容量为：131072
    v3.resize(3);
    cout << "容器的大小为：" << v3.size() <<"\t容器的容量为：" << v3.capacity() << endl;  // 容器的大小为：3	容器的容量为：131072
    // 使用swap收缩内存
    vector<int>(v3).swap(v3);   // vector<int>(v3)代表匿名对象
    cout << "容器的大小为：" << v3.size() <<"\t容器的容量为：" << v3.capacity() << endl;  // 容器的大小为：3	容器的容量为：3
}

/* vector预留空间 */
void use_vector_11(){
    vector<int>v;

    int num = 0;    // 用于统计vector开辟空间次数
    int * p = NULL;
    // 插入数据
    for(int i=0;i<100000;i++){
        v.push_back(i);
        if(p!=&v[0]){   // 如果记录的地址不为当前内存地址，次数+1
            p = &v[0];
            num++;
        }
    }
    // 开辟空间次数：18	容器的大小为：100000	容器的容量为：131072
    cout << "开辟空间次数：" << num << "\t容器的大小为：" << v.size() <<"\t容器的容量为：" << v.capacity() << endl;


    vector<int>v2;
    // 利用reserve预留空间
    v2.reserve(100000);
    int num2 = 0;    // 用于统计vector开辟空间次数
    int * p2 = NULL;
    // 插入数据
    for(int i=0;i<100000;i++){
        v2.push_back(i);
        if(p2!=&v2[0]){   // 如果记录的地址不为当前内存地址，次数+1
            p2 = &v2[0];
            num2++;
        }
    }
    // 开辟空间次数：1	容器的大小为：100000	容器的容量为：100000
    cout << "开辟空间次数：" << num2 << "\t容器的大小为：" << v2.size() <<"\t容器的容量为：" << v2.capacity() << endl;

}


int main() {
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
    cout << "\tstring查找和替换:" << endl;
    use_string_4(); // string查找和替换
    cout << "\tstring字符串比较:" << endl;
    use_string_5(); // string字符串比较
    cout << "\tstring字符存取:" << endl;
    use_string_6(); // string字符存取
    cout << "\tstring插入和删除:" << endl;
    use_string_7(); // string插入和删除
    cout << "\tstring子串:" << endl;
    use_string_8(); // string子串
    cout << "\tvector容器构造:" << endl;
    use_vector_5(); // vector容器构造
    cout << "\tvector赋值操作:" << endl;
    use_vector_6(); // vector赋值操作
    cout << "\tvector容量和大小:" << endl;
    use_vector_7(); // vector容量和大小
    cout << "\tvector插入和删除:" << endl;
    use_vector_8(); //vector插入和删除
    cout << "\tvector数据存取:" << endl;
    use_vector_9(); // vector数据存取与互换容器
    cout << "\tvector互换容器:" << endl;
    use_vector_10(); // vector互换容器
    cout << "\tvector预留空间:" << endl;
    use_vector_11(); // vector预留空间
    return 0;
}
