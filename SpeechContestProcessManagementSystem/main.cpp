#include <iostream>
#include "sources/speechManager.h"
#include <time.h>
using namespace std;


int main(){
    SpeechManager manager;  // �������������
    srand((int)time(nullptr));
    int choice = 0;     // �洢�û�����
    while (true){
        manager.show_menu();    // ��ʾ�˵�
        cout << "��ѡ��:";
        cin >> choice;
        switch (choice) {
            case 1:     // ��ʼ�ݽ�����
                manager.start_speech();
                break;
            case 2:     // �鿴�����¼
                manager.show_history();
                break;
            case 3:     // ��ձ�����¼
                break;
            case 4:     // �˳���������
                cout << "�����˳�" << endl;
                return 0;
            default:
                cout << "�������!��������" << endl;
        }
    }
}
