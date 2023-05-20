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
		cout << "请输入作者，输入STOP以结束输入：" << endl;
		getline(cin, author);
		// 以"STOP"作为输入结束的标志
		if (author == "STOP") {
			break;
		}
		string book;
		cout << "请输入其作品：" << endl;
		getline(cin, book);
		m.insert({ author, book });
	}
	string k;
	cout << "请输入要删除的键值对的键：（若存在多个满足要求的键，则该方法只能删除第一个匹配的键值对）" << endl;
	cin >> k;
	if (m.find(k) != m.end()) {
		m.erase(k);
	}
	else {
		cout << "该键不存在" << endl;
	}
	// 由于元素已经按照键的字典序排序，因此无需额外排序，直接输出即可
	for (auto it = m.begin(); it != m.end(); it++) {
		cout << "作者是：" << it->first << "作品为：" << it->second << endl;
	}
	return 0;
}
