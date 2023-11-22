/*2151974 ��� ������*/
#include <iostream>
using namespace std;

const int A = 0;		//������¼�����С�����ʼ
const int B = 3;
const int C = 6;

int block(int a[][9], int row, int col)
{
	int sign = 0;
	int check[10] = { 0 };

	for (int i = row; i < row + 3; i++)
	{
		for (int j = col; j < col + 3; j++)
		{
			if (a[i][j] >= 1 && a[i][j] <= 9 && check[a[i][j]] == 0)
			{
				check[a[i][j]] = 1;
			}
			else
			{
				sign = 1;
				break;
			}
		}
	}
	return sign;
}

int judge(int a[][9])
{
	int sign = 0;
	int check[10] = { 0 };

	for (int i = 0; i < 9; i++)				//���м��
	{
		for (int j = 0; j < 9; j++)
		{
			if (a[i][j] >= 1 && a[i][j] <= 9 && check[a[i][j]] == 0)
			{
				check[a[i][j]] = 1;
			}
			else
			{
				sign = 1;
				break;
			}
		}
		for (int k = 0; k <= 9; k++)			//����һ�м���������
		{
			check[k] = 0;
		}
	}
	for (int k = 0; k <= 9; k++)				//����������û������
	{
		check[k] = 0;
	}
	if (sign)								//����ֱ���˳�
	{
		return sign;
	}
	
	for (int i = 0; i < 9; i++)				//���м��
	{
		for (int j = 0; j < 9; j++)
		{
			if (a[j][i] >= 1 && a[j][i] <= 9 && check[a[j][i]] == 0)
			{
				check[a[j][i]] = 1;
			}
			else
			{
				sign = 1;
				break;
			}
		}
		for (int k = 0; k <= 9; k++)			//����һ�м���������
		{
			check[k] = 0;
		}
	}
	for (int k = 0; k <= 9; k++)				//����������û������
	{
		check[k] = 0;
	}
	if (sign)								//����ֱ���˳�
	{
		return sign;
	}
	
	if (block(a, A, A) || block(a, A, B) || block(a, A, C) ||
		block(a, B, A) || block(a, B, B) || block(a, B, C) ||
		block(a, C, A) || block(a, C, B) || block(a, C, C))
	{
		sign = 1;
	}
	return sign;
}

int main()
{
	int sudoku[9][9] = {};

	cout << "������9*9�ľ���ֵΪ1-9֮��" << endl;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> sudoku[i][j];

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(9999, '\n');
				cout << "�����������" << i + 1 << "��" << j + 1 << "��(���о���1��ʼ����)��ֵ" << endl;
				j--;
				continue;
			}
			if (sudoku[i][j] < 1 || sudoku[i][j] > 9)
			{
				cout << "�����������" << i + 1 << "��" << j + 1 << "��(���о���1��ʼ����)��ֵ" << endl;
				j--;
				continue;
			}
		}
	}

	if (judge(sudoku))
	{
		cout << "��";
	}
	cout << "�������Ľ�" << endl;

	//for (int i = 0; i < 9; i++)			//����
	//{
	//	for (int j = 0; j < 9; j++)
	//	{
	//		cout << sudoku[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//cout << judge(sudoku) << endl;

	return 0;
}