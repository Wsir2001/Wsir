#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//using namespace std;
//
//class Date {
//public:
//	Date(int year = 0, int month = 1,int  day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void f1() const
//	{
//		cout << _year << "-" << _month << "-" << _day<<endl;
//	}
//
//private :
//	int _year;
//	int _month;
//	int _day;
//};
//void fun2(const Date& d)
//{
//	d.f1();
//}
//
//int main()
//{
//	Date d1(2020,10,11);
//	d1.f1();
//	fun2(d1);
//	return 0;
//}
//
//
//#include <iostream>
//using namespace std;
//
//class Date {
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day<<endl;
//	}
//private :
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2024, 3, 28);
//	d1.print();
//
//	Date d2(d1);
//	d2.print();
//	return 0;
//}
//
//#include <iostream>
//using namespace std;
//
//class Date {
//public:
//
//	int GetMonthDay(int year, int month)
//	{
//		static int MonthDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//		if (year >= 0 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)&&month ==2)
//		{
//			return 29;
//		}
//		return MonthDay[month];
//	}
//
//
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		if (year > 0 && month >= 1 && month <= 12 && day >= 1 && day <= GetMonthDay(year,month))
//		{
//			_year = year;
//			_month = month;
//			_day = day;
//
//		}
//		else
//		{
//			cout << "输入的日期错误" << endl;
//		}
//	}
//
//
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	bool operator==(const Date& d)
//	{
//		return _year == d._year &&
//			_month == d._month &&
//			_day == d._day;
//	}
//
//	bool operator<(const Date& d)
//	{
//		if (_year < d._year)
//			return true;
//		else
//			if (_year == d._year && _month < d._month)
//				return true;
//			else
//				if (_year == d._year && _month == d._month && _day < d._day)
//					return true;
//
//		return false;
//	}
//	bool operator>=(Date& d)
//	{
//		return !(*this < d);
//	}
//	bool operator<=(Date& d)
//	{
//		return *this == d || *this < d;
//	}
//	bool operator> (Date& d)
//	{
//		return !(*this == d || *this < d);
//	}
//	bool operator!= (Date& d)
//	{
//		return !(*this == d);
//	}
//	Date operator+(int n)
//	{
//		Date ret = *this;
//
//		ret._day += n;
//		while (ret._day > GetMonthDay(ret._year, ret._month))
//		{
//			ret._day -= GetMonthDay(ret._year, ret._month);
//			ret._month++;
//			if (ret._month == 13)
//			{
//				ret._year++;
//				ret._month = 1;
//			}
//		}
//		return ret;
//	}
//
//	Date& operator+=(int n)
//	{
//		this->_day += n;
//		while (this->_day > GetMonthDay(this->_year, this->_month))
//		{
//			this->_day -= GetMonthDay(this->_year, this->_month);
//			this->_month++;
//			if (this->_month == 13)
//			{
//				this->_year++;
//				this->_month = 1;
//			}
//		}
//		return *this;
//	}
//	Date operator++(int n)
//	{
//		Date temp(*this);
//		 *this += 1;
//		 return temp;
//	}
//	Date operator++()
//	{
//		return *this += 1;
//	}
//	//int  operator-(Date& d)
//	//{
//	//	int count = 0;
//	//	Date ret = d;
//	//	Date self = *this;
//	//	if (self >= ret)
//	//	{
//	//		
//	//			if (self._year == d._year && self._month == d._month)
//	//			{
//	//				return self._day - d._day;
//	//			}
//	//			else
//	//			{
//	//				count = self._day;
//	//				self._month--;
//	//				while (self._month != d._month&&_year!=d._year)
//	//				{
//	//					count += GetMonthDay(self._year, self._month);
//	//					self._month--;
//	//					if (self._month == 0)
//	//					{
//	//						self._year--;
//	//						self._month = 12;
//	//					}
//	//				}
//	//				count += (GetMonthDay(d._year, d._month) - d._day);
//	//				return count;
//	//			}
//	//	}
//
//	//}
//
//	Date& operator-=(int day)
//	{
//		_day -= day;
//		while (_day <= 0)
//		{
//			_month--;
//			if (_month == 0)
//			{
//				_year--;
//				_month = 12;
//			}
//			_day -= GetMonthDay(_year, _month);
//		}
//		return *this;
//		
//	}
//
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	/*Date d1(2024, 3, 28);
//	d1.print();
//
//	Date d2(2025,1,1);
//	d2.print();
//
//	Date d3 = d1 + 1000;
//	d3.print();
//
//	d1 += 1000;
//	d1.print();
//
//	d1 -= 10;
//	d1.print();*/
//
//	Date d1(2024, 4, 1);
//
//	Date d4 = d1++;
//	d4.print();
//	d1.print();
//
//	Date d5 = ++d1;
//	d5.print();
//	d1.print();
//	return 0;
//}
//
//#include <iostream>
//using namespace std;
//
//class Date {
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		cout << "Date(Date& d)" << endl;
//	}
//
//	Date& operator= (Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//private :
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2024, 3, 29);
//	Date d2(d1);//拷贝构造
//	
//
//
//	Date d3;
//	d3 = d1;//operator= 赋值符号的重载
//
//
//	return 0;
//}