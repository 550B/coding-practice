/*2151974 ��� ������*/
#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;
int main()
{
	//����������
	int year, month, day;
	int maxFeb, num;
	int cnt = 0;

	//year&month����;�����
	while (1)
	{
		cout << "���������(2000-2030)���·�(1-12) : ";
		cin >> year >> month;
		if (cin.fail() || year < 2000 || year>2030 || month < 1 || month>12)
		{
			cin.clear();
			cin.ignore((std::numeric_limits< streamsize >::max)(), '\n');
			cout << "����Ƿ�������������" << endl;
		}
		else
		{
			break;
		}
	}

	//day����;�����
	while (1)
	{
		cout << "������" << year << "��" << month << "��1�յ�����(0-6��ʾ������-������) : ";
		cin >> day;
		if (cin.fail() || day < 0 || day>6)
		{
			cin.clear();
			cin.ignore((std::numeric_limits< streamsize >::max)(), '\n');
			cout << "����Ƿ�������������" << endl;
		}
		else
		{
			break;
		}
	}

	//�����ж���
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
	{
		maxFeb = 29;
	}
	else
	{
		maxFeb = 28;
	}

	//�·ݸ�ֵ��
	switch (month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			num = 31;
			break;
		case 2:
			num = maxFeb;
			break;
		default:
			num = 30;
			break;
	}

	//�����
	cnt = day;
	cout << endl;
	cout << year << "��" << month << "�µ�����Ϊ:" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
	for (int j = cnt; j > 0; j--)
	{
		cout << "        ";
	}
	for (int i = 1; i <= num; i++)
	{
		cout << setw(4) << setiosflags(ios::right) << i;
		cnt++;
		if (cnt == 7)
		{
			cout << "    ";
			cout << endl;
			cnt = 0;
		}
		else
		{
			cout << "    ";
		}
	}
	cout << endl;

	return 0;
}