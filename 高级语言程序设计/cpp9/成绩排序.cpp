/*2151974 ��� ������*/
#include <iostream>
using namespace std;

int main()
{
	cout << "������ɼ������1000��������-1����" << endl;

	int count[105] = { 0 };
	int score[1010];
	int i = 0;
	int tmp;
	do
	{
		cin >> tmp;
		if (tmp < 0 && i == 0)
		{
			cout << "����Ч����" << endl;
			return 0;
		}
		if (tmp < 0)
		{
			break;
		}
		score[i] = tmp;
		count[tmp]++;
		i++;
	} while (i < 1000);

	cout << "���������Ϊ:" << endl;

	int cnt = 0;
	for (int j = 0; j < i; j++)
	{
		cout << score[j] << " ";
		cnt++;
		if (cnt == 10)
		{
			cout << endl;
			cnt = 0;
		}
	}
	if (cnt)
	{
		cout << endl;
	}

	cout << "���������εĶ�Ӧ��ϵΪ:" << endl;

	int sum = 0;
	for (int k = 100; k >= 0; k--)
	{
		if (count[k])
		{
			int t = sum + 1;
			for (int j = count[k]; j > 0; j--)
			{
				cout << k << " " << t << endl;
				sum ++;
			}
		}
	}

	return 0;
}