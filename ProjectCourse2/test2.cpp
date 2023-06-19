//#include <iostream>
//#include <cmath>
//
//
//
//// ����ͼ�λ�Ԫ�Ļ���
//class Shape {
//public:
//    // �����������������Ա���ȷ�ͷ����������
//    virtual ~Shape() = default;
//
//    // ���崿�麯������ӡͼ�ε���Ϣ
//    virtual void print() const = 0;
//
//    // ���崿�麯��������ͼ�ε�����
//    virtual void input() = 0;
//};
//
//// �����߶��࣬�̳���ͼ�λ�Ԫ
//class Line : public Shape {
//public:
//    // ����Ĭ�Ϲ��캯������ʼ���߶ε������˵�Ϊԭ��
//    Line() : x1(0), y1(0), x2(0), y2(0) {}
//
//    // ���幹�캯�������ݲ�����ʼ���߶ε������˵�
//    Line(double x1, double y1, double x2, double y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
//
//    // ���忽�����캯����������һ���߶ζ����ʼ����ǰ����
//    Line(const Line& l) : x1(l.x1), y1(l.y1), x2(l.x2), y2(l.y2) {}
//
//    // ���忽����ֵ�����������һ���߶ζ����ֵ������ǰ����
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
//    // �����ƶ����캯��������һ����ֵ�߶ζ����ʼ����ǰ����
//    Line(Line&& l) noexcept : x1(std::move(l.x1)), y1(std::move(l.y1)), x2(std::move(l.x2)), y2(std::move(l.y2)) {}
//
//    // �����ƶ���ֵ���������һ����ֵ�߶ζ����ֵ������ǰ����
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
//    // ���������������������κβ���
//    ~Line() override {}
//
//    // �����ӡ����������߶ε������˵�ͳ���
//    void print() const override {
//        std::cout << "Line: (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << "), length = " << length() << "\n";
//    }
//
//    // �������뺯�����ӱ�׼�����ȡ�߶ε������˵�
//    void input() override {
//        std::cout << "Please enter the coordinates of the two endpoints of the line: \n";
//        std::cin >> x1 >> y1 >> x2 >> y2;
//    }
//
//private:
//    // ������㳤�ȵĺ��������������˵����������߶εĳ���
//    double length() const {
//        return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
//    }
//
//    // �������ݳ�Ա����ʾ�߶ε������˵������
//    double x1, y1, x2, y2;
//};
//
//// ���巽���࣬�̳���ͼ�λ�Ԫ
//class Square : public Shape {
//public:
//    // ����Ĭ�Ϲ��캯������ʼ����������½�����Ϊԭ�㣬�߳�Ϊ0
//    Square() : x(0), y(0), side(0) {}
//
//    // ���幹�캯�������ݲ�����ʼ����������½�����ͱ߳�
//    Square(double x, double y, double side) : x(x), y(y), side(side) {}
//
//    // ���忽�����캯����������һ����������ʼ����ǰ����
//    Square(const Square& s) : x(s.x), y(s.y), side(s.side) {}
//
//    // ���忽����ֵ�����������һ����������ֵ������ǰ����
//    Square& operator=(const Square& s) {
//        if (this != &s) {
//            x = s.x;
//            y = s.y;
//            side = s.side;
//        }
//        return *this;
//    }
//
//    // �����ƶ����캯��������һ����ֵ��������ʼ����ǰ����
//    Square(Square&& s) noexcept : x(std::move(s.x)), y(std::move(s.y)), side(std::move(s.side)) {}
//
//    // �����ƶ���ֵ���������һ����ֵ��������ֵ������ǰ����
//    Square& operator=(Square&& s) noexcept {
//        if (this != &s) {
//            x = std::move(s.x);
//            y = std::move(s.y);
//            side = std::move(s.side);
//        }
//        return *this;
//    }
//
//    // ���������������������κβ���
//    ~Square() override {}
//
//    // �����ӡ�����������������½����ꡢ�߳������
//    void print() const override {
//        std::cout << "Square: (" << x << ", " << y << "), side = " << side << ", area = " << area() << "\n";
//    }
//
//    // �������뺯�����ӱ�׼�����ȡ��������½�����ͱ߳�
//    void input() override {
//        std::cout << "Please enter the coordinates of the lower left corner and the side length of the square: \n";
//        std::cin >> x >> y >> side;
//    }
//
//private:
//    // �����������ĺ��������ݱ߳����㷽������
//    double area() const {
//        return side * side;
//    }
//
//    // �������ݳ�Ա����ʾ��������½�����ͱ߳�
//    double x, y, side;
//};
//
//// ����Բ�࣬�̳���ͼ�λ�Ԫ
//class Circle : public Shape {
//public:
//    // ����Ĭ�Ϲ��캯������ʼ��Բ��Բ������Ϊԭ�㣬�뾶Ϊ0
//    Circle() : x(0), y(0), r(0) {}
//
//    // ���幹�캯�������ݲ�����ʼ��Բ��Բ������Ͱ뾶
//    Circle(double x, double y, double r) : x(x), y(y), r(r) {}
//
//    // ���忽�����캯����������һ��Բ�����ʼ����ǰ����
//    Circle(const Circle& c) : x(c.x), y(c.y), r(c.r) {}
//
//    // ���忽����ֵ�����������һ��Բ�����ֵ������ǰ����
//    Circle& operator=(const Circle& c) {
//        if (this != &c) {
//            x = c.x;
//            y = c.y;
//            r = c.r;
//        }
//        return *this;
//    }
//
//    // �����ƶ����캯��������һ����ֵԲ�����ʼ����ǰ����
//    Circle(Circle&& c) noexcept : x(std::move(c.x)), y(std::move(c.y)), r(std::move(c.r)) {}
//
//    // �����ƶ���ֵ���������һ����ֵԲ�����ֵ������ǰ����
//    Circle& operator=(Circle&& c) noexcept {
//        if (this != &c) {
//            x = std::move(c.x);
//            y = std::move(c.y);
//            r = std::move(c.r);
//        }
//        return *this;
//    }
//
//    // ���������������������κβ���
//    ~Circle() override {}
//
//    // �����ӡ���������Բ��Բ�����ꡢ�뾶�����
//    void print() const override {
//        std::cout << "Circle: (" << x << ", " << y << "), radius = " << r << ", area = " << area() << "\n";
//    }
//
//    // �������뺯�����ӱ�׼�����ȡԲ��Բ������Ͱ뾶
//    void input() override {
//        std::cout << "Please enter the coordinates of the center and the radius of the circle: \n";
//        std::cin >> x >> y >> r;
//    }
//
//private:
//    // �����������ĺ��������ݰ뾶����Բ�����
//    double area() const {
//        return 3.14 * r * r;
//    }
//
//    // �������ݳ�Ա����ʾԲ��Բ������Ͱ뾶
//    double x, y, r;
//};
//
//// �������࣬�̳���ͼ�λ�Ԫ
//class Sphere : public Shape {
//public:
//    // ����Ĭ�Ϲ��캯������ʼ�������������Ϊԭ�㣬�뾶Ϊ0
//    Sphere() : x(0), y(0), z(0), r(0) {}
//
//    // ���幹�캯�������ݲ�����ʼ�������������Ͱ뾶
//    Sphere(double x, double y, double z, double r) : x(x), y(y), z(z), r(r) {}
//
//    // ���忽�����캯����������һ��������ʼ����ǰ����
//    Sphere(const Sphere& s) : x(s.x), y(s.y), z(s.z), r(s.r) {}
//
//    // ���忽����ֵ�����������һ��������ֵ������ǰ����
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
//    // �����ƶ����캯��������һ����ֵ������ʼ����ǰ����
//    Sphere(Sphere&& s) noexcept : x(std::move(s.x)), y(std::move(s.y)), z(std::move(s.z)), r(std::move(s.r)) {}
//
//    // �����ƶ���ֵ���������һ����ֵ������ֵ������ǰ����
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
//    // ���������������������κβ���
//    ~Sphere() override {}
//
//    // �����ӡ�������������������ꡢ�뾶�����
//    void print() const override {
//        std::cout << "Sphere: (" << x << ", " << y << ", " << z << "), radius = " << r << ", volume = " << volume() << "\n";
//    }
//
//    // �������뺯�����ӱ�׼�����ȡ�����������Ͱ뾶
//    void input() override {
//        std::cout << "Please enter the coordinates of the center and the radius of the sphere: \n";
//        std::cin >> x >> y >> z >> r;
//    }
//
//private:
//    // �����������ĺ��������ݰ뾶����������
//    double volume() const {
//        return 4.0 / 3.0 * 3.14 * r * r * r;
//    }
//
//    // �������ݳ�Ա����ʾ�����������Ͱ뾶
//    double x, y, z, r;
//};
//
//// ����Բ׶�࣬�̳���ͼ�λ�Ԫ
//class Cone : public Shape {
//public:
//    // ����Ĭ�Ϲ��캯������ʼ��Բ׶�Ķ�������Ϊԭ�㣬����Բ������Ϊ(0, 0, -1)������뾶Ϊ1����Ϊ1
//    Cone() : x(0), y(0), z(0), cx(0), cy(0), cz(-1), r(1), h(1) {}
//
//    // ���幹�캯�������ݲ�����ʼ��Բ׶�Ķ������ꡢ����Բ�����ꡢ����뾶�͸�
//    Cone(double x, double y, double z, double cx, double cy, double cz, double r, double h) : x(x), y(y), z(z), cx(cx), cy(cy), cz(cz), r(r), h(h) {}
//
//    // ���忽�����캯����������һ��Բ׶�����ʼ����ǰ����
//    Cone(const Cone& c) : x(c.x), y(c.y), z(c.z), cx(c.cx), cy(c.cy), cz(c.cz), r(c.r), h(c.h) {}
//
//    // ���忽����ֵ�����������һ��Բ׶�����ֵ������ǰ����
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
//    // �����ƶ����캯��������һ����ֵԲ׶�����ʼ����ǰ����
//    Cone(Cone&& c) noexcept : x(std::move(c.x)), y(std::move(c.y)), z(std::move(c.z)), cx(std::move(c.cx)), cy(std::move(c.cy)), cz(std::move(c.cz)), r(std::move(c.r)), h(std::move(c.h)) {}
//
//    // �����ƶ���ֵ���������һ����ֵԲ׶�����ֵ������ǰ����
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
//    // ���������������������κβ���
//    ~Cone() override {}
//
//    // �����ӡ���������Բ׶�Ķ������ꡢ����Բ�����ꡢ����뾶���ߺ����
//    void print() const override {
//        std::cout << "Cone: (" << x << ", " << y << ", " << z << ") to (" << cx << ", " << cy << ", " << cz << "), radius = " << r << ", height = " << h << ", volume = " << volume() << "\n";
//    }
//
//    // �������뺯�����ӱ�׼�����ȡԲ׶�Ķ������ꡢ����Բ�����ꡢ����뾶�͸�
//    void input() override {
//        std::cout << "Please enter the coordinates of the vertex and the center of the base circle, the radius of the base circle and the height of the cone: \n";
//        std::cin >> x >> y >> z >> cx >> cy >> cz >> r >> h;
//    }
//
//private:
//    // �����������ĺ��������ݵ���뾶�͸߼���Բ׶�����
//    double volume() const {
//        return 1.0 / 3.0 * 3.14 * r * r * h;
//    }
//
//    // �������ݳ�Ա����ʾԲ׶�Ķ������ꡢ����Բ�����ꡢ����뾶�͸�
//    double x, y, z, cx, cy, cz, r, h;
//};
//
//// ��main�����в���ͼ�λ�Ԫ�ļ̳���ϵ
//int main() {
//    // ����һ��ͼ�λ�Ԫ��ָ�����飬������Ų�ͬ���͵�ͼ�ζ���
//    Shape* shapes[5];
//
//    // ����һ���߶ζ��󣬲������ַ����������
//    Line l(1, 2, 3, 4);
//    shapes[0] = &l;
//
//    // ����һ��������󣬲������ַ����������
//    Square s(5, 6, 7);
//    shapes[1] = &s;
//
//    // ����һ��Բ���󣬲������ַ����������
//    Circle c(8, 9, 10);
//    shapes[2] = &c;
//
//    // ����һ������󣬲������ַ����������
//    Sphere sp(12, 13, 14, 15);
//    shapes[3] = &sp;
//
//    // ����һ��Բ׶���󣬲������ַ����������
//    Cone co(16, 17, 18, 19, 20, 21, 22, 23);
//    shapes[4] = &co;
//
//    // �������飬����ÿ��ͼ�ζ���Ĵ�ӡ���������ͼ�ε���Ϣ
//    for (int i = 0; i < 5; ++i) {
//        shapes[i]->print();
//    }
//
//    // �������飬����ÿ��ͼ�ζ�������뺯�����ӱ�׼�����ȡͼ�ε�����
//    for (int i = 0; i < 5; ++i) {
//        shapes[i]->input();
//    }
//
//    // �ٴα������飬����ÿ��ͼ�ζ���Ĵ�ӡ���������ͼ�ε���Ϣ
//    for (int i = 0; i < 5; ++i) {
//        shapes[i]->print();
//    }
//
//    return 0;
//}
//
//
