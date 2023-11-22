/*2151974 ��� ������*/
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <iomanip>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;

/***************************************************************************
  �������ƣ�print_border
  ��    �ܣ���ӡ�߿�
  ���������const int row, const int col, const int g[MAXG][MAXG], const int choice
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void print_border(const int row, const int col, const int g[MAXG][MAXG], const int choice)
{
	cct_setcolor(15, 0);
	cout << "\u2554";
	for (int i = 1; i <= col; i++)
		cout << "\u2550";
	cout << "\u2557" << endl;
	for (int i = 1; i <= row; i++) {
		cout << "\u2551";
		for (int j = 1; j <= col; j++) {
			if (g[i][j]) {
				cct_setcolor(color[g[i][j]]);
				cout << "\u3007";
			}
			else
				cout << "  ";
			cct_setcolor(15, 0);
		}
		cout << "\u2551" << endl;
	}
	cout << "\u255A";
	for (int i = 1; i <= col; i++)
		cout << "\u2550";
	cout << "\u255D" << endl;
	cct_setcolor();
}

/***************************************************************************
  �������ƣ�print_block
  ��    �ܣ���ӡ����
  ���������const int row, const int col, const int g[MAXG][MAXG]
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void print_block(const int row, const int col, const int g[MAXG][MAXG])
{
	cct_setcolor(15, 0);
	cout << "\u2554";
	for (int i = 1; i <= col; i++) {
			cout << "\u2550";
		if (i != col)
			cout << "\u2566";
	}
	cout << "\u2557" << endl;
	for (int i = 1; i <= row; i++) {
		cout << "\u2551";
		for (int j = 1; j <= col; j++) {
			if (g[i][j]) {
				cct_setcolor(color[g[i][j]]);
				cout << "\u3007";
			}
			else
				cout << "  ";
			cct_setcolor(15, 0);
			cout << "\u2551";
		}
		cout << endl;
		if(i!=row){
			cout << "\u2560";
			for (int j = 1; j <= col; j++) {
				cout << "\u2550";
				if (j != col)
					cout << "\u256C";
			}
			cout << "\u2563" << endl;
		}
	}
	cout << "\u255A";
	for (int i = 1; i <= col; i++) {
		cout << "\u2550";
		if (i != col)
			cout << "\u2569";
	}
	cout << "\u255D" << endl;
	cct_setcolor();
}

/***************************************************************************
  �������ƣ�move_up
  ��    �ܣ��ƶ�
  ���������int x, int y, int X, int Y, const int Farben
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void move_up(int y, int x, int X, int Y, const int Farben)
{
	int xs = 4 * x - 2, ys = y * 2;
	cct_gotoxy(xs, ys);
	cct_setcolor(15, 0);
	cout << "  ";
	cct_gotoxy(xs, --ys);
	cct_setcolor(Farben);
	cout << "\u25CF";
	Sleep(100);
	cct_setcolor(15, 0);
	cct_gotoxy(xs, ys);
	cout << "\u2550";
	cct_gotoxy(xs, --ys);
	cct_setcolor(Farben);
	cout << "\u25CF";
	Sleep(100);
	cct_setcolor();
}

/***************************************************************************
  �������ƣ�move_down
  ��    �ܣ��ƶ�
  ���������int x, int y, int X, int Y, const int Farben
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void move_down(int y, int x, int X, int Y, const int Farben)
{
	int xs = 4 * x - 2, ys = y * 2;
	cct_gotoxy(xs, ys);
	cct_setcolor(15, 0);
	cout << "  ";
	cct_gotoxy(xs, ++ys);
	cct_setcolor(Farben);
	cout << "\u25CF";
	Sleep(100);
	cct_setcolor(15, 0);
	cct_gotoxy(xs, ys);
	cout << "\u2550";
	cct_gotoxy(xs, ++ys);
	cct_setcolor(Farben);
	cout << "\u25CF";
	Sleep(100);
	cct_setcolor();
}

/***************************************************************************
  �������ƣ�move_left
  ��    �ܣ��ƶ�
  ���������int x, int y, int X, int Y, const int Farben
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void move_left(int y, int x, int X, int Y, const int Farben)
{
	int xs = 4 * x - 2, ys = y * 2;
	cct_gotoxy(xs, ys);
	cct_setcolor(15, 0);
	cout << "  ";
	cct_gotoxy(----xs, ys);
	cct_setcolor(Farben);
	cout << "\u25CF";
	Sleep(100);
	cct_setcolor(15, 0);
	cct_gotoxy(xs, ys);
	cout << "\u2551";
	cct_gotoxy(----xs, ys);
	cct_setcolor(Farben);
	cout << "\u25CF";
	Sleep(100);
	cct_setcolor();
}

/***************************************************************************
  �������ƣ�move_right
  ��    �ܣ��ƶ�
  ���������int x, int y, int X, int Y, const int Farben
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void move_right(int y, int x, int X, int Y, const int Farben)
{
	int xs = 4 * x - 2, ys = y * 2;
	cct_gotoxy(xs, ys);
	cct_setcolor(15, 0);
	cout << "  ";
	cct_gotoxy(++++xs, ys);
	cct_setcolor(Farben);
	cout << "\u25CF";
	Sleep(100);
	cct_setcolor(15, 0);
	cct_gotoxy(xs, ys);
	cout << "\u2551";
	cct_gotoxy(++++xs, ys);
	cct_setcolor(Farben);
	cout << "\u25CF";
	Sleep(100);
	cct_setcolor();
}

/***************************************************************************
  �������ƣ�move_all
  ��    �ܣ��ƶ�
  ���������const int row, const int col, const int g[MAXG][MAXG], int tp[2][2], int path[][2]
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void move_all(const int row, const int col, const int g[MAXG][MAXG], int tp[2][2], int path[][2])
{
	int cnt = 0;
	int Farben = color[g[tp[0][0]][tp[0][1]]];
	while(1)
	{
		if (path[cnt][0] == tp[1][0] && path[cnt][1] == tp[1][1]) {
			cct_gotoxy(4 * tp[1][1] - 2, 2 * tp[1][0]);
			cct_setcolor(Farben);
			cout << "\u3007";
			cct_setcolor();
			break;
		}
		if (path[cnt][1] == path[cnt + 1][1] && path[cnt][0] > path[cnt + 1][0])
			move_up(path[cnt][0], path[cnt][1], path[cnt + 1][0], path[cnt + 1][1], Farben);
		if (path[cnt][1] == path[cnt + 1][1] && path[cnt][0] < path[cnt + 1][0])
			move_down(path[cnt][0], path[cnt][1], path[cnt + 1][0], path[cnt + 1][1], Farben);
		if (path[cnt][0] == path[cnt + 1][0] && path[cnt][1] > path[cnt + 1][1])
			move_left(path[cnt][0], path[cnt][1], path[cnt + 1][0], path[cnt + 1][1], Farben);
		if (path[cnt][0] == path[cnt + 1][0] && path[cnt][1] < path[cnt + 1][1])
			move_right(path[cnt][0], path[cnt][1], path[cnt + 1][0], path[cnt + 1][1], Farben);
		cnt++;
	}
}

/***************************************************************************
  �������ƣ�show_mouse
  ��    �ܣ���ʾ���
  ���������const int row, const int col, const int g[MAXG][MAXG], int tp[2][2], int path[][2]
  �� �� ֵ��int
  ˵    ����
***************************************************************************/
int show_mouse(const int row, const int col, const int g[MAXG][MAXG], int tp[2][2], int path[][2])
{
	int X = 0, Y = 2 * row + 2, x, y, ret, maction, keycode1, keycode2, loop = 1, sign = 0, xt, yt;
	cct_enable_mouse(), cct_setcursor(CURSOR_INVISIBLE);	//�رչ��
	while (loop) {
		ret = cct_read_keyboard_and_mouse(x, y, maction, keycode1, keycode2);
		if (ret == CCT_MOUSE_EVENT) {
			cct_gotoxy(X, Y);
			if ((x % 4 == 2 || x % 4 == 3) && y >= 2 && y <= 2 * row + 1 && x >= 2 && x <= 4 * col - 1){
				if (maction == MOUSE_LEFT_BUTTON_CLICK && g[y / 2][x / 4 + 1] == 0 && y % 2 == 0 && sign) {
					tp[0][0] = yt / 2, tp[0][1] = xt / 4 + 1, tp[1][0] = y / 2, tp[1][1] = x / 4 + 1;
					if (find_path(row, col, g, tp, path)) {
						cout << "[��ʾ] ���Դ�[" << (char)('A' + tp[0][0] - 1) << tp[0][1] << "]�ƶ���[" << (char)('A' + tp[1][0] - 1) << tp[1][1] << "]";
						move_all(row, col, g, tp, path);
						cct_gotoxy(0, 2 * row + 2), cout << "                                          ", cct_gotoxy(0, 2 * row + 2);
						cct_disable_mouse(), cct_setcursor(CURSOR_VISIBLE_NORMAL);
						return 1;
					}
					else {
						cout << "[����] �޷���[" << (char)('A' + tp[0][0] - 1) << tp[0][1] << "]�ƶ���[" << (char)('A' + tp[1][0] - 1) << tp[1][1] << "]";
						continue;
					}
				}
				if (maction == MOUSE_RIGHT_BUTTON_CLICK)
					break;
				cout << "[��ǰ���] " << (char)('A' + y / 2 - 1) << "��" << x / 4 + 1 << "��          ";
				if (maction == MOUSE_LEFT_BUTTON_CLICK && g[y / 2][x / 4 + 1] && y % 2 == 0 && sign && (((yt / 2) != (y / 2)) || ((xt / 4 + 1) != (x / 4 + 1)))) {
					sign = 0;
					cct_gotoxy(xt, yt);
					cct_setcolor(color[g[yt / 2][xt / 4 + 1]]);
					cout << "\u3007";
					cct_setcolor();
				}
				if (maction == MOUSE_LEFT_BUTTON_CLICK && g[y / 2][x / 4 + 1] && y % 2 == 0) {
					if (x % 4 == 3)
						x--;
					cct_gotoxy(x, y);
					cct_setcolor(color[g[y / 2][x / 4 + 1]]);
					cout << "\u25CF";
					cct_setcolor();
					sign = 1, xt = x, yt = y;
				}
			}
		}
	}
	cct_disable_mouse(), cct_setcursor(CURSOR_VISIBLE_NORMAL);
	return 0;
}

