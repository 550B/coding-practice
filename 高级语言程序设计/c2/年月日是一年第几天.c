/*2151974 ��� ������*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("�������꣬�£���\n");

	int year, month, day;
	int maxFeb, num;

	scanf("%d%d%d", &year, &month, &day);

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
				printf("�������-�����µĹ�ϵ�Ƿ�\n");

			}
			else
			{
				num = day;
				printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, num);

			}
			break;
		case 2:
			if ((day <= 0) || (day > maxFeb))
			{
				printf("�������-�����µĹ�ϵ�Ƿ�\n");

			}
			else
			{
				num = 31 + day;
				printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, num);

			}
			break;
		case 3:
			if ((day <= 0) || (day > 31))
			{
				printf("�������-�����µĹ�ϵ�Ƿ�\n");

			}
			else
			{
				num = 31 + maxFeb + day;
				printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, num);

			}
			break;
		case 4:
			if ((day <= 0) || (day > 30))
			{
				printf("�������-�����µĹ�ϵ�Ƿ�\n");

			}
			else
			{
				num = 31 + maxFeb + 31 + day;
				printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, num);

			}
			break;
		case 5:
			if ((day <= 0) || (day > 31))
			{
				printf("�������-�����µĹ�ϵ�Ƿ�\n");

			}
			else
			{
				num = 31 + maxFeb + 31 + 30 + day;
				printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, num);

			}
			break;
		case 6:
			if ((day <= 0) || (day > 30))
			{
				printf("�������-�����µĹ�ϵ�Ƿ�\n");

			}
			else
			{
				num = 31 + maxFeb + 31 + 30 + 31 + day;
				printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, num);

			}
			break;
		case 7:
			if ((day <= 0) || (day > 31))
			{
				printf("�������-�����µĹ�ϵ�Ƿ�\n");

			}
			else
			{
				num = 31 + maxFeb + 31 + 30 + 31 + 30 + day;
				printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, num);

			}
			break;
		case 8:
			if ((day <= 0) || (day > 31))
			{
				printf("�������-�����µĹ�ϵ�Ƿ�\n");

			}
			else
			{
				num = 31 + maxFeb + 31 + 30 + 31 + 30 + 31 + day;
				printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, num);

			}
			break;
		case 9:
			if ((day <= 0) || (day > 30))
			{
				printf("�������-�����µĹ�ϵ�Ƿ�\n");

			}
			else
			{
				num = 31 + maxFeb + 31 + 30 + 31 + 30 + 31 + 31 + day;
				printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, num);

			}
			break;
		case 10:
			if ((day <= 0) || (day > 31))
			{
				printf("�������-�����µĹ�ϵ�Ƿ�\n");

			}
			else
			{
				num = 31 + maxFeb + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day;
				printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, num);

			}
			break;
		case 11:
			if ((day <= 0) || (day > 30))
			{
				printf("�������-�����µĹ�ϵ�Ƿ�\n");

			}
			else
			{
				num = 31 + maxFeb + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;
				printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, num);

			}
			break;
		case 12:
			if ((day <= 0) || (day > 31))
			{
				printf("�������-�����µĹ�ϵ�Ƿ�\n");

			}
			else
			{
				num = 31 + maxFeb + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day;
				printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, num);

			}
			break;

		default:
			printf("�������-�·ݲ���ȷ\n");

	}

	return 0;

}