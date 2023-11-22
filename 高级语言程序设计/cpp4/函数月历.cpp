/*2151974 软件 赵明泽*/
#include <iostream>
#include <limits>
#include <iomanip>
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

void calendar(int year, int month, int day)
{
	int maxFeb, num;

	//闰年判断区
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
	{
		maxFeb = 29;
	}
	else
	{
		maxFeb = 28;
	}

	//月份赋值区
	switch (month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			num = 31;
			break;
		case 2:
			num = maxFeb;
			break;
		default:
			num = 30;
			break;
	}

	//输出区
	int cnt = 0;
	cnt = day;
	cout << endl;
	cout << year << "年" << month << "月" << endl;
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;
	for (int j = cnt; j > 0; j--)
	{
		cout << "        ";
	}
	for (int i = 1; i <= num; i++)
	{
		cout << setw(4) << setiosflags(ios::right) << i;
		cnt++;
		if (cnt == 7)
		{
			cout << "    ";
			cout << endl;
			cnt = 0;
		}
		else
		{
			cout << "    ";
		}
	}
	cout << endl;
	cout << endl;
}

int main()
{
	int Year, Month;

	while (1)
	{
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> Year >> Month;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore((std::numeric_limits< streamsize >::max)(), '\n');
			cout << "输入错误，请重新输入" << endl;
			continue;
		}
		else if (Year < 1900 || Year > 2100)
		{
			cin.clear();
			cin.ignore((std::numeric_limits< streamsize >::max)(), '\n');
			cout << "年份不正确，请重新输入" << endl;
			continue;
		}
		else if (Month < 1 || Month > 12)
		{
			cin.clear();
			cin.ignore((std::numeric_limits< streamsize >::max)(), '\n');
			cout << "月份不正确，请重新输入" << endl;
			continue;
		}
		break;
	}
	
	calendar(Year, Month, zeller(Year, Month, 1));

	return 0;
}









