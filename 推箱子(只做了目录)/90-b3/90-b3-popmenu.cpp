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
  函数名称：tj_strlen
  功    能：字符串长度
  输入参数：const char* str
  返 回 值：int
  说    明：
***************************************************************************/
int tj_strlen(const char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* p = str;
    const char* q = str;
    if (p == NULL)
        return 0;
    while (*p != '\0')
        p++;
    return (int)(p - q);
}

/***************************************************************************
  函数名称：tj_strcat
  功    能：拼接字符串
  输入参数：char* s1, const char* s2
  返 回 值：char*
  说    明：
***************************************************************************/
char* tj_strcat(char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p;
    const char* q;
    p = s1;
    q = s2;
    if (p == NULL)
        return NULL;
    if (q == NULL)
        return s1;
    while (*p != '\0')
        p++;
    while (*q != '\0')
    {
        *p = *q;
        p++;
        q++;
    }
    *p = '\0';
    return s1;
}

/***************************************************************************
  函数名称：tj_strcpy
  功    能：复制文字
  输入参数：char* s1, const char* s2
  返 回 值：char*
  说    明：
***************************************************************************/
char* tj_strcpy(char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = s1;
    const char* q = s2;
    if (p == NULL)
        return NULL;
    if (q == NULL)
    {
        *p = '\0';
        return p;
    }
    while (*q != '\0')
    {
        *p = *q;
        p++;
        q++;
    }
    *p = '\0';
    return s1;
}

/***************************************************************************
  函数名称：tj_strcmp
  功    能：比较两个字符串
  输入参数：const char* s1, const char* s2
  返 回 值：int
  说    明：
***************************************************************************/
int tj_strcmp(const char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* p = s1;
    const char* q = s2;
    if (p == NULL && q == NULL)
        return 0;
    if (p == NULL)
        return -1;
    if (q == NULL)
        return 1;
    while (*p != '\0' && *q != '\0')
    {
        if (*p != *q)
            return *p - *q;
        p++;
        q++;
    }
    if (*p == '\0' && *q != '\0')
        return -*q;
    else if (*p != '\0' && *q == '\0')
        return *p;
    else
        return 0;
}

/***************************************************************************
  函数名称：tj_strncmp
  功    能：比较前n个字符
  输入参数：const char* s1, const char* s2, const int len
  返 回 值：int
  说    明：
***************************************************************************/
int tj_strncmp(const char* s1, const char* s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int n = len;
    const char* p = s1;
    const char* q = s2;
    if (p == NULL && q == NULL)
        return 0;
    if (p == NULL)
        return -1;
    if (q == NULL)
        return 1;
    if (len > (tj_strlen(s2) + 1 > tj_strlen(s1) + 1 ? tj_strlen(s1) + 1 : tj_strlen(s2) + 1))
        n = (tj_strlen(s2) + 1 > tj_strlen(s1) + 1 ? tj_strlen(s1) + 1 : tj_strlen(s2) + 1);
    while (n)
    {
        if (*p != *q)
            return *p - *q;
        p++;
        q++;
        n--;
    }
    if (*--p == '\0' && *--q != '\0')
        return -*q;
    else if (*--p != '\0' && *--q == '\0')
        return *p;
    else
        return 0;
}

/***************************************************************************
  函数名称：orders_backspace
  功    能：模拟退格
  输入参数：int X, int Y, int& x, int& y, char tmp[]
  返 回 值：int
  说    明：
***************************************************************************/
int orders_backspace(int X, int Y, int& x, int& y, char tmp[])
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
                cnt = orders_backspace(X, Y, x, y, h);
                cct_gotoxy(0, Y + 1);
                cout << "输入错误，请重新输入！";
                cct_gotoxy(X, Y);
            }
            //cout << "本小题结束，请输入End继续...";
        }
    }
}

