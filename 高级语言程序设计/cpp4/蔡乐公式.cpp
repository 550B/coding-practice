/*2151974 ��� ������*/
#include <iostream>
#include <limits>
using namespace std;

int zeller(int y, int m, int d)
{
	int Year, Century, a, b, c, Week;

	if (m == 1 || m == 2)
	{
		y = y - 1;
		m += 12;
	}

	Year = y % 100;
	Century = y / 100;
	a = Year / 4;
	b = Century / 4;
	c = (m + 1) * 13 / 5;
	Week = Year + a + b + c - 2 * Century + d - 1;

	while (Week < 0)
	{
		Week += 7;
	}

	return Week % 7;
}

int main()
{
	int year, month, day;
	int maxFeb, num;

	while (1)
	{
		cout << "��������[1900-2100]���¡��գ�" << endl;
		cin >> year >> month >> day;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore((std::numeric_limits< streamsize >::max)(), '\n');
			cout << "�����������������" << endl;
			continue;
		}
		else if (year < 1900 || year > 2100)
		{
			cin.clear();
			cin.ignore((std::numeric_limits< streamsize >::max)(), '\n');
			cout << "��ݲ���ȷ������������" << endl;
			continue;
		}
		else if (month < 1 || month > 12)
		{
			cin.clear();
			cin.ignore((std::numeric_limits< streamsize >::max)(), '\n');
			cout << "�·ݲ���ȷ������������" << endl;
			continue;
		}
		else
		{
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

			if (day<1 || day>num)
			{
				cin.clear();
				cin.ignore((std::numeric_limits< streamsize >::max)(), '\n');
				cout << "�ղ���ȷ������������" << endl;
				continue;
			}
		}
		break;
	}

	switch (zeller(year, month, day))
	{
		case 0:
			cout << "������" << endl;
			break;
		case 1:
			cout << "����һ" << endl;
			break;
		case 2:
			cout << "���ڶ�" << endl;
			break;
		case 3:
			cout << "������" << endl;
			break;
		case 4:
			cout << "������" << endl;
			break;
		case 5:
			cout << "������" << endl;
			break;
		case 6:
			cout << "������" << endl;
			break;
	}

	return 0;
}