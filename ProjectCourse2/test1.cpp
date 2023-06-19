//#include <iostream>
//#include <string>
//
//class Quote {
//public:
//    Quote() { std::cout << "Quote default constructor\n"; }
//    Quote(const std::string& book, double sales_price) : bookNo(book), price(sales_price) { std::cout << "Quote constructor\n"; }
//    // 拷贝构造
//    Quote(const Quote& q) : bookNo(q.bookNo), price(q.price) { std::cout << "Quote copy constructor\n"; }
//    // 移动构造
//    Quote(Quote&& q) noexcept : bookNo(std::move(q.bookNo)), price(std::move(q.price)) { std::cout << "Quote move constructor\n"; }
//    // 拷贝赋值
//    Quote& operator=(const Quote& rhs) {
//        std::cout << "Quote copy assignment operator\n";
//        if (this != &rhs) {
//            bookNo = rhs.bookNo;
//            price = rhs.price;
//        }
//        return *this;
//    }
//    // 移动赋值
//    Quote& operator=(Quote&& rhs) noexcept {
//        std::cout << "Quote move assignment operator\n";
//        if (this != &rhs) {
//            bookNo = std::move(rhs.bookNo);
//            price = std::move(rhs.price);
//        }
//        return *this;
//    }
//    virtual ~Quote() { std::cout << "Quote destructor\n"; }
//
//    std::string isbn() const { return bookNo; }
//    virtual double net_price(std::size_t n) const { return n * price; }
//
//private:
//    std::string bookNo;
//
//protected:
//    double price = 0.0;
//};
//
//class Bulk_quote : public Quote {
//public:
//    Bulk_quote() { std::cout << "Bulk_quote default constructor\n"; }
//    Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) : Quote(book, p), min_qty(qty), discount(disc) {
//        std::cout << "Bulk_quote constructor\n"; }
//    // 拷贝构造
//    Bulk_quote(const Bulk_quote& bq) : Quote(bq), min_qty(bq.min_qty), discount(bq.discount) { std::cout << "Bulk_quote copy constructor\n"; }
//    // 移动构造
//    Bulk_quote(Bulk_quote&& bq) noexcept : Quote(std::move(bq)), min_qty(std::move(bq.min_qty)), discount(std::move(bq.discount)) { 
//        std::cout << "Bulk_quote move constructor\n"; }
//    // 拷贝赋值
//    Bulk_quote& operator=(const Bulk_quote& rhs) {
//        std::cout << "Bulk_quote copy assignment operator\n";
//        Quote::operator=(rhs);
//        min_qty = rhs.min_qty;
//        discount = rhs.discount;
//        return *this;
//    }
//    // 移动赋值
//    Bulk_quote& operator=(Bulk_quote&& rhs) noexcept {
//        std::cout << "Bulk_quote move assignment operator\n";
//        Quote::operator=(std::move(rhs));
//        min_qty = std::move(rhs.min_qty);
//        discount = std::move(rhs.discount);
//        return *this;
//    }
//    ~Bulk_quote() override { std::cout << "Bulk_quote destructor\n"; }
//
//    double net_price(std::size_t n) const override;
//
//private:
//    std::size_t min_qty = 0;
//    double discount = 0.0;
//};
//
//double Bulk_quote::net_price(std::size_t n) const {
//    if (n >= min_qty)
//        return n * (1 - discount) * price;
//    else
//        return n * price;
//}
//
//int main() {
//    // Test code
//    Quote q1("C++ Primer", 89.99);
//    Quote q2(q1);
//    Quote q3(std::move(q1));
//    q1 = q2;
//    q2 = std::move(q3);
//
//    Bulk_quote bq1("Effective C++", 39.99, 5, 0.2);
//    Bulk_quote bq2(bq1);
//    Bulk_quote bq3(std::move(bq1));
//    bq1 = bq2;
//    bq2 = std::move(bq3);
//
//}
