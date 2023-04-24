//#include<iostream>
//#include<string>
//
//using namespace std;
//
//class Time {
//public:
//	int h;
//	int m;
//	int s;
//	
//	Time(int h, int m, int s) {
//		this->h = h;
//		this->m = m;
//		this->s = s;
//	}
//
//	void set(int h, int m, int s) {
//		this->h = h;
//		this->m = m;
//		this->s = s;
//	}
//
//	void display() {
//		cout << h << "h " << m << "m " << s << "s " << endl;
//	}
//
//	bool equal(Time& other_time) {
//		if (other_time.h == this->h && other_time.m == this->m && other_time.s == this->s) {
//			return true;
//		}
//		return false;
//	}
//};
//
//int main() {
//	Time time(23, 56, 7);
//	time.display();
//	time.set(22, 34, 59);
//	time.display();
//	Time time2(22, 35, 36);
//	Time time3(22, 34, 59);
//	cout << time.equal(time2) << endl;
//	cout << time.equal(time3) << endl;
//	return 0;
//}
//
