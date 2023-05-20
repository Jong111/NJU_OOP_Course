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
//        // 定义"STOP"为结束输入的标志
//        if (word == "STOP") {
//            break;
//        }
//        int tt = 0;
//        // 为了消除大小写差异，这里将每个单词都全部转为小写
//        transform(word.begin(), word.end(), word.begin(), ::tolower);
//        //为了消除单词开头或结尾标点带来的差异，先为每个单词去除开头或结尾的标点
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