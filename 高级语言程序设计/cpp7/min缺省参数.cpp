/*2151974 软件 赵明泽*/
#include <iostream>
#include <limits>
using namespace std;

const int MAXNUM = 2147483647;

int min(int n, int a, int b, int c = MAXNUM, int d = MAXNUM)
{
	int tmp;

	if (n == 2)
	{
		tmp = a > b ? b : a;
	}
	else if (n == 3)
	{
		if (a > b)
		{
			if (b > c)
			{
				tmp = c;
			}
			else
			{
				tmp = b;
			}
		}
		else
		{
			if (a > c)
			{
				tmp = c;
			}
			else
			{
				tmp = a;
			}
		}
	}
	else
	{
		if (a < b)
		{
			if (a < c)
			{
				if (a < d)
				{
					tmp = a;
				}
				else
				{
					tmp = d;
				}
			}
			else
			{
				if (c < d)
				{
					tmp = c;
				}
				else
				{
					tmp = d;
				}
			}
		}
		else
		{
			if (b < c)
			{
				if (b < d)
				{
					tmp = b;
				}
				else
				{
					tmp = d;
				}
			}
			else
			{
				if (c < d)
				{
					tmp = c;
				}
				else
				{
					tmp = d;
				}
			}
		}
	}

	return tmp;
}

int main()
{
	int n;
	int a, b, c, d;
	int ans;

	while (1)
	{
		cout << "请输入个数num及num个正整数：" << endl;

		cin >> n;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore((std::numeric_limits< streamsize >::max)(), '\n');
			continue;
		}
		else if (n == 2 || n == 3 || n == 4)
		{
			if (n == 2)
			{
				cin >> a >> b;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore((std::numeric_limits< streamsize >::max)(), '\n');
					continue;
				}
				else if (a <= 0 || b <= 0)
				{
					cin.clear();
					cin.ignore();
					continue;
				}
				else
				{
					break;
				}
			}
			else if (n == 3)
			{
				cin >> a >> b >> c;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore((std::numeric_limits< streamsize >::max)(), '\n');
					continue;
				}
				else if (a <= 0 || b <= 0 || c <= 0)
				{
					cin.clear();
					cin.ignore();
					continue;
				}
				else
				{
					break;
				}
			}
			else
			{
				cin >> a >> b >> c >> d;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore((std::numeric_limits< streamsize >::max)(), '\n');
					continue;
				}
				else if (a <= 0 || b <= 0 || c <= 0 || d <= 0)
				{
					cin.clear();
					cin.ignore();
					continue;
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			cout << "个数输入错误" << endl;
			return 0;
		}
	}

	switch (n)
	{
		case 2:
			ans = min(2, a, b);
			break;
		case 3:
			ans = min(3, a, b, c);
			break;
		case 4:
			ans = min(4, a, b, c, d);
			break;
	}

	cout << "min=" << ans << endl;

	return 0;
}