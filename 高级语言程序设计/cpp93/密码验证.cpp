/*2151974 软件 赵明泽*/
#include <iostream>
using namespace std;

/***************************************************************************
  函数名称：check
  功    能：检查数据和字符串
  输入参数：char c[],int len, int upper, int lower, int num, int els
  返 回 值：int
  说    明：
***************************************************************************/
int check(char c[], int len, int upper, int lower, int num, int els)
{
	static const char other[] = "!@#$%^&*-_=+,.?";
	int cnt = 0;
	int un = 0, ln = 0, nn = 0, en = 0;
	while (c[cnt] != '\0')
	{
		cnt++;
	}
	//cout << "KKKKKKKKKKKKKKKKKKKKKK" << cnt << endl;
	if (cnt != len)
	{
		cout << "错误" << endl;
		return 1;
	}
	for (int i = 0; i < len; i++)
	{
		if (c[i] >= 'A' && c[i] <= 'Z')
		{
			un++;
		}
		if (c[i] >= 'a' && c[i] <= 'z')
		{
			ln++;
		}
		if (c[i] >= '0' && c[i] <= '9')
		{
			nn++;
		}
		for (int j = 0; j < 15; j++)
		{
			if (c[i] == other[j])
			{
				en++;
			}
		}
	}
	if (un < upper || ln < lower || nn < num || en < els)
	{
		cout << "错误" << endl;
		return 1;
	}
	if ((un + ln + nn + en) != len)
	{
		cout << "错误" << endl;
		return 1;
	}
	return 0;
}

/***************************************************************************
  函数名称：read
  功    能：读取数据和字符串
  输入参数：void
  返 回 值：int
  说    明：
***************************************************************************/
int read()
{
	int len, upper, lower, num, els;
	while (getchar() != '\n');
	cin >> len >> upper >> lower >> num >> els;
	getchar();
	//cout << len << upper << lower << num << els;
	for (int i = 0; i < 10; i++)
	{
		char result[30];
		int cnt = 0;
		char t;
		while ((t = getchar()) != '\n')
		{
			result[cnt++] = t;
		}
		result[cnt] = '\0';
		//cout << "KKKKKKKKKKKKKKKKKKKKKKK" << cnt << endl;
		if (check(result, len, upper, lower, num, els))
		{
			return 1;
		}
		/*for (int j = 0; j < len; j++)
		{
			cout << result[j] << endl;
		}*/
	}
	return 0;
}

/***************************************************************************
  函数名称：main
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	if (read())
	{
		return 0;
	}
	cout << "正确" << endl;
	return 0;
}