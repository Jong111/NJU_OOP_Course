//#include<iostream>
//#include <cassert>
//
//using namespace std;
//
//int ack(int m, int n) {
//	assert(m >= 0 && n >= 0);
//	if (m == 0) {
//		return n + 1;
//	}
//	if (n == 0) {
//		return ack(m - 1, 1);
//	}
//	return ack(m - 1, ack(m, n - 1));
//}
//
//
//int main() {
//	cout << ack(2, 2) << endl;
// return 0;
//}