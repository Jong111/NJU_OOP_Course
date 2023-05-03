//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//
//class My_date {
//private:
//	unsigned year, month, day;
//public:
//	My_date(const string& s) {
//		unsigned tag;
//		unsigned format;
//		format = 0;
//		tag = 0;
//		// 1/1/1900
//		if (s.find_first_of("/") != string::npos)
//		{
//			format = 0x01;
//		}
//		// January 1, 1900 or Jan 1, 1900
//		else if ((s.find_first_of(',') >= 4) && s.find_first_of(',') != string::npos) {
//			format = 0x10;
//			tag = 1;
//		}
//		// Jan 1 1900
//		else if (s.find_first_of(' ') >= 3 && s.find_first_of(' ') != string::npos) { 
//			format = 0x10;
//		}
//		// 1月1日1990年
//		else if (s.find_first_of("年月日") != string::npos)
//		{
//			format = 0x11;
//		}
//		switch (format) {
//		case 0x01:
//			day = stoi(s.substr(0, s.find_first_of("/")));
//			month = stoi(s.substr(s.find_first_of("/") + 1, s.find_last_of("/") - s.find_first_of("/") - 1 ));
//			year = stoi(s.substr(s.find_last_of("/") + 1, 4));
//		break;
//		case 0x10:
//			if (s.find("Jan") < s.size()) month = 1;
//			if (s.find("Feb") < s.size()) month = 2;
//			if (s.find("Mar") < s.size()) month = 3;
//			if (s.find("Apr") < s.size()) month = 4;
//			if (s.find("May") < s.size()) month = 5;
//			if (s.find("Jun") < s.size()) month = 6;
//			if (s.find("Jul") < s.size()) month = 7;
//			if (s.find("Aug") < s.size()) month = 8;
//			if (s.find("Sep") < s.size()) month = 9;
//			if (s.find("Oct") < s.size()) month = 10;
//			if (s.find("Nov") < s.size()) month = 11;
//			if (s.find("Dec") < s.size()) month = 12;
//			if (tag == 1) {
//				day = stoi(s.substr(s.find_first_of("123456789"), s.find_last_of(',') - s.find_first_of("123456789")));
//			}
//			else {
//				day = stoi(s.substr(s.find_first_of("123456789"), s.find_last_of(' ') - s.find_first_of("123456789")));
//			}
//			year = stoi(s.substr(s.find_last_of(' ') + 1, 4));
//		break;
//		case 0x11:
//			day = stoi(s.substr(s.find_first_of("月") + 2, s.find_first_of("日") - s.find_first_of("月") - 2));
//			month = stoi(s.substr(0, s.find_first_of("月")));
//			year = stoi(s.substr(s.find_first_of("日") + 2, 4));
//		break;
//		}
//	}
//	void print() {
//		cout << "day:" << day << " " << "month: " << month << " " << "year: " << year << endl;
//	}
//};
//int main() {
//	My_date d("Jan 1 1900");
//	My_date d2("1/2/1901");
//	My_date d3("2月25日2000年");
//	d.print();
//	d2.print();
//	d3.print();
//	return 0;
//}