/***************************************************************************
  �������ƣ�print_score
  ��    �ܣ���ӡ������
  ���������const int score
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void print_score(const int score)
{
	cct_gotoxy(40, 1);
	cct_setcolor(15, 0);
	cout << "\u2554\u2550\u2550\u2550\u2550\u2550\u2557";
	cct_gotoxy(40, 2);
	cout << "\u2551�÷֣�" << setw(4) << setiosflags(ios::left) << score << "\u2551";
	cct_gotoxy(40, 3);
	cout << "\u255A\u2550\u2550\u2550\u2550\u2550\u255D";
	cct_setcolor();
}

/***************************************************************************
  �������ƣ�print_next
  ��    �ܣ���ӡ��������������
  ���������const int next[]
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void print_next(const int next[])
{
	cct_gotoxy(40, 5);
	cct_setcolor(15, 0);
	cout << "\u2554\u2550\u2566\u2550\u2566\u2550\u2557";
	cct_gotoxy(40, 6);
	cout << "\u2551";
	cct_setcolor(color[next[0]]);
	cout << "\u3007";
	cct_setcolor(15, 0);
	cout << "\u2551";
	cct_setcolor(color[next[1]]);
	cout << "\u3007";
	cct_setcolor(15, 0);
	cout << "\u2551";
	cct_setcolor(color[next[2]]);
	cout << "\u3007";
	cct_setcolor(15, 0);
	cout << "\u2551";
	cct_gotoxy(40, 7);
	cout << "\u255A\u2550\u2569\u2550\u2569\u2550\u255D";
	cct_setcolor();
}

/***************************************************************************
  �������ƣ�count_five
  ��    �ܣ�ͳ������
  ���������const int row, const int col, const int g[MAXG][MAXG], int count[]
  �� �� ֵ��int
  ˵    ����
***************************************************************************/
int count_five(const int row, const int col, const int g[MAXG][MAXG], int count[])
{
	int tmp[8] = {}, num = 0;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			tmp[g[i][j]]++;
	for (int i = 0; i < 8; i++)
		if (tmp[i] < count[i])
			num = i * 100 + (count[i] - tmp[i]);
	for (int i = 0; i < 8; i++)
		count[i] = tmp[i];
	return num;
}

