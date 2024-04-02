#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}
bool Date::operator==(const Date& d)
{
	return _year == d._year &&
		_month == d._month &&
		_day == d._day;
}
void Date::print() const
	{
		cout << _year << "-" << _month << "-" << _day<<endl;
	}
Date Date:: operator++(int n)
{
	Date temp(*this);
	*this += 1;
	return temp;
}
Date& Date::operator+=(int n)
{
	this->_day += n;
	while (this->_day > GetMonthDay(this->_year, this->_month))
	{
		this->_day -= GetMonthDay(this->_year, this->_month);
		this->_month++;
		if (this->_month == 13)
		{
			this->_year++;
			this->_month = 1;
		}
	}
	return *this;
}
bool Date::operator!= (Date& d)
{
	return !(*this == d);
}
int Date::GetMonthDay(int year, int month)
{
	static int MonthDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (year >= 0 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month == 2)
	{
		return 29;
	}
	return MonthDay[month];
}
bool Date::operator<(const Date& d)
{
	if (_year < d._year)
		return true;
	else
		if (_year == d._year && _month < d._month)
			return true;
		else
			if (_year == d._year && _month == d._month && _day < d._day)
				return true;

	return false;
}
int  Date::operator-(Date& d)
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (max!=min)
	{
		min++;
		n++;
	}
	return n*flag;
}
