#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"

int main()
{
	Date d1(2024, 3, 20);
	Date d2(2023, 3, 20);
	cout << d2 - d1 << endl;
	cout << d1 - d2 << endl;

	return 0;
}