#include<iostream>

using namespace std;

int f(int n) {
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 1;
	}
	if (n % 2) {
		return f(n - 1) + f(n - 2);
	}
	else {
		return f(n - 1) + f(n - 2) + f(n - 3);
	}
}

int main() {
	cout << f(8) << endl;
	return 0;
}

