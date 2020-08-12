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
void print_vector(vector<int> &v) {
    for (vector<int>::iterator i = v.begin(); i != v.end(); i++) {
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
    vector<int> v2(v1.begin(), v1.end()); // 将v1传入v2
    print_vector(v2);

    // 3.n个elem方式构造
    vector<int> v3(10, 100);  // 传入10个100
    print_vector(v3);

    // 4.拷贝构造
    vector<int> v4(v3);
    print_vector(v4);
}

/* vector赋值操作 */
void use_vector_6() {
    vector<int> v1;
    // 插入数据
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    print_vector(v1);
    // 赋值
    // 1.=号
    vector<int> v2 = v1;
    print_vector(v2);
    // 2.assign
    vector<int> v3;
    v3.assign(v1.begin(), v1.end());
    print_vector(v3);
    // 3.n个elem方式
    vector<int> v4;
    v4.assign(10, 100);
    print_vector(v4);
}

/* vector容量和大小 */
void use_vector_7() {
    vector<int> v1;
    // 插入数据
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    print_vector(v1);
    // 判断容器是否为空
    if (v1.empty()) {
        cout << "vector容器为空" << endl;
    } else {
        cout << "容器的大小为：" << v1.size() << "\t容器的容量为：" << v1.capacity() << endl;
    }
    // 重新指定大小
    v1.resize(15);  // 如果重新指定的比原来长，默认使用0填充
    cout << "容器的大小为：" << v1.size() << "\t容器的容量为：" << v1.capacity() << endl;
    print_vector(v1);
    v1.resize(16, 100);  // 可以指定填充值
    cout << "容器的大小为：" << v1.size() << "\t容器的容量为：" << v1.capacity() << endl;
    print_vector(v1);
    // 指定大小比原来短 超出的部分会删除
    v1.resize(10);
    cout << "容器的大小为：" << v1.size() << "\t容器的容量为：" << v1.capacity() << endl;
    print_vector(v1);
}


/* vector插入和删除 */
void use_vector_8() {
    vector<int> v1;
    // 插入数据
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);    // 尾插法
    }
    print_vector(v1);
    v1.pop_back();  // 尾删法
    print_vector(v1);
    // 指定位置插入元素
    v1.insert(v1.begin(), 100);
    print_vector(v1);
    // 指定位置插入多个元素
    v1.insert(v1.begin(), 2, 80);
    print_vector(v1);
    // 删除指定位置元素
    v1.erase(v1.begin());   // 删除头部元素
    print_vector(v1);
    // 删除区间元素
    v1.erase(v1.begin(), v1.begin() + 3);  // 删除头部3个元素
    print_vector(v1);
    // 清空
    v1.clear();
    print_vector(v1);
}

/* vector数据存取 */
void use_vector_9() {
    vector<int> v1;
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
void use_vector_10() {
    vector<int> v1;
    // 插入数据
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);    // 尾插法
    }
    // vector互换容器
    vector<int> v2;
    // 插入数据
    for (int i = 0; i < 10; i++) {
        v2.push_back(i * 3);    // 尾插法
    }
    print_vector(v1);
    print_vector(v2);
    v1.swap(v2);    // 互换元素
    print_vector(v1);
    print_vector(v2);

    // 实际用途
    // 使用swap可以收缩内存空间
    vector<int> v3;
    for (int i = 0; i < 100000; i++) {
        v3.push_back(i);
    }
    cout << "容器的大小为：" << v3.size() << "\t容器的容量为：" << v3.capacity() << endl;  // 容器的大小为：100000	容器的容量为：131072
    v3.resize(3);
    cout << "容器的大小为：" << v3.size() << "\t容器的容量为：" << v3.capacity() << endl;  // 容器的大小为：3	容器的容量为：131072
    // 使用swap收缩内存
    vector<int>(v3).swap(v3);   // vector<int>(v3)代表匿名对象
    cout << "容器的大小为：" << v3.size() << "\t容器的容量为：" << v3.capacity() << endl;  // 容器的大小为：3	容器的容量为：3
}