/***************************************************************************
  函数名称：print_level
  功    能：打印关卡
  输入参数：int cnt, const char files[][MAX_LEN_OF_FILENAME]
  返 回 值：void
  说    明：
***************************************************************************/
void move_button(int cnt, const char files[][MAX_LEN_OF_FILENAME])
{
    int cur = 0, top = 0, ret, maction, keycode1, keycode2, loop = 1, sign = 0, x, y, xt = X + 1, yt = Y + 2;
    cct_setcursor(CURSOR_INVISIBLE);	//关闭光标
    while (loop) {
        ret = cct_read_keyboard_and_mouse(x, y, maction, keycode1, keycode2);
        if (ret == CCT_KEYBOARD_EVENT) {
            switch (keycode1) {
                case 27:	//ESC键
                    loop = 0;
                    cct_setcursor(CURSOR_VISIBLE_NORMAL);
                    break;
                case 13:    //ENTER键
                    read(cur, files);
                    print_level(cnt, top, cur, files);
                    break;
                case 224:
                    switch (keycode2) {
                        case KB_ARROW_UP:
                            if (cnt <= 24) {
                                if (cur != 0)
                                    cur--;
                            }
                            else {
                                if (cur != 0 && top != 0 && cur == top)
                                    cur--, top--;
                                else if (cur != 0)
                                    cur--;
                                else
                                    continue;
                            }
                            print_level(cnt, top, cur, files);
                            break;
                        case KB_ARROW_DOWN:
                            if (cnt <= 24) {
                                if (cur != cnt - 1)
                                    cur++;
                            }
                            else {
                                if (cur != cnt - 1 && cur == top + 24)
                                    cur++, top++;
                                else if (cur != cnt - 1)
                                    cur++;
                                else
                                    continue;
                            }
                            print_level(cnt, top, cur, files);
                            break;
                    }
                    break;
            }
        }
    }
}

/***************************************************************************
  函数名称：print_level
  功    能：打印关卡
  输入参数：int cnt, int top, int cur, const char files[][MAX_LEN_OF_FILENAME]
  返 回 值：void
  说    明：
***************************************************************************/
void print_level(int cnt, int top, int cur, const char files[][MAX_LEN_OF_FILENAME])
{
    int x = X, y = Y, xt = X + 1, yt = Y + 2;
    cct_gotoxy(X, Y);
    cout << "请选择关卡";
    cct_gotoxy(--x, ++y);
    cout << "\u2554\u2550\u2550\u2550\u2550\u2557";
    for (int i = top; i <= top + 24; i++) {
        if (cnt == i)
            break;
        cct_gotoxy(x, ++y);
        cout << "\u2551关卡" << files[i][14] << files[i][15] << files[i][16] << " \u2551";
    }
    cct_gotoxy(x, ++y);
    cout << "\u255A\u2550\u2550\u2550\u2550\u255D";
    cct_gotoxy(++++x, yt + (cur - top));
    cct_setcolor(15, 0);
    cout << "关卡" << files[cur][14] << files[cur][15] << files[cur][16] << " ";
    cct_setcolor();

}

/***************************************************************************
  函数名称：read_name
  功    能：检查名字
  输入参数：char files[][MAX_LEN_OF_FILENAME]
  返 回 值：int
  说    明：
***************************************************************************/
int read_name(char files[][MAX_LEN_OF_FILENAME])
{
        intptr_t hFile = 0;     //文件句柄
        struct _finddata_t fileinfo;        //文件信息结构体
        if ((hFile = _findfirst("..\\stage\\*.txt", &fileinfo)) != -1)
        {
            int cnt = 0;
            do
            {
                if (tj_strncmp("Sokoban-Level-", fileinfo.name, 14))
                    continue;
                else if (fileinfo.name[17] == '.' && fileinfo.name[18] == 't' && fileinfo.name[19] == 'x' && fileinfo.name[20] == 't' && fileinfo.name[21] == '\0') {
                    tj_strcpy(files[cnt], fileinfo.name);
                    //cout << files[cnt] << "\t**" << fileinfo.name << endl;
                    cnt++;
                }
                else
                    continue;
            } while (_findnext(hFile, &fileinfo) == 0);
            _findclose(hFile);
            return cnt;
        }
        return 0;
}