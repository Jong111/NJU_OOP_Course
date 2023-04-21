//#include<iostream>
//using namespace std;
//class A {
//private:
//    A() {} 
//    static A* aa;
//public:
//    static A* getinstance() { 
//        if (aa == nullptr) { 
//            aa = new A(); 
//        }
//        return aa; 
//    }
//};
//
//A* A::aa = nullptr;
//
//int main() {
//    A* a1 = A::getinstance(); 
//    A* a2 = A::getinstance(); 
//    cout << (a1 == a2) << endl; 
//    return 0;
//}