#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
    int i = 42;
    double d = 3.14;
    float f = 3.5;
    char c = 'a';

 
    cout << "i 的类型是" << typeid(i).name() << endl; 
    cout << "d 的类型是" << typeid(d).name() << endl; 
    cout << "c 的类型是" << typeid(c).name() << endl; 
    cout << "f 的类型是" << typeid(f).name() << endl;
    cout << "d+i 的类型是" << typeid(d + i).name() << endl; 
    cout << "d+f 的类型是" << typeid(d + f).name() << endl;
    cout << "i+f 的类型是" << typeid(i+f).name() << endl;
    cout << "i+c 的类型是" << typeid(i + c).name() << endl; 
    cout << "d+c 的类型是" << typeid(d + c).name() << endl; 
    return 0;
}