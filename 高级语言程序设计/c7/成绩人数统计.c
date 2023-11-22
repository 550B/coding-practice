/*2151974 软件 赵明泽*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("请输入成绩（最多1000个），以-1结束\n");

	int count[105] = { 0 };
	int score[1010];
	int i = 0;
	int tmp;
	do
	{
		scanf("%d", &tmp);
		if (tmp < 0 && i == 0)
		{
			printf("无有效输入\n");
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
	
	printf("输入的数组为:\n");

	int cnt = 0;
	for (int j = 0; j < i; j++)
	{
		printf("%d ", score[j]);
		cnt++;
		if (cnt == 10)
		{
			printf("\n");
			cnt = 0;
		}
	}
	if (cnt)
	{
		printf("\n");
	}
	
	printf("分数与人数的对应关系为:\n");

	for (int k = 100; k >= 0; k--)
	{
		if (count[k])
		{
			printf("%d %d\n", k , count[k]);
		}
	}

	return 0;
}