/* vector预留空间 */
void use_vector_11() {
    vector<int> v;

    int num = 0;    // 用于统计vector开辟空间次数
    int *p = NULL;
    // 插入数据
    for (int i = 0; i < 100000; i++) {
        v.push_back(i);
        if (p != &v[0]) {   // 如果记录的地址不为当前内存地址，次数+1
            p = &v[0];
            num++;
        }
    }
    // 开辟空间次数：18	容器的大小为：100000	容器的容量为：131072
    cout << "开辟空间次数：" << num << "\t容器的大小为：" << v.size() << "\t容器的容量为：" << v.capacity() << endl;


    vector<int> v2;
    // 利用reserve预留空间
    v2.reserve(100000);
    int num2 = 0;    // 用于统计vector开辟空间次数
    int *p2 = NULL;
    // 插入数据
    for (int i = 0; i < 100000; i++) {
        v2.push_back(i);
        if (p2 != &v2[0]) {   // 如果记录的地址不为当前内存地址，次数+1
            p2 = &v2[0];
            num2++;
        }
    }
    // 开辟空间次数：1	容器的大小为：100000	容器的容量为：100000
    cout << "开辟空间次数：" << num2 << "\t容器的大小为：" << v2.size() << "\t容器的容量为：" << v2.capacity() << endl;

}

/* deque容器构造函数 */
#include <deque>

void print_deque(const deque<int> &d) {
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void use_deque_1() {
    deque<int> deque1;   // 1.
    // 插入数据
    for (int i = 0; i < 10; i++) {
        deque1.push_back(i);    // 尾插法
    }
    print_deque(deque1);
    deque<int> deque2(deque1.begin(), deque1.end());  // 2.
    print_deque(deque2);
    deque<int> deque3(10, 100);   // 3.
    print_deque(deque3);
    deque<int> deque4(deque3);   // 4.
    print_deque(deque4);
}

/* deque赋值操作 */
void use_deque_2() {
    deque<int> deque1;   // 1.
    // 插入数据
    for (int i = 0; i < 10; i++) {
        deque1.push_back(i);    // 尾插法
    }
    print_deque(deque1);
    // 1.=赋值
    deque<int> deque2 = deque1;
    print_deque(deque2);
    // 2.assign赋值
    deque<int> deque3;
    deque3.assign(deque2.begin(), deque2.end());
    print_deque(deque3);
    // 3.assign
    deque<int> deque4;
    deque4.assign(4, 100);
    print_deque(deque4);
}

/* deque大小操作 */
void use_deque_3() {
    deque<int> deque1;
    // 插入数据
    for (int i = 0; i < 10; i++) {
        deque1.push_back(i);    // 尾插法
    }
    if (deque1.empty()) {
        cout << "deque为空" << endl;
    } else {
        cout << "deque的大小为：" << deque1.size() << endl;
        print_deque(deque1);
    }
    // 重新指定大小
    deque1.resize(12);
    print_deque(deque1);
    deque1.resize(15, 3);    // 设定大小为15， 使用3来填充
    print_deque(deque1);
}

/* deque插入和删除 */
void use_deque_4() {
    // 创建deque容器
    deque<int> d1;
    // 尾插法
    d1.push_back(123);
    d1.push_back(456);
    print_deque(d1);    // 打印输出 123 456
    // 头插法
    d1.push_front(11);
    d1.push_front(22);
    print_deque(d1);    // 打印输出 22 11 123 456
    // 头删法
    d1.pop_front();
    print_deque(d1);    // 打印输出 11 123 456
    // 尾删法
    d1.pop_back();
    print_deque(d1);    // 打印输出 11 123
    // insert插入
    d1.insert(d1.begin(), 3);  // 向d1的头部插入3
    print_deque(d1);    // 打印输出 3 11 123
    d1.insert(d1.begin(), 2, 2);  // 向d1的头部插入两个2
    print_deque(d1);    // 打印输出 2 2 3 11 123
    // 按区间插入
    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);
    d1.insert(d1.begin(), d2.begin(), d2.end());  // 按区间插入 在d1头部插入d2
    print_deque(d1);

    // 删除
    d1.erase(d1.begin());   // 删除头部元素
    print_deque(d1);
    d1.erase(d1.begin(), d1.begin() + 3);  // 删除头部3个元素
    print_deque(d1);
}

