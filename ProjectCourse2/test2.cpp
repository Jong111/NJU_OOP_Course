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
//void wordTransformation() {
//    ifstream ifs_map("in.txt"), ifs_content("in2.txt");
//    if (!ifs_map || !ifs_content) {
//        cerr << "can't find the documents." << std::endl;
//        return;
//    }
//    unordered_map<string, string> trans_map;
//    for (string key, value; ifs_map >> key && getline(ifs_map, value); )
//        if (value.size() > 1) trans_map[key] =
//            value.substr(1).substr(0, value.find_last_not_of(' '));
//    for (string text, word; getline(ifs_content, text);
//        cout << endl)
//        for (istringstream iss(text); iss >> word; ) {
//            auto map_it = trans_map.find(word);
//            cout << (map_it == trans_map.cend() ?
//                word : map_it->second) << " ";
//        }
//}
//
//int main() {
//    wordTransformation();
//}