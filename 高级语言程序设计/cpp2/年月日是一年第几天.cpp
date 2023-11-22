/*2151974 软件 赵明泽*/
#include <iostream>

using namespace std;
int main()
{
	cout << "请输入年，月，日" << endl;

	int year, month, day;
	int maxFeb, num;

	cin >> year >> month >> day;


	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
	{
		maxFeb = 29;

	}
	else
	{
		maxFeb = 28;

	}

	switch (month)
	{
		case 1:
			if ((day <= 0) || (day > 31))
			{
				cout << "输入错误-日与月的关系非法" << endl;

			}
			else
			{
				num = day;
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << num << "天" << endl;

			}
			break;
		case 2:
			if ((day <= 0) || (day > maxFeb))
			{
				cout << "输入错误-日与月的关系非法" << endl;

			}
			else
			{
				num = 31 + day;
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << num << "天" << endl;

			}
			break;
		case 3:
			if ((day <= 0) || (day > 31))
			{
				cout << "输入错误-日与月的关系非法" << endl;

			}
			else
			{
				num = 31 + maxFeb + day;
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << num << "天" << endl;

			}
			break;
		case 4:
			if ((day <= 0) || (day > 30))
			{
				cout << "输入错误-日与月的关系非法" << endl;

			}
			else
			{
				num = 31 + maxFeb + 31 + day;
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << num << "天" << endl;

			}
			break;
		case 5:
			if ((day <= 0) || (day > 31))
			{
				cout << "输入错误-日与月的关系非法" << endl;

			}
			else
			{
				num = 31 + maxFeb + 31 + 30 + day;
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << num << "天" << endl;

			}
			break;
		case 6:
			if ((day <= 0) || (day > 30))
			{
				cout << "输入错误-日与月的关系非法" << endl;

			}
			else
			{
				num = 31 + maxFeb + 31 + 30 + 31 + day;
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << num << "天" << endl;

			}
			break;
		case 7:
			if ((day <= 0) || (day > 31))
			{
				cout << "输入错误-日与月的关系非法" << endl;

			}
			else
			{
				num = 31 + maxFeb + 31 + 30 + 31 + 30 + day;
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << num << "天" << endl;

			}
			break;
		case 8:
			if ((day <= 0) || (day > 31))
			{
				cout << "输入错误-日与月的关系非法" << endl;

			}
			else
			{
				num = 31 + maxFeb + 31 + 30 + 31 + 30 + 31 + day;
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << num << "天" << endl;

			}
			break;
		case 9:
			if ((day <= 0) || (day > 30))
			{
				cout << "输入错误-日与月的关系非法" << endl;

			}
			else
			{
				num = 31 + maxFeb + 31 + 30 + 31 + 30 + 31 + 31 + day;
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << num << "天" << endl;

			}
			break;
		case 10:
			if ((day <= 0) || (day > 31))
			{
				cout << "输入错误-日与月的关系非法" << endl;

			}
			else
			{
				num = 31 + maxFeb + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day;
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << num << "天" << endl;

			}
			break;
		case 11:
			if ((day <= 0) || (day > 30))
			{
				cout << "输入错误-日与月的关系非法" << endl;

			}
			else
			{
				num = 31 + maxFeb + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << num << "天" << endl;

			}
			break;
		case 12:
			if ((day <= 0) || (day > 31))
			{
				cout << "输入错误-日与月的关系非法" << endl;

			}
			else
			{
				num = 31 + maxFeb + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day;
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << num << "天" << endl;

			}
			break;

		default:
			cout << "输入错误-月份不正确" << endl;

	}

	return 0;

}