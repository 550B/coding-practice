/*2151974 ��� ������*/
#include <iostream>

using namespace std;
int main()
{
	cout << "�������꣬�£���" << endl;

	int year, month, day;
	int maxFeb, num;

	cin >> year >> month >> day;


	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
	{
		maxFeb = 29;

	}
	else
	{
		maxFeb = 28;

	}

	switch (month)
	{
		case 1:
			if ((day <= 0) || (day > 31))
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;

			}
			else
			{
				num = day;
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << num << "��" << endl;

			}
			break;
		case 2:
			if ((day <= 0) || (day > maxFeb))
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;

			}
			else
			{
				num = 31 + day;
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << num << "��" << endl;

			}
			break;
		case 3:
			if ((day <= 0) || (day > 31))
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;

			}
			else
			{
				num = 31 + maxFeb + day;
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << num << "��" << endl;

			}
			break;
		case 4:
			if ((day <= 0) || (day > 30))
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;

			}
			else
			{
				num = 31 + maxFeb + 31 + day;
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << num << "��" << endl;

			}
			break;
		case 5:
			if ((day <= 0) || (day > 31))
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;

			}
			else
			{
				num = 31 + maxFeb + 31 + 30 + day;
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << num << "��" << endl;

			}
			break;
		case 6:
			if ((day <= 0) || (day > 30))
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;

			}
			else
			{
				num = 31 + maxFeb + 31 + 30 + 31 + day;
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << num << "��" << endl;

			}
			break;
		case 7:
			if ((day <= 0) || (day > 31))
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;

			}
			else
			{
				num = 31 + maxFeb + 31 + 30 + 31 + 30 + day;
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << num << "��" << endl;

			}
			break;
		case 8:
			if ((day <= 0) || (day > 31))
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;

			}
			else
			{
				num = 31 + maxFeb + 31 + 30 + 31 + 30 + 31 + day;
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << num << "��" << endl;

			}
			break;
		case 9:
			if ((day <= 0) || (day > 30))
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;

			}
			else
			{
				num = 31 + maxFeb + 31 + 30 + 31 + 30 + 31 + 31 + day;
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << num << "��" << endl;

			}
			break;
		case 10:
			if ((day <= 0) || (day > 31))
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;

			}
			else
			{
				num = 31 + maxFeb + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day;
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << num << "��" << endl;

			}
			break;
		case 11:
			if ((day <= 0) || (day > 30))
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;

			}
			else
			{
				num = 31 + maxFeb + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << num << "��" << endl;

			}
			break;
		case 12:
			if ((day <= 0) || (day > 31))
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;

			}
			else
			{
				num = 31 + maxFeb + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day;
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << num << "��" << endl;

			}
			break;

		default:
			cout << "�������-�·ݲ���ȷ" << endl;

	}

	return 0;

}