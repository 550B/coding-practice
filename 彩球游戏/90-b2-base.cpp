/*2151974 ��� ������*/
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;

/***************************************************************************
  �������ƣ�print_color
  ��    �ܣ���ӡ��ɫ
  ���������const int row, const int col, const int g[][MAXG]
  �� �� ֵ��void
  ˵    ����
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
  �������ƣ�print_path
  ��    �ܣ���ӡ·��
  ���������const int row, const int col, const int i, const int j, const int p[][2]
  �� �� ֵ��void
  ˵    ����
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
  �������ƣ�print_path_color
  ��    �ܣ���ӡ��ɫ·��
  ���������const int row, const int col, const int i, const int j, const int p[][2], const int g[][MAXG]
  �� �� ֵ��void
  ˵    ����
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
  �������ƣ�print_sheet
  ��    �ܣ���ӡ����
  ���������const int row, const int col, const int g[][MAXG], const int p[][2], const int choice
  �� �� ֵ��void
  ˵    ����
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
  �������ƣ�orders_backspace
  ��    �ܣ�ģ���˸�
  ���������int X, int Y, int& x, int& y, char tmp[], const int JUDGE = 0
  �� �� ֵ��int
  ˵    ����
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
  �������ƣ�orders_check
  ��    �ܣ����ָ���Ƿ���ȷ
  ���������const int row, const int col, int n, const int tp[2][2], const int X, const int Y, int g[MAXG][MAXG], int path[][2]
  �� �� ֵ��int
  ˵    ����
***************************************************************************/
int orders_check(const int row, const int col, int n, const int tp[2][2], const int X, const int Y, int g[MAXG][MAXG], int path[][2])
{
    int x, y;
    char t[20];
    cct_getxy(x, y);
    if (n == 0) {
        if (g[tp[n][0]][tp[n][1]] == 0) {
            orders_backspace(X, Y, x, y, t), cct_gotoxy(0, y + 1);
            cout << "��ʼλ��Ϊ�գ����������룡                     ";
            Sleep(1000), orders_backspace(0, Y, x, y, t), cct_gotoxy(X, Y);
            return 0;
        }
        return 1;
    }
    if (n == 1) {
        if (g[tp[n][0]][tp[n][1]] != 0) {
            orders_backspace(X, Y, x, y, t), cct_gotoxy(0, y + 1);
            cout << "Ŀ��λ�÷ǿգ����������룡                  ";
            Sleep(1000), orders_backspace(0, Y, x, y, t), cct_gotoxy(X, Y);
            return 0;
        }
        if (!find_path(row, col, g, tp, path)) {
            orders_backspace(X, Y, x, y, t), cct_gotoxy(0, y + 1);
            cout << "�޷��ҵ��ƶ�·����                         ";
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
//  �������ƣ�orders_sign
//  ��    �ܣ������ʾ��
//  ���������const int n, int& X, int& Y, const int choice = 0
//  �� �� ֵ��void
//  ˵    ����
//***************************************************************************/
//void orders_sign(const int n, int& X, int& Y, const int choice = 0)
//{
//    if (choice && n == 0) {
//        cct_gotoxy(0, Y);
//        cout << "������ĸ+������ʽ[����c2]����Ҫ�ƶ���ľ������꣺";
//    }
//    if (choice && n == 1) {
//        cct_gotoxy(0, Y + 2);
//        cout << "������ĸ+������ʽ[����c2]����Ҫ�ƶ����Ŀ�����꣺";
//    }
//}

/***************************************************************************
  �������ƣ�orders_one
  ��    �ܣ���ȡ��һ��ָ��
  ���������const int row, const int col, int g[MAXG][MAXG], int path[][2], int tp[2][2]
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void orders_one(const int row, const int col, int g[MAXG][MAXG], int path[][2], int tp[2][2])
{
    char h[20];
    int n = 0, cnt = 0, X, Y, x, y, judge;
    cout << "������ĸ+������ʽ[����c2]����Ҫ�ƶ���ľ������꣺";
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
                    cout << endl << "����Ϊ" << h[0] << "��" << h[1] << "��                                 " << endl;
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
                cout << "����������������룡";
                cct_gotoxy(X, Y);
                continue;
            }
        }
    }
}

/***************************************************************************
  �������ƣ�orders_two
  ��    �ܣ���ȡ�ڶ���ָ��
  ���������const int row, const int col, int g[MAXG][MAXG], int path[][2], int tp[2][2]
  �� �� ֵ��int
  ˵    ����
***************************************************************************/
int orders_two(const int row, const int col, int g[MAXG][MAXG], int path[][2], int tp[2][2])
{
    char h[20];
    int n = 1, cnt = 0, X, Y, x, y, judge;
    cout << "������ĸ+������ʽ[����c2]����Ҫ�ƶ����Ŀ�����꣺";
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
                    cout << endl << "����Ϊ" << h[0] << "��" << h[1] << "��                                 " << endl;
                    break;
                }
                else if (judge == 3) {
                    cout << endl << "����Ϊ" << h[0] << "��" << h[1] << "��                                 " << endl;
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
                cout << "����������������룡";
                cct_gotoxy(X, Y);
                continue;
            }
        }
    }
    return 0;
}

/***************************************************************************
  �������ƣ�orders
  ��    �ܣ���ȡָ��
  ���������const int row, const int col, int g[MAXG][MAXG], int path[][2], int tp[2][2], const int choice
  �� �� ֵ��int
  ˵    ����
***************************************************************************/
int orders(const int row, const int col, int g[MAXG][MAXG], int path[][2], int tp[2][2], const int choice)
{
    orders_one(row, col, g, path, tp);
    return (orders_two(row, col, g, path, tp));
}