#pragma once
#include <string>

using namespace std;

struct Sales_data {
	string bookNo;
	string isbn;
	unsigned units_sold = 0;
	double revenue = 0.0;
};