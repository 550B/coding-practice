/*2151974 软件 赵明泽*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//变量定义区
	int year, month, day;
	int maxFeb, num;
	int cnt = 0;
	int ret1, ret2;

	//year&month输入和纠错区
	while (1)
	{
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		ret1 = scanf("%d%d", &year, &month);
		if (ret1 == 0 || year < 2000 || year>2030 || month < 1 || month>12)
		{
			char c;
			while ((c = getchar()) != '\n' && c != EOF);
			printf("输入非法，请重新输入\n");
		}
		else
		{
			break;
		}
	}

	//day输入和纠错区
	while (1)
	{
		printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ", year, month);
		ret2 = scanf("%d", &day);
		if (ret2 == 0 || day < 0 || day > 6)
		{
			char c;
			while ((c = getchar()) != '\n' && c != EOF);
			printf("输入非法，请重新输入\n");
		}
		else
		{
			break;
		}
	}

	//闰年判断区
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
	{
		maxFeb = 29;
	}
	else
	{
		maxFeb = 28;
	}

	//月份赋值区
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

	//输出区
	cnt = day;
	printf("\n");
	printf("%d年%d月的月历为:\n", year, month);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
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