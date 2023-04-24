//#include<iostream>
//#include<string>
//#include<fstream>
//#include<vector>
//#include<map>
//
//using namespace std;
//
//void counter(char c, string fileName) {
//	ifstream f;
//	f.open(fileName, ios::in);
//	if (!f) {
//		cout << "Error: Failed to open the file" << endl;
//		exit(-1);
//	}
//
//	vector<string> strs;
//	while (!f.eof()) {
//		string str;
//		getline(f, str);
//		strs.push_back(str);
//	}
//
//	map<char, vector<pair<int, string>>> m;
//	for (int i = 0; i < strs.size(); i++) {
//		for (int j = 0; j < strs[i].length(); j++) {
//			if (m.count(strs[i][j]) == 0) {
//				vector<pair<int, string>> temp;
//				pair<int, string> p ( 1, "第" + to_string(i + 1) + "行，第" + to_string(j + 1) + "列" );
//				temp.push_back(p);
//				m.insert(pair<char, vector<pair<int, string>>>(strs[i][j], temp));
//			}
//			else {
//				pair<int, string> p2(m[strs[i][j]][m[strs[i][j]].size() - 1].first + 1, "第" + to_string(i + 1) + "行，第" + to_string(j + 1) + "列");
//				m[strs[i][j]].push_back(p2);
//			}
//		}
//	}
//	if (m.count(c) == 0) {
//		cout << "文本中不包含该字符" << endl;
//	}
//	else {
//		for (int i = 0; i < m[c].size(); i++) {
//			cout << m[c][i].first << " " << m[c][i].second << endl;
//		}
//	}
//}
//
//int main() {
//	char c;
//	cin >> c;
//	counter(c, "d:\\srcFile.txt");
//	return 0;
//}
