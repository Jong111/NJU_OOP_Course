#include<map>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	multimap<string, string> m;
	while (1) {
		string author;
		cout << "���������ߣ�����STOP�Խ������룺" << endl;
		getline(cin, author);
		// ��"STOP"��Ϊ��������ı�־
		if (author == "STOP") {
			break;
		}
		string book;
		cout << "����������Ʒ��" << endl;
		getline(cin, book);
		m.insert({ author, book });
	}
	string k;
	cout << "������Ҫɾ���ļ�ֵ�Եļ����������ڶ������Ҫ��ļ�����÷���ֻ��ɾ����һ��ƥ��ļ�ֵ�ԣ�" << endl;
	cin >> k;
	if (m.find(k) != m.end()) {
		m.erase(k);
	}
	else {
		cout << "�ü�������" << endl;
	}
	// ����Ԫ���Ѿ����ռ����ֵ���������������������ֱ���������
	for (auto it = m.begin(); it != m.end(); it++) {
		cout << "�����ǣ�" << it->first << "��ƷΪ��" << it->second << endl;
	}
	return 0;
}
