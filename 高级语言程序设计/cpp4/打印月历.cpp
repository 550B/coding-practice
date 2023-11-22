/*2151974 软件 赵明泽*/
#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;
int main()
{
	//变量定义区
	int year, month, day;
	int maxFeb, num;
	int cnt = 0;

	//year&month输入和纠错区
	while (1)
	{
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> year >> month;
		if (cin.fail() || year < 2000 || year>2030 || month < 1 || month>12)
		{
			cin.clear();
			cin.ignore((std::numeric_limits< streamsize >::max)(), '\n');
			cout << "输入非法，请重新输入" << endl;
		}
		else
		{
			break;
		}
	}

	//day输入和纠错区
	while (1)
	{
		cout << "请输入" << year << "年" << month << "月1日的星期(0-6表示星期日-星期六) : ";
		cin >> day;
		if (cin.fail() || day < 0 || day>6)
		{
			cin.clear();
			cin.ignore((std::numeric_limits< streamsize >::max)(), '\n');
			cout << "输入非法，请重新输入" << endl;
		}
		else
		{
			break;
		}
	}

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
	cnt = day;
	cout << endl;
	cout << year << "年" << month << "月的月历为:" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
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

	return 0;
}