/* deque排序 */
void use_deque_5() {
    // 创建deque容器
    deque<int> d1;
    // 尾插法
    d1.push_back(123);
    d1.push_back(456);
    d1.push_back(56);
    d1.push_back(26);
    print_deque(d1);
    sort(d1.begin(), d1.end());
    print_deque(d1);
}

/* 案例-评委打分 */
/* 案例描述
        有5名选手:选手ABCDE, 10个评委分别对每一名选手打分, 去除最高分，去除评委中最低分，取平均分。

    实现步骤
        1.创建五名选手,放到vector中
        2.遍历vector容器，取出来每一个选手, 执行for循环，可以把10个评分打分存到deque容器中
        3.sort算法对deque容器中分数排序，去除最高和最低分
        4.deque容器遍历-遍，累加总分
        5.获取平均分
*/
// 选手类
class Player {
public:
    string name;
    deque<double> scores;   // 用于保存10个评委的分数
    double average_score;   // 平均分

    Player(string name) {
        this->name = name;
    }

    // 打印选手信息
    void show_info() {
        cout << "选手姓名：" << this->name << " 选手平均分：" << this->average_score << endl;
    }

    // 获取平均分
    void get_average_score() {
        sort(this->scores.begin(), this->scores.end());  // 排序
        this->scores.pop_front();   // 删除最低分
        this->scores.pop_back();    // 删除最高分
        double average_score = 0; // 平均分
        double total_score = 0;   // 总分
        for (deque<double>::iterator it = this->scores.begin(); it != this->scores.end(); it++) {
            total_score += *it;
        }
        cout << "总分为：" << total_score << endl;
        average_score = total_score / scores.size();    // 平均分为总分除以元素个数
        this->average_score = average_score;
    }
};

void case_1() {
    // 1.创建五名选手,放到vector中
    vector<Player> vector_array;
    string player_name[5] = {"章三", "里斯", "王无", "赵流", "消歧"};
    for (int i = 0; i < 5; i++) {
        vector_array.push_back(Player(player_name[i])); // 添加选手
    }
    // 2.遍历vector容器，取出来每一个选手, 执行for循环，可以把10个评分打分存到deque容器中
    // 产生随机数种子
    srand((int) time(0));
    for (vector<Player>::iterator it = vector_array.begin(); it != vector_array.end(); it++) {

        // 存储评分
        for (int j = 0; j < 10; j++) {
            // 生成随机数
            double score = (rand() % (10 - 4 + 1)) + 4; // 生成[10,4]区间的随机数
            cout << "评委" << j + 1 << "打分" << score << " ";
            (*it).scores.push_back(score);
        }
        cout << endl;
    }
    // 3.sort算法对deque容器中分数排序，去除最高和最低分
    // 4.deque容器遍历-遍，累加总分
    // 5.获取平均分
    for (vector<Player>::iterator it = vector_array.begin(); it != vector_array.end(); it++) {
        (*it).get_average_score();  // 获取平均分
    }
    // 打印结果
    for (vector<Player>::iterator it = vector_array.begin(); it != vector_array.end(); it++) {
        (*it).show_info();
    }

}

#include <stack>
/* stack(栈)常用接口 */
void use_stack_1(){
    stack<int>s1;
    // 入栈
    s1.push(20);
    s1.push(40);
    s1.push(30);
    // 只要栈不为空，查看栈的信息，并执行出栈操作
    while(!s1.empty()){
        cout << "栈顶元素为：" << s1.top() << " 栈的大小为：" << s1.size() << endl;
        s1.pop();
    }
}

#include <queue>
/* queue(队列)常用接口 */
void use_queue_1(){
    queue<int>q1;
    // 入队
    q1.push(20);
    q1.push(30);
    q1.push(50);
    q1.push(70);
    // 只要队列不为空，输出队列信息，执行出队操作
    while (!q1.empty()){
        cout << "队头元素为：" << q1.front() << "队尾元素为：" << q1.back() << " 队列的大小为：" << q1.size() << endl;
        q1.pop();
    }
}

