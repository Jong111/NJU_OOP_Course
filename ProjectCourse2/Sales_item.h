// ����һ��Sales_item�࣬��ʾһ��������ۼ�¼������ISBN���۳��������۳��۸��������

#include <iostream>
#include <string>

class Sales_item
{
    // ��Ԫ���������������������������ͼӷ������
    friend std::istream& operator>>(std::istream&, Sales_item&);
    friend std::ostream& operator<<(std::ostream&, const Sales_item&);
    friend Sales_item operator+(const Sales_item&, const Sales_item&);

public:
    // ���캯��������ʹ��Ĭ��ֵ����ָ��ֵ��ʼ������
    Sales_item() : bookNo(""), units_sold(0), revenue(0.0) {}
    Sales_item(const std::string& s) : bookNo(s), units_sold(0), revenue(0.0) {}
    Sales_item(const std::string& s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p* n) {}
    Sales_item(std::istream& is) { is >> *this; }

    // ��Ա���������ڻ�ȡ�����ISBN
    std::string isbn() const { return bookNo; }

    // ��Ա�������������ظ��ϸ�ֵ�����
    Sales_item& operator+=(const Sales_item&);

private:
    // ���ݳ�Ա����ʾ���ISBN���۳��������۳��۸��������
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};

// ��������������أ����ڴ��������ж�ȡSales_item���������
std::istream& operator>>(std::istream& is, Sales_item& item)
{
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    if (is) // ��������Ƿ���Ч
        item.revenue = price * item.units_sold;
    else // ���������Ч����������ΪĬ��״̬
        item = Sales_item();
    return is;
}

// �������������أ��������������д��Sales_item���������
std::ostream& operator<<(std::ostream& os, const Sales_item& item)
{
    os << item.isbn() << " " << item.units_sold << " "
        << item.revenue << " " << item.revenue / item.units_sold;
    return os;
}

// �ӷ�����������أ����ڽ�����Sales_item������ӣ�����һ���µĶ���
Sales_item operator+(const Sales_item& lhs, const Sales_item& rhs)
{
    Sales_item sum = lhs; // ����������
    sum += rhs;           // ʹ�ø��ϸ�ֵ��������Ҳ����ӵ�sum��
    return sum;           // ����sum
}

// ���ϸ�ֵ����������أ����ڽ�����Sales_item������ӣ������������������
Sales_item& Sales_item::operator+=(const Sales_item& rhs)
{
    units_sold += rhs.units_sold; // ���Ҳ������۳������ӵ���������
    revenue += rhs.revenue;       // ���Ҳ�����������ӵ���������
    return *this;                 // ���������������
};