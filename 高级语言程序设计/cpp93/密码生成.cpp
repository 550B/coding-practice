/*2151974 ��� ������*/
#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;

/***************************************************************************
  �������ƣ�make_password
  ��    �ܣ���������
  ���������int len, int upper, int lower, int num, int els
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void make_password(int len, int upper, int lower, int num, int els)
{
	static const char other[] = "!@#$%^&*-_=+,.?";
	int un = 0, ln = 0, nn = 0, en = 0;
	char result[17];
	int cnt = un + ln + nn + en;
	while (cnt != upper + lower + num + els)
	{
		switch (rand() % 4)
		{
			case 0:
				if (un < upper)
				{
					result[cnt] = 'A' + rand() % 26;
					un++;
				}
				break;
			case 1:
				if (ln < lower)
				{
					result[cnt] = 'a' + rand() % 26;
					ln++;
				}
				break;
			case 2:
				if (nn < num)
				{
					result[cnt] = '0' + rand() % 10;
					nn++;
				}
				break;
			default:
				if (en < els)
				{
					result[cnt] = other[rand() % 15];
					en++;
				}
				break;
		}
		cnt = un + ln + nn + en;
	}
	while (len - cnt)
	{
		switch (rand() % 4)
		{
			case 0:
				result[cnt] = 'A' + rand() % 26;
				break;
			case 1:
				result[cnt] = 'a' + rand() % 26;
				break;
			case 2:
				result[cnt] = '0' + rand() % 10;
				break;
			default:
				result[cnt] = other[rand() % 15];
				break;
		}
		cnt++;
	}
	result[cnt] = '\0';
	cout << result << endl;
}

/***************************************************************************
  �������ƣ�main
  ��    �ܣ����ú���
  ���������
  �� �� ֵ��0
  ˵    ����
***************************************************************************/
int main()
{
	srand((unsigned int)(time(0)));
	int len, upper, lower, num, els;
	cout << "���������볤��(12-16)�� ��д��ĸ����(��2)�� Сд��ĸ����(��2)�� ���ָ���(��2)�� �������Ÿ���(��2)" << endl;
	cin >> len >> upper >> lower >> num >> els;
	if (cin.fail())
	{
		cout << "����Ƿ�" << endl;
		return 0;
	}
	if (len < 12 || len > 16)
	{
		cout << "���볤��[" << len << "]����ȷ" << endl;
		return 0;
	}
	if (upper < 2 || upper > len)
	{
		cout << "��д��ĸ����[" << upper << "]����ȷ" << endl;
		return 0;
	}
	if (lower < 2 || lower > len)
	{
		cout << "Сд��ĸ����[" << lower << "]����ȷ" << endl;
		return 0;
	}
	if (num < 2 || num > len)
	{
		cout << "���ָ���[" << num << "]����ȷ" << endl;
		return 0;
	}
	if (els < 2 || els > len)
	{
		cout << "�������Ÿ���[" << els << "]����ȷ" << endl;
		return 0;
	}
	if (upper + lower + num + els > len)
	{
		cout << "�����ַ�����֮��[" << upper << "+" << lower << "+" << num << "+" << els << "]���������볤��[" << len << "]" << endl;
		return 0;
	}
	cout << len << " " << upper << " " << lower << " " << num << " " << els << endl;
	for (int i = 0; i < 10; i++)
	{
		make_password(len, upper, lower, num, els);
	}
	
	return 0;
}