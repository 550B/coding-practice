/*2151974 ��� ������*/
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;

/***************************************************************************
  �������ƣ�new_a_graph
  ��    �ܣ�����ͼ
  ���������const int row, const int col, int g[MAXG][MAXG], const int choice = 0
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void new_a_graph(const int row, const int col, int g[MAXG][MAXG], const int choice)
{
	srand((unsigned int)(time(0)));
	int cnt;
	if (choice)
		cnt = (int)(row * col * 0.6);
	else
		cnt = 5;
	while (cnt--)
	{
		int x = rand() % col + 1;
		int y = rand() % row + 1;
		if (g[y][x] == 0)
			g[y][x] = rand() % 7 + 1;
		else
			cnt++;
	}
    for (int i = 0; i <= row + 1; i++)
        g[i][0] = 8, g[i][col + 1] = 8;
    for (int i = 0; i <= col + 1; i++)
        g[0][i] = 8, g[row + 1][i] = 8;
}

/***************************************************************************
  �������ƣ�clear_all
  ��    �ܣ����main�е��Զ���������ֵ
  ���������int& row, int& col, int g[MAXG][MAXG], int path[MAXG * MAXG][2], int tp[2][2]
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void clear_all(int& row, int& col, int g[MAXG][MAXG], int path[MAXG * MAXG][2], int tp[2][2])
{
	for (int i = 0; i < MAXG; i++)
		for (int j = 0; j < MAXG; j++)
			g[i][j] = 0;
    for (int i = 0; i < MAXG * MAXG; i++)
        path[i][0] = path[i][1] = 0;
	row = col = 0;
    tp[0][0] = 0, tp[0][1] = 0, tp[1][0] = 0, tp[1][1] = 0;
}

/***************************************************************************
  �������ƣ�orders_end
  ��    �ܣ�����End
  ���������void
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void orders_end()
{
    char h[20];
    int cnt = 0, x, y, X, Y;
    cout << "��С�������������End����...";
    cct_getxy(X, Y);
    while (1) {
        char t = _getch();
        if (cnt == 5) {
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
            if ((h[0] == 'e' || h[0] == 'E') && (h[1] == 'n' || h[1] == 'N') && (h[2] == 'd' || h[2] == 'D') && (cnt == 3))
                return;
            else {
                cnt = orders_backspace(X, Y, x, y, h, 1);
                cct_gotoxy(0, Y + 1);
                cout << "����������������룡";
                cct_gotoxy(X, Y);
            }
            //cout << "��С�������������End����...";
        }
    }
}

/***************************************************************************
  �������ƣ�to_be_continued
  ��    �ܣ���ʾ��ʾ��Ϣ�����س�
  ���������const char* prompt
  �� �� ֵ��void
  ˵    �����������������ʱ���ţ���ָ�������ѧϰ��ɺ����Ķ�
***************************************************************************/
void to_be_continued(const char* prompt)
{
    cct_setcolor(); //�ָ�ȱʡ��ɫ

    if (prompt)
        cout << prompt;
    else
        cout << "���س�������...";

    /* ���Գ��س�������������루ע�⣺_getch�Ļس���\r����getchar��\n��*/
    while (_getch() != '\r')
        ;

    cct_cls();

    return;
}

/***************************************************************************
  �������ƣ�find_path
  ��    �ܣ�Ѱ·
  ���������const int row, const int col, const int g[MAXG][MAXG], const int tp[2][2],int path[][2]
  �� �� ֵ��int
  ˵    ����
***************************************************************************/
int find_path(const int row, const int col, const int g[MAXG][MAXG], const int tp[2][2], int path[][2])
{
    int a = path[0][0] = tp[0][0], b = path[0][1] = tp[0][1], cnt = 1, gtmp[MAXG][MAXG] = {};
    for (int i = 0; i < MAXG; i++)
        for (int j = 0; j < MAXG; j++)
            gtmp[i][j] = g[i][j];
    while (1) {
        gtmp[a][b] = 9;
        if (a == tp[1][0] && b == tp[1][1])
            return 1;
        else if (gtmp[a + 1][b] == 0)
            path[cnt++][0] = ++a, path[cnt - 1][1] = b;
        else if (gtmp[a - 1][b] == 0)
            path[cnt++][0] = --a, path[cnt - 1][1] = b;
        else if (gtmp[a][b + 1] == 0)
            path[cnt++][0] = a, path[cnt - 1][1] = ++b;
        else if (gtmp[a][b - 1] == 0)
            path[cnt++][0] = a, path[cnt - 1][1] = --b;
        else {
            gtmp[a][b] = 9, a = path[--cnt][0], b = path[cnt][1], path[cnt + 1][0] = 0, path[cnt + 1][1] = 0;
            if (gtmp[a][b + 1] == 0 || gtmp[a][b - 1] == 0 || gtmp[a + 1][b] == 0 || gtmp[a - 1][b] == 0)
                cnt++;
            if (cnt == 0)
                return 0;
        }
    }
}

