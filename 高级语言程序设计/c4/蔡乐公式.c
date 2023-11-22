/*2151974 ��� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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
	int ret1, ret2, ret3;

	while (1)
	{
		printf("��������[1900-2100]���¡��գ�\n");
		ret1 = scanf("%d", &year);
		if (ret1 == 0)
		{
			char c;
			while ((c = getchar()) != '\n' && c != EOF);
			printf("�����������������\n");
			continue;
		}
		ret2 = scanf("%d", &month);
		if (ret2 == 0)
		{
			char c;
			while ((c = getchar()) != '\n' && c != EOF);
			printf("�����������������\n");
			continue;
		}
		ret3 = scanf("%d", &day);
		if (ret3 == 0)
		{
			char c;
			while ((c = getchar()) != '\n' && c != EOF);
			printf("�����������������\n");
			continue;
		}

		if (year < 1900 || year > 2100)
		{
			char c;
			while ((c = getchar()) != '\n' && c != EOF);
			printf("��ݲ���ȷ������������\n");
			continue;
		}
		else if (month < 1 || month > 12)
		{
			char c;
			while ((c = getchar()) != '\n' && c != EOF);
			printf("�·ݲ���ȷ������������\n");
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
				char c;
				while ((c = getchar()) != '\n' && c != EOF);
				printf("�ղ���ȷ������������\n");
				continue;
			}
		}
		break;
	}

	switch (zeller(year, month, day))
	{
		case 0:
			printf("������");
			break;
		case 1:
			printf("����һ");
			break;
		case 2:
			printf("���ڶ�");
			break;
		case 3:
			printf("������");
			break;
		case 4:
			printf("������");
			break;
		case 5:
			printf("������");
			break;
		case 6:
			printf("������");
			break;
	}
	printf("\n");

	return 0;
}