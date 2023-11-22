/*2151974 软件 赵明泽*/
#include <iostream>
#include <limits>
using namespace std;

int max(int a, int b, int c, int d)
{
	int tmp;

	if (a > b)
	{
		if (a > c)
		{
			if (a > d)
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
			if (c > d)
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
		if (b > c)
		{
			if (b > d)
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
			if (c > d)
			{
				tmp = c;
			}
			else
			{
				tmp = d;
			}
		}
	}

	return tmp;
}

int max(int a, int b, int c)
{
	int tmp;

	if (a > b)
	{
		if (a > c)
		{
			tmp = a;
		}
		else
		{
			tmp = c;
		}
	}
	else
	{
		if (b > c)
		{
			tmp = b;
		}
		else
		{
			tmp = c;
		}
	}

	return tmp;
}

int max(int a, int b)
{
	return a > b ? a : b;
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
			ans = max(a, b);
			break;
		case 3:
			ans = max(a, b, c);
			break;
		case 4:
			ans = max(a, b, c, d);
			break;
	}

	cout << "max=" << ans << endl;

	return 0;
}