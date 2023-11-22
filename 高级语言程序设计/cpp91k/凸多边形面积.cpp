/*2151974 软件 赵明泽*/
#include <iostream>
using namespace std;

int judge(double s[][2], int num, double tt[])
{
	int sign = 0;
	double t1[2] = {};
	double t2[2] = {};
	double t[8] = {};

	for (int i = num - 1; i >= 0; i--)
	{
		if (i == num - 1)
		{
			t1[0] = s[0][0] - s[i][0];
			t1[1] = s[0][1] - s[i][1];
			t2[0] = s[i - 1][0] - s[i][0];
			t2[1] = s[i - 1][1] - s[i][1];
			t[i] = t1[0] * t2[1] - t2[0] * t1[1];
			tt[i] = s[i][0] * s[0][1] - s[0][0] * s[i][1];
		}
		else if (i == 0)
		{
			t1[0] = s[1][0] - s[0][0];
			t1[1] = s[1][1] - s[0][1];
			t2[0] = s[num - 1][0] - s[0][0];
			t2[1] = s[num - 1][1] - s[0][1];
			t[0] = t1[0] * t2[1] - t2[0] * t1[1];
			tt[0] = s[0][0] * s[1][1] - s[1][0] * s[0][1];
		}
		else if (i == 1)
		{
			t1[0] = s[2][0] - s[1][0];
			t1[1] = s[2][1] - s[1][1];
			t2[0] = s[0][0] - s[1][0];
			t2[1] = s[0][1] - s[1][1];
			t[1] = t1[0] * t2[1] - t2[0] * t1[1];
			tt[1] = s[1][0] * s[2][1] - s[2][0] * s[1][1];
		}
		else
		{
			t1[0] = s[i + 1][0] - s[i][0];
			t1[1] = s[i + 1][1] - s[i][1];
			t2[0] = s[i - 1][0] - s[i][0];
			t2[1] = s[i - 1][1] - s[i][1];
			t[i] = t1[0] * t2[1] - t2[0] * t1[1];
			tt[i] = s[i][0] * s[i + 1][1] - s[i + 1][0] * s[i][1];
		}
	}
	for (int i = 0; i < num - 1; i++)
	{
		if (i == 0)
		{
			if (t[num - 1] * t[i] < 0)
			{
				sign = 1;
				break;
			}
		}
		else
		{
			if (t[i] * t[i - 1] < 0)
			{
				sign = 1;
				break;
			}
		}

		if (t[i] == 0)
		{
			sign = 1;
			break;
		}
	}

	return sign;
}

double suan(double tt[], int num)
{
	double ans = 0;

	for (int i = 0; i < num; i++)
	{
		ans += tt[i];
	}
	ans *= 0.5;
	if (ans < 0)
	{
		ans = -ans;
	}

	return ans;
}

int main()
{
	int num;
	double s[8][2];
	double tt[8] = {};

	while (1)
	{
		cout << "请输入多边形的顶点数量(4-7)" << endl;
		cin >> num;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(9999, '\n');
			continue;
		}
		if (num < 4 || num>7)
		{
			continue;
		}
		break;
	}
	cout << "请按顺时针/逆时针方向输入" << num << "个顶点的x,y坐标：" << endl;
	for (int i = 0; i < num; i++)
	{
		cout << "请输入第" << i + 1 << "个顶点的坐标：" << endl;
		cin >> s[i][0] >> s[i][1];

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(9999, '\n');
			i--;
			continue;
		}
	}

	//judge(s, num, t);                      测试
	/*for (int i = 0; i < num + 1; i++)
	{
		cout << tt[i] << " ";
	}
	cout << endl;*/

	if (judge(s, num, tt))
	{
		cout << "不是凸" << num << "边形" << endl;
		return 0;
	}
	else
	{
		cout << "凸" << num << "边形的面积=" << suan(tt, num) << endl;
	}

	/*for (int i = 0; i < num + 1; i++)      测试
	{
		cout << tt[i] << " ";
	}*/

	return 0;
}