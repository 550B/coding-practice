/*2151974 ��� ������*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int maxFeb(int year)
{
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
	{
		return 29;
	}
	else
	{
		return 28;
	}
}

int dayNum(int y, int m, int d)
{
	int months[20] = { 0,31,maxFeb(y),31,30,31,30,31,31,30,31,30,31 };
	int sum = 0;

	if (m < 1 || m > 12)
	{
		return -1;
	}
	if (d<1 || d>months[m])
	{
		return 0;
	}
	else
	{
		for (int i = 1; i < m; i++)
		{
			sum += months[i];
		}
		return sum + d;
	}
}

int main()
{
	printf("�������꣬�£���\n");

	int year, month, day;

	scanf("%d%d%d", &year, &month, &day);

	if (dayNum(year, month, day) == -1)
	{
		printf("�������-�·ݲ���ȷ\n");
	}
	else if (dayNum(year, month, day) == 0)
	{
		printf("�������-�����µĹ�ϵ�Ƿ�\n");
	}
	else
	{
		printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, dayNum(year, month, day));
	}

	return 0;
}