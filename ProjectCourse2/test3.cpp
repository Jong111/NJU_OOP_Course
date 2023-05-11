//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <numeric>
//#include "Sales_item.h" 
//
//using namespace std;
//
//
//bool compareIsbn(const Sales_item& item1, const Sales_item& item2)
//{
//    return item1.isbn() < item2.isbn();
//}
//
//int main()
//{
//    vector<Sales_item> vec; 
//    Sales_item item; 
//    while (std::cin >> item) 
//    {
//        vec.push_back(item); 
//    }
//    sort(vec.begin(), vec.end(), compareIsbn); 
//    for (auto beg = vec.cbegin(), end = beg; beg != vec.cend(); beg = end) 
//    {
//        if (beg->isbn().empty()) break; // 如果ISBN为空，说明对象无效，跳出循环
//        end = find_if(beg, vec.cend(), [beg](const Sales_item& item) { return item.isbn() != beg->isbn(); }); 
//        cout << accumulate(beg, end, Sales_item(beg->isbn())) << endl; 
//    }
//
//    return 0;
//}