#include <list>
/* list容器 */
void print_list_info(const list<int>lst){
    for(list<int>::const_iterator it=lst.begin();it!=lst.end();it++){
        cout << *it << " ";
    }
    cout << endl;
}
void use_list_1(){
    /* 构造函数 */
    // 1.默认构造
    list<int>lst1;
    lst1.push_back(20);
    lst1.push_back(40);
    lst1.push_back(50);
    lst1.push_back(60);
    print_list_info(lst1);
    // 2.区间方式构造
    list<int>lst2(lst1.begin(),lst1.end());
    print_list_info(lst2);
    // 3.拷贝构造
    list<int>lst3(lst1);
    print_list_info(lst3);
    // 4.n个elem方式构造
    list<int>lst4(3,100);
    print_list_info(lst4);

}
void use_list_2(){
    /* 赋值和交换 */
    list<int>l1(5,40);
    print_list_info(l1);
    list<int>l2 = l1;   // =号运算符赋值
    print_list_info(l2);
    list<int>l3;
    l3.assign(l1.begin(),l1.end()); // assign区间方式赋值
    print_list_info(l3);
    list<int>l4;
    l4.assign(10,100);  // n个elem方式赋值
    print_list_info(l4);
    // 交换l4和l3
    cout << "交换前l3和l4:\n";
    print_list_info(l3);
    print_list_info(l4);
    l3.swap(l4);
    cout << "交换后l3和l4:\n";
    print_list_info(l3);
    print_list_info(l4);
}
void use_list_3(){
    /* list大小操作 */
    list<int>lst;
    lst.push_back(12);
    lst.push_back(13);
    lst.push_back(14);
    lst.push_back(15);
    print_list_info(lst);
    // 判断容器是否为空
    if(lst.empty()){
        cout << "链表为空！" << endl;
    }else{
        cout << "链表不为空" << endl;
        cout << "链表元素个数：" << lst.size() << endl;
    }
    // 重新指定大小
    lst.resize(6);  // 默认以0填充
    print_list_info(lst);
    lst.resize(8,10);   // 以10填充
    print_list_info(lst);
}
void use_list_4(){
    /* list插入和删除 */
    list<int>lst;
    // 尾插
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    // 头插
    lst.push_front(100);
    lst.push_front(200);
    lst.push_front(300);
    print_list_info(lst);   // 打印输出     300 200 100 10 20 30
    lst.pop_back();     // 尾删
    print_list_info(lst);   // 打印输出     300 200 100 10 20
    lst.pop_front();    //头删
    print_list_info(lst);   // 打印输出     200 100 10 20
    // insert插入
    lst.insert(lst.begin(),1000);   // 在头部插入1000
    list<int>::iterator it=lst.begin(); // 创建lst的迭代器
    lst.insert(++it,2000);  // 利用迭代器偏移在头部的下一个元素位置插入2000
    print_list_info(lst);
    // 删除
    lst.erase(lst.begin()); // 删除头部元素
    print_list_info(lst);
    // 移除指定元素
    lst.remove(200);    // 移除所有值为200的元素
    print_list_info(lst);
    // 清空
    lst.clear();
    print_list_info(lst);
}

void use_list_5() {
    /* list数据存取 */
    list<int>lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    cout << "第一个元素：" << lst.back();
    cout << "第二个元素：" << lst.front() << endl;
    // 迭代器不支持随即访问
    list<int>::iterator it = lst.begin();
    it++;
    cout << *it << endl;
}

bool my_compare(int num1,int num2){
    // 降序 就让第一个数>第二个数
    return num1 > num2;
}

