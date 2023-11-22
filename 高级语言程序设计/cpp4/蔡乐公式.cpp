/*2151974 软件 赵明泽*/
#include <iostream>
#include <limits>
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

int main()
{
	int year, month, day;
	int maxFeb, num;

	while (1)
	{
		cout << "请输入年[1900-2100]、月、日：" << endl;
		cin >> year >> month >> day;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore((std::numeric_limits< streamsize >::max)(), '\n');
			cout << "输入错误，请重新输入" << endl;
			continue;
		}
		else if (year < 1900 || year > 2100)
		{
			cin.clear();
			cin.ignore((std::numeric_limits< streamsize >::max)(), '\n');
			cout << "年份不正确，请重新输入" << endl;
			continue;
		}
		else if (month < 1 || month > 12)
		{
			cin.clear();
			cin.ignore((std::numeric_limits< streamsize >::max)(), '\n');
			cout << "月份不正确，请重新输入" << endl;
			continue;
		}
		else
		{
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

			if (day<1 || day>num)
			{
				cin.clear();
				cin.ignore((std::numeric_limits< streamsize >::max)(), '\n');
				cout << "日不正确，请重新输入" << endl;
				continue;
			}
		}
		break;
	}

	switch (zeller(year, month, day))
	{
		case 0:
			cout << "星期日" << endl;
			break;
		case 1:
			cout << "星期一" << endl;
			break;
		case 2:
			cout << "星期二" << endl;
			break;
		case 3:
			cout << "星期三" << endl;
			break;
		case 4:
			cout << "星期四" << endl;
			break;
		case 5:
			cout << "星期五" << endl;
			break;
		case 6:
			cout << "星期六" << endl;
			break;
	}

	return 0;
}