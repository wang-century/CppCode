#include "../header/workManager.h"

// 初始化属性
WorkManager::WorkManager() {
    ifstream ifs(FILENAME, ios::in); // 读取数据文件
    // 若文件不存在
    if (!ifs.is_open()) {
        cout << "数据文件不存在" << endl;
        this->worker_count = 0; // 总人数设为0
        this->WorkerArray = NULL; // 初始化数组指针
        this->data_file_empty = true;   // 数据文件为空
        ifs.close(); // 关闭文件
        return;
    }
    // 若文件存在但数据为空
    char ch;
    ifs >> ch;  // 读一个字符 将结尾标读到
    if (ifs.eof()) {
        cout << "数据文件为空" << endl;
        this->worker_count = 0; // 总人数设为0
        this->WorkerArray = NULL; // 初始化数组指针
        this->data_file_empty = true;   // 数据文件不为空
        ifs.close(); // 关闭文件
        return;
    }
    // 文件存在且有数据
    // 获取数据文件内保存的员工个数
    int count = this->get_worker_count();
    cout << "已有员工:" << count << endl;
    this->worker_count = count;     // 将员工个数更新
    // 根据职工数创建数组
    this->WorkerArray = new Worker *[this->worker_count];
    // 初始化职工
    init_worker();
}

// 显示菜单信息
void WorkManager::show_menu() {
    cout << "**********************" << endl;
    cout << "\t欢迎使用职工管理系统" << endl;
    cout << "\t 0.退出管理系统" << endl;
    cout << "\t 1.增加职工信息" << endl;
    cout << "\t 2.显示职工信息" << endl;
    cout << "\t 3.删除离职职工" << endl;
    cout << "\t 4.修改职工信息" << endl;
    cout << "\t 5.查找职工信息" << endl;
    cout << "\t 6.按照编号排序" << endl;
    cout << "\t 7.清空所有文档" << endl;
    cout << "**********************" << endl;
}

// 增加职工
void WorkManager::add_worker() {
    cout << "请输入要增加的员工数量：";
    int add_count;  // 增加的员工数
    cin >> add_count;
    if (add_count > 0) {
        // 计算新空间大小
        int new_size = this->worker_count + add_count;
        // 开辟新空间
        Worker **new_space = new Worker *[new_size];
        // 若原空间有数据，将原空间下内容放到新空间下
        if (this->WorkerArray != NULL) {
            for (int i = 0; i < this->worker_count; i++) {
                new_space[i] = WorkerArray[i];
            }
        }
        // 输入新数据
        for (int i = 0; i < add_count; i++) {
            int id;
            string name;
            int department_select;  // 职位选择
            FLAG:
            // 输入
            cout << "请输入第" << i + 1 << "个职工的编号：";
            cin >> id;
            // 判断编号是否存在
            int flag = this->id_worker_exists(id);
            if(flag!=-1){
                cout << "编号已存在，请重新输入！" << endl;
                goto FLAG;
            }
            cout << "请输入第" << i + 1 << "个职工的姓名：";
            cin >> name;
            cout << "请选择该员工的岗位(1.普通职工 2.经理 3.老板)：";
            cin >> department_select;

            Worker *worker = NULL;
            switch (department_select) {
                case 1: // 普通职工
                    worker = new Employee(id, name, 1);
                    break;
                case 2: // 经理
                    worker = new Manager(id, name, 2);
                    break;
                case 3: // 老板
                    worker = new Boss(id, name, 3);
                    break;
                default:
                    break;
            }
            // 将输入的数据存放到开辟的空间
            new_space[this->worker_count + i] = worker;
        }
        // 释放原有空间
        delete[] this->WorkerArray;
        // 更改存放空间地址指向
        this->WorkerArray = new_space;
        // 更新统计个数
        this->worker_count = new_size;
        // 提示信息
        cout << "成功添加" << add_count << "名员工" << endl;
        // 保存到文件
        this->save();
        // 将文件数据设为非空
        this->data_file_empty = false;
    } else {
        cout << "输入错误！" << endl;
    }
    printf("\033[2J");  // 清屏
}


// 保存文件
void WorkManager::save() {
    ofstream ofs(FILENAME, ios::out);
    for (int i = 0; i < this->worker_count; i++) {
        ofs << this->WorkerArray[i]->id << " "
            << this->WorkerArray[i]->name << " "
            << this->WorkerArray[i]->department_id << " "
            << endl;
    }
    ofs.close();
}

