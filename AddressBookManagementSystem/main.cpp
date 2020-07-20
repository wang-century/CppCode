#include <iostream>
using namespace std;

// 定义联系人结构体
struct ConnectHuman {
    string name;
    string sex;
    int age;
    string phone;
    string home_address;
} human[1000];  // 限制最大1000人

void print_menu(){
    // 打印菜单
    cout << "************\n1.添加联系人\n2.显示联系人\n3.删除指定联系人\n4.查找联系人\n5.修改联系人\n6.清空联系人\n0.退出通讯录\n************" << endl;
}

void add_connect_human() {
    // 添加联系人
    // 若该位置为空则将信息录入
    for (auto &i : human) {
        if (i.age == 0) {
            cout << "添加联系人(请录入联系人信息)\n" << "姓名：";
            cin >> i.name;
            cout << "性别：";
            cin >> i.sex;
            cout << "年龄：";
            cin >> i.age;
            cout << "电话：";
            cin >> i.phone;
            cout << "家庭住址：";
            cin >> i.home_address;
            cout << "录入完成" << endl;
            break;
        } else {
            continue;
        }
    }
}

void show_all_connect_human() {
    // 显示所有联系人
    for (auto &i : human) {
        if (i.age == 0) {
            continue;
        } else {
            cout << "姓名：" << human[0].name << "\t性别" << human[0].sex << "\t年龄：" << human[0].age << "\t电话："
                 << human[0].phone
                 << "\t家庭住址：" << human[0].home_address << endl;
        }
    }
}

void delete_one_connect_human() {
    // 删除指定姓名联系人
    cout << "删除指定姓名联系人\n" << "请输入要删除的联系人姓名：";
    string name;
    cin >> name;
    for (auto &i : human) {
        if (i.name == name) {
            i.name = "";
            i.age = 0;
            i.sex = "";
            i.phone = "";
            i.home_address = "";
            cout << "删除联系人" << name << "成功" << endl;
            //break;
        } else {
            continue;
        }
    }

}

void delete_all_connect_human() {
    // 清空联系人
    for (auto &i : human) {
        i.name = "";
        i.age = 0;
        i.sex = "";
        i.phone = "";
        i.home_address = "";
    }
    cout << "已清空联系人" << endl;
}

void select_connect_human() {
    // 根据姓名查找联系人
    cout << "根据姓名查找联系人\n" << "请输入要查找的联系人姓名：";
    string name;
    cin >> name;
    for (auto &i : human) {
        if (i.name == name) {
            cout << "姓名：" << human[0].name << "\t性别：" << human[0].sex << "\t年龄：" << human[0].age << "\t电话："
                 << human[0].phone
                 << "\t家庭住址：" << human[0].home_address << endl;
        } else {
            continue;
        }
    }
}

void update_connect_human() {
    // 根据姓名修改联系人信息
    cout << "根据姓名修改联系人信息\n" << "请输入要修改的联系人姓名：";
    string name;
    cin >> name;
    for (auto &i : human) {
        if (i.name == name) {
            cout << "姓名：" << human[0].name << "\t性别" << human[0].sex << "\t年龄：" << human[0].age << "\t电话："
                 << human[0].phone
                 << "\t家庭住址：" << human[0].home_address << endl;
            int input_choice;
            cout << "请输入要修改的字段：\n1.姓名\t2.性别\t3.年龄\t4.电话\t5.家庭住址\t0.退出:" << endl;
            cin >> input_choice;
            switch (input_choice) {
                case 1:
                    cout << "请输入姓名：";
                    cin >> i.name;
                    break;
                case 2:
                    cout << "请输入性别：";
                    cin >> i.sex;
                    break;
                case 3:
                    cout << "请输入年龄：";
                    cin >> i.age;
                    break;
                case 4:
                    cout << "请输入电话：";
                    cin >> i.phone;
                    break;
                case 5:
                    cout << "请输入家庭住址：";
                    cin >> i.home_address;
                    break;
                default:
                    break;
            }
            cout << "修改成功" << endl;
        } else {
            continue;
        }
    }

}

int main() {
    cout << "\t通讯录管理系统" << endl;
    cout << "系统功能：" << endl;

    int input_choice;

    while (true) {
        printf("\033[2J");  // 清屏
        print_menu();
        cout << "请选择：";
        cin >> input_choice;
        switch (input_choice) {
            case 1:
                add_connect_human();
                break;
            case 2:
                show_all_connect_human();
                break;
            case 3:
                delete_one_connect_human();
                break;
            case 4:
                select_connect_human();
                break;
            case 5:
                update_connect_human();
                break;
            case 6:
                delete_all_connect_human();
                break;
            case 0:
                cout << "退出通讯录" << endl;
                return 0;
            default:
                break;
        }
        cout << "是否继续？(1.是0.否)";
        cin >> input_choice;
        if(input_choice==1){
            continue;
        }else{
            cout << "退出通讯录" << endl;
            break;
        }
    }


    return 0;
}
