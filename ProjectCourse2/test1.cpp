#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

int main() {
	ifstream f;
	f.open("srcFile.txt", ios::in);
	if (!f) {
		cout << "Error: Failed to open the file" << endl;
		exit(-1);
	}
	vector<string> strs;
	while (!f.eof()) {
		string str;
		getline(f, str);
		strs.push_back(str);
	}

	ofstream of;
	of.open("destFile.txt", ios::out);
	if (!of) {
		cout << "Error: Failed to open the file" << endl;
		exit(-1);
	}
	// int tt = 0;
	for (int i = 0; i < strs.size(); i++) {
		of << strs[i] << endl;
	}
	of.close();
	return 0;
}