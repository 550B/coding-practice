/*2151974 软件 赵明泽*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //取系统时间
using namespace std;

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int num1 = 123, num2 = 500, num3 = 500;
	int bai1 , bai2 , bai3 , shi1 , shi2 , shi3 , ge1 , ge2 , ge3 ;
	int yi1 = 0, er1 = 0, san1 = 0, si1 = 0, wu1 = 0, liu1 = 0, qi1 = 0, ba1 = 0, jiu1 = 0;
	int yi2 = 0, er2 = 0, san2 = 0, si2 = 0, wu2 = 0, liu2 = 0, qi2 = 0, ba2 = 0, jiu2 = 0;
	int yi3 = 0, er3 = 0, san3 = 0, si3 = 0, wu3 = 0, liu3 = 0, qi3 = 0, ba3 = 0, jiu3 = 0;
	int cnt = 0;

	for (int i=num1; i < 600; i++)
	{
		yi1 = er1 = san1 = si1 = wu1 = liu1 = qi1 = ba1 = jiu1 = 0;

		bai1 = i / 100;
		shi1 = i / 10 % 10;
		ge1 = i % 10;

		if (bai1 == 1)
			yi1 = 1;
		else if (bai1 == 2)
			er1 = 1;
		else if (bai1 == 3)
			san1 = 1;
		else if (bai1 == 4)
			si1 = 1;
		else if (bai1 == 5)
			wu1 = 1;
		else if (bai1 == 6)
			liu1 = 1;
		else if (bai1 == 7)
			qi1 = 1;
		else if (bai1 == 8)
			ba1 = 1;
		else if (bai1 == 9)
			jiu1 = 1;
		else
			continue;

		if (shi1 == 1)
			yi1 = 1;
		else if (shi1 == 2)
			er1 = 1;
		else if (shi1 == 3)
			san1 = 1;
		else if (shi1 == 4)
			si1 = 1;
		else if (shi1 == 5)
			wu1 = 1;
		else if (shi1 == 6)
			liu1 = 1;
		else if (shi1 == 7)
			qi1 = 1;
		else if (shi1 == 8)
			ba1 = 1;
		else if (shi1 == 9)
			jiu1 = 1;
		else
			continue;

		if (ge1 == 1)
			yi1 = 1;
		else if (ge1 == 2)
			er1 = 1;
		else if (ge1 == 3)
			san1 = 1;
		else if (ge1 == 4)
			si1 = 1;
		else if (ge1 == 5)
			wu1 = 1;
		else if (ge1 == 6)
			liu1 = 1;
		else if (ge1 == 7)
			qi1 = 1;
		else if (ge1 == 8)
			ba1 = 1;
		else if (ge1 == 9)
			jiu1 = 1;
		else
			continue;

		for (int j=num2; j <= 987; j++)
		{
			yi2 = er2 = san2 = si2 = wu2 = liu2 = qi2 = ba2 = jiu2 = 0;

			bai2 = j / 100;
			shi2 = j / 10 % 10;
			ge2 = j % 10;

			if (bai2 == 1)
				yi2 = 1;
			else if (bai2 == 2)
				er2 = 1;
			else if (bai2 == 3)
				san2 = 1;
			else if (bai2 == 4)
				si2 = 1;
			else if (bai2 == 5)
				wu2 = 1;
			else if (bai2 == 6)
				liu2 = 1;
			else if (bai2 == 7)
				qi2 = 1;
			else if (bai2 == 8)
				ba2 = 1;
			else if (bai2 == 9)
				jiu2 = 1;
			else
				continue;

			if (shi2 == 1)
				yi2 = 1;
			else if (shi2 == 2)
				er2 = 1;
			else if (shi2 == 3)
				san2 = 1;
			else if (shi2 == 4)
				si2 = 1;
			else if (shi2 == 5)
				wu2 = 1;
			else if (shi2 == 6)
				liu2 = 1;
			else if (shi2 == 7)
				qi2 = 1;
			else if (shi2 == 8)
				ba2 = 1;
			else if (shi2 == 9)
				jiu2 = 1;
			else
				continue;

			if (ge2 == 1)
				yi2 = 1;
			else if (ge2 == 2)
				er2 = 1;
			else if (ge2 == 3)
				san2 = 1;
			else if (ge2 == 4)
				si2 = 1;
			else if (ge2 == 5)
				wu2 = 1;
			else if (ge2 == 6)
				liu2 = 1;
			else if (ge2 == 7)
				qi2 = 1;
			else if (ge2 == 8)
				ba2 = 1;
			else if (ge2 == 9)
				jiu2 = 1;
			else
				continue;
			
			for (int k=num3; k <= 987; k++)
			{
				yi3 = er3 = san3 = si3 = wu3 = liu3 = qi3 = ba3 = jiu3 = 0;

				bai3 = k / 100;
				shi3 = k / 10 % 10;
				ge3 = k % 10;

				if (bai3 == 1)
					yi3 = 1;
				else if (bai3 == 2)
					er3 = 1;
				else if (bai3 == 3)
					san3 = 1;
				else if (bai3 == 4)
					si3 = 1;
				else if (bai3 == 5)
					wu3 = 1;
				else if (bai3 == 6)
					liu3 = 1;
				else if (bai3 == 7)
					qi3 = 1;
				else if (bai3 == 8)
					ba3 = 1;
				else if (bai3 == 9)
					jiu3 = 1;
				else
					continue;

				if (shi3 == 1)
					yi3 = 1;
				else if (shi3 == 2)
					er3 = 1;
				else if (shi3 == 3)
					san3 = 1;
				else if (shi3 == 4)
					si3 = 1;
				else if (shi3 == 5)
					wu3 = 1;
				else if (shi3 == 6)
					liu3 = 1;
				else if (shi3 == 7)
					qi3 = 1;
				else if (shi3 == 8)
					ba3 = 1;
				else if (shi3 == 9)
					jiu3 = 1;
				else
					continue;

				if (ge3 == 1)
					yi3 = 1;
				else if (ge3 == 2)
					er3 = 1;
				else if (ge3 == 3)
					san3 = 1;
				else if (ge3 == 4)
					si3 = 1;
				else if (ge3 == 5)
					wu3 = 1;
				else if (ge3 == 6)
					liu3 = 1;
				else if (ge3 == 7)
					qi3 = 1;
				else if (ge3 == 8)
					ba3 = 1;
				else if (ge3 == 9)
					jiu3 = 1;
				else
					continue;

				if ((yi1 + yi2 + yi3 == 1) && (er1 + er2 + er3 == 1) && (san1 + san2 + san3 == 1) && (si1 + si2 + si3 == 1) && (wu1 + wu2 + wu3 == 1) && (liu1 + liu2 + liu3 == 1) && (qi1 + qi2 + qi3 == 1) && (ba1 + ba2 + ba3 == 1) && (jiu1 + jiu2 + jiu3 == 1))
				{
					if (i + j + k == 1953)
					{
						if (i < j && j < k && i < k)
						{
							cnt++;
							cout << "No." << setw(3) << cnt << " : " << i << "+" << j << "+" << k << "=" << 1953 << endl;
						}
					}
				}
			}
		}
	}

	cout << "total=" << cnt << endl;
	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;

	return 0;
}