#include "speechManager.h"

SpeechManager::SpeechManager() {
    this->init_speech();    // ��ʼ������������
    this->create_speaker(); // ����ѡ��
}

SpeechManager::~SpeechManager() {

}

void SpeechManager::show_menu() {
    /* ��ʾ�˵� */
    cout << string(20, '*') << endl;
    cout << "\t�ݽ��������̹���ϵͳ" << endl;
    cout << "\t1.��ʼ�ݽ�����" << endl;
    cout << "\t2.�鿴�����¼" << endl;
    cout << "\t3.��ձ�����¼" << endl;
    cout << "\t4.�˳���������" << endl;
    cout << string(20, '*') << endl;
}

void SpeechManager::init_speech() {
    /* ��ʼ������������ */
    this->v1.clear();
    this->v2.clear();
    this->victory_v.clear();
    this->speaker_m.clear();
    this->turn_count = 1;
}

void SpeechManager::create_speaker() {
    /* ����ѡ�� */
    string speaker_names = "ABCDEFGHIJKL";
    for (int i = 0; i < 12; i++) {
        // ����ѡ�֣���������
        string name = "ѡ��";
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
    /* ��ǩ */
    cout << "�ڡ�" << this->turn_count << "���ֱ���ѡ�ֳ�ǩ" << endl;
    cout << string(20, '-') << endl;
    cout << "��ǩ���ݽ�˳�����£�" << endl;
    if (this->turn_count == 1) {
        // ��һ�ֱ���
        random_shuffle(this->v1.begin(), this->v1.end());
        for (int it:this->v1) {
            cout << it << " ";
        }
        cout << endl;
    } else {
        // �ڶ��ֱ���
        random_shuffle(this->v2.begin(), this->v2.end());
        for (int it:this->v2) {
            cout << it << " ";
        }
        cout << endl;
    }
    cout << string(20, '-') << endl;
    system("pause");
}

void SpeechManager::sppech_contest() {
    /* ���� */
    cout << "�ڡ�" << this->turn_count << "���ֱ�����ʽ��ʼ" << endl;
    vector<int> v_speaker;   // ����ѡ������
    multimap<double, int, greater<>> group_score;  // ���С��ɼ�
    int num = 0;    // ��¼��Ա���� 6��һ��
    if (this->turn_count == 1) {
        v_speaker = this->v1;
    } else {
        v_speaker = this->v2;
    }
    // ��������ѡ�ֽ��б���
    for (vector<int>::iterator it = v_speaker.begin(); it != v_speaker.end(); it++) {
        // ��ί���
        deque<double> d;
        for (int i = 0; i < 10; i++) {
            double score = (rand() % 401 + 600) / 10.f;   // 600-1000
            d.push_back(score);
        }
        sort(d.begin(), d.end(), greater<>());    // ����
        d.pop_front();  // ȥ����߷�
        d.pop_back();   // ȥ����ͷ�
        double sum = accumulate(d.begin(), d.end(), 0.0f);    // �ۼӷ�
        double avg = sum / (double) d.size();    // ƽ����
        // cout << "��ţ�" << *it << " ������" << this->speaker_m[*it].name << " ƽ���֣�" << avg << endl;
        this->speaker_m[*it].score[this->turn_count - 1] = avg;    // ��ƽ���ַ���map����
        group_score.insert(make_pair(avg, *it));  // ���ɼ�����С������
        num++;
        // ÿ6��һ��
        if (num % 6 == 0) {
            cout << "��" << num / 6 << "С��������Σ�" << endl;
            for (auto &i : group_score) {
                cout << "��ţ�" << i.second << " ������" << this->speaker_m[i.second].name << " �ɼ���"
                     << this->speaker_m[i.second].score[this->turn_count - 1] << endl;
            }
            // ȡ��ǰ����
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
    cout << "��" << this->turn_count << "�ֱ�����ϣ�" << endl;
    system("pause");
}

void SpeechManager::show_score() {
    /* ��ӡ�ɼ� */
    cout << "-----��" << this->turn_count << "�ֽ���ѡ����Ϣ��-----" << endl;
    vector<int> v;
    if (this->turn_count == 1) {
        v = this->v2;
    } else {
        v = this->victory_v;
    }
    cout << v.size() << endl;
    for (auto it:v) {
        cout << "��ţ�" << it << "\t������" << this->speaker_m[it].name << "\t������"
             << this->speaker_m[it].score[this->turn_count - 1] << endl;
    }
}

void SpeechManager::save_data() {
    /* �������ݵ��ļ� */
    ofstream ofs("speech.csv", ios::out | ios::app); // ��׷�ӵķ�ʽ���ļ�   -- д
    // ������д���ļ�
    for (auto it : victory_v) {
        ofs << it << "," << speaker_m[it].score[1] << ",";
    }
    ofs << endl;

    ofs.close();    // �ر��ļ�
    cout << "�����ѱ���" << endl;

}

void SpeechManager::start_speech() {
    /* ��ʼ���� */
    // ��һ�ֿ�ʼ����
    // 1����ǩ
    this->random_draw();
    // 2������
    this->sppech_contest();
    // 3����ʾ�������
    this->show_score();
    // �ڶ��ֿ�ʼ����
    this->turn_count++;
    // 1����ǩ
    this->random_draw();
    // 2������
    this->sppech_contest();
    // 3����ʾ�������
    this->show_score();
    // 4.����������ļ���
    this->save_data();
    cout << "���������ϣ�" << endl;
    system("pause");
}


void SpeechManager::show_history() {
    /* �鿴��¼ */
    ifstream ifs("speech.csv", ios::in); // ��ȡ�ļ�

    // �ļ�������
    if (!ifs.is_open()) {
        this->data_file_empty = true;
        cout << "�����ļ������ڣ�" << endl;
        ifs.close();
        return;
    }

    // �ļ����
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        this->data_file_empty = true;
        cout << "�����ļ�Ϊ�գ�" << endl;
        ifs.close();
        return;
    }

    // �ļ���Ϊ��
    this->data_file_empty = false;
    ifs.putback(ch);    // ����ȡ�ĵ����ַ�����
    string data;
    while (ifs >> data) {
        cout << data << endl;
    }

    ifs.close();


}


