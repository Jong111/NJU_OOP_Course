#include <iostream>
#include <string>

class HasPtr {
public:
    // 默认构造函数
    HasPtr(const std::string& s = std::string()) :
        ps(new std::string(s)), i(0) { }

    // 拷贝构造函数
    HasPtr(const HasPtr& hp) :
        ps(new std::string(*hp.ps)), i(hp.i) {
        std::cout << "Copy constructor called" << std::endl;
    }

    HasPtr& operator=(const HasPtr& hp) {
        if (this != &hp) {
            delete ps;
            ps = new std::string(*hp.ps);
            i = hp.i;
        }
        std::cout << "Copy assignment operator called" << std::endl;
        return *this;
    }

    // 析构函数，释放内存
    ~HasPtr() {
        delete ps;
        std::cout << "Destructor called" << std::endl;
    }

    // 移动赋值运算符
    HasPtr& operator=(HasPtr&& hp) noexcept {
        if (this != &hp) {
            delete ps;
            // 交换指针和整数
            ps = hp.ps;
            i = hp.i;
            hp.ps = nullptr;
            hp.i = 0;
        }
        std::cout << "Move assignment operator called" << std::endl;
        return *this;
    }

    // 移动构造函数
    HasPtr(HasPtr&& hp) noexcept :
        ps(hp.ps), i(hp.i) {
        hp.ps = nullptr;
        hp.i = 0;
        std::cout << "Move constructor called" << std::endl;
    }

    void print() const {
        std::cout << "ps: " << *ps << ", i: " << i << std::endl;
    }

private:
    std::string* ps;
    int i;
};

int main() {
    HasPtr p1("Hello");
    p1.print();

    HasPtr p2(p1);
    p2.print();

    HasPtr p3("World");
    p3.print();
    p3 = p1;
    p3.print();

    HasPtr p4("Foo");
    p4.print();
    p4 = std::move(p1);
    p4.print();

    HasPtr p5(std::move(p2));
    p5.print();

}