void use_list_6() {
    /* list反转和排序 */
    list<int>lst;
    lst.push_back(40);
    lst.push_back(20);
    lst.push_back(50);
    lst.push_back(80);
    lst.push_back(10);
    cout << "反转前：" << endl;
    print_list_info(lst);
    // 反转
    lst.reverse();
    cout << "反转后：" << endl;
    print_list_info(lst);
    // 排序
    lst.sort();
    cout << "排序(升序)后：" << endl;
    print_list_info(lst);
    cout << "排序(降序)后：" << endl;
    lst.sort(my_compare);
    print_list_info(lst);
}

/*
 * 排序案例
 *  案例描述：
 *      将Human自定义类型数据进行排序，Human属性有姓名、年龄、身高
 *  排序规则：
 *      按照年龄进行升序，如果年龄相同按照身高进行排序
 */
class Human{
public:
    int age;
    string name;
    double height;

    Human(string name,int age,double height){
        this->name = name;
        this->age = age;
        this->height = height;
    }

    void print_info(){
        cout << "姓名：" << this->name << " 年龄：" << this->age << " 身高(cm)：" << this->height << endl;
    }
};
// print list content
void print_list_info(const list<Human>lst){
    for(list<Human>::const_iterator it=lst.begin();it!=lst.end();it++){
        cout << "Name:" << it->name << "\tAge:" << it->age << "\tHeight:" << it->height << endl;
    }
}
bool compare_human(Human &human1,Human &human2){
    // 按照年龄进行升序，如果年龄相同按照身高进行排序
    if(human1.age==human2.age){
        return human1.height > human2.height;
    }
    return human1.age < human2.age;

}



void sort_case(){
    list<Human>human_list;
    Human human1("John",20,180);
    Human human2("Lucy",19,166);
    Human human3("Tom",21,180);
    Human human4("Jack",20,181);
    // push into human_list
    human_list.push_back(human1);
    human_list.push_back(human2);
    human_list.push_back(human3);
    human_list.push_back(human4);
    print_list_info(human_list);
    // 按照年龄进行升序，如果年龄相同按照身高进行排序
    human_list.sort(compare_human);
    cout << "Sort result:\n";
    print_list_info(human_list);
}



#include <set>
void print_info(const set<int>set1){
    for(int it : set1){
        cout << it << " ";
    }
    cout << endl;
}
void use_set_1(){
    /* set构造和赋值 */
    set<int>set_1;
    // only use insert
    set_1.insert(20);
    set_1.insert(10);
    set_1.insert(30);
    set_1.insert(5);
    // print content
    print_info(set_1);
    // copy construction
    set<int>set_2(set_1);
    print_info(set_2);
    set<int>set_3 = set_1;
    print_info(set_3);
}

void use_set_2(){
    /* set大小和交换 */
    set<int>set_1;
    // insert value
    set_1.insert(20);
    set_1.insert(10);
    set_1.insert(30);
    set_1.insert(5);
    print_info(set_1);
    // determine empty
    if(set_1.empty()){
        cout << "Set is empty!" << endl;
    }else{
        cout << "Set size is:" << set_1.size() << endl;
    }
    // create set_2
    set<int>set_2;
    set_2.insert(101);
    set_2.insert(102);
    set_2.insert(103);
    // swap set_1 and set_2
    cout << "Exchange before:\n";
    print_info(set_1);
    print_info(set_2);
    set_1.swap(set_2);
    cout << "After exchange :\n";
    print_info(set_1);
    print_info(set_2);
}
void use_set_3() {
    /* set插入和删除 */
    set<int>set_1;
    // insert value
    set_1.insert(20);
    set_1.insert(10);
    set_1.insert(30);
    set_1.insert(5);
    print_info(set_1);  // print
    // delete value
    set_1.erase(set_1.begin()); // delete first value
    set_1.erase(20);    // delete specified value
    print_info(set_1);
    // clear set
    set_1.erase(set_1.begin(),set_1.end()); // first method
    set_1.clear();  // second method
}

