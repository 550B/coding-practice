/*2151974 软件 赵明泽*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
int main()
{
	int x;
	double tmp, sum = 1;

	while (true)
	{
		cout << "请输入x的值[-10 ~ +65]" << endl;
		cin >> x;
		tmp = 1;

		if (x < -10 || x > 65)
		{
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
		else
		{
			for (int i = 1; true; i++)
			{
				tmp = tmp * x;
				tmp = tmp / i;
				if (sum >= 0 && fabs(tmp) < 1e-6)
				{
					break;
				}
				sum += tmp;
			}
			break;
		}
	}

	cout << "e^" << x << "=" << setprecision(10) << sum << endl;

	return 0;
}