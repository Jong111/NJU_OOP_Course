//#include<iostream>
//#include<map>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> v(n);
//	for (int i = 0; i < n; i++) {
//		int temp;
//		cin >> temp;
//		v[i] = temp;
//	}
//	int x;
//	cin >> x;
//	map<int, int> m;
//	for (int i = 0; i < n; i++) {
//		if (m.count(v[i]) == 0) {
//			m.insert(pair<int, int>(v[i], i));
//		}
//		else {
//			m[v[i]] = i;
//		}
//	}
//	vector<int> res(2);
//	for (int i = 0; i < n; i++) {
//		if (m.count(x - v[i]) != 0 && m[x - v[i]] != i) {
//			res[0] = i;
//			res[1] = m[x - v[i]];
//		}
//	}
//	sort(res.begin(), res.end());
//	for (int i = 0; i < 2; i++) {
//		cout << res[i] << " ";
//	}
//	return 0;
//}