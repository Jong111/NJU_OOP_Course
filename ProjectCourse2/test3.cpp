#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;


bool comp(pair<string, double> p1, pair<string, double> p2) {
	if (p1.second < p2.second) {
		return true;
	}
	else if (p1.second > p2.second) {
		return false;
	}
	else {
		return p1.first < p2.first;
	}
}


void counter(string fileName) {
	ifstream f;
	f.open(fileName, ios::in);
	if (!f) {
		cout << "Error: Failed to open the file" << endl;
		exit(-1);
	}
	
	int cnt = 0;
	vector<string> words;
	while (!f.eof()) {
		string str;
		f >> str;
		words.push_back(str);
		cnt++;
	}

	map<string, double> m;
	for (int i = 0; i < words.size(); i++) {
		if (m.count(words[i]) == 0) {
			m.insert(pair<string, double>(words[i], 1));
		}
		else {
			m[words[i]]++;
		}
	}

	for (map<string, double>::iterator it = m.begin(); it != m.end(); it++) {
		it->second = it->second / cnt;
	}
	vector<pair<string, double>>v2(m.begin(), m.end());
	sort(v2.begin(), v2.end(), comp);
	ofstream of;
	of.open("d:\\destTedFile.txt", ios::out);
	if (!of) {
		cout << "Error: Failed to open the file" << endl;
		exit(-1);
	}
	for (int i = 0; i < v2.size(); i++) {
		of << v2[i].first << " " << v2[i].second << endl;
	}
	of.close();
}

int main() {
	counter("d:\\ted.txt");
	return 0;
}
