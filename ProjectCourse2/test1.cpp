//#include <unordered_map>
//#include <set>
//#include <string>
//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <algorithm>
//using namespace std;
//
//
//void wordCounting() {
//    unordered_map<string, int> word_count;
//    while (1) {
//        string word;
//        cin >> word;
//        // ����"STOP"Ϊ��������ı�־
//        if (word == "STOP") {
//            break;
//        }
//        int tt = 0;
//        // Ϊ��������Сд���죬���ｫÿ�����ʶ�ȫ��תΪСд
//        transform(word.begin(), word.end(), word.begin(), ::tolower);
//        //Ϊ���������ʿ�ͷ���β�������Ĳ��죬��Ϊÿ������ȥ����ͷ���β�ı��
//        if (word[0] < 'a' || word[0] >'z') {
//            word.erase(0, 1);
//        }
//        if (word[word.length() - 1] < 'a' || word[word.length() - 1] >'z') {
//            word.erase(word.length() - 1, 1);
//        }
//        word_count[word]++;
//    }
//    for (const auto& w : word_count)
//        cout << w.first << " occurs " << w.second << (w.second > 1 ? "times" : "time") << endl;
//}
//
//
//int main() {
//    wordCounting();
//    return 0;
//}