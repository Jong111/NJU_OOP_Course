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
    cout << "姓名：" << s->name << endl;
    cout<< "语文："<< get_score(s, 0)<<endl;
    cout<< "数学："<<get_score(s, 1) << endl;
    cout<< "英语："<<get_score(s, 2) << endl;
    cout << "物理：" << get_score(s, 3) << endl;
    cout << "化学：" << get_score(s, 4) << endl;
}

int main() {
    int n;
    cout << "请输入学生人数:" << endl;
    cin >> n;
    vector<student> students(n);
    for (int i = 0; i < n; i++) {
        cout << "请输入第" << i + 1 << "个学生的姓名：" << endl;
        cin >> students[i].name;
        students[i].score = 0; 
        for (int j = 0; j < 5; j++) {
            cout << "请输入第" << i + 1 << "个学生的第" << j + 1 << "门课的成绩：" << endl;
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