// 获取数据文件内的员工人数
int WorkManager::get_worker_count() {
    ifstream ifs(FILENAME, ios::in); // 读取文件
    int id;
    string name;
    int department_id;
    int count = 0;  // 统计人数
    // 将数据写入创建的变量
    while (ifs >> id && ifs >> name && ifs >> department_id) {
        count++;    // 人数++
    }
    ifs.close();
    return count;
}

// 从数据文件添加成员到数组
void WorkManager::init_worker() {
    ifstream ifs(FILENAME, ios::in); // 读取文件数据

    int id;
    string name;
    int department_id;

    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> department_id) {
        Worker *worker = NULL; // 创建员工对象
        // 根据department_id来确定要创建的员工类别
        if (department_id == 1) {  // 普通员工
            worker = new Employee(id, name, department_id);
        } else if (department_id == 2) { // 经理
            worker = new Manager(id, name, department_id);
        } else {
            worker = new Boss(id, name, department_id);
        }
        // 存放到数组
        this->WorkerArray[index] = worker;
        index++;    // 索引+1
    }
    ifs.close();    // 关闭文件
}

// 显示职工
void WorkManager::show_worker() {
    // 判断数据是否为空
    if (this->worker_count == 0) {
        cout << "员工数据为空！" << endl;
    } else {
        for (int i = 0; i < this->worker_count; i++) {
            this->WorkerArray[i]->show_info();
        }
    }
}

// 判断某id员工是否存在，若存在则返回职工在数组中的下标，否则返回-1
int WorkManager::id_worker_exists(int id) {
    // 在数组查找id
    for (int i = 0; i < this->worker_count; i++) {
        if (WorkerArray[i]->id == id) {    // 若找到匹配项 返回true
            return i;
        }
    }
    return -1;
}

// 删除员工
void WorkManager::delete_worker() {
    // 判断是否有员工
    if (this->worker_count == 0) {
        cout << "员工数据为空！" << endl;
    } else {
        int id;
        cout << "请输入要删除的员工编号：";
        cin >> id;
        // 判断输入的员工id是否存在
        int flag = id_worker_exists(id);    // 若存在则返回员工在数组内的下标
        if (flag != -1) {
            // 使用数据前移删除员工
            for (int i = flag; i < this->worker_count - 1; i++) {
                this->WorkerArray[i] = this->WorkerArray[i + 1];
            }
            // 删除该员工后，员工个数减一
            this->worker_count--;
            // 将修改应用到文件
            this->save();
            cout << "删除员工成功！" << flag << endl;
        } else {
            cout << "未找到该id员工！" << endl;
        }
    }
}

// 修改员工
void WorkManager::update_worker() {
    // 判断是否有员工
    if (this->worker_count == 0) {
        cout << "员工数据为空！" << endl;
    } else {
        int id;
        cout << "请输入要修改的员工编号：";
        cin >> id;
        // 判断输入的员工id是否存在
        int flag = id_worker_exists(id);    // 若存在则返回员工在数组内的下标
        if (flag != -1) {
            // 根据下标修改数组中元素
            cout << "要修改的员工信息为：" << endl;
            this->WorkerArray[flag]->show_info();
            int choice = 0;
            cout << "清选择要修改的字段(1.员工编号 2.员工姓名 3.员工所在部门 0.取消修改)：";
            cin >> choice;
            Worker *worker = this->WorkerArray[flag];
            switch (choice) {
                case 0: {
                    cout << "取消修改" << endl;
                    return;
                }
                case 1: {
                    int worker_id;
                    FLAG:
                    cout << "请输入新的员工编号：";
                    cin >> worker_id;
                    // 判断编号是否存在
                    int flag = this->id_worker_exists(id);
                    if(flag!=-1){
                        cout << "编号已存在，请重新输入！" << endl;
                        goto FLAG;
                    }else{
                        worker->id = worker_id;
                        break;
                    }
                }
                case 2: {
                    string worker_name;
                    cout << "请输入新的员工姓名：";
                    cin >> worker_name;
                    worker->name = worker_name;
                    break;
                }
                case 3: {
                    int worker_dep_id;
                    cout << "请输入新的员工部门(1.普通职工 2.经理 3.老板)：";
                    cin >> worker_dep_id;
                    Worker *temp = NULL;    // 新建员工类用于与原数组交换信息
                    if (worker_dep_id == 1) { // 普通职工
                        temp = new Employee(this->WorkerArray[flag]->id, this->WorkerArray[flag]->name, 1);
                        delete this->WorkerArray[flag];
                        this->WorkerArray[flag] = temp;
                    } else if (worker_dep_id == 2) {
                        temp = new Manager(this->WorkerArray[flag]->id, this->WorkerArray[flag]->name, 1);
                        delete this->WorkerArray[flag];
                        this->WorkerArray[flag] = temp;
                    } else if (worker_dep_id == 3) {
                        temp = new Boss(this->WorkerArray[flag]->id, this->WorkerArray[flag]->name, 1);
                        delete this->WorkerArray[flag];
                        this->WorkerArray[flag] = temp;
                    } else {
                        cout << "输入错误！" << endl;
                    }
                    worker->department_id = worker_dep_id;
                    break;
                }
                default:
                    break;
            }
            // 将修改应用到文件
            this->save();
            cout << "修改字段成功！" << endl;
        } else {
            cout << "未找到该id员工！" << endl;
        }
    }

}

