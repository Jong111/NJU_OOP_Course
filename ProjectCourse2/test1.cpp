//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//
// 用于判断i是否是水仙花数，若是则返回1，否则返回0
//int resNum(int i) {
//	int n = i;
//	int ans = 0;
//	int tmp[3];
//	int j = 0;
//	while (i) {
//		tmp[j] = i % 10;
//		i /= 10;
//		j++;
//	}
//	if (tmp[0] * tmp[0] * tmp[0] + tmp[1] * tmp[1] * tmp[1] + tmp[2] * tmp[2] * tmp[2] == n) {
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}
//
//
//int main() {
//	for (int i = 100; i <= 999; i++) {
//		if (resNum(i)) {
//			cout << i << endl;
//		}
//	}
//	return 0;
//}