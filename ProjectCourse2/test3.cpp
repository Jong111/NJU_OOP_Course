//#include <iostream>
//#include <string>
//using namespace std;
//
//
//class String : public string { // 继承自std::string类
//public:
//    // 使用std::string类的构造函数
//    using string::string;
//
//    // 判断子串是否在当前字符串里
//    bool is_substring(const String& sub_str) {
//        if (this->find(sub_str) != string::npos) { // 如果找到子串
//            return true; // 返回true
//        }
//        else { // 如果没找到子串
//            return false; // 返回false
//        }
//    }
//
//    // 查找子串并替换，返回替换次数
//    int replace(const char* find, const char* replace) {
//        int count = 0; // 记录替换次数
//        size_t pos = this->find(find); // 查找第一个子串的位置
//        while (pos != string::npos) { // 如果找到子串
//            this->replace(pos, strlen(find), replace); // 替换子串
//            count++; // 增加替换次数
//            pos = this->find(find, pos + strlen(replace)); // 查找下一个子串的位置
//        }
//        return count; // 返回替换次数
//    }
//};