void use_set_4(){
    /* set查找和统计 */
    set<int>set_1;
    // insert value
    set_1.insert(20);
    set_1.insert(10);
    set_1.insert(30);
    set_1.insert(5);
    print_info(set_1);  // print
    // find value
    set<int>::iterator pos = set_1.find(30);
    if(pos!=set_1.end()){
        cout << "Found the value:" << *pos << endl;
    }else{
        cout << "Not found the value." << endl;
    }
    // statistics
    int num = set_1.count(30);  // count 30
    cout << "30 time:" << num << endl;
}
void print_info(multiset<int>multi){
    for(int it:multi){
        cout << it << " ";
    }
    cout << endl;
}

void set_multiset_different(){
    /* set和multiset区别 */
    set<int>set_1;
    // insert value
    pair<set<int>::iterator,bool> insert_result = set_1.insert(20); // insert value and return insert result to insert_result
    if(insert_result.second){
        cout << "Insert 20 successful!" << endl;
    }else{
        cout << "Insert 20 failed!" << endl;
    }
    insert_result = set_1.insert(20); // insert value and return insert result to insert_result
    if(insert_result.second){
        cout << "Insert 20 successful!" << endl;
    }else{
        cout << "Insert 20 failed!" << endl;
    }
    set_1.insert(10);
    set_1.insert(30);
    multiset<int>set_2;
    // insert value
    set_2.insert(20);
    set_2.insert(20);
    set_2.insert(10);
    set_2.insert(30);
    cout << "set insert result:";
    print_info(set_1);
    cout << "multiset insert result:";
    print_info(set_2);
}


class MyCompare{
public:
    bool operator()(int v1,int v2){
        return v1 > v2;
    }
};

class Sheep{
public:
    int age;
    string name;

    Sheep(string name,int age){
        this->name = name;
        this->age = age;
    }
};
class CompareSheep{
public:
    bool operator()(const Sheep&sheep1,const Sheep&sheep2){
        return sheep1.age > sheep2.age;
    }
};

void use_set_sort(){
    /* set容器排序 */
    // 指定内置数据类型排序规则
    set<int,MyCompare>set_1;
    // insert value
    set_1.insert(20);
    set_1.insert(10);
    set_1.insert(30);
    set_1.insert(5);
    // print
    for(int it : set_1){
        cout << it << " ";
    }
    cout << endl;

    // 指定自定义数据类型排序规则
    set<Sheep,CompareSheep>set_2;
    // create sheep
    Sheep s1("Lily",10);
    Sheep s2("Lucy",6);
    Sheep s3("Tom",3);
    Sheep s4("Jake",12);
    // insert into set
    set_2.insert(s1);
    set_2.insert(s2);
    set_2.insert(s3);
    set_2.insert(s4);
    // print
    for(const Sheep& it : set_2){
        cout << "Sheep\tName:" << it.name << "\tAge:"<< it.age << endl;
    }


}



void use_pair(){
    /* pair对组创建 */
    // first method
    pair<string,int> p1(string("Tom"),20);
    cout << "Name:" << p1.first << "\tAge:" << p1.second << endl;
    // second method
    pair<string,int>p2 = make_pair("Jarry",16);
    cout << "Name:" << p2.first << "\tAge:" << p2.second << endl;
}



