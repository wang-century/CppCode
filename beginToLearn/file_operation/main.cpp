#include <iostream>

using namespace std;

#include <fstream>
#include "fstream"

// 写文件
void write_to_file(string path, string text) {
    // 1.引入头文件
    // 2.创建流对象
    ofstream ofs;
    // 3.打开文件
    ofs.open(path, ios::out);
    // 4.写数据
    ofs << text;
    // 5.关闭文件
    ofs.close();
}

void read_file(string path) {
    // 1.包含头文件
    // 2.创建流对象
    ifstream ifs;
    // 3.打开文件并判断文件是否打开成功
    ifs.open(path, ios::in);
    if (!ifs.is_open()) {
        cout << "File open fail!" << endl;
        return;
    }
    // 4.读数据
    // 四种方式读取
    // 1.
    /*
    char content[1024] = {0};
    while (ifs >> content){
        cout << content << endl;
    }*/
    // 2
    /*
    char content[1024] = {0};
    while (ifs.getline(content,1024)){  // read line
        cout << content << endl;
    }*/
    // 3
    string content;
    while (getline(ifs, content)) {
        cout << content << endl;
    }
    // 4
    /*
    char c;
    while ((c=ifs.get())!=EOF){
        cout << c << endl;
    }  // EOF代表文件结束
    */
    // 5.关闭文件
    ifs.close();
}


// 二进制写文件
class Person {
public:
    string name;
    int age;
    Person(){

    }
    Person(string name,int age){
        this->name = name;
        this->age = age;
    }
};


void test01() {
    // 1.引入头文件
    // 2.创建流对象
    ofstream ofs("test2.txt", ios::out | ios::binary);
    // 4.写数据
    Person p("章三",28);
    ofs.write((const char *)&p, sizeof(Person));
    // 5.关闭文件
    ofs.close();
}

// 二进制读文件
void test02(){
    // 1.包含头文件
    // 2.创建流对象
    ifstream ifs;
    // 3.打开文件并判断文件是否打开成功
    ifs.open("test2.txt", ios::in|ios::binary);
    if (!ifs.is_open()) {
        cout << "File open fal!" << endl;
        return;
    }
    Person p;
    ifs.read((char *)&p, sizeof(Person));
    cout << "姓名：" << p.name << " 年龄：" << p.age << endl;
}

int main() {
    write_to_file("./test.txt", "Test Content");
    read_file("./test.txt");
    test01();
    test02();
    return 0;
}