#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
    int i = 42;
    double d = 3.14;
    float f = 3.5;
    char c = 'a';

 
    cout << "i ��������" << typeid(i).name() << endl; 
    cout << "d ��������" << typeid(d).name() << endl; 
    cout << "c ��������" << typeid(c).name() << endl; 
    cout << "f ��������" << typeid(f).name() << endl;
    cout << "d+i ��������" << typeid(d + i).name() << endl; 
    cout << "d+f ��������" << typeid(d + f).name() << endl;
    cout << "i+f ��������" << typeid(i+f).name() << endl;
    cout << "i+c ��������" << typeid(i + c).name() << endl; 
    cout << "d+c ��������" << typeid(d + c).name() << endl; 
    return 0;
}