#include <map>
void print_info(map<int,string>&mp){
    for(map<int,string>::iterator it=mp.begin();it!=mp.end();it++){
        cout << "map   id:" << (*it).first << "\tname:" << (*it).second << endl;
    }
    cout << endl;
}
void use_map_1(){
    /* map构造和赋值 */
    map<int,string>mp;  // create map
    mp.insert(pair<int,string>(1,"Jake"));  // insert key,value
    mp.insert(pair<int,string>(3,"Lucy"));
    mp.insert(pair<int,string>(2,"Tom"));
    print_info(mp); // print

    // copy construct
    map<int,string>mp2(mp);
    print_info(mp2);

    // "=" assignment
    map<int,string>mp3 = mp;
    print_info(mp3);

}
void use_map_2(){
    /* map大小和交换 */
    map<int,string>mp;  // create map
    mp.insert(pair<int,string>(1,"Jake"));  // insert key,value
    mp.insert(pair<int,string>(3,"Lucy"));
    mp.insert(pair<int,string>(2,"Tom"));
    print_info(mp); // print
    if(!mp.empty()){
        cout << "map is not empty." << " map size:" << mp.size() << endl;
    }else{
        cout << "map is empty." << endl;
    }
    // swap
    map<int,string>mp2;
    mp2.insert(pair<int,string>(4,"LULU"));
    mp2.insert(pair<int,string>(5,"TIMO"));
    cout << "swap before:" << endl;
    cout << "mp:" << endl;
    print_info(mp);
    cout << "mp2:" << endl;
    print_info(mp2);
    // swap mp and mp2
    mp.swap(mp2);
    cout << "after swap:" << endl;
    cout << "mp:" << endl;
    print_info(mp);
    cout << "mp2:" << endl;
    print_info(mp2);
}
void use_map_3(){
    /* map插入和删除 */
    map<int,string>mp;  // create map
    // insert methods
    mp.insert(pair<int,string>(1,"Jake"));  // method 1
    mp.insert(make_pair(2,"Tom"));  // method 2
    mp.insert(map<int,string>::value_type(3,"Lucy"));   // method 3
    mp[4] = "Lily"; // method 4

    print_info(mp); // print

    // delete element
    mp.erase(mp.begin());   // delete first element
    print_info(mp);

    mp.erase(3);    // delete element by key
    print_info(mp);

    mp.erase(mp.begin(),mp.end());  // clear map
    mp.clear();     // clear map
}
void use_map_4(){
    /* map查找和统计 */
    map<int,string>mp;  // create map
    // insert methods
    mp.insert(pair<int,string>(1,"Jake"));  // method 1
    mp.insert(make_pair(2,"Tom"));  // method 2
    mp.insert(map<int,string>::value_type(3,"Lucy"));   // method 3
    mp[4] = "Lily"; // method 4

    // find element
    map<int,string>::iterator pos = mp.find(3);
    if(pos!=mp.end()){
        cout << "Found key:3" << endl;
    }else{
        cout << "Not Fount key:3" << endl;
    }
    // count element
    int num = mp.count(3);  // count key=3 element
    cout << "key=3 element count:" << num << endl;
}
class CompareMap{
public:
    bool operator()(int v1,int v2){
        return v1>v2;   // from largest to smallest
    }
};
void use_map_5(){
    /* map容器排序 */
    map<int,string,CompareMap>mp;  // create map
    // insert methods
    mp.insert(pair<int,string>(1,"Jake"));  // insert key,value
    mp.insert(pair<int,string>(3,"Lucy"));
    mp.insert(pair<int,string>(2,"Tom"));
    for(map<int,string,CompareMap>::iterator it=mp.begin();it!=mp.end();it++){
        cout << (*it).first << " " << (*it).second << endl;
    }
}

/*
 * 案例-员工分组</h5>
    案例描述
        ·公司今天招聘了10个员工(ABCDEFGHI)，10名员工进入公司之后，需要指派员工在那个部门工作
        ·员工信息有:姓名工资组成;部门分为:策划、美术、研发
        ·随机给10名员工分配部门和工资
        ·通过multimap进行信息的插入key(部门编号) value(员工)
        ·分部门显示员工信息
    实现步骤
        1.创建10名员工，放到vector中
        2.遍历vector容器，取出每个员工，进行随机分组
        3.分组后，将员工部门编号作为key，具体员工作为value，放入到multimap容器中
        4.分部门显示员工信息
 */
class Employee{
public:
    string name;
    double salary;

