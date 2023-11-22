/*2151974 软件 赵明泽*/
#include <iostream>
using namespace std;

const int A = 0;		//常量记录三大行、列起始
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

	for (int i = 0; i < 9; i++)				//按行检查
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
		for (int k = 0; k <= 9; k++)			//查完一行检查数组归零
		{
			check[k] = 0;
		}
	}
	for (int k = 0; k <= 9; k++)				//查完所有行没死归零
	{
		check[k] = 0;
	}
	if (sign)								//死了直接退出
	{
		return sign;
	}
	
	for (int i = 0; i < 9; i++)				//按列检查
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
		for (int k = 0; k <= 9; k++)			//查完一列检查数组归零
		{
			check[k] = 0;
		}
	}
	for (int k = 0; k <= 9; k++)				//查完所有列没死归零
	{
		check[k] = 0;
	}
	if (sign)								//死了直接退出
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

	cout << "请输入9*9的矩阵，值为1-9之间" << endl;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> sudoku[i][j];

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(9999, '\n');
				cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
				j--;
				continue;
			}
			if (sudoku[i][j] < 1 || sudoku[i][j] > 9)
			{
				cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
				j--;
				continue;
			}
		}
	}

	if (judge(sudoku))
	{
		cout << "不";
	}
	cout << "是数独的解" << endl;

	//for (int i = 0; i < 9; i++)			//测试
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