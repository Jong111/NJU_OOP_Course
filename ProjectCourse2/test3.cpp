#include <iostream>
using namespace std;

// 基类
class Base {
public:
    virtual void func() { // 非虚函数
        cout << "Base::func()" << endl;
    }
};

// 派生类
class Derived : public Base {
public:
    void func() { // 隐藏基类的函数
        cout << "Derived::func()" << endl;
    }
};

// 测试代码
int main() {
    Derived d;
    Base* p = &d; // 基类指针指向派生类对象
    p->func(); // 调用 Base::func()
    return 0;
}






