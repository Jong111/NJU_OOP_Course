#include<iostream>
#include<vector>

using namespace std;

int main() {
	double aQuarterPi = 0;
	int base = 0;
	while (1.0/(2*base+1)>=1e-8) {
		if (base % 2) {
			aQuarterPi += -1 * (1.0 / (2 * base + 1));
		}
		else {
			aQuarterPi += 1.0 / (2 * base + 1);
		}
		base++;
	}
	cout << aQuarterPi * 4;
	return 0;
}