    Employee(string name, double salary){
        this->name = name;
        this->salary = salary;
    }
};
void create_employee(vector<Employee>&vec){
    /* 创建10名员工，放到vector中 */
    string employee_name = "ABCDEFGHIJ";
    double salary_array[] = {2000,3000,4000,5000};
    for(int i=0;i<10;i++){
        string name = "员工";
        name+=employee_name[i];
        double salary = salary_array[rand()%4];
        vec.push_back(Employee(name,salary));
    }
}
void set_group(vector<Employee>&vec,multimap<int,Employee>&mutmap){
    /* 遍历vector容器，取出每个员工，进行随机分组 */
    for(vector<Employee>::iterator it=vec.begin();it!=vec.end();it++){
        // 分组后，将员工部门编号作为key，具体员工作为value，放入到multimap容器中
        int department_id = rand() % 3+1; // 1.策划、2.美术、3.研发
        mutmap.insert(make_pair(department_id,(*it)));
    }
}
void print_employee_by_group(multimap<int,Employee>&mutmap){
    /* 分部门显示员工信息 */
    cout << "策划:" << endl;
    multimap<int,Employee>::iterator pos = mutmap.find(1);
    int count = mutmap.count(1);
    int index = 0;
    for(;pos!=mutmap.end() && index<count;pos++,index++){
        cout << "Name:" << pos->second.name << " Salary:" << pos->second.salary << endl;
    }
    cout << "美术:" << endl;
    pos = mutmap.find(2);
    count = mutmap.count(2);
    index = 0;
    for(;pos!=mutmap.end() && index<count;pos++,index++){
        cout << "Name:" << pos->second.name << " Salary:" << pos->second.salary << endl;
    }
    cout << "研发:" << endl;
    pos = mutmap.find(3);
    count = mutmap.count(3);
    index = 0;
    for(;pos!=mutmap.end() && index<count;pos++,index++){
        cout << "Name:" << pos->second.name << " Salary:" << pos->second.salary << endl;
    }


}
void case_2(){
    /* 案例-员工分组 */
    // 创建10名员工，放到vector中
    vector<Employee>vector_employee;
    create_employee(vector_employee);
    // 遍历vector容器，取出每个员工，进行随机分组
    multimap<int,Employee>employee_map;
    set_group(vector_employee,employee_map);
    // 分部门显示员工信息
    print_employee_by_group(employee_map);
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
    cout << "\tdeque容器构造函数:" << endl;
    use_deque_1();  // deque容器构造函数
    cout << "\tdeque赋值操作:" << endl;
    use_deque_2();  // deque赋值操作
    cout << "\tdeque大小操作:" << endl;
    use_deque_3();  // deque大小操作
    cout << "\tdeque插入和删除:" << endl;
    use_deque_4();  // deque插入和删除
    cout << "\tdeque排序:" << endl;
    use_deque_5();  // deque排序
    cout << "\t案例-评委打分:" << endl;
    case_1();   // 案例-评委打分
    cout << "\tstack(栈)常用接口:" << endl;
    use_stack_1();  // stack(栈)常用接口
    cout << "\tqueue(队列)常用接口:" << endl;
    use_queue_1();  // queue(队列)常用接口
    cout << "\tlist容器:" << endl;
    use_list_1();   // list容器
    use_list_2();   // 赋值和交换
    use_list_3();   // list大小操作
    use_list_4();   // list插入和删除
    use_list_5();   // list数据存取
    use_list_6();   // list反转和排序
    sort_case();    // 排序案例
    cout << "\tset构造和赋值:" << endl;
    use_set_1();    // set构造和赋值
    cout << "\tset大小和交换:" << endl;
    use_set_2();    // set大小和交换
    cout << "\tset插入和删除:" << endl;
    use_set_3();    // set插入和删除
    cout << "\tset查找和统计:" << endl;
    use_set_4();    // set查找和统计
    cout << "\tset和multiset区别:" << endl;
    set_multiset_different();   // set和multiset区别
    cout << "\tpair对组创建:" << endl;
    use_pair(); // pair对组创建
    cout << "\tset容器排序:" << endl;
    use_set_sort(); // set容器排序

    cout << "\tmap构造和赋值:" << endl;
    use_map_1();    // map构造和赋值
    cout << "\tmap大小和交换:" << endl;
    use_map_2();    // map大小和交换
    cout << "\tmap插入和删除:" << endl;
    use_map_3();    // map插入和删除
    cout << "\tmap查找和统计:" << endl;
    use_map_4();    // map查找和统计
    cout << "\tmap容器排序:" << endl;
    use_map_5();    // map容器排序
    cout << "\t案例-员工分组:" << endl;
    case_2();   // 案例-员工分组
    return 0;
}