// 查找职工
void WorkManager::find_worker() {
    // 判断是否有员工
    if (this->worker_count == 0) {
        cout << "员工数据为空！" << endl;
    } else {
        cout << "请输入查找方式(1.编号 2.姓名)：";
        int choice = 0;
        cin >> choice;
        if (choice == 1) {
            int id;
            cout << "请输入要查找的员工编号：";
            cin >> id;
            // 判断输入的员工id是否存在
            int flag = id_worker_exists(id);    // 若存在则返回员工在数组内的下标
            if (flag != -1) {
                cout << "要查找的员工信息如下：" << endl;
                this->WorkerArray[flag]->show_info();
            } else {
                cout << "未找到该id员工！" << endl;
            }
        } else if (choice == 2) {
            string name;
            cout << "请输入要查找的员工姓名：";
            cin >> name;
            // 判断输入的员工id是否存在
            int *flag = name_worker_exists(name);    // 若存在则返回员工在数组内的下标
            if (flag != NULL) {
                cout << "要查找的员工信息如下：" << endl;
                for (int i = 0; i < (sizeof(flag) / sizeof(flag[0])); i++) {
                    this->WorkerArray[flag[i]]->show_info();
                }
                // 显示完删除保存员工下标的数组
                delete[] flag;
            } else {
                cout << "未找到该姓名员工！" << endl;
            }
        } else {
            cout << "输入错误！" << endl;
        }
    }
}

// 判断某姓名员工是否存在
int *WorkManager::name_worker_exists(string name) {
    int *index_array = new int[10];
    int count = 0;
    // 在数组查找name  注意重名的存在
    for (int i = 0; i < this->worker_count; i++) {
        if (WorkerArray[i]->name == name) {    // 若找到匹配项 返回true
            index_array[count] = i;
            count++;
        }
    }
    // 若未找到则返回空指针，否则返回指针
    if (count == 0) {
        delete[] index_array;
        return NULL;
    } else {
        return index_array;
    }
}

// 员工根据编号排序
void WorkManager::sort_worker_by_id() {
    // 判断是否有员工
    if (this->worker_count == 0) {
        cout << "员工数据为空！" << endl;
    } else {
        // 冒泡排序
        for (int i = 0; i < this->worker_count - 1; i++) {
            for (int j = 0; j < this->worker_count - 1 - i; j++) {
                if (this->WorkerArray[j]->id > this->WorkerArray[j + 1]->id) {
                    Worker *worker = this->WorkerArray[j];
                    this->WorkerArray[j] = this->WorkerArray[j + 1];
                    this->WorkerArray[j + 1] = worker;
                }
            }
        }
        // 保存排序
        this->save();
        cout << "升序排序完成！" << endl;
    }
}

// 清空数据
void WorkManager::clean_data(){
    int choice=0;
    cout << "确定要清空数据？(1.确定 0.取消)" <<endl;
    cin >> choice;
    if (choice==1){
        // 打开模式  ios::trunc 如果文件存在 删除文件并重新创建
        ifstream ofs(FILENAME,ios::trunc);
        ofs.close();    // 关闭文件

        // 清空堆区
        if(this->WorkerArray!=NULL){
            // 删除堆区的每个职工对象
            for(int i=0;i<this->worker_count;i++){
                if(this->WorkerArray[i]!=NULL){
                    delete this->WorkerArray[i];
                    this->WorkerArray[i] = NULL;
                }
            }
            this->worker_count = 0;
            delete[] this->WorkerArray;
            this->WorkerArray = NULL;
            this->data_file_empty = true;
        }
        cout << "清空完成！" << endl;
    }else{
        return;
    }
}


WorkManager::~WorkManager() {
    if (this->WorkerArray != NULL) {
        for(int i=0;i<this->worker_count;i++){
            if(this->WorkerArray[i]!=NULL){
                delete this->WorkerArray[i];
            }
        }
        delete[] this->WorkerArray;
        this->WorkerArray = NULL;
    }
}