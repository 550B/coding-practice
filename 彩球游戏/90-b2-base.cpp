/*2151974 软件 赵明泽*/
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;

/***************************************************************************
  函数名称：print_color
  功    能：打印彩色
  输入参数：const int row, const int col, const int g[][MAXG]
  返 回 值：void
  说    明：
***************************************************************************/
void print_color(const int i, const int j, const int g[][MAXG])
{
    if (g[i][j] > 0) {
        cct_setcolor(14, color[g[i][j]]);
        cout << g[i][j];
        cct_setcolor();
    }
    else
        cout << g[i][j];
}

/***************************************************************************
  函数名称：print_path
  功    能：打印路径
  输入参数：const int row, const int col, const int i, const int j, const int p[][2]
  返 回 值：void
  说    明：
***************************************************************************/
void print_path(const int row, const int col, const int i, const int j, const int p[][2])
{
    int cnt = 0, sign = 0;
    while (p[cnt][0] && p[cnt][1]) {
        if (p[cnt][0] == i && p[cnt][1] == j) {
            cout << "*";
            sign = 1;
            break;
        }
        cnt++;
    }
    if (!sign)
        cout << "0";
}

/***************************************************************************
  函数名称：print_path_color
  功    能：打印彩色路径
  输入参数：const int row, const int col, const int i, const int j, const int p[][2], const int g[][MAXG]
  返 回 值：void
  说    明：
***************************************************************************/
void print_path_color(const int row, const int col, const int i, const int j, const int p[][2], const int g[][MAXG])
{
    int cnt = 0, sign = 0;
    while (p[cnt][0] && p[cnt][1]) {
        if (p[cnt][0] == i && p[cnt][1] == j) {
            sign = 1;
            break;
        }
        cnt++;
    }
    if (sign)
        cct_setcolor(14);
    cout << g[i][j];
    if (sign)
        cct_setcolor();
}

/***************************************************************************
  函数名称：print_sheet
  功    能：打印场面
  输入参数：const int row, const int col, const int g[][MAXG], const int p[][2], const int choice
  返 回 值：void
  说    明：
***************************************************************************/
void print_sheet(const int row, const int col, const int g[][MAXG], const int p[][2], const int choice)
{
	for (int i = 0; i <= col; i++){
		if (i == 0)
			cout << "  |";
		else
			cout << "  " << i;
	}
	cout << endl;
	for (int i = 0; i <= col; i++){
		if (i == 0)
			cout << "--+";
		else
			cout << "---";
	}
	cout << endl;
	for (int i = 1; i <= row; i++){
		for (int j = 0; j <= col; j++){
			if (j == 0)
				cout << (char)('A' + i - 1) << " |";
			else{
				cout << "  ";
                if (choice == 0)
                    print_color(i, j, g);
                if (choice == 1)
                    print_path(row, col, i, j, p);
                if (choice == 2)
                    print_path_color(row, col, i, j, p, g);
			}
		}
		cout << endl;
	}
	cout << endl;
}

/***************************************************************************
  函数名称：orders_backspace
  功    能：模拟退格
  输入参数：int X, int Y, int& x, int& y, char tmp[], const int JUDGE = 0
  返 回 值：int
  说    明：
***************************************************************************/
int orders_backspace(int X, int Y, int& x, int& y, char tmp[], const int JUDGE)
{
	cct_getxy(x, y);
	while (x > X)
	{
		cct_gotoxy(--x, y);
		putchar(' ');
	}
	for (int i = 0; i < 20; i++)
		tmp[i] = 0;
	return 0;
}

/***************************************************************************
  函数名称：orders_check
  功    能：检查指令是否正确
  输入参数：const int row, const int col, int n, const int tp[2][2], const int X, const int Y, int g[MAXG][MAXG], int path[][2]
  返 回 值：int
  说    明：
***************************************************************************/
int orders_check(const int row, const int col, int n, const int tp[2][2], const int X, const int Y, int g[MAXG][MAXG], int path[][2])
{
    int x, y;
    char t[20];
    cct_getxy(x, y);
    if (n == 0) {
        if (g[tp[n][0]][tp[n][1]] == 0) {
            orders_backspace(X, Y, x, y, t), cct_gotoxy(0, y + 1);
            cout << "起始位置为空，请重新输入！                     ";
            Sleep(1000), orders_backspace(0, Y, x, y, t), cct_gotoxy(X, Y);
            return 0;
        }
        return 1;
    }
    if (n == 1) {
        if (g[tp[n][0]][tp[n][1]] != 0) {
            orders_backspace(X, Y, x, y, t), cct_gotoxy(0, y + 1);
            cout << "目标位置非空，请重新输入！                  ";
            Sleep(1000), orders_backspace(0, Y, x, y, t), cct_gotoxy(X, Y);
            return 0;
        }
        if (!find_path(row, col, g, tp, path)) {
            orders_backspace(X, Y, x, y, t), cct_gotoxy(0, y + 1);
            cout << "无法找到移动路径！                         ";
            for (int k = 0; k < MAXG * MAXG; k++)
                path[k][0] = path[k][1] = 0;
            Sleep(1000), orders_backspace(0, Y, x, y, t), cct_gotoxy(X, Y);
            return 3;
        }
        return 2;
    }
    return 0;
}

