/*2151974 ��� ������*/
/*2151753 ������ 2154270 �Գ��� 2151804 ����� 2151569 ����ʶ 2152568 ���κ� 2050780 ����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define L 12
#define R 28

int main()
{
	char ch[L][R] = { 0 };
	int cnt = 0;
	
	for (int i = 1; i < L - 1; i++)
	{
		for (int j = 1; j < R - 1; j++)
		{
			ch[i][j] = getchar();
			/*char che = getchar();
			if (che == '*')
			{
				ch[i][j] = che;
			}
			else if (che >= '0' && che <= '8')
			{
				ch[i][j] = che;
			}
			else
			{
				ch[i][j] = che;
			}*/
			getchar();
		}
		if (i != L - 1)
		{
			getchar();
		}
	}

	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < R; j++)
		{
			if (ch[i][j] == '*')
			{
				cnt++;
			}
		}
	}

	//printf("\n");
	//for (int i = 1; i < L - 1; i++)
	//{
	//	for (int j = 1; j < R - 1; j++)
	//	{
	//		printf("%c ", ch[i][j]);
	//	}
	//	printf("\n");
	//	//cout << "*" << endl;
	//}
	//printf("\n");

	if (cnt != 50)
	{
		printf("����1\n");
		return 0;
	}

	for (int i = 1; i < L - 1; i++)
	{
		for (int j = 1; j < R - 1; j++)
		{
			char num = '0';
			if (ch[i][j] == '*')
			{
				continue;
			}
			if (ch[i - 1][j - 1] == '*')
			{
				num++;
			}
			if (ch[i - 1][j] == '*')
			{
				num++;
			}
			if (ch[i - 1][j + 1] == '*')
			{
				num++;
			}
			if (ch[i][j - 1] == '*')
			{
				num++;
			}
			if (ch[i][j + 1] == '*')
			{
				num++;
			}
			if (ch[i + 1][j - 1] == '*')
			{
				num++;
			}
			if (ch[i + 1][j] == '*')
			{
				num++;
			}
			if (ch[i + 1][j + 1] == '*')
			{
				num++;
			}
			if (ch[i][j] != num)
			{
				printf("����2\n");
				return 0;
			}
		}
	}

	printf("��ȷ\n");

	//printf("\n");
	//for (int i = 1; i < L - 1; i++)
	//{
	//	for (int j = 1; j < R - 1; j++)
	//	{
	//		printf("%d ", ch[i][j]);
	//	}
	//	printf("\n");
	//	//cout << "*" << endl;
	//}
	//printf("\n");

	return 0;
}