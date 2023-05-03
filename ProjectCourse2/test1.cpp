//#include<string>
//#include<vector>
//#include<iostream>
//#include<cmath>
//#include<algorithm>
//
//using namespace std;
//
//int main() {
//	string str1;
//	string str2;
//	cin >> str1 >> str2;
//	reverse(str1.begin(), str1.end());
//	reverse(str2.begin(), str2.end());
//	string ans = "";
//	int n1 = str1.length();
//	int n2 = str2.length();
//	int flag = 0;
//	if (n1 < n2) {
//		for (int i = 0; i < n1; i++) {
//			ans += to_string((str1[i] - '0' + str2[i] - '0' + flag) % 10);
//			if (str1[i] - '0' + str2[i] - '0' + flag >= 10) {
//				flag = 1;
//			}
//			else {
//				flag = 0;
//			}
//		}
//		for (int i = n1; i < n2; i++) {
//			ans += to_string(((str2[i] - '0') + flag) % 10);
//			if ((str2[i] - '0') + flag >= 10) {
//				flag = 1;
//			}
//			else {
//				flag = 0;
//			}
//		}
//		if (flag == 1) {
//			ans += "1";
//		}
//	}
//	else if (n2 < n1) {
//		for (int i = 0; i < n2; i++) {
//			ans += to_string((str1[i] - '0' + str2[i] - '0' + flag) % 10);
//			if (str1[i] - '0' + str2[i] - '0' + flag >= 10) {
//				flag = 1;
//			}
//			else {
//				flag = 0;
//			}
//		}
//		for (int i = n2; i < n1; i++) {
//			ans += to_string(((str2[i] - '0') + flag) % 10);
//			if ((str2[i] - '0') + flag >= 10) {
//				flag = 1;
//			}
//			else {
//				flag = 0;
//			}
//		}
//		if (flag == 1) {
//			ans += "1";
//		}
//	}
//	else {
//		for (int i = 0; i < n1; i++) {
//			ans += to_string((str1[i] - '0' + str2[i] - '0' + flag) % 10);
//			if (str1[i] - '0' + str2[i] - '0' + flag >= 10) {
//				flag = 1;
//			}
//			else {
//				flag = 0;
//			}
//		}
//		if (flag == 1) {
//			ans += "1";
//		}
//	}
//
//	reverse(ans.begin(), ans.end());
//	cout << ans;
//	return 0;
//}