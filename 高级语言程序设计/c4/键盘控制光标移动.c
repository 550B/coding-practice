/*2151974 软件 赵明泽*/
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
			char ch    ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	printf("***********************************************************************\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("***********************************************************************\n");

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/

/***************************************************************************
  函数名称：menu
  功    能：菜单显示及选择
  输入参数：void
  返 回 值：int
  说    明：NULL
***************************************************************************/
int menu()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	cls(hout);

	printf("1.用I、J、K、L键控制上下左右(大小写均可，边界停止)\n");
	printf("2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)\n");
	printf("3.用箭头键控制上下左右，边界停止（按大写HPKM时不会移动）\n");
	printf("4.用箭头键控制上下左右，边界回绕（按大写HPKM时不会移动）\n");
	printf("5.用I、J、K、L键控制上下左右(大小写均可，边界停止,按左箭头不会向下移动)\n");
	printf("6.用I、J、K、L键控制上下左右(大小写均可，边界回绕,按左箭头不会向下移动)\n");
	printf("0.退出\n");
	printf("[请选择0-6]");

	char ch;
	ch = _getche();
	int num;
	switch (ch)
	{
		case '0':
			num = 0;
			break;
		case '1':
			num = 1;
			break;
		case '2':
			num = 2;
			break;
		case '3':
			num = 3;
			break;
		case '4':
			num = 4;
			break;
		case '5':
			num = 5;
			break;
		case '6':
			num = 6;
			break;
		default:
			num = 2151974;
			break;
	}
	return num;
}

/***************************************************************************
  函数名称：move_by_arrow
  功    能：用箭头移动函数
  输入参数：int hr
  返 回 值：void
  说    明：NULL
***************************************************************************/
void move_by_arrow(int hr)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	//上下左右挪动
	char f, t;
	int x2 = 35, y2 = 9;

	while (1)
	{
		f = _getch();
		if (f == 'q' || f == 'Q')
		{
			break;
		}
		if ((int)f == 32)
		{
			putchar(' ');
			gotoxy(hout, x2, y2);
		}
		if ((int)f == -32)
		{
			t = _getch();

			if (hr == 3)
			{
				if ((x2 == 1 && t == 75) || (x2 == 69 && t == 77) || (y2 == 1 && t == 72) || (y2 == 17 && t == 80))
				{
					continue;
				}
			}
			else if (hr == 4)
			{
				if (x2 == 1 && t == 75)
				{
					x2 = 69;
					gotoxy(hout, x2, y2);
					continue;
				}
				if (x2 == 69 && t == 77)
				{
					x2 = 1;
					gotoxy(hout, x2, y2);
					continue;
				}
				if (y2 == 1 && t == 72)
				{
					y2 = 17;
					gotoxy(hout, x2, y2);
					continue;
				}
				if (y2 == 17 && t == 80)
				{
					y2 = 1;
					gotoxy(hout, x2, y2);
					continue;
				}
			}

			//normal
			if ((int)t == 75)
			{
				x2 -= 1;
				gotoxy(hout, x2, y2);
			}
			if ((int)t == 77)
			{
				x2 += 1;
				gotoxy(hout, x2, y2);
			}
			if ((int)t == 72)
			{
				y2 -= 1;
				gotoxy(hout, x2, y2);
			}
			if ((int)t == 80)
			{
				y2 += 1;
				gotoxy(hout, x2, y2);
			}
		}
	}
}

/***************************************************************************
  函数名称：move_by_ijkl_better
  功    能：用ijkl移动函数
  输入参数：int hr
  返 回 值：void
  说    明：NULL
***************************************************************************/
void move_by_ijkl_better(int hr)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	//上下左右挪动
	char m, n;
	int x3 = 35, y3 = 9;

	while (1)
	{
		m = _getch();
		if ((int)m == -32)
		{
			n = _getch();
			continue;
		}
		if (m == 'q' || m == 'Q')
		{
			break;
		}
		//判断是否回绕
		if (hr == 5)		//不回绕
		{
			if ((x3 == 1 && (m == 'j' || m == 'J')) || (x3 == 69 && (m == 'l' || m == 'L')) || (y3 == 1 && (m == 'i' || m == 'I')) || (y3 == 17 && (m == 'k' || m == 'K')))
			{
				continue;
			}
		}
		else if (hr == 6)	//回绕
		{
			if (x3 == 1 && (m == 'j' || m == 'J'))
			{
				x3 = 69;
				gotoxy(hout, x3, y3);
				continue;
			}
			if (x3 == 69 && (m == 'l' || m == 'L'))
			{
				x3 = 1;
				gotoxy(hout, x3, y3);
				continue;
			}
			if (y3 == 1 && (m == 'i' || m == 'I'))
			{
				y3 = 17;
				gotoxy(hout, x3, y3);
				continue;
			}
			if (y3 == 17 && (m == 'k' || m == 'K'))
			{
				y3 = 1;
				gotoxy(hout, x3, y3);
				continue;
			}
		}
		//正常
		if (m == 'j' || m == 'J')
		{
			x3 -= 1;
			gotoxy(hout, x3, y3);
		}
		if (m == 'l' || m == 'L')
		{
			x3 += 1;
			gotoxy(hout, x3, y3);
		}
		if (m == 'i' || m == 'I')
		{
			y3 -= 1;
			gotoxy(hout, x3, y3);
		}
		if (m == 'k' || m == 'K')
		{
			y3 += 1;
			gotoxy(hout, x3, y3);
		}
		if ((int)m == 32)
		{
			putchar(' ');
			gotoxy(hout, x3, y3);
		}
	}
}

