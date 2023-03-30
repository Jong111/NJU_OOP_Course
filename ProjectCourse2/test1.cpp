#include <iostream>
#include<vector>
#include<string>

using namespace std;


typedef struct {
    string name; 
    unsigned int score; 
} student;


void set_score(student* s, int k, int x) {
    unsigned int mask = x << (6 * k);
    s->score |= mask;
}


int get_score(student* s, int k) {
    const unsigned int mask = 63;
    unsigned int temp = s->score >> (6 * k);
    return temp & mask;
}


void print_student(student* s) {
    cout << "������" << s->name << endl;
    cout<< "���ģ�"<< get_score(s, 0)<<endl;
    cout<< "��ѧ��"<<get_score(s, 1) << endl;
    cout<< "Ӣ�"<<get_score(s, 2) << endl;
    cout << "����" << get_score(s, 3) << endl;
    cout << "��ѧ��" << get_score(s, 4) << endl;
}

int main() {
    int n;
    cout << "������ѧ������:" << endl;
    cin >> n;
    vector<student> students(n);
    for (int i = 0; i < n; i++) {
        cout << "�������" << i + 1 << "��ѧ����������" << endl;
        cin >> students[i].name;
        students[i].score = 0; 
        for (int j = 0; j < 5; j++) {
            cout << "�������" << i + 1 << "��ѧ���ĵ�" << j + 1 << "�ſεĳɼ���" << endl;
            int x;
            cin >> x;
            set_score(&students[i], j, x); 
        }
    }
    for (int i = 0; i < n; i++) {
        print_student(&students[i]); 
        cout << endl;
    }
    return 0;
}