#include <iostream>

using namespace std;

#include <fstream>

// 写文件
void test01() {
    // 1.引入头文件
    // 2.创建流对象
    ofstream ofs;
    // 3.打开文件
    ofs.open("./test.txt", ios::out);
    // 4.写数据
    ofs << "测试数据";
    // 5.关闭文件
    ofs.close();
}

int main(){
    test01();

    return 0;
}