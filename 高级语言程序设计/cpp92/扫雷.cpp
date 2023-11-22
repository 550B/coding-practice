/*2151974 软件 赵明泽*/
#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

const int L = 12;
const int R = 28;

int main()
{
	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));

	int minesweeper[L][R] = {};
	int lns, cols;
	int cnt = 0;

	for (int i = 0; i < 50; i++)
	{
		lns = rand() % 10 + 1;
		cols = rand() % 26 + 1;
		minesweeper[lns][cols] = 9;
	}
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < R; j++)
		{
			if (minesweeper[i][j] == 9)
			{
				cnt++;
			}
		}
	}
	while (cnt < 50)
	{
		lns = rand() % 10 + 1;
		cols = rand() % 26 + 1;
		minesweeper[lns][cols] = 9;
		cnt = 0;
		for (int i = 0; i < L; i++)
		{
			for (int j = 0; j < R; j++)
			{
				if (minesweeper[i][j] == 9)
				{
					cnt++;
				}
			}
		}
	}

	for (int i = 1; i < L - 1; i++)
	{
		for (int j = 1; j < R - 1; j++)
		{
			int num = 0;
			if (minesweeper[i][j] == 9)
			{
				continue;
			}
			if (minesweeper[i - 1][j - 1] == 9)
			{
				num++;
			}
			if (minesweeper[i - 1][j] == 9)
			{
				num++;
			}
			if (minesweeper[i - 1][j + 1] == 9)
			{
				num++;
			}
			if (minesweeper[i][j - 1] == 9)
			{
				num++;
			}
			if (minesweeper[i][j + 1] == 9)
			{
				num++;
			}
			if (minesweeper[i + 1][j - 1] == 9)
			{
				num++;
			}
			if (minesweeper[i + 1][j] == 9)
			{
				num++;
			}
			if (minesweeper[i + 1][j + 1] == 9)
			{
				num++;
			}
			minesweeper[i][j] = num;
		}
	}

	for (int i = 1; i < L - 1; i++)
	{
		for (int j = 1; j < R - 1; j++)
		{
			if (minesweeper[i][j] == 9)
			{
				cout << "* ";
			}
			else
			{
				cout << minesweeper[i][j] << " ";
			}
		}
		cout << endl;
		//cout << "*" << endl;
	}
	//cout << endl;
	/*cout << cnt << endl;
	cout << lns << " " << cols << endl;*/
	return 0;
}