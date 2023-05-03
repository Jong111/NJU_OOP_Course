//#include<iostream>
//#include<vector>
//#include<string>
//
//using namespace std;
//
//typedef struct {
//	int num;
//	int currIdx;
//	int alive;
//}ppl;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	int aliveNum = n;
//	int num = 0;
//	int idx = 1;
//	int lastDead = -1;
//	vector<ppl> v(n);
//	for (int i = 0; i < n; i++) {
//		v[i].num = i;
//		v[i].alive = 1;
//	}
//	while (aliveNum >= 2) {
//		if (v[num].alive == 0) {
//			num = (num + 1) % n;
//			continue;
//		}
//		if (idx == m) {
//			v[num].alive = 0;
//			lastDead = num;
//			num = (lastDead + 1) % n;
//			idx = 1;
//			aliveNum--;
//		}
//		else {
//			v[num].currIdx = idx;
//			idx++;
//			num = (num + 1) % n;
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		if (v[i].alive == 1) {
//			cout << v[i].num + 1 << endl;
//		}
//	}
//	return 0;
//}