//#include <iostream>
//#include <cmath>
//
//
//
//// 定义图形基元的基类
//class Shape {
//public:
//    // 定义虚析构函数，以便正确释放派生类对象
//    virtual ~Shape() = default;
//
//    // 定义纯虚函数，打印图形的信息
//    virtual void print() const = 0;
//
//    // 定义纯虚函数，输入图形的数据
//    virtual void input() = 0;
//};
//
//// 定义线段类，继承自图形基元
//class Line : public Shape {
//public:
//    // 定义默认构造函数，初始化线段的两个端点为原点
//    Line() : x1(0), y1(0), x2(0), y2(0) {}
//
//    // 定义构造函数，根据参数初始化线段的两个端点
//    Line(double x1, double y1, double x2, double y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
//
//    // 定义拷贝构造函数，根据另一个线段对象初始化当前对象
//    Line(const Line& l) : x1(l.x1), y1(l.y1), x2(l.x2), y2(l.y2) {}
//
//    // 定义拷贝赋值运算符，将另一个线段对象的值赋给当前对象
//    Line& operator=(const Line& l) {
//        if (this != &l) {
//            x1 = l.x1;
//            y1 = l.y1;
//            x2 = l.x2;
//            y2 = l.y2;
//        }
//        return *this;
//    }
//
//    // 定义移动构造函数，根据一个右值线段对象初始化当前对象
//    Line(Line&& l) noexcept : x1(std::move(l.x1)), y1(std::move(l.y1)), x2(std::move(l.x2)), y2(std::move(l.y2)) {}
//
//    // 定义移动赋值运算符，将一个右值线段对象的值赋给当前对象
//    Line& operator=(Line&& l) noexcept {
//        if (this != &l) {
//            x1 = std::move(l.x1);
//            y1 = std::move(l.y1);
//            x2 = std::move(l.x2);
//            y2 = std::move(l.y2);
//        }
//        return *this;
//    }
//
//    // 定义虚析构函数，不做任何操作
//    ~Line() override {}
//
//    // 定义打印函数，输出线段的两个端点和长度
//    void print() const override {
//        std::cout << "Line: (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << "), length = " << length() << "\n";
//    }
//
//    // 定义输入函数，从标准输入读取线段的两个端点
//    void input() override {
//        std::cout << "Please enter the coordinates of the two endpoints of the line: \n";
//        std::cin >> x1 >> y1 >> x2 >> y2;
//    }
//
//private:
//    // 定义计算长度的函数，根据两个端点的坐标计算线段的长度
//    double length() const {
//        return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
//    }
//
//    // 定义数据成员，表示线段的两个端点的坐标
//    double x1, y1, x2, y2;
//};
//
//// 定义方格类，继承自图形基元
//class Square : public Shape {
//public:
//    // 定义默认构造函数，初始化方格的左下角坐标为原点，边长为0
//    Square() : x(0), y(0), side(0) {}
//
//    // 定义构造函数，根据参数初始化方格的左下角坐标和边长
//    Square(double x, double y, double side) : x(x), y(y), side(side) {}
//
//    // 定义拷贝构造函数，根据另一个方格对象初始化当前对象
//    Square(const Square& s) : x(s.x), y(s.y), side(s.side) {}
//
//    // 定义拷贝赋值运算符，将另一个方格对象的值赋给当前对象
//    Square& operator=(const Square& s) {
//        if (this != &s) {
//            x = s.x;
//            y = s.y;
//            side = s.side;
//        }
//        return *this;
//    }
//
//    // 定义移动构造函数，根据一个右值方格对象初始化当前对象
//    Square(Square&& s) noexcept : x(std::move(s.x)), y(std::move(s.y)), side(std::move(s.side)) {}
//
//    // 定义移动赋值运算符，将一个右值方格对象的值赋给当前对象
//    Square& operator=(Square&& s) noexcept {
//        if (this != &s) {
//            x = std::move(s.x);
//            y = std::move(s.y);
//            side = std::move(s.side);
//        }
//        return *this;
//    }
//
//    // 定义虚析构函数，不做任何操作
//    ~Square() override {}
//
//    // 定义打印函数，输出方格的左下角坐标、边长和面积
//    void print() const override {
//        std::cout << "Square: (" << x << ", " << y << "), side = " << side << ", area = " << area() << "\n";
//    }
//
//    // 定义输入函数，从标准输入读取方格的左下角坐标和边长
//    void input() override {
//        std::cout << "Please enter the coordinates of the lower left corner and the side length of the square: \n";
//        std::cin >> x >> y >> side;
//    }
//
//private:
//    // 定义计算面积的函数，根据边长计算方格的面积
//    double area() const {
//        return side * side;
//    }
//
//    // 定义数据成员，表示方格的左下角坐标和边长
//    double x, y, side;
//};
//
//// 定义圆类，继承自图形基元
//class Circle : public Shape {
//public:
//    // 定义默认构造函数，初始化圆的圆心坐标为原点，半径为0
//    Circle() : x(0), y(0), r(0) {}
//
//    // 定义构造函数，根据参数初始化圆的圆心坐标和半径
//    Circle(double x, double y, double r) : x(x), y(y), r(r) {}
//
//    // 定义拷贝构造函数，根据另一个圆对象初始化当前对象
//    Circle(const Circle& c) : x(c.x), y(c.y), r(c.r) {}
//
//    // 定义拷贝赋值运算符，将另一个圆对象的值赋给当前对象
//    Circle& operator=(const Circle& c) {
//        if (this != &c) {
//            x = c.x;
//            y = c.y;
//            r = c.r;
//        }
//        return *this;
//    }
//
//    // 定义移动构造函数，根据一个右值圆对象初始化当前对象
//    Circle(Circle&& c) noexcept : x(std::move(c.x)), y(std::move(c.y)), r(std::move(c.r)) {}
//
//    // 定义移动赋值运算符，将一个右值圆对象的值赋给当前对象
//    Circle& operator=(Circle&& c) noexcept {
//        if (this != &c) {
//            x = std::move(c.x);
//            y = std::move(c.y);
//            r = std::move(c.r);
//        }
//        return *this;
//    }
//
//    // 定义虚析构函数，不做任何操作
//    ~Circle() override {}
//
//    // 定义打印函数，输出圆的圆心坐标、半径和面积
//    void print() const override {
//        std::cout << "Circle: (" << x << ", " << y << "), radius = " << r << ", area = " << area() << "\n";
//    }
//
//    // 定义输入函数，从标准输入读取圆的圆心坐标和半径
//    void input() override {
//        std::cout << "Please enter the coordinates of the center and the radius of the circle: \n";
//        std::cin >> x >> y >> r;
//    }
//
//private:
//    // 定义计算面积的函数，根据半径计算圆的面积
//    double area() const {
//        return 3.14 * r * r;
//    }
//
//    // 定义数据成员，表示圆的圆心坐标和半径
//    double x, y, r;
//};
//
//// 定义球类，继承自图形基元
//class Sphere : public Shape {
//public:
//    // 定义默认构造函数，初始化球的球心坐标为原点，半径为0
//    Sphere() : x(0), y(0), z(0), r(0) {}
//
//    // 定义构造函数，根据参数初始化球的球心坐标和半径
//    Sphere(double x, double y, double z, double r) : x(x), y(y), z(z), r(r) {}
//
//    // 定义拷贝构造函数，根据另一个球对象初始化当前对象
//    Sphere(const Sphere& s) : x(s.x), y(s.y), z(s.z), r(s.r) {}
//
//    // 定义拷贝赋值运算符，将另一个球对象的值赋给当前对象
//    Sphere& operator=(const Sphere& s) {
//        if (this != &s) {
//            x = s.x;
//            y = s.y;
//            z = s.z;
//            r = s.r;
//        }
//        return *this;
//    }
//
//    // 定义移动构造函数，根据一个右值球对象初始化当前对象
//    Sphere(Sphere&& s) noexcept : x(std::move(s.x)), y(std::move(s.y)), z(std::move(s.z)), r(std::move(s.r)) {}
//
//    // 定义移动赋值运算符，将一个右值球对象的值赋给当前对象
//    Sphere& operator=(Sphere&& s) noexcept {
//        if (this != &s) {
//            x = std::move(s.x);
//            y = std::move(s.y);
//            z = std::move(s.z);
//            r = std::move(s.r);
//        }
//        return *this;
//    }
//
//    // 定义虚析构函数，不做任何操作
//    ~Sphere() override {}
//
//    // 定义打印函数，输出球的球心坐标、半径和体积
//    void print() const override {
//        std::cout << "Sphere: (" << x << ", " << y << ", " << z << "), radius = " << r << ", volume = " << volume() << "\n";
//    }
//
//    // 定义输入函数，从标准输入读取球的球心坐标和半径
//    void input() override {
//        std::cout << "Please enter the coordinates of the center and the radius of the sphere: \n";
//        std::cin >> x >> y >> z >> r;
//    }
//
//private:
//    // 定义计算体积的函数，根据半径计算球的体积
//    double volume() const {
//        return 4.0 / 3.0 * 3.14 * r * r * r;
//    }
//
//    // 定义数据成员，表示球的球心坐标和半径
//    double x, y, z, r;
//};
//
//// 定义圆锥类，继承自图形基元
//class Cone : public Shape {
//public:
//    // 定义默认构造函数，初始化圆锥的顶点坐标为原点，底面圆心坐标为(0, 0, -1)，底面半径为1，高为1
//    Cone() : x(0), y(0), z(0), cx(0), cy(0), cz(-1), r(1), h(1) {}
//
//    // 定义构造函数，根据参数初始化圆锥的顶点坐标、底面圆心坐标、底面半径和高
//    Cone(double x, double y, double z, double cx, double cy, double cz, double r, double h) : x(x), y(y), z(z), cx(cx), cy(cy), cz(cz), r(r), h(h) {}
//
//    // 定义拷贝构造函数，根据另一个圆锥对象初始化当前对象
//    Cone(const Cone& c) : x(c.x), y(c.y), z(c.z), cx(c.cx), cy(c.cy), cz(c.cz), r(c.r), h(c.h) {}
//
//    // 定义拷贝赋值运算符，将另一个圆锥对象的值赋给当前对象
//    Cone& operator=(const Cone& c) {
//        if (this != &c) {
//            x = c.x;
//            y = c.y;
//            z = c.z;
//            cx = c.cx;
//            cy = c.cy;
//            cz = c.cz;
//            r = c.r;
//            h = c.h;
//        }
//        return *this;
//    }
//
//    // 定义移动构造函数，根据一个右值圆锥对象初始化当前对象
//    Cone(Cone&& c) noexcept : x(std::move(c.x)), y(std::move(c.y)), z(std::move(c.z)), cx(std::move(c.cx)), cy(std::move(c.cy)), cz(std::move(c.cz)), r(std::move(c.r)), h(std::move(c.h)) {}
//
//    // 定义移动赋值运算符，将一个右值圆锥对象的值赋给当前对象
//    Cone& operator=(Cone&& c) noexcept {
//        if (this != &c) {
//            x = std::move(c.x);
//            y = std::move(c.y);
//            z = std::move(c.z);
//            cx = std::move(c.cx);
//            cy = std::move(c.cy);
//            cz = std::move(c.cz);
//            r = std::move(c.r);
//            h = std::move(c.h);
//        }
//        return *this;
//    }
//
//    // 定义虚析构函数，不做任何操作
//    ~Cone() override {}
//
//    // 定义打印函数，输出圆锥的顶点坐标、底面圆心坐标、底面半径、高和体积
//    void print() const override {
//        std::cout << "Cone: (" << x << ", " << y << ", " << z << ") to (" << cx << ", " << cy << ", " << cz << "), radius = " << r << ", height = " << h << ", volume = " << volume() << "\n";
//    }
//
//    // 定义输入函数，从标准输入读取圆锥的顶点坐标、底面圆心坐标、底面半径和高
//    void input() override {
//        std::cout << "Please enter the coordinates of the vertex and the center of the base circle, the radius of the base circle and the height of the cone: \n";
//        std::cin >> x >> y >> z >> cx >> cy >> cz >> r >> h;
//    }
//
//private:
//    // 定义计算体积的函数，根据底面半径和高计算圆锥的体积
//    double volume() const {
//        return 1.0 / 3.0 * 3.14 * r * r * h;
//    }
//
//    // 定义数据成员，表示圆锥的顶点坐标、底面圆心坐标、底面半径和高
//    double x, y, z, cx, cy, cz, r, h;
//};
//
//// 在main函数中测试图形基元的继承体系
//int main() {
//    // 创建一个图形基元的指针数组，用来存放不同类型的图形对象
//    Shape* shapes[5];
//
//    // 创建一个线段对象，并将其地址存入数组中
//    Line l(1, 2, 3, 4);
//    shapes[0] = &l;
//
//    // 创建一个方格对象，并将其地址存入数组中
//    Square s(5, 6, 7);
//    shapes[1] = &s;
//
//    // 创建一个圆对象，并将其地址存入数组中
//    Circle c(8, 9, 10);
//    shapes[2] = &c;
//
//    // 创建一个球对象，并将其地址存入数组中
//    Sphere sp(12, 13, 14, 15);
//    shapes[3] = &sp;
//
//    // 创建一个圆锥对象，并将其地址存入数组中
//    Cone co(16, 17, 18, 19, 20, 21, 22, 23);
//    shapes[4] = &co;
//
//    // 遍历数组，调用每个图形对象的打印函数，输出图形的信息
//    for (int i = 0; i < 5; ++i) {
//        shapes[i]->print();
//    }
//
//    // 遍历数组，调用每个图形对象的输入函数，从标准输入读取图形的数据
//    for (int i = 0; i < 5; ++i) {
//        shapes[i]->input();
//    }
//
//    // 再次遍历数组，调用每个图形对象的打印函数，输出图形的信息
//    for (int i = 0; i < 5; ++i) {
//        shapes[i]->print();
//    }
//
//    return 0;
//}
//
//
