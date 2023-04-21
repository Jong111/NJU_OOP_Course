//#include <iostream>
//#include <cstring>
//using namespace std;
//
//
//class String {
//private:
//    char* data; 
//    int length; 
//public:
//    String(const char* str) {
//        if (str == nullptr) { 
//            data = new char[1];
//            data[0] = '\0';
//            length = 0;
//        }
//        else { 
//            length = strlen(str);
//            data = new char[length + 1];
//            strcpy(data, str);
//        }
//    }
//
//
//    String(const String& other) {
//        length = other.length;
//        data = new char[length + 1];
//        strcpy(data, other.data);
//    }
//
//  
//    ~String() {
//        delete[] data;
//    }
//
//    
//    String& operator=(const String& other) {
//        if (this != &other) { 
//            delete[] data; 
//            length = other.length;
//            data = new char[length + 1];
//            strcpy(data, other.data);
//        }
//        return *this;
//    }
//
//    
//    bool is_substring(const String& sub_str) {
//        if (sub_str.length > length) return false; 
//        for (int i = 0; i <= length - sub_str.length; i++) { 
//            bool match = true; 
//            for (int j = 0; j < sub_str.length; j++) { 
//                if (data[i + j] != sub_str.data[j]) { 
//                    match = false;
//                    break;
//                }
//            }
//            if (match) return true; 
//        }
//        return false; 
//    }
//
//
//    int replace(const char* find, const char* replace) {
//        int new_length = length;
//        if (find == nullptr || replace == nullptr) return 0; 
//        int find_len = strlen(find); 
//        int replace_len = strlen(replace); 
//        if (find_len == 0 || find_len > length) return 0; 
//
//        int count = 0; 
//        char* new_data = nullptr; 
//
//        if (find_len == replace_len) { 
//            new_data = new char[length + 1]; 
//            strcpy(new_data, data);
//            for (int i = 0; i <= length - find_len; i++) { 
//                bool match = true; 
//                for (int j = 0; j < find_len; j++) { 
//                    if (new_data[i + j] != find[j]) { 
//                        match = false; 
//                        break;
//                    }
//                    if (match) { 
//                        for (int j = 0; j < replace_len; j++) {
//                            new_data[i + j] = replace[j];
//                        }
//                        count++;
//                    }
//                }
//            }
//        }
//        else { 
//            
//            for (int i = 0; i <= length - find_len; i++) { 
//                bool match = true;
//                for (int j = 0; j < find_len; j++) { 
//                    if (data[i + j] != find[j]) { 
//                        match = false;
//                        break;
//                    }
//                }
//                if (match) { 
//                    new_length += replace_len - find_len;
//                    count++;
//                }
//            }
//            if (count == 0) return 0; 
//            new_data = new char[new_length + 1]; 
//            int index = 0; 
//            for (int i = 0; i < length;) { 
//                bool match = true; 
//                for (int j = 0; j < find_len; j++) { 
//                    if (data[i + j] != find[j]) { 
//                        match = false;
//                        break;
//                    }
//                }
//                if (match) { 
//                    for (int j = 0; j < replace_len; j++) {
//                        new_data[index++] = replace[j];
//                    }
//                    i += find_len;
//                }
//                else { 
//                    new_data[index++] = data[i++];
//                }
//            }
//            new_data[index] = '\0'; 
//            new_length = index; 
//        }
//
//        delete[] data; 
//        data = new_data; 
//        length = new_length; 
//        return count; 
//        }
//
//        
//        void print() {
//            cout << data << endl;
//        }
//    };
//
//    
//int main() {
//    String s1("NJU CS"); 
//    s1.print(); 
//
//    String s2(s1); 
//    s2.print(); 
//
//    String s3("NJU OOP"); 
//    s3.print(); 
//
//    s3 = s1; 
//    s3.print(); 
//
//
//    String s5("NJU"); 
//    cout << s1.is_substring(s5) << endl; 
//
//    String s6(""); 
//    cout << s1.is_substring(s6) << endl; 
//
//    cout << s1.replace("NJU", "THU") << endl; 
//    s1.print(); 
//
//    cout << s2.replace("J", "K") << endl; 
//    s2.print(); 
//
//    cout << s3.replace("NJU", "Stanford") << endl; 
//    s3.print(); 
//
//    return 0;
//}