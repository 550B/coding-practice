/*2151974 ��� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//����������
	int year, month, day;
	int maxFeb, num;
	int cnt = 0;
	int ret1, ret2;

	//year&month����;�����
	while (1)
	{
		printf("���������(2000-2030)���·�(1-12) : ");
		ret1 = scanf("%d%d", &year, &month);
		if (ret1 == 0 || year < 2000 || year>2030 || month < 1 || month>12)
		{
			char c;
			while ((c = getchar()) != '\n' && c != EOF);
			printf("����Ƿ�������������\n");
		}
		else
		{
			break;
		}
	}

	//day����;�����
	while (1)
	{
		printf("������%d��%d��1�յ�����(0-6��ʾ������-������) : ", year, month);
		ret2 = scanf("%d", &day);
		if (ret2 == 0 || day < 0 || day > 6)
		{
			char c;
			while ((c = getchar()) != '\n' && c != EOF);
			printf("����Ƿ�������������\n");
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
	printf("\n");
	printf("%d��%d�µ�����Ϊ:\n", year, month);
	printf("������  ����һ  ���ڶ�  ������  ������  ������  ������\n");
	for (int j = cnt; j > 0; j--)
	{
		printf("        ");
	}
	for (int i = 1; i <= num; i++)
	{
		printf("%4d", i);
		//cout << setw(2) << setiosflags(ios::right) << i;
		cnt++;
		if (cnt == 7)
		{
			printf("    ");
			printf("\n");
			cnt = 0;
		}
		else
		{
			printf("    ");
		}
	}
	printf("\n");

	return 0;
}