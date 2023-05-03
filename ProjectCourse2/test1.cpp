//#include<iostream>
//#include<string>
//#include<fstream>
//#include<vector>
//#include<map>
//#include<algorithm>
//
//using namespace std;
//
//
//// Judge if value s1 is less than value s2
//bool comp(string s1, string s2) {
//	if (s1.length() < s2.length()) {
//		return true;
//	}
//	else if (s1.length() > s2.length()) {
//		return false;
//	}
//	else {
//		return s1 < s2;
//	}
//}
//
//
//void counter(string fileName) {
//	ifstream f;
//	f.open(fileName, ios::in);
//	if (!f) {
//		cout << "Error: Failed to open the file" << endl;
//		exit(-1);
//	}
//	
//	vector<pair<string, string>> datas;
//	int idx = 0;
//	while (!f.eof()) {
//		string data;
//		f >> data;
//		if (idx == 0) {
//			pair<string, string> p(data, "-1");
//			datas.push_back(p);
//		}
//		else if (idx == 7) {
//			datas[datas.size() - 1].second = data;
//			idx = 0;
//			continue;
//		}
//		idx++;
//	}
//	int tt = 0;
//	
//	vector<string> indexes;
//	vector<string> dates;
//	for (int i = 239; i < datas.size(); i += 240) {
//		indexes.push_back(datas[i].second);
//		dates.push_back(datas[i].first);
//	}
//
//	int maxUp = -1;
//	int maxDown = -1;
//	int l1 = 0; 
//	int r1 = 1;
//	int l2 = 0;
//	int r2 = 1;
//	int lres1 = 0;
//	int rres1 = 1;
//	int lres2 = 0;
//	int rres2 = 1;
//	while (r1 < indexes.size()) {
//		if (comp(indexes[r1 - 1], indexes[r1])) {
//			if (r1 - l1 > maxUp) {
//				maxUp = r1 - l1;
//				lres1 = l1;
//				rres1 = r1;
//			}
//		}
//		else {
//			l1 = r1;
//		}
//		r1++;
//	}
//	while (r2 < indexes.size()) {
//		if (comp(indexes[r2], indexes[r2 - 1])) {
//			if (r2 - l2 > maxDown) {
//				maxDown = r2 - l2;
//				lres2 = l2;
//				rres2 = r2;
//			}
//		}
//		else {
//			l2 = r2;
//		}
//		r2++;
//	}
//	// cout << "最多连续上涨天数：" << maxUp << " " << "最多连续下跌天数：" << maxDown << endl;
//	cout << "最多连续上涨区间为从" << dates[lres1] << "到" << dates[rres1] << endl;
//	cout << "最多连续下跌区间为从" << dates[lres2] << "到" << dates[rres2] << endl;
//}
//
//int main() {
//	counter("SZZS.csv");
//	return 0;
//}