/***************************************************************************
  �������ƣ�print_count
  ��    �ܣ���ӡͳ����
  ���������const int row, const int col, int count[], int xiaochu[]
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void print_count(const int row, const int col, int count[], int xiaochu[])
{
	cct_gotoxy(40, 9), cct_setcolor(15, 0);
	cout << "\u2554\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2557";
	cct_gotoxy(40, 10);
	cout << "\u2551  :" << resetiosflags(ios::left)<< setw(2) << setfill('0') << count[0] << "/(" << setw(5) << setiosflags(ios::fixed) << setprecision(2) << setfill(' ') << (double)(((double)count[0] / (double)row / (double)col) * 100) << "%) ����-0   " << "\u2551";
	cct_gotoxy(40, 11), cout << "\u2551", cct_setcolor(color[1]), cout << "\u3007", cct_setcolor(15, 0);
	cout << ":" << resetiosflags(ios::left) << setw(2) << setfill('0') << count[1] << "/(" << setw(5) << setprecision(2) << setfill(' ') << (double)(((double)count[1] / (double)row / (double)col) * 100) << "%) ����-" << setw(4) << setfill(' ') << setiosflags(ios::left) << xiaochu[1] << "\u2551";
	cct_gotoxy(40, 12), cout << "\u2551", cct_setcolor(color[2]), cout << "\u3007", cct_setcolor(15, 0);
	cout << ":" << resetiosflags(ios::left) << setw(2) << setfill('0') << count[2] << "/(" << setw(5) << setprecision(2) << setfill(' ') << (double)(((double)count[2] / (double)row / (double)col) * 100) << "%) ����-" << setw(4) << setfill(' ') << setiosflags(ios::left) << xiaochu[2] << "\u2551";
	cct_gotoxy(40, 13);
	cout << "\u2551";
	cct_setcolor(color[3]);
	cout << "\u3007";
	cct_setcolor(15, 0);
	cout << ":" << resetiosflags(ios::left) << setw(2) << setfill('0') << count[3] << "/(" << setw(5) << setprecision(2) << setfill(' ') << (double)(((double)count[3] / (double)row / (double)col) * 100) << "%) ����-" << setw(4) << setfill(' ') << setiosflags(ios::left) << xiaochu[3] << "\u2551";
	cct_gotoxy(40, 14);
	cout << "\u2551";
	cct_setcolor(color[4]);
	cout << "\u3007";
	cct_setcolor(15, 0);
	cout << ":" << resetiosflags(ios::left) << setw(2) << setfill('0') << count[4] << "/(" << setw(5) << setprecision(2) << setfill(' ') << (double)(((double)count[4] / (double)row / (double)col) * 100) << "%) ����-" << setw(4) << setfill(' ') << setiosflags(ios::left) << xiaochu[4] << "\u2551";
	cct_gotoxy(40, 15);
	cout << "\u2551";
	cct_setcolor(color[5]);
	cout << "\u3007";
	cct_setcolor(15, 0);
	cout << ":" << resetiosflags(ios::left) << setw(2) << setfill('0') << count[5] << "/(" << setw(5) << setprecision(2) << setfill(' ') << (double)(((double)count[5] / (double)row / (double)col) * 100) << "%) ����-" << setw(4) << setfill(' ') << setiosflags(ios::left) << xiaochu[5] << "\u2551";
	cct_gotoxy(40, 16);
	cout << "\u2551";
	cct_setcolor(color[6]);
	cout << "\u3007";
	cct_setcolor(15, 0);
	cout << ":" << resetiosflags(ios::left) << setw(2) << setfill('0') << count[6] << "/(" << setw(5) << setprecision(2) << setfill(' ') << (double)(((double)count[6] / (double)row / (double)col) * 100) << "%) ����-" << setw(4) << setfill(' ') << setiosflags(ios::left) << xiaochu[6] << "\u2551";
	cct_gotoxy(40, 17);
	cout << "\u2551";
	cct_setcolor(color[7]);
	cout << "\u3007";
	cct_setcolor(15, 0);
	cout << ":" << resetiosflags(ios::left) << setw(2) << setfill('0') << count[7] << "/(" << setw(5) << setprecision(2) << setfill(' ') << (double)(((double)count[7] / (double)row / (double)col) * 100) << "%) ����-" << setw(4) << setfill(' ') << setiosflags(ios::left) << xiaochu[7] << "\u2551";
	cct_gotoxy(40, 18), cct_setcolor(15, 0);
	cout << "\u255A\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u255D";
	cct_setcolor();
}