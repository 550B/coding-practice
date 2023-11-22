/*2151974 软件 赵明泽*/
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;

/***************************************************************************
  函数名称：new_a_graph
  功    能：创建图
  输入参数：const int row, const int col, int g[MAXG][MAXG], const int choice = 0
  返 回 值：void
  说    明：
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
  函数名称：clear_all
  功    能：清空main中的自动变量数组值
  输入参数：int& row, int& col, int g[MAXG][MAXG], int path[MAXG * MAXG][2], int tp[2][2]
  返 回 值：void
  说    明：
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
  函数名称：orders_end
  功    能：输入End
  输入参数：void
  返 回 值：void
  说    明：
***************************************************************************/
void orders_end()
{
    char h[20];
    int cnt = 0, x, y, X, Y;
    cout << "本小题结束，请输入End继续...";
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
                cout << "输入错误，请重新输入！";
                cct_gotoxy(X, Y);
            }
            //cout << "本小题结束，请输入End继续...";
        }
    }
}

/***************************************************************************
  函数名称：to_be_continued
  功    能：显示提示信息，读回车
  输入参数：const char* prompt
  返 回 值：void
  说    明：如果读不懂，暂时放着，等指针和引用学习完成后再阅读
***************************************************************************/
void to_be_continued(const char* prompt)
{
    cct_setcolor(); //恢复缺省颜色

    if (prompt)
        cout << prompt;
    else
        cout << "按回车键继续...";

    /* 忽略除回车键外的所有输入（注意：_getch的回车是\r，而getchar是\n）*/
    while (_getch() != '\r')
        ;

    cct_cls();

    return;
}

/***************************************************************************
  函数名称：find_path
  功    能：寻路
  输入参数：const int row, const int col, const int g[MAXG][MAXG], const int tp[2][2],int path[][2]
  返 回 值：int
  说    明：
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
  函数名称：whether_end
  功    能：判断结束
  输入参数：const int row, const int col, const int g[MAXG][MAXG]
  返 回 值：int
  说    明：
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
  函数名称：move_only
  功    能：起点挪终点
  输入参数：const int tp[2][2], int g[MAXG][MAXG]
  返 回 值：void
  说    明：
***************************************************************************/
void move_only(const int tp[2][2], int g[MAXG][MAXG])
{
    int tmp = g[tp[0][0]][tp[0][1]];
    g[tp[0][0]][tp[0][1]] = g[tp[1][0]][tp[1][1]];
    g[tp[1][0]][tp[1][1]] = tmp;
}

/***************************************************************************
  函数名称：fill_only
  功    能：填充下一个
  输入参数：const int row, const int col, const int next[MAXN], int g[MAXG][MAXG]
  返 回 值：void
  说    明：
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
  函数名称：north
  功    能：返回north方可消除个数
  输入参数：const int i, const int j, int g[MAXG][MAXG]
  返 回 值：int
  说    明：
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
  函数名称：south
  功    能：返回south方可消除个数
  输入参数：const int i, const int j, int g[MAXG][MAXG]
  返 回 值：int
  说    明：
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
  函数名称：east
  功    能：返回east方可消除个数
  输入参数：const int i, const int j, int g[MAXG][MAXG]
  返 回 值：int
  说    明：
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
  函数名称：west
  功    能：返回west方可消除个数
  输入参数：const int i, const int j, int g[MAXG][MAXG]
  返 回 值：int
  说    明：
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
  函数名称：northeast
  功    能：返回northeast方可消除个数
  输入参数：const int i, const int j, int g[MAXG][MAXG]
  返 回 值：int
  说    明：
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
  函数名称：southeast
  功    能：返回southeast方可消除个数
  输入参数：const int i, const int j, int g[MAXG][MAXG]
  返 回 值：int
  说    明：
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
  函数名称：northwest
  功    能：返回northwest方可消除个数
  输入参数：const int i, const int j, int g[MAXG][MAXG]
  返 回 值：int
  说    明：
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
  函数名称：southwest
  功    能：返回southwest方可消除个数
  输入参数：const int i, const int j, int g[MAXG][MAXG]
  返 回 值：int
  说    明：
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
  函数名称：five
  功    能：检查连线
  输入参数：const int row, const int col, int g[MAXG][MAXG]
  返 回 值：int
  说    明：
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
  函数名称：next_three
  功    能：生成后续三个随机数
  输入参数：int n[MAXN], const int choice
  返 回 值：void
  说    明：
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
        cout << "下3个彩球的颜色分别是：";
        for (int i = 0; i < MAXN; i++)
            cout << n[i] << " ";
    }
    cout << endl;
}