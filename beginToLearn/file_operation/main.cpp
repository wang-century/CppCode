#include <iostream>
using namespace std;
#include <fstream>
#include "fstream"

// 写文件
void write_to_file(string path,string text) {
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

void read_file(string path){
    // 1.包含头文件
    // 2.创建流对象
    ifstream ifs;
    // 3.打开文件并判断文件是否打开成功
    ifs.open(path,ios::in);
    if(!ifs.is_open()){
        cout << "File open fal!" << endl;
        return;
    }
    // 4.读数据
    // 四种方式读取
    // First method
    /*
    char content[1024] = {0};
    while (ifs >> content){
        cout << content << endl;
    }*/
    // econd method
    /*
    char content[1024] = {0};
    while (ifs.getline(content,1024)){  // read line
        cout << content << endl;
    }*/
    // Third method
    string content;
    while (getline(ifs,content)){
        cout << content << endl;
    }
    // 4
    /*
    char c;
    while ((c=ifs.get())!=EOF){
        cout << c << endl;
    }  // end of file
    */
    // 5.关闭文件
    ifs.close();
}




int main(){
//    write_to_file("./test.txt","Test Content");
    read_file("./test.txt");
    return 0;
}