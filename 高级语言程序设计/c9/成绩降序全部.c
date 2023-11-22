/*2151974 ��� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define STU 10
#define NUM 8
#define NAME 9

/***************************************************************************
  �������ƣ�tj_strcpy
  ��    �ܣ��ѵڶ�����������ݸ��Ƶ���һ��
  ���������char s1[], const char s2[]
  �� �� ֵ��0
  ˵    ����
***************************************************************************/
int tj_strcpy(char s1[], const char s2[])
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	int cnt = 0;
	while (s2[cnt] != '\0')
	{
		s1[cnt] = s2[cnt];
		cnt++;
	}
	s1[cnt] = '\0';

	return 0; //returnֵ�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�data_in
  ��    �ܣ���������
  ���������char num[STU][NUM], char name[STU][NAME], int score[STU][1]
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void data_in(char num[STU][NUM], char name[STU][NAME], int score[STU][1])
{
	int cnt = 0;
	while (cnt < STU)
	{
		printf("�������%d���˵�ѧ�š��������ɼ�\n", cnt + 1);
		scanf("%s %s %d", num[cnt], name[cnt], score[cnt]);
		cnt++;
	}
}

/***************************************************************************
  �������ƣ�data_sort
  ��    �ܣ���������
  ���������char num[STU][NUM], char name[STU][NAME], int score[STU][1]
  �� �� ֵ��void
  ˵    ����
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
  �������ƣ�data_out
  ��    �ܣ����
  ���������char num[STU][NUM], char name[STU][NAME], int score[STU][1]
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void data_out(char num[STU][NUM], char name[STU][NAME], int score[STU][1])
{
	printf("\n");
	printf("ȫ��ѧ��(�ɼ�����):\n");
	for (int i = 0; i < STU; i++)
	{
		printf("%s %s %d\n", name[i], num[i], score[i][0]);
	}
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
	char num[STU][NUM];
	char name[STU][NAME];
	int score[STU][1];
	data_in(num, name, score);
	data_sort(num, name, score);
	data_out(num, name, score);

	return 0;
}