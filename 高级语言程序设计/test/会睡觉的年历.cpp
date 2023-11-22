#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;

int zeller(int y, int m, int d)
{
	int Year, Century, a, b, c, Week;

	if (m == 1 || m == 2)
	{
		y = y - 1;
		m += 12;
	}

	Year = y % 100;
	Century = y / 100;
	a = Year / 4;
	b = Century / 4;
	c = (m + 1) * 13 / 5;
	Week = Year + a + b + c - 2 * Century + d - 1;

	while (Week < 0)
	{
		Week += 7;
	}

	return Week % 7;
}

void printsmall(int t[], int y, int d[], int m)
{
	//设置左对齐和表头
	cout << setiosflags(ios::left);
	cout << "            ";
	cout << m << "月" << "                             ";
	cout << ++m << "月" << "                             ";
	cout << ++m << "月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat";
	cout << endl;

	//line1
	m -= 2;
	for (int i = zeller(y, m, 1); i > 0; i--)
	{
		cout << "    ";
	}
	for (int i = 7 - zeller(y, m, 1); i > 0; i--)
	{
		cout << setw(4) << ++t[m - 1];
		Sleep(50);
	}
	cout << "    ";
	m++;
	for (int i = zeller(y, m, 1); i > 0; i--)
	{
		cout << "    ";
	}
	for (int i = 7 - zeller(y, m, 1); i > 0; i--)
	{
		cout << setw(4) << ++t[m - 1];
		Sleep(50);
	}
	cout << "    ";
	m++;
	for (int i = zeller(y, m, 1); i > 0; i--)
	{
		cout << "    ";
	}
	for (int i = 7 - zeller(y, m, 1); i > 0; i--)
	{
		cout << setw(4) << ++t[m - 1];
		Sleep(50);
	}
	cout << endl;

	//line2,3,4,5
	for (int j = 4; j > 0; j--)
	{
		m -= 2;
		for (int i = 7; i > 0; i--)
		{
			cout << setw(4) << ++t[m - 1];
			Sleep(50);
			if (t[m - 1] == d[m - 1])
			{
				for (int k = 6 - zeller(y, m, d[m - 1]); k > 0; k--)
				{
					cout << "    ";
				}
				break;
			}
		}
		cout << "    ";
		m++;
		for (int i = 7; i > 0; i--)
		{
			cout << setw(4) << ++t[m - 1];
			Sleep(50);
			if (t[m - 1] == d[m - 1])
			{
				for (int k = 6 - zeller(y, m, d[m - 1]); k > 0; k--)
				{
					cout << "    ";
				}
				break;
			}
		}
		cout << "    ";
		m++;
		for (int i = 7; i > 0; i--)
		{
			cout << setw(4) << ++t[m - 1];
			Sleep(50);
			if (t[m - 1] == d[m - 1])
			{
				for (int k = 6 - zeller(y, m, d[m - 1]); k > 0; k--)
				{
					cout << "    ";
				}
				break;
			}
		}
		cout << endl;
	}
	cout << endl;
}

void print(int t[], int y, int d[])
{
	//闰年判断区
	if ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0))
	{
		d[1] = 29;
	}
	printsmall(t, y, d, 1);
	printsmall(t, y, d, 4);
	printsmall(t, y, d, 7);
	printsmall(t, y, d, 10);
}

int main()
{
	system("mode con cols=120 lines=45");

	int year;
	int t[14] = { 0 };
	int day[14] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	while (1)
	{
		cout << "请输入年份[1900-2100]" << endl;
		cin >> year;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(9999, '\n');
			continue;
		}
		if (year < 1900 || year > 2100)
		{
			continue;
		}
		break;
	}

	cout << year << "年的日历:" << endl << endl;
	print(t, year, day);

	system("pause");
	return 0;
}