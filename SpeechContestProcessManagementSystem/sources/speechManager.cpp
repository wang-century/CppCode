#include "speechManager.h"

SpeechManager::SpeechManager() {
    this->init_speech();    // 初始化容器和属性
    this->create_speaker(); // 创建选手
}

SpeechManager::~SpeechManager() {

}

void SpeechManager::show_menu() {
    /* 显示菜单 */
    cout << string(20, '*') << endl;
    cout << "\t演讲比赛流程管理系统" << endl;
    cout << "\t1.开始演讲比赛" << endl;
    cout << "\t2.查看往届记录" << endl;
    cout << "\t3.清空比赛记录" << endl;
    cout << "\t4.退出比赛程序" << endl;
    cout << string(20, '*') << endl;
}

void SpeechManager::init_speech() {
    /* 初始化容器和属性 */
    this->v1.clear();
    this->v2.clear();
    this->victory_v.clear();
    this->speaker_m.clear();
    this->turn_count = 1;
    this->history_m.clear();
}

void SpeechManager::create_speaker() {
    /* 创建选手 */
    string speaker_names = "ABCDEFGHIJKL";
    for (int i = 0; i < 12; i++) {
        // 创建选手，放入容器
        string name = "选手";
        name += speaker_names[i];
        int id = i + 1001;
        Speaker speaker;
        speaker.name = name;
        speaker.score[0] = 0;
        speaker.score[1] = 0;
        this->v1.push_back(id);
        this->speaker_m.insert(make_pair(id, speaker));
    }
}

void SpeechManager::random_draw() {
    /* 抽签 */
    cout << "第《" << this->turn_count << "》轮比赛选手抽签" << endl;
    cout << string(20, '-') << endl;
    cout << "抽签后演讲顺序如下：" << endl;
    if (this->turn_count == 1) {
        // 第一轮比赛
        random_shuffle(this->v1.begin(), this->v1.end());
        for (int it:this->v1) {
            cout << it << " ";
        }
        cout << endl;
    } else {
        // 第二轮比赛
        random_shuffle(this->v2.begin(), this->v2.end());
        for (int it:this->v2) {
            cout << it << " ";
        }
        cout << endl;
    }
    cout << string(20, '-') << endl;
}

void SpeechManager::sppech_contest() {
    /* 比赛 */
    cout << "第《" << this->turn_count << "》轮比赛正式开始" << endl;
    vector<int> v_speaker;   // 比赛选手容器
    multimap<double, int, greater<>> group_score;  // 存放小组成绩
    int num = 0;    // 记录人员个数 6人一组
    if (this->turn_count == 1) {
        v_speaker = this->v1;
    } else {
        v_speaker = this->v2;
    }
    // 遍历所有选手进行比赛
    for (vector<int>::iterator it = v_speaker.begin(); it != v_speaker.end(); it++) {
        // 评委打分
        deque<double> d;
        for (int i = 0; i < 10; i++) {
            double score = (rand() % 401 + 600) / 10.f;   // 600-1000
            d.push_back(score);
        }
        sort(d.begin(), d.end(), greater<>());    // 排序
        d.pop_front();  // 去除最高分
        d.pop_back();   // 去除最低分
        double sum = accumulate(d.begin(), d.end(), 0.0f);    // 累加分
        double avg = sum / (double) d.size();    // 平均分
        // cout << "编号：" << *it << " 姓名：" << this->speaker_m[*it].name << " 平均分：" << avg << endl;
        this->speaker_m[*it].score[this->turn_count - 1] = avg;    // 将平均分放入map容器
        group_score.insert(make_pair(avg, *it));  // 将成绩存入小组容器
        num++;
        // 每6人一组
        if (num % 6 == 0) {
            cout << "第" << num / 6 << "小组比赛名次：" << endl;
            for (auto &i : group_score) {
                cout << "编号：" << i.second << " 姓名：" << this->speaker_m[i.second].name << " 成绩："
                     << this->speaker_m[i.second].score[this->turn_count - 1] << endl;
            }
            // 取出前三名
            int count = 0;
            for (auto i = group_score.begin(); i != group_score.end() && count < 3; i++, count++) {
                if (this->turn_count == 1) {
                    this->v2.push_back((*i).second);
                } else {
                    this->victory_v.push_back((*i).second);
                }
            }
            group_score.clear();
        }
    }
    cout << "第" << this->turn_count << "轮比赛完毕！" << endl;
}

