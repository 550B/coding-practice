/*2151974 ��� ������*/
#include <iostream>
#include <limits>
using namespace std;

const int NUM = 25;

int main()
{
	cout << "��������������������������20��������-1����" << endl;

	int a[NUM];
	int i;
	cin >> a[0];
	if (a[0] == -1)
	{
		cout << "����Ч����" << endl;
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

	cout << "ԭ����Ϊ��" << endl;

	for (int j = 0; j < i ; j++)
	{
		cout << a[j] << " ";
	}
	cout << endl;

	cout << "������Ҫ�����������" << endl;

	int tmp;
	cin >> tmp;
	a[i] = tmp;

	cout << "����������Ϊ��" << endl;

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