/*2151974 软件 赵明泽*/
#include <iostream>
#include <limits>
using namespace std;

const int NUM = 25;

int main()
{
	cout << "请输入任意个正整数（升序，最多20个），以-1结束" << endl;

	int a[NUM];
	int i;
	cin >> a[0];
	if (a[0] == -1)
	{
		cout << "无有效输入" << endl;
		return 0;
	}
	for (i = 1; i < 20 ; i++)
	{
		int temp;
		cin >> temp;
		if (temp < 0)
		{
			break;
		}
		a[i] = temp;
	}
	
	cin.clear();
	cin.ignore((std::numeric_limits< streamsize >::max)(), '\n');

	cout << "原数组为：" << endl;

	for (int j = 0; j < i ; j++)
	{
		cout << a[j] << " ";
	}
	cout << endl;

	cout << "请输入要插入的正整数" << endl;

	int tmp;
	cin >> tmp;
	a[i] = tmp;

	cout << "插入后的数组为：" << endl;

	for (int k = i; k > 0; k--)
	{
		if (a[k-1] > tmp)
		{
			int t = a[k];
			a[k] = a[k - 1];
			a[k - 1] = t;
		}
	}

	for (int j = 0; j <= i; j++)
	{
		cout << a[j] << " ";
	}
	cout << endl;

	return 0;
}