/***************************************************************************
  �������ƣ�whether_end
  ��    �ܣ��жϽ���
  ���������const int row, const int col, const int g[MAXG][MAXG]
  �� �� ֵ��int
  ˵    ����
***************************************************************************/
int whether_end(const int row, const int col, const int g[MAXG][MAXG])
{
    for (int i = 1; i <= row; i++)
        for (int j = 1; j <= col; j++)
            if (!g[i][j])
                return 1;
    return 0;
}

/***************************************************************************
  �������ƣ�move_only
  ��    �ܣ����Ų�յ�
  ���������const int tp[2][2], int g[MAXG][MAXG]
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void move_only(const int tp[2][2], int g[MAXG][MAXG])
{
    int tmp = g[tp[0][0]][tp[0][1]];
    g[tp[0][0]][tp[0][1]] = g[tp[1][0]][tp[1][1]];
    g[tp[1][0]][tp[1][1]] = tmp;
}

/***************************************************************************
  �������ƣ�fill_only
  ��    �ܣ������һ��
  ���������const int row, const int col, const int next[MAXN], int g[MAXG][MAXG]
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void fill_only(const int row, const int col, const int next[MAXN], int g[MAXG][MAXG])
{
    srand((unsigned int)(time(0)));
    int cnt = 3;
    while (cnt--) {
        int r = rand() % row + 1;
        int c = rand() % col + 1;
        if (!g[r][c])
            g[r][c] = next[cnt];
        else
            cnt++;
        if (!whether_end(row, col, g))
            break;
    }
}

/***************************************************************************
  �������ƣ�north
  ��    �ܣ�����north������������
  ���������const int i, const int j, int g[MAXG][MAXG]
  �� �� ֵ��int
  ˵    ����
***************************************************************************/
int north(const int i, const int j, int g[MAXG][MAXG])
{
    int cnt = 0, k;
    for (k = 1; g[i - k][j] != 8; k++) {
        if (g[i - k][j] != g[i][j])
            break;
        else
            cnt++;
    }
    if (cnt < 4)
        return 0;
    else
    {
        for (k = 1; g[i - k][j] != 8; k++) {
            if (g[i - k][j] == g[i][j])
                g[i - k][j] = 0;
            else
                break;
        }
        return cnt;
    }
}

/***************************************************************************
  �������ƣ�south
  ��    �ܣ�����south������������
  ���������const int i, const int j, int g[MAXG][MAXG]
  �� �� ֵ��int
  ˵    ����
***************************************************************************/
int south(const int i, const int j, int g[MAXG][MAXG])
{
    int cnt = 0, k;
    for (k = 1; g[i + k][j] != 8; k++) {
        if (g[i + k][j] != g[i][j])
            break;
        else
            cnt++;
    }
    if (cnt < 4)
        return 0;
    else
    {
        for (k = 1; g[i + k][j] != 8; k++) {
            if (g[i + k][j] == g[i][j])
                g[i + k][j] = 0;
            else
                break;
        }
        return cnt;
    }
}

/***************************************************************************
  �������ƣ�east
  ��    �ܣ�����east������������
  ���������const int i, const int j, int g[MAXG][MAXG]
  �� �� ֵ��int
  ˵    ����
***************************************************************************/
int east(const int i, const int j, int g[MAXG][MAXG])
{
    int cnt = 0, k;
    for (k = 1; g[i][j + k] != 8; k++) {
        if (g[i][j + k] != g[i][j])
            break;
        else
            cnt++;
    }
    if (cnt < 4)
        return 0;
    else
    {
        for (k = 1; g[i][j + k] != 8; k++) {
            if (g[i][j + k] == g[i][j])
                g[i][j + k] = 0;
            else
                break;
        }
        return cnt;
    }
}

/***************************************************************************
  �������ƣ�west
  ��    �ܣ�����west������������
  ���������const int i, const int j, int g[MAXG][MAXG]
  �� �� ֵ��int
  ˵    ����
***************************************************************************/
int west(const int i, const int j, int g[MAXG][MAXG])
{
    int cnt = 0, k;
    for (k = 1; g[i][j - k] != 8; k++) {
        if (g[i][j - k] != g[i][j])
            break;
        else
            cnt++;
    }
    if (cnt < 4)
        return 0;
    else
    {
        for (k = 1; g[i][j - k] != 8; k++) {
            if (g[i][j - k] == g[i][j])
                g[i][j - k] = 0;
            else
                break;
        }
        return cnt;
    }
}

