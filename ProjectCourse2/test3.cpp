//#include <iostream>
//#include <string>
//using namespace std;
//
//
//class String : public string { // �̳���std::string��
//public:
//    // ʹ��std::string��Ĺ��캯��
//    using string::string;
//
//    // �ж��Ӵ��Ƿ��ڵ�ǰ�ַ�����
//    bool is_substring(const String& sub_str) {
//        if (this->find(sub_str) != string::npos) { // ����ҵ��Ӵ�
//            return true; // ����true
//        }
//        else { // ���û�ҵ��Ӵ�
//            return false; // ����false
//        }
//    }
//
//    // �����Ӵ����滻�������滻����
//    int replace(const char* find, const char* replace) {
//        int count = 0; // ��¼�滻����
//        size_t pos = this->find(find); // ���ҵ�һ���Ӵ���λ��
//        while (pos != string::npos) { // ����ҵ��Ӵ�
//            this->replace(pos, strlen(find), replace); // �滻�Ӵ�
//            count++; // �����滻����
//            pos = this->find(find, pos + strlen(replace)); // ������һ���Ӵ���λ��
//        }
//        return count; // �����滻����
//    }
//};