///***************************************************************************
//  函数名称：orders_sign
//  功    能：输出提示语
//  输入参数：const int n, int& X, int& Y, const int choice = 0
//  返 回 值：void
//  说    明：
//***************************************************************************/
//void orders_sign(const int n, int& X, int& Y, const int choice = 0)
//{
//    if (choice && n == 0) {
//        cct_gotoxy(0, Y);
//        cout << "请以字母+数字形式[例：c2]输入要移动球的矩阵坐标：";
//    }
//    if (choice && n == 1) {
//        cct_gotoxy(0, Y + 2);
//        cout << "请以字母+数字形式[例：c2]输入要移动球的目的坐标：";
//    }
//}

/***************************************************************************
  函数名称：orders_one
  功    能：读取第一条指令
  输入参数：const int row, const int col, int g[MAXG][MAXG], int path[][2], int tp[2][2]
  返 回 值：void
  说    明：
***************************************************************************/
void orders_one(const int row, const int col, int g[MAXG][MAXG], int path[][2], int tp[2][2])
{
    char h[20];
    int n = 0, cnt = 0, X, Y, x, y, judge;
    cout << "请以字母+数字形式[例：c2]输入要移动球的矩阵坐标：";
    cct_getxy(X, Y);
    while (1) {
        char t = _getch();
        if (cnt == 20) {
            cnt = orders_backspace(X, Y, x, y, h);
            continue;
        }
        if (t >= 33 && t <= 126) {
            putchar(t);
            if (t >= 'a' && t <= 'z')
                t -= 'a' - 'A';
            h[cnt++] = t;
        }
        if (t == '\r') {
            if (h[0] >= 'A' && h[0] <= 'A' + row - 1 && h[1] >= '1' && h[1] <= '1' + col - 1 && cnt == 2) {
                tp[n][0] = h[0] - 'A' + 1, tp[n][1] = h[1] - '0';
                judge = orders_check(row, col, n, tp, X, Y, g, path);
                if (judge == 1) {
                    cout << endl << "输入为" << h[0] << "行" << h[1] << "列                                 " << endl;
                    break;
                }
                else {
                    cnt = orders_backspace(X, Y, x, y, h, 1);
                    continue;
                }
            }
            else {
                cnt = orders_backspace(X, Y, x, y, h, 1);
                cct_gotoxy(0, Y + 1);
                cout << "输入错误，请重新输入！";
                cct_gotoxy(X, Y);
                continue;
            }
        }
    }
}

/***************************************************************************
  函数名称：orders_two
  功    能：读取第二条指令
  输入参数：const int row, const int col, int g[MAXG][MAXG], int path[][2], int tp[2][2]
  返 回 值：int
  说    明：
***************************************************************************/
int orders_two(const int row, const int col, int g[MAXG][MAXG], int path[][2], int tp[2][2])
{
    char h[20];
    int n = 1, cnt = 0, X, Y, x, y, judge;
    cout << "请以字母+数字形式[例：c2]输入要移动球的目的坐标：";
    cct_getxy(X, Y);
    while (1) {
        char t = _getch();
        if (cnt == 20) {
            cnt = orders_backspace(X, Y, x, y, h);
            continue;
        }
        if (t >= 33 && t <= 126) {
            putchar(t);
            if (t >= 'a' && t <= 'z')
                t -= 'a' - 'A';
            h[cnt++] = t;
        }
        if (t == '\r') {
            if (h[0] >= 'A' && h[0] <= 'A' + row - 1 && h[1] >= '1' && h[1] <= '1' + col - 1 && cnt == 2) {
                tp[n][0] = h[0] - 'A' + 1, tp[n][1] = h[1] - '0';
                judge = orders_check(row, col, n, tp, X, Y, g, path);
                if (judge == 2) {
                    cout << endl << "输入为" << h[0] << "行" << h[1] << "列                                 " << endl;
                    break;
                }
                else if (judge == 3) {
                    cout << endl << "输入为" << h[0] << "行" << h[1] << "列                                 " << endl;
                    return 1;
                }
                else {
                    cnt = orders_backspace(X, Y, x, y, h, 1);
                    continue;
                }
            }
            else {
                cnt = orders_backspace(X, Y, x, y, h, 1);
                cct_gotoxy(0, Y + 1);
                cout << "输入错误，请重新输入！";
                cct_gotoxy(X, Y);
                continue;
            }
        }
    }
    return 0;
}

/***************************************************************************
  函数名称：orders
  功    能：读取指令
  输入参数：const int row, const int col, int g[MAXG][MAXG], int path[][2], int tp[2][2], const int choice
  返 回 值：int
  说    明：
***************************************************************************/
int orders(const int row, const int col, int g[MAXG][MAXG], int path[][2], int tp[2][2], const int choice)
{
    orders_one(row, col, g, path, tp);
    return (orders_two(row, col, g, path, tp));
}