/***************************************************************************
  �������ƣ�northeast
  ��    �ܣ�����northeast������������
  ���������const int i, const int j, int g[MAXG][MAXG]
  �� �� ֵ��int
  ˵    ����
***************************************************************************/
int northeast(const int i, const int j, int g[MAXG][MAXG])
{
    int cnt = 0, k;
    for (k = 1; g[i - k][j + k] != 8; k++) {
        if (g[i - k][j + k] != g[i][j])
            break;
        else
            cnt++;
    }
    if (cnt < 4)
        return 0;
    else
    {
        for (k = 1; g[i - k][j + k] != 8; k++) {
            if (g[i - k][j + k] == g[i][j])
                g[i - k][j + k] = 0;
            else
                break;
        }
        return cnt;
    }
}

/***************************************************************************
  �������ƣ�southeast
  ��    �ܣ�����southeast������������
  ���������const int i, const int j, int g[MAXG][MAXG]
  �� �� ֵ��int
  ˵    ����
***************************************************************************/
int southeast(const int i, const int j, int g[MAXG][MAXG])
{
    int cnt = 0, k;
    for (k = 1; g[i + k][j + k] != 8; k++) {
        if (g[i + k][j + k] != g[i][j])
            break;
        else
            cnt++;
    }
    if (cnt < 4)
        return 0;
    else
    {
        for (k = 1; g[i + k][j + k] != 8; k++) {
            if (g[i + k][j + k] == g[i][j])
                g[i + k][j + k] = 0;
            else
                break;
        }
        return cnt;
    }
}

/***************************************************************************
  �������ƣ�northwest
  ��    �ܣ�����northwest������������
  ���������const int i, const int j, int g[MAXG][MAXG]
  �� �� ֵ��int
  ˵    ����
***************************************************************************/
int northwest(const int i, const int j, int g[MAXG][MAXG])
{
    int cnt = 0, k;
    for (k = 1; g[i - k][j - k] != 8; k++) {
        if (g[i - k][j - k] != g[i][j])
            break;
        else
            cnt++;
    }
    if (cnt < 4)
        return 0;
    else
    {
        for (k = 1; g[i - k][j - k] != 8; k++) {
            if (g[i - k][j - k] == g[i][j])
                g[i - k][j - k] = 0;
            else
                break;
        }
        return cnt;
    }
}

/***************************************************************************
  �������ƣ�southwest
  ��    �ܣ�����southwest������������
  ���������const int i, const int j, int g[MAXG][MAXG]
  �� �� ֵ��int
  ˵    ����
***************************************************************************/
int southwest(const int i, const int j, int g[MAXG][MAXG])
{
    int cnt = 0, k;
    for (k = 1; g[i + k][j - k] != 8; k++) {
        if (g[i + k][j - k] != g[i][j])
            break;
        else
            cnt++;
    }
    if (cnt < 4)
        return 0;
    else
    {
        for (k = 1; g[i + k][j - k] != 8; k++) {
            if (g[i + k][j - k] == g[i][j])
                g[i + k][j - k] = 0;
            else
                break;
        }
        return cnt;
    }
}

/***************************************************************************
  �������ƣ�five
  ��    �ܣ��������
  ���������const int row, const int col, int g[MAXG][MAXG]
  �� �� ֵ��int
  ˵    ����
***************************************************************************/
int five(const int row, const int col, int g[MAXG][MAXG])
{
    int pts = 0, n = 0, s = 0, w = 0, e = 0, ne = 0, se = 0, nw = 0, sw = 0;
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            if (g[i][j] == 0)
                continue;
            n = north(i, j, g);
            s = south(i, j, g);
            e = east(i, j, g);
            ne = northeast(i, j, g);
            se = southeast(i, j, g);
            w = west(i, j, g);
            nw = northwest(i, j, g);
            sw = southwest(i, j, g);
            if (n + s + e + w + ne + se + nw + sw != 0)
            {
                pts += n + s + e + w + ne + se + nw + sw + 1;
                g[i][j] = 0;
            }
        }
    }
    return (pts);
}

/***************************************************************************
  �������ƣ�next_three
  ��    �ܣ����ɺ������������
  ���������int n[MAXN], const int choice
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void next_three(int n[MAXN], const int choice)
{
    srand((unsigned int)(time(0)));
    for (int i = 0; i < MAXN; i++)
    {
        n[i] = rand() % 7 + 1;
    }
    if (choice)
    {
        cout << "��3���������ɫ�ֱ��ǣ�";
        for (int i = 0; i < MAXN; i++)
            cout << n[i] << " ";
    }
    cout << endl;
}