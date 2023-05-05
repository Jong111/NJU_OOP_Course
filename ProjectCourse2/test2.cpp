//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	if (n < 2) {
//		cout << 1 << endl;
//	}
//	else {
//		vector<int> dp(n + 1);
//		dp[0] = 1;
//		dp[1] = 1;
//		for (int i = 2; i <= n; i++) {
//			if (i % 2 == 0) {
//				dp[i] = dp[i - 1] + dp[i - 2];
//			}
//			else {
//				dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
//			}
//		}
//		cout << dp[n];
//	}
//	return 0;
//}