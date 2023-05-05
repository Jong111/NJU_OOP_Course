//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	if (n <= 3) {
//		if (n == 0) {
//			cout << 1;
//		}
//		else if (n == 1) {
//			cout << 1;
//		}
//		else if (n == 2) {
//			cout << 2;
//		}
//		else if (n == 3) {
//			cout << 4;
//		}
//	}
//	else {
//		vector<int> dp(n + 1);
//		dp[0] = 1;
//		dp[1] = 1;
//		dp[2] = 2;
//		dp[3] = 3;
//		for (int i = 4; i <= n; i++) {
//			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
//		}
//		cout << dp[n];
//	}
//	return 0;
//}