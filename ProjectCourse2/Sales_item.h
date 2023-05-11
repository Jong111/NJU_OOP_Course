// 定义一个Sales_item类，表示一本书的销售记录，包括ISBN、售出数量、售出价格和总收入

#include <iostream>
#include <string>

class Sales_item
{
    // 友元函数，用于重载输入输出运算符和加法运算符
    friend std::istream& operator>>(std::istream&, Sales_item&);
    friend std::ostream& operator<<(std::ostream&, const Sales_item&);
    friend Sales_item operator+(const Sales_item&, const Sales_item&);

public:
    // 构造函数，可以使用默认值或者指定值初始化对象
    Sales_item() : bookNo(""), units_sold(0), revenue(0.0) {}
    Sales_item(const std::string& s) : bookNo(s), units_sold(0), revenue(0.0) {}
    Sales_item(const std::string& s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p* n) {}
    Sales_item(std::istream& is) { is >> *this; }

    // 成员函数，用于获取对象的ISBN
    std::string isbn() const { return bookNo; }

    // 成员函数，用于重载复合赋值运算符
    Sales_item& operator+=(const Sales_item&);

private:
    // 数据成员，表示书的ISBN、售出数量、售出价格和总收入
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};

// 输入运算符的重载，用于从输入流中读取Sales_item对象的数据
std::istream& operator>>(std::istream& is, Sales_item& item)
{
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    if (is) // 检查输入是否有效
        item.revenue = price * item.units_sold;
    else // 如果输入无效，将对象置为默认状态
        item = Sales_item();
    return is;
}

// 输出运算符的重载，用于向输出流中写入Sales_item对象的数据
std::ostream& operator<<(std::ostream& os, const Sales_item& item)
{
    os << item.isbn() << " " << item.units_sold << " "
        << item.revenue << " " << item.revenue / item.units_sold;
    return os;
}

// 加法运算符的重载，用于将两个Sales_item对象相加，返回一个新的对象
Sales_item operator+(const Sales_item& lhs, const Sales_item& rhs)
{
    Sales_item sum = lhs; // 复制左侧对象
    sum += rhs;           // 使用复合赋值运算符将右侧对象加到sum上
    return sum;           // 返回sum
}

// 复合赋值运算符的重载，用于将两个Sales_item对象相加，并将结果赋给左侧对象
Sales_item& Sales_item::operator+=(const Sales_item& rhs)
{
    units_sold += rhs.units_sold; // 将右侧对象的售出数量加到左侧对象上
    revenue += rhs.revenue;       // 将右侧对象的总收入加到左侧对象上
    return *this;                 // 返回左侧对象的引用
};