/*2151974 软件 赵明泽*/
#include <iostream>
#include <io.h>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "90-b3.h"
using namespace std;

/***************************************************************************
  函数名称：read_c
  功    能：读取继续
  输入参数：void
  返 回 值：void
  说    明：
***************************************************************************/
void read_c()
{
	cct_gotoxy(0, 45);
	cout << "关卡显示完成，按C/c继续...";
	char ch;
	while (ch = _getch()) {
		if (ch == 'c' || ch == 'C')
			break;
	}
	cct_gotoxy(0, 45);
	cout << "                                                 ";
}

/***************************************************************************
  函数名称：print_block
  功    能：绘制
  输入参数：int x0, int y0, char ch
  返 回 值：void
  说    明：
***************************************************************************/
void print_block(int x0, int y0, char ch)
{
	int x = x0 * 6, y = y0 * 3;
	cct_gotoxy(x, y);
	if (ch == '9')
		return;
	if (ch == 'W' || ch == 'w') {
		cct_setcolor(4, 0);
		cout << "\u2554\u2550\u2557";
		cct_gotoxy(x, ++y);
		cout << "\u2551XX\u2551";
		cct_gotoxy(x, ++y);
		cout << "\u255A\u2550\u255D";
	}
	if (ch == '0') {
		cct_setcolor(7);
		cout << "      ";
		cct_gotoxy(x, ++y);
		cout << "      ";
		cct_gotoxy(x, ++y);
		cout << "      ";
	}
	if (ch == 'b' || ch == 'B') {
		cct_setcolor(2, 14);
		cout << "\u2554\u2550\u2557";
		cct_gotoxy(x, ++y);
		cout << "\u2551\u2605\u2551";
		cct_gotoxy(x, ++y);
		cout << "\u255A\u2550\u255D";
	}
	if (ch == 'F' || ch == 'f') {
		cct_setcolor(11, 2);
		cout << "\u2554\u2550\u2557";
		cct_gotoxy(x, ++y);
		cout << "\u2551\u25CF\u2551";
		cct_gotoxy(x, ++y);
		cout << "\u255A\u2550\u255D";
	}
	if (ch == 's' || ch == 'S') {
		cct_setcolor(9, 14);
		cout << "\u2554\u2550\u2557";
		cct_gotoxy(x, ++y);
		cout << "\u2551\u2640\u2551";
		cct_gotoxy(x, ++y);
		cout << "\u255A\u2550\u255D";
	}
	if (ch == 'r' || ch == 'R') {
		cct_setcolor(14, 12);
		cout << "\u2554\u2550\u2557";
		cct_gotoxy(x, ++y);
		cout << "\u2551\u2605\u2551";
		cct_gotoxy(x, ++y);
		cout << "\u255A\u2550\u255D";
	}
	cct_setcolor();
}

/***************************************************************************
  函数名称：read
  功    能：读取关卡
  输入参数：int cur, const char files[][MAX_LEN_OF_FILENAME]
  返 回 值：void
  说    明：
***************************************************************************/
void read(int cur, const char files[][MAX_LEN_OF_FILENAME])
{
	int x = 0, y = 0;
	char ch, name[MAX_LEN_OF_FILENAME];
	ifstream in;
	tj_strcpy(name, "..\\stage\\");
	tj_strcat(name, files[cur]);
	in.open(name, ios::in);
	if (in.is_open() == 0)
	{
		cct_gotoxy(0, 45);
		cout << "打开推箱子数据文件[" << files[cur] << "]失败，按回车键继续";
		char che;
		while (che = _getch()) {
			if (che == '\r')
				break;
		}
		cct_gotoxy(0, 45);
		cout << "                                                           ";
		return;
	}
	while (y <= 13 && !in.eof()) {
		while (x <= 15) {
			ch = in.get();
			//if (ch == '\n' && x == 0)
			//	continue;
			if (ch == '\n' && x != 0)
				break;
			if (ch != '9' && ch != 'W' && ch != 'w' && ch != '0' && ch != 'B' && ch != 'b' && ch != 'F' && ch != 'f' && ch != 'S' && ch != 's' && ch != 'R' && ch != 'r' && ch != -1 && ch != '\n') {
				cct_gotoxy(0, 45);
				cout << "推箱子数据文件[" << files[cur] << "]有非法字符(" << y + 1 << "行" << x + 1 << "列)，按回车键继续";
				char che;
				while (che = _getch()) {
					if (che == '\r')
						break;
				}
				cct_gotoxy(0, 45);
				cout << "                                                                                  ";
				return;
			}
			print_block(x, y, ch);
			x++;
		}
		if (x == 16 && !in.eof())
			while (in.peek())
				if (in.get() == '\n' || in.eof())
					break;
		x = 0;
		y++;
	}
	in.close();
	read_c();
	cct_cls();
}