/***************************************************************************
  函数名称：move_by_ijkl
  功    能：用ijkl和左箭头移动函数
  输入参数：int hr
  返 回 值：void
  说    明：NULL
***************************************************************************/
void move_by_ijkl(int hr)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	//上下左右挪动
	char a;
	int x1 = 35, y1 = 9;

	while (1)
	{
		a = _getch();
		if (a == 'q' || a == 'Q')
		{
			break;
		}
		//判断是否回绕
		if (hr == 1)		//不回绕
		{
			if ((x1 == 1 && (a == 'j' || a == 'J')) || (x1 == 69 && (a == 'l' || a == 'L')) || (y1 == 1 && (a == 'i' || a == 'I')) || (y1 == 17 && (a == 'k' || a == 'K')))
			{
				continue;
			}
		}
		else if (hr == 2)	//回绕
		{
			if (x1 == 1 && (a == 'j' || a == 'J'))
			{
				x1 = 69;
				gotoxy(hout, x1, y1);
				continue;
			}
			if (x1 == 69 && (a == 'l' || a == 'L'))
			{
				x1 = 1;
				gotoxy(hout, x1, y1);
				continue;
			}
			if (y1 == 1 && (a == 'i' || a == 'I'))
			{
				y1 = 17;
				gotoxy(hout, x1, y1);
				continue;
			}
			if (y1 == 17 && (a == 'k' || a == 'K'))
			{
				y1 = 1;
				gotoxy(hout, x1, y1);
				continue;
			}
		}
		//正常
		if (a == 'j' || a == 'J')
		{
			x1 -= 1;
			gotoxy(hout, x1, y1);
		}
		if (a == 'l' || a == 'L')
		{
			x1 += 1;
			gotoxy(hout, x1, y1);
		}
		if (a == 'i' || a == 'I')
		{
			y1 -= 1;
			gotoxy(hout, x1, y1);
		}
		if (a == 'k' || a == 'K')
		{
			y1 += 1;
			gotoxy(hout, x1, y1);
		}
		if ((int)a == 32)
		{
			putchar(' ');
			gotoxy(hout, x1, y1);
		}
	}
}

/***************************************************************************
  函数名称：moving
  功    能：初始化游戏界面和选择移动函数方式
  输入参数：int choice
  返 回 值：void
  说    明：NULL
***************************************************************************/
void moving(int choice)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 显示初始的边框及其中的随机字符 */
	init_border(hout);

	//把光标移动到屏幕正中心
	gotoxy(hout, 35, 9);

	//选择
	switch (choice)
	{
		case 1:
		case 2:
			move_by_ijkl(choice);
			break;
		case 3:
		case 4:
			move_by_arrow(choice);
			break;
		default:
			move_by_ijkl_better(choice);
			break;
	}

	//退出模块
	gotoxy(hout, 0, 23);
	printf("游戏结束，按回车键返回菜单.");
	//按回车退出
	char b;
	while (1)
	{
		b = _getch();
		if ((int)b == 13)
		{
			break;
		}
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));

	/* 此句的作用是调用系统的cls命令清屏 */
	cls(hout);

	//选择
	while (1)
	{
		int tmp;
		tmp = menu();

		if (tmp == 2151974)
		{
			cls(hout);
			continue;
		}
		else if (tmp == 0)
		{
			break;
		}
		else
		{
			cls(hout);
			moving(tmp);
		}
	}

	return 0;
}

/*
思考
1、能。因为上下左右箭头不在ASCII码里，所以输入箭头的时候，其实是两个值。
如果是char类型，第一个值是-32，第二个值分别是上下左右72，80，75，77.
如果是int类型，第一个值是224，第二个值同上。
大写字母“K”的ASCII码正好是75.
循环读到第一个数，发现并没有什么用，然后开始读第二个数，发现左箭头的第二个数
正好和K一样，也就是光标下移，所以就产生了这种现象。

2、不一定，有可能不到20个，当取模运算得到0时，字母正好生成在*位置，而那个位置
不能生成字母，所以导致字母少了
*/