void SpeechManager::show_score() {
    /* 打印成绩 */
    cout << "-----第" << this->turn_count << "轮晋级选手信息：-----" << endl;
    vector<int> v;
    if (this->turn_count == 1) {
        v = this->v2;
    } else {
        v = this->victory_v;
    }
    cout << v.size() << endl;
    for (auto it:v) {
        cout << "编号：" << it << "\t姓名：" << this->speaker_m[it].name << "\t分数："
             << this->speaker_m[it].score[this->turn_count - 1] << endl;
    }
}

void SpeechManager::save_data() {
    /* 保存数据到文件 */
    ofstream ofs("speech.csv", ios::out | ios::app); // 用追加的方式打开文件   -- 写
    // 将数据写入文件

    for (auto it : this->victory_v) {
        ofs << it << "," << this->speaker_m[it].score[1] << ",";
    }
    ofs << endl;

    ofs.close();    // 关闭文件
    cout << "数据已保存" << endl;
}

void SpeechManager::start_speech() {
    /* 开始比赛 */
    // 第一轮开始比赛
    // 1、抽签
    this->random_draw();
    // 2、比赛
    this->sppech_contest();
    // 3、显示晋级结果
    this->show_score();
    // 第二轮开始比赛
    this->turn_count++;
    // 1、抽签
    this->random_draw();
    // 2、比赛
    this->sppech_contest();
    // 3、显示晋级结果
    this->show_score();
    // 4.保存分数到文件中
    this->save_data();
    cout << "本届比赛完毕！" << endl;
    this->init_speech();
    this->create_speaker();
}


void SpeechManager::show_history() {
    /* 查看记录 */
    ifstream ifs("speech.csv", ios::in); // 读取文件

    // 文件不存在
    if (!ifs.is_open()) {
        this->data_file_empty = true;
        cout << "数据文件不存在！" << endl;
        ifs.close();
        return;
    }

    // 文件清空
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        this->data_file_empty = true;
        cout << "数据文件为空！" << endl;
        ifs.close();
        return;
    }

    // 文件不为空
    this->data_file_empty = false;
    ifs.putback(ch);    // 将读取的单个字符返回
    string data;
    int index = 1;      // 统计第几届
    while (ifs >> data) {
        // 1011,81.7375,1012,79.3375,1002,78.8875,
        int pos = -1;   // 用于保存","位置
        int start = 0;  // 起始查找位置
        vector<string>v;    // 用于存放6个数据
        while (true){
            pos = data.find(',',start);
            if(pos==-1){
                break;
            }else{
                string temp = data.substr(start,pos-start);
                v.push_back(temp);
                start = pos+1;  // 设置起始位置为上一次结束位置后一位
            }
        }
        this->history_m.insert(make_pair(index,v));
        index++;
    }
    ifs.close();
    for(auto i:this->history_m){
        cout << "第" << i.first << "届数据:\t"
            << "冠军:" << i.second[0] << "\t成绩:" << i.second[1]
            << "\t亚军:" << i.second[2] << "\t成绩:" << i.second[3]
            << "\t季军:" << i.second[4] << "\t成绩:" << i.second[5];
        cout << endl;
    }
}

void SpeechManager::clear_data(){
    /* 清空记录 */
    int choice;
    cout << "确认清空记录？(1.确定 2.返回):";
    cin >> choice;
    if(choice==1){
        ofstream ofs("speech.csv",ios::trunc);
        ofs.close();
        // 初始化属性
        this->init_speech();
        this->create_speaker();
        cout << "清空完成！" << endl;
    }else{
        return;
    }

}


