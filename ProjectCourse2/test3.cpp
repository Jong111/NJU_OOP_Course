#include <iostream>
using namespace std;

// ����
class Base {
public:
    virtual void func() { // ���麯��
        cout << "Base::func()" << endl;
    }
};

// ������
class Derived : public Base {
public:
    void func() { // ���ػ���ĺ���
        cout << "Derived::func()" << endl;
    }
};

// ���Դ���
int main() {
    Derived d;
    Base* p = &d; // ����ָ��ָ�����������
    p->func(); // ���� Base::func()
    return 0;
}






