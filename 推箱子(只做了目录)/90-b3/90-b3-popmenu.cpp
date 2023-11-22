/*2151974 ��� ������*/
#include <iostream>
#include <io.h>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "90-b3.h"
using namespace std;

/***************************************************************************
  �������ƣ�tj_strlen
  ��    �ܣ��ַ�������
  ���������const char* str
  �� �� ֵ��int
  ˵    ����
***************************************************************************/
int tj_strlen(const char* str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    const char* p = str;
    const char* q = str;
    if (p == NULL)
        return 0;
    while (*p != '\0')
        p++;
    return (int)(p - q);
}

/***************************************************************************
  �������ƣ�tj_strcat
  ��    �ܣ�ƴ���ַ���
  ���������char* s1, const char* s2
  �� �� ֵ��char*
  ˵    ����
***************************************************************************/
char* tj_strcat(char* s1, const char* s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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
  �������ƣ�tj_strcpy
  ��    �ܣ���������
  ���������char* s1, const char* s2
  �� �� ֵ��char*
  ˵    ����
***************************************************************************/
char* tj_strcpy(char* s1, const char* s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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
  �������ƣ�tj_strcmp
  ��    �ܣ��Ƚ������ַ���
  ���������const char* s1, const char* s2
  �� �� ֵ��int
  ˵    ����
***************************************************************************/
int tj_strcmp(const char* s1, const char* s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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
  �������ƣ�tj_strncmp
  ��    �ܣ��Ƚ�ǰn���ַ�
  ���������const char* s1, const char* s2, const int len
  �� �� ֵ��int
  ˵    ����
***************************************************************************/
int tj_strncmp(const char* s1, const char* s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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
  �������ƣ�orders_backspace
  ��    �ܣ�ģ���˸�
  ���������int X, int Y, int& x, int& y, char tmp[]
  �� �� ֵ��int
  ˵    ����
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
                cnt = orders_backspace(X, Y, x, y, h);
                cct_gotoxy(0, Y + 1);
                cout << "����������������룡";
                cct_gotoxy(X, Y);
            }
            //cout << "��С�������������End����...";
        }
    }
}

/***************************************************************************
  �������ƣ�print_level
  ��    �ܣ���ӡ�ؿ�
  ���������int cnt, const char files[][MAX_LEN_OF_FILENAME]
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void move_button(int cnt, const char files[][MAX_LEN_OF_FILENAME])
{
    int cur = 0, top = 0, ret, maction, keycode1, keycode2, loop = 1, sign = 0, x, y, xt = X + 1, yt = Y + 2;
    cct_setcursor(CURSOR_INVISIBLE);	//�رչ��
    while (loop) {
        ret = cct_read_keyboard_and_mouse(x, y, maction, keycode1, keycode2);
        if (ret == CCT_KEYBOARD_EVENT) {
            switch (keycode1) {
                case 27:	//ESC��
                    loop = 0;
                    cct_setcursor(CURSOR_VISIBLE_NORMAL);
                    break;
                case 13:    //ENTER��
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
  �������ƣ�print_level
  ��    �ܣ���ӡ�ؿ�
  ���������int cnt, int top, int cur, const char files[][MAX_LEN_OF_FILENAME]
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void print_level(int cnt, int top, int cur, const char files[][MAX_LEN_OF_FILENAME])
{
    int x = X, y = Y, xt = X + 1, yt = Y + 2;
    cct_gotoxy(X, Y);
    cout << "��ѡ��ؿ�";
    cct_gotoxy(--x, ++y);
    cout << "\u2554\u2550\u2550\u2550\u2550\u2557";
    for (int i = top; i <= top + 24; i++) {
        if (cnt == i)
            break;
        cct_gotoxy(x, ++y);
        cout << "\u2551�ؿ�" << files[i][14] << files[i][15] << files[i][16] << " \u2551";
    }
    cct_gotoxy(x, ++y);
    cout << "\u255A\u2550\u2550\u2550\u2550\u255D";
    cct_gotoxy(++++x, yt + (cur - top));
    cct_setcolor(15, 0);
    cout << "�ؿ�" << files[cur][14] << files[cur][15] << files[cur][16] << " ";
    cct_setcolor();

}

/***************************************************************************
  �������ƣ�read_name
  ��    �ܣ��������
  ���������char files[][MAX_LEN_OF_FILENAME]
  �� �� ֵ��int
  ˵    ����
***************************************************************************/
int read_name(char files[][MAX_LEN_OF_FILENAME])
{
        intptr_t hFile = 0;     //�ļ����
        struct _finddata_t fileinfo;        //�ļ���Ϣ�ṹ��
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