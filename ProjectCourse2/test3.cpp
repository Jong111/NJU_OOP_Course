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
//        if (string::find(sub_str) != string::npos) { // ����ҵ��Ӵ�
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
//            string::replace(pos, strlen(find), replace); // �滻�Ӵ�
//            count++; // �����滻����
//            pos = this->find(find, pos + strlen(replace)); // ������һ���Ӵ���λ��
//        }
//        return count; // �����滻����
//    }
//
//};
//
//int main() {
//    String s1("NJU CS");
//    cout << s1 << endl;
//
//    String s2(s1);
//    cout << s2 << endl;
//
//    String s3("NJU OOP");
//    cout << s3 << endl;
//
//    s3 = s1;
//    cout << endl;
//
//
//    String s5("NJU");
//    cout << s1.is_substring(s5) << endl;
//
//    String s6("");
//    cout << s1.is_substring(s6) << endl;
//
//    cout << s1.replace("NJU", "THU") << endl;
//    cout << s1 << endl;
//
//    cout << s2.replace("J", "K") << endl;
//    cout << s2;
//
//    cout << s3.replace("NJU", "Stanford") << endl;
//    // s3.print();
//
//    return 0;
//}