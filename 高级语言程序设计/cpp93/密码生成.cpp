/*2151974 软件 赵明泽*/
#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;

/***************************************************************************
  函数名称：make_password
  功    能：生成密码
  输入参数：int len, int upper, int lower, int num, int els
  返 回 值：void
  说    明：
***************************************************************************/
void make_password(int len, int upper, int lower, int num, int els)
{
	static const char other[] = "!@#$%^&*-_=+,.?";
	int un = 0, ln = 0, nn = 0, en = 0;
	char result[17];
	int cnt = un + ln + nn + en;
	while (cnt != upper + lower + num + els)
	{
		switch (rand() % 4)
		{
			case 0:
				if (un < upper)
				{
					result[cnt] = 'A' + rand() % 26;
					un++;
				}
				break;
			case 1:
				if (ln < lower)
				{
					result[cnt] = 'a' + rand() % 26;
					ln++;
				}
				break;
			case 2:
				if (nn < num)
				{
					result[cnt] = '0' + rand() % 10;
					nn++;
				}
				break;
			default:
				if (en < els)
				{
					result[cnt] = other[rand() % 15];
					en++;
				}
				break;
		}
		cnt = un + ln + nn + en;
	}
	while (len - cnt)
	{
		switch (rand() % 4)
		{
			case 0:
				result[cnt] = 'A' + rand() % 26;
				break;
			case 1:
				result[cnt] = 'a' + rand() % 26;
				break;
			case 2:
				result[cnt] = '0' + rand() % 10;
				break;
			default:
				result[cnt] = other[rand() % 15];
				break;
		}
		cnt++;
	}
	result[cnt] = '\0';
	cout << result << endl;
}

/***************************************************************************
  函数名称：main
  功    能：调用函数
  输入参数：
  返 回 值：0
  说    明：
***************************************************************************/
int main()
{
	srand((unsigned int)(time(0)));
	int len, upper, lower, num, els;
	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	cin >> len >> upper >> lower >> num >> els;
	if (cin.fail())
	{
		cout << "输入非法" << endl;
		return 0;
	}
	if (len < 12 || len > 16)
	{
		cout << "密码长度[" << len << "]不正确" << endl;
		return 0;
	}
	if (upper < 2 || upper > len)
	{
		cout << "大写字母个数[" << upper << "]不正确" << endl;
		return 0;
	}
	if (lower < 2 || lower > len)
	{
		cout << "小写字母个数[" << lower << "]不正确" << endl;
		return 0;
	}
	if (num < 2 || num > len)
	{
		cout << "数字个数[" << num << "]不正确" << endl;
		return 0;
	}
	if (els < 2 || els > len)
	{
		cout << "其他符号个数[" << els << "]不正确" << endl;
		return 0;
	}
	if (upper + lower + num + els > len)
	{
		cout << "所有字符类型之和[" << upper << "+" << lower << "+" << num << "+" << els << "]大于总密码长度[" << len << "]" << endl;
		return 0;
	}
	cout << len << " " << upper << " " << lower << " " << num << " " << els << endl;
	for (int i = 0; i < 10; i++)
	{
		make_password(len, upper, lower, num, els);
	}
	
	return 0;
}