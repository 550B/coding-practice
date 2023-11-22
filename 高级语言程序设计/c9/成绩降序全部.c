/*2151974 软件 赵明泽*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define STU 10
#define NUM 8
#define NAME 9

/***************************************************************************
  函数名称：tj_strcpy
  功    能：把第二个数组的内容复制到第一个
  输入参数：char s1[], const char s2[]
  返 回 值：0
  说    明：
***************************************************************************/
int tj_strcpy(char s1[], const char s2[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int cnt = 0;
	while (s2[cnt] != '\0')
	{
		s1[cnt] = s2[cnt];
		cnt++;
	}
	s1[cnt] = '\0';

	return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：data_in
  功    能：输入数据
  输入参数：char num[STU][NUM], char name[STU][NAME], int score[STU][1]
  返 回 值：void
  说    明：
***************************************************************************/
void data_in(char num[STU][NUM], char name[STU][NAME], int score[STU][1])
{
	int cnt = 0;
	while (cnt < STU)
	{
		printf("请输入第%d个人的学号、姓名、成绩\n", cnt + 1);
		scanf("%s %s %d", num[cnt], name[cnt], score[cnt]);
		cnt++;
	}
}

/***************************************************************************
  函数名称：data_sort
  功    能：数据排序
  输入参数：char num[STU][NUM], char name[STU][NAME], int score[STU][1]
  返 回 值：void
  说    明：
***************************************************************************/
void data_sort(char num[STU][NUM], char name[STU][NAME], int score[STU][1])
{
	for (int i = 0; i < STU; i++)
	{
		int temp = score[i][0];
		for (int j = i; j > 0; j--)
		{
			if (score[j][0] > score[j-1][0])
			{
				char t1[NUM];
				tj_strcpy(t1, num[j]);
				tj_strcpy(num[j], num[j-1]);
				tj_strcpy(num[j-1], t1);
				char t2[NAME];
				tj_strcpy(t2, name[j]);
				tj_strcpy(name[j], name[j-1]);
				tj_strcpy(name[j-1], t2);
				int t = score[j][0];
				score[j][0] = score[j-1][0];
				score[j-1][0] = t;
			}
		}
	}
}

/***************************************************************************
  函数名称：data_out
  功    能：输出
  输入参数：char num[STU][NUM], char name[STU][NAME], int score[STU][1]
  返 回 值：void
  说    明：
***************************************************************************/
void data_out(char num[STU][NUM], char name[STU][NAME], int score[STU][1])
{
	printf("\n");
	printf("全部学生(成绩降序):\n");
	for (int i = 0; i < STU; i++)
	{
		printf("%s %s %d\n", name[i], num[i], score[i][0]);
	}
}

/***************************************************************************
  函数名称：main
  功    能：调用函数
  输入参数：
  返 回 值：0
  说    明：
***************************************************************************/
int main()
{
	char num[STU][NUM];
	char name[STU][NAME];
	int score[STU][1];
	data_in(num, name, score);
	data_sort(num, name, score);
	data_out(num, name, score);

	return 0;
}