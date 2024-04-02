#pragma once

#include <iostream>
using namespace std;

class Date {

public:
	Date(int year = 0, int month = 1, int day = 1) ;
	Date(const Date& d) ;
	void print() const; 
	int  operator-(Date& d);
	Date operator++(int n);
	Date& operator+=(int n);
	bool operator!= (Date& d);
	bool operator==(const Date& d);
	int GetMonthDay(int year, int month);
	bool operator<(const Date& d);
private:
	int _year;
	int _month;
	int _day;
};
