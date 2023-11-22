/*2151974 ��� ������*/
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
using namespace std;

static int cnt = 0;            //���ƶ�����
static int top[3] = {};        //Բ��������Բ�̵�����
static int d[3][10] = {};      //Բ��������Բ�̵ı��
static int yanshi;             //��¼��ʱ

//��������ɫ��������
const int COLOR[12] = { 1,2,3,4,5,6,8,9,10,11,12,13 };

//������������������
const int JZX = 9;
const int JZY = 12;
const int Z = JZY - 1;
const int A = JZX + 2;
const int B = JZX + 12;
const int C = JZX + 22;

//������������������
const int LX = 1;
const int MX = 12;
const int DY = 15;
const int UY = 3;
const int G = 32;

//����������ƫ��ֵ
const int DELTA = 16;

/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
	1����ű� hanoi_main.cpp �и��ݲ˵�����ֵ���õĸ��˵����Ӧ��ִ�к���

     ���ļ�Ҫ��
	1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
	2�������徲̬ȫ�ֱ�����������Ҫ��������Ҫ�����ĵ���ʾ��ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
	3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */


/***************************************************************************
  �������ƣ�quantity_of_plates
  ��    �ܣ����뺺ŵ������
  ���������void
  �� �� ֵ��int
  ˵    ����
***************************************************************************/
int quantity_of_plates()
{
    int n;
    while (1)
    {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
        cin >> n;
        if (cin.fail())
        {
            cin.clear();
            char t;
            while ((t = getchar()) != '\n' && t != EOF);
            continue;
        }
        else if (n < 1 || n > 10)
        {
            cin.clear();
            continue;
        }
        else
        {
            char t;
            while ((t = getchar()) != '\n' && t != EOF);
            break;
        }
    }
    return n;
}

/***************************************************************************
  �������ƣ�scan_source
  ��    �ܣ����뺺ŵ����ʼ��
  ���������void
  �� �� ֵ��char
  ˵    ����
***************************************************************************/
char scan_source()
{
    char start;
    while (1)
    {
        cout << "��������ʼ��(A-C)" << endl;
        cin >> start;
        if (start != 'A' && start != 'a' && start != 'B' && start != 'b' && start != 'C' && start != 'c')
        {
            char t;
            while ((t = getchar()) != '\n' && t != EOF);
            continue;
        }
        else
        {
            if (start >= 'a' && start <= 'c')
            {
                start = start - 'a' + 'A';
            }
            char t;
            while ((t = getchar()) != '\n' && t != EOF);
            break;
        }
    }
    return start;
}

/***************************************************************************
  �������ƣ�destination
  ��    �ܣ����뺺ŵ��Ŀ����
  ���������char start
  �� �� ֵ��char
  ˵    ����
***************************************************************************/
char scan_destination(char start)
{
    char end;
    while (1)
    {
        cout << "������Ŀ����(A-C)" << endl;
        cin >> end;
        if (end != 'A' && end != 'a' && end != 'B' && end != 'b' && end != 'C' && end != 'c')
        {
            char t;
            while ((t = getchar()) != '\n' && t != EOF);
            continue;
        }
        else
        {
            if (end >= 'a' && end <= 'c')
            {
                end = end - 'a' + 'A';
            }
            if (start == end)
            {
                cout << "Ŀ����(";
                putchar(end);
                cout << ")��������ʼ��(";
                putchar(start);
                cout << ")��ͬ" << endl;
                char t;
                while ((t = getchar()) != '\n' && t != EOF);
                continue;
            }
            char t;
            while ((t = getchar()) != '\n' && t != EOF);
            break;
        }
    }
    return end;
}

/***************************************************************************
  �������ƣ�temporary
  ��    �ܣ����㺺ŵ���м���
  ���������char start, char end
  �� �� ֵ��char
  ˵    ����
***************************************************************************/
char temporary(char start, char end)
{
    return 'A' + 'B' + 'C' - start - end;
}

/***************************************************************************
  �������ƣ�time_delay
  ��    �ܣ����뺺ŵ����ʱ
  ���������void
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void time_delay()
{
    while (1)
    {
        cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)";
        cin >> yanshi;
        if (cin.fail())
        {
            cin.clear();
            char t;
            while ((t = getchar()) != '\n' && t != EOF);
            continue;
        }
        else if (yanshi < 0 || yanshi > 5)
            continue;
        else
        {
            char t;
            while ((t = getchar()) != '\n' && t != EOF);
            break;
        }
    }
}

/***************************************************************************
    �������ƣ�data_in
    ��    �ܣ����뺺ŵ��������������ʼ��
    ���������int& n, char& start, char& end, char& tmp, const int WHETHER_DELAY = 0
    �� �� ֵ��void
    ˵    ����
***************************************************************************/
void data_in(int& n, char& start, char& end, char& tmp, const int WHETHER_DELAY = 0)
{
    n = quantity_of_plates();
    start = scan_source();
    end = scan_destination(start);
    tmp = temporary(start, end);
    for (int i = n; i > 0; i--)
    {
        d[(int)(start - 'A')][top[(int)(start - 'A')]] = i;
        top[(int)(start - 'A')]++;
    }
    if (WHETHER_DELAY)
        time_delay();
}

/***************************************************************************
  �������ƣ�to_be_continued
  ��    �ܣ���ʾ��ʾ��Ϣ
  ���������
  �� �� ֵ��
  ˵    �����������������ʱ���ţ���ָ�������ѧϰ��ɺ����Ķ�
***************************************************************************/
void to_be_continued(const int X = 0, const int Y = 0)
{
    cct_setcolor(); //�ָ�ȱʡ��ɫ
    cct_gotoxy(X, Y);

    cout << "���س�������...";

    /* ���Գ��س�������������루ע�⣺_getch�Ļس���\r����getchar��\n��*/
    while (_getch() != '\r')
        ;

    cct_cls();

    return;
}

/***************************************************************************
  �������ƣ�how_long_will_u_sleep
  ��    �ܣ���ѯ˯��ʱ��
  ���������const int a = 0
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void how_long_will_u_sleep(const int a = 0)
{
    switch (yanshi)
    {
        case 0:
            if (a)
                Sleep(1);
            else
                while (getchar() != '\n');
            break;
        case 1:
            Sleep(100);
            break;
        case 2:
            Sleep(50);
            break;
        case 3:
            Sleep(10);
            break;
        case 4:
            Sleep(1);
            break;
        default:
            break;
    }
}

/***************************************************************************
    �������ƣ�printH
    ��    �ܣ���ӡ���ӻ���ŵ��
    ���������const int D = 0
    �� �� ֵ��void
    ˵    ����
***************************************************************************/
void printH(const int D = 0)
{
    cct_gotoxy(JZX, JZY + D);
    cout << "=========================";
    cct_gotoxy(A, JZY + D + 1);
    cout << "A         B         C";
    cct_gotoxy(A, Z + D);
    for (int i = Z + D, j = 0; j < top[0]; i--, j++)
    {
        cct_gotoxy(A, i);
        if (d[0][j] == 10)
        {
            cct_gotoxy(A - 1, Z + D);
            cout << d[0][j];
        }
        else
            cout << d[0][j];
    }
    cct_gotoxy(B, Z + D);
    for (int i = Z + D, j = 0; j < top[1]; i--, j++)
    {
        cct_gotoxy(B, i);
        if (d[1][j] == 10)
        {
            cct_gotoxy(B - 1, Z + D);
            cout << d[1][j];
        }
        else
            cout << d[1][j];
    }
    cct_gotoxy(C, Z + D);
    for (int i = Z + D, j = 0; j < top[2]; i--, j++)
    {
        cct_gotoxy(C, i);
        if (d[2][j] == 10)
        {
            cct_gotoxy(C - 1, Z + D);
            cout << d[2][j];
        }
        else
            cout << d[2][j];
    }
}

/***************************************************************************
    �������ƣ�printStack
    ��    �ܣ���ӡ�����������
    ���������
    �� �� ֵ��void
    ˵    ����
***************************************************************************/
void printStack()
{
    cout << " A:";
    for (int i = 0; i < top[0]; i++)
        cout << setw(2) << d[0][i];
    for (int j = 10 - top[0]; j > 0; j--)
        cout << "  ";
    cout << " B:";
    for (int i = 0; i < top[1]; i++)
        cout << setw(2) << d[1][i];
    for (int j = 10 - top[1]; j > 0; j--)
        cout << "  ";
    cout << " C:";
    for (int i = 0; i < top[2]; i++)
        cout << setw(2) << d[2][i];
    for (int j = 10 - top[2]; j > 0; j--)
        cout << "  ";
    cout << endl;
}

/***************************************************************************
    �������ƣ�H_and_Stack_pre
    ��    �ܣ�Ϊ��ӡ�ݺ�����������ǰ׼��
    ���������int n, char src, char tmp, char dst, const int D = 0
    �� �� ֵ��void
    ˵    ����
***************************************************************************/
void H_and_Stack_pre(int n, char src, char tmp, char dst, const int D = 0)
{
    cct_cls();
    cct_gotoxy(0, 0);
    cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << yanshi;
    printH(D);
    cct_gotoxy(0, JZY + D + 5);
    cout << "��ʼ:   ";
    printStack();
}

/***************************************************************************
    �������ƣ�H_and_Stack
    ��    �ܣ���ӡ�ݺ�����
    ���������int n, char src, char tmp, char dst, const int D = 0, const int JUDGE = 0
    �� �� ֵ��void
    ˵    ����
***************************************************************************/
void H_and_Stack(int n, char src, char tmp, char dst, const int D = 0, const int JUDGE = 0)
{
    if (!JUDGE)
        how_long_will_u_sleep();
    cct_gotoxy(0, JZY + D + 5);
    d[(int)(dst - 'A')][top[(int)(dst - 'A')]++] = d[(int)(src - 'A')][--top[(int)(src - 'A')]];
    cout << setiosflags(ios::right) << "��" << setw(4) << ++cnt << " ��(" << setw(2) << d[(int)(dst - 'A')][top[(int)(dst - 'A')] - 1] << "#: " << src << "-->" << dst << ")";
    printStack();
    switch (src)
    {
        case 'A':
            cct_gotoxy(A - 1, Z + D - top[0]);
            cout << "  ";
            break;
        case 'B':
            cct_gotoxy(B - 1, Z + D - top[1]);
            cout << "  ";
            break;
        case 'C':
            cct_gotoxy(C - 1, Z + D - top[2]);
            cout << "  ";
            break;
    }
    printH(D);
}

/***************************************************************************
  �������ƣ�three_poles
  ��    �ܣ���������Բ��
  ���������void
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void three_poles()
{
    int x, y;
    for (x = LX; x < 2 * MX; x++)
    {
        cct_showch(x, DY, ' ', 14);
        cct_showch(x + G, DY, ' ', 14);
        cct_showch(x + G * 2, DY, ' ', 14);
    }
    for (y = DY; y >= UY; y--)
    {
        cct_showch(MX, y, ' ', 14);
        cct_showch(MX + G, y, ' ', 14);
        cct_showch(MX + G * 2, y, ' ', 14);
        Sleep(30);
    }
}

/***************************************************************************
  �������ƣ�plates
  ��    �ܣ�����Բ��
  ���������int n, char src, char tmp, char dst
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void plates(int n, char src, char tmp, char dst, const int TIME = 1000)
{
    cct_gotoxy(0, 0);
    cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " ��";
    three_poles();
    int x = LX + G * ((int)(src - 'A')) + 11 - n, y = DY - 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= (n - i) * 2; j ++)
            cct_showch(x + i + j, y - i, ' ', COLOR[top[(int)(src - 'A')] - i]);
        Sleep(10);
    }
    Sleep(TIME);
}

/***************************************************************************
  �������ƣ�move_plates
  ��    �ܣ��ƶ�����
  ���������int n, char src, char tmp, char dst
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void move_plates(int n, char src, char tmp, char dst)
{
    how_long_will_u_sleep(1);
    int x = LX + G * ((int)(src - 'A')) + MX - d[(int)(dst - 'A')][top[(int)(dst - 'A')] - 1] - 1, y = DY - top[(int)(src - 'A')] - 1;
    for (int j = y; j >= UY - 1; j--)
    {
        for (int i = 0; i < (d[(int)(dst - 'A')][top[(int)(dst - 'A')] - 1]) * 2 + 1; i++)
        {
            cct_showch(x + i, j, ' ', 0);
            cct_showch(x + i, j - 1, ' ', COLOR[d[(int)(dst - 'A')][top[(int)(dst - 'A')] - 1]]);
        }
        if (j >= UY)
            cct_showch(LX + G * ((int)(src - 'A')) + MX - 1, j, ' ', 14);
        how_long_will_u_sleep(1);
    }
    if ((int)(src - dst) > 0)    //left
    {
        for (int i = 0; i <= (int)(src - dst) * G; i++)
        {
            cct_showch(x - i, UY - 2, ' ', COLOR[d[(int)(dst - 'A')][top[(int)(dst - 'A')] - 1]]);
            cct_showch(x - i + (d[(int)(dst - 'A')][top[(int)(dst - 'A')] - 1]) * 2 + 1, UY - 2, ' ', 0);
            how_long_will_u_sleep(1);
        }
        x -= (int)(src - dst) * G;
    }
    else
    {
        for (int i = 0; i < (int)(dst - src) * G; i++)
        {
            cct_showch(x + i, UY - 2, ' ', 0);
            cct_showch(x + i + (d[(int)(dst - 'A')][top[(int)(dst - 'A')] - 1]) * 2 + 1, UY - 2, ' ', COLOR[d[(int)(dst - 'A')][top[(int)(dst - 'A')] - 1]]);
            how_long_will_u_sleep(1);
        }
        x += (int)(dst - src) * G;
    }
    for (int j = UY - 2; j < DY - top[(int)(dst - 'A')]; j++)
    {
        for (int i = 0; i < (d[(int)(dst - 'A')][top[(int)(dst - 'A')] - 1]) * 2 + 1; i++)
        {
            cct_showch(x + i, j, ' ', 0);
            cct_showch(x + i, j + 1, ' ', COLOR[d[(int)(dst - 'A')][top[(int)(dst - 'A')] - 1]]);
        }
        if (j >= UY)
            cct_showch(LX + G * ((int)(dst - 'A')) + MX - 1, j, ' ', 14);
        how_long_will_u_sleep(1);
    }
}

/***************************************************************************
  �������ƣ�games_backspace
  ��    �ܣ�ģ���˸�
  ���������int X, int Y, int& x, int& y, char tmp[], const int JUDGE = 0
  �� �� ֵ��int
  ˵    ����
***************************************************************************/
int games_backspace(int X, int Y, int& x, int& y, char tmp[], const int JUDGE = 0)
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
  �������ƣ�games_data
  ��    �ܣ����ݴ���
  ���������int n, char src, char dst
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void games_data(int n, char src, char dst)
{
    int x, y;
    cct_getxy(x, y);
    H_and_Stack(n, src, ' ', dst, DELTA, 1);
    move_plates(n, src, ' ', dst);
    cct_setcolor();
    cct_gotoxy(x, y);
}

/***************************************************************************
  �������ƣ�games_check
  ��    �ܣ����ָ�������
  ���������char src, char dst, int X, int Y
  �� �� ֵ��int
  ˵    ����
***************************************************************************/
int games_check(char src, char dst, int X, int Y)
{
    if (src >= 'a' && src <= 'c')
        src -= ('a' - 'A');
    if (dst >= 'a' && dst <= 'c')
        dst -= ('a' - 'A');
    int x, y;
    cct_getxy(x, y);
    if (top[(int)(src - 'A')] == 0)
    {
        cct_gotoxy(0, JZY + DELTA + 8);
        cout << "Դ��Ϊ�գ�";
        Sleep(1000);
        for (int i = x; i != 0; i--)
        {
            cct_gotoxy(i - 1, JZY + DELTA + 8);
            putchar(' ');
        }
        cct_gotoxy(x, y);
        return 1;
    }
    else if (d[(int)(src - 'A')][top[(int)(src - 'A')] - 1] > d[(int)(dst - 'A')][top[(int)(dst - 'A')] - 1] && top[(int)(dst - 'A')] != 0)
    {
        cct_gotoxy(0, JZY + DELTA + 8);
        cout << "����ѹС�̣��Ƿ��ƶ���";
        Sleep(1000);
        for (int i = x; i != 0; i--)
        {
            cct_gotoxy(i - 1, JZY + DELTA + 8);
            putchar(' ');
        }
        cct_gotoxy(x, y);
        return 1;
    }
    return 0;
}

/***************************************************************************
  �������ƣ�games
  ��    �ܣ���ʼ��ҳ�沢��ȡָ��
  ���������int n, char src, char dst
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void games(int n, char src, char dst)
{
    char h[20];
    int cnt = 0;
    int X, Y, x, y;
    cct_gotoxy(0, JZY + DELTA + 7);
    cout << "�������ƶ�������(������ʽ��AC=A���˵������ƶ���C��Q=�˳�)��";
    cct_getxy(X, Y);
    while (1){
        char t = _getch();
        if (cnt == 20){
            cnt = games_backspace(X, Y, x, y, h);
            continue;
        }
        if (t >= 33 && t <= 126){
            h[cnt++] = t;
            putchar(t);
        }
        if (t == '\r'){
            if (h[0] == 'q' || h[0] == 'Q'){
                cct_gotoxy(0, JZY + DELTA + 8);
                cout << "��Ϸ��ֹ!!!!!!!!";
                break;
            }
            else if (cnt != 2 || h[0] == h[1] || h[0] - h[1] == 'a' - 'A' || h[1] - h[0] == 'a' - 'A' || (!(h[0] >= 'a' && h[0] <= 'c') && !(h[0] >= 'A' && h[0] <= 'C')) || (!(h[1] >= 'a' && h[1] <= 'c') && !(h[1] >= 'A' && h[1] <= 'C')))
                cnt = games_backspace(X, Y, x, y, h);
            else if (games_check(h[0], h[1], X, Y))
                cnt = games_backspace(X, Y, x, y, h);
            else{
                if (h[0] >= 'a' && h[0] <= 'c')
                    h[0] -= ('a' - 'A');
                if (h[1] >= 'a' && h[1] <= 'c')
                    h[1] -= ('a' - 'A');
                games_data(n, h[0], h[1]);
                if (top[(int)(dst - 'A')] == n) {
                    cct_gotoxy(0, JZY + DELTA + 8);
                    cout << "��Ϸ����!!!!!!!!";
                    break;
                }
                cnt = games_backspace(X, Y, x, y, h, 1);
            } 
        }
    }
}

/***************************************************************************
    �������ƣ�way_of_out
    ��    �ܣ�ѡ��ŵ�������ʽ
    ���������int n, char src, char tmp, char dst, int num
    �� �� ֵ��void
    ˵    ����
***************************************************************************/
void way_of_out(int n, char src, char tmp, char dst, int num)
{
    switch (num)
    {
        case 1:
            cout << setiosflags(ios::right) << setw(2) << n << "# " << src << "-->" << dst << endl;
            break;
        case 2:
            d[(int)(dst - 'A')][top[(int)(dst - 'A')]++] = d[(int)(src - 'A')][--top[(int)(src - 'A')]];
            cout << setiosflags(ios::right) << "��" << setw(4) << ++cnt << " ��(" << setw(2) << d[(int)(dst - 'A')][top[(int)(dst - 'A')] - 1] << "#: " << src << "-->" << dst << ")" << endl;
            break;
        case 3:
            d[(int)(dst - 'A')][top[(int)(dst - 'A')]++] = d[(int)(src - 'A')][--top[(int)(src - 'A')]];
            cout << setiosflags(ios::right) << "��" << setw(4) << ++cnt << " ��(" << setw(2) << d[(int)(dst - 'A')][top[(int)(dst - 'A')] - 1] << "#: " << src << "-->" << dst << ")";
            printStack();
            break;
        case 4:
            H_and_Stack(n, src, tmp, dst);
            break;
        case 7:
            d[(int)(dst - 'A')][top[(int)(dst - 'A')]++] = d[(int)(src - 'A')][--top[(int)(src - 'A')]];
            cnt++;
            move_plates(n, src, tmp, dst);
            break;
        case 8:
            cct_setcolor();
            H_and_Stack(n, src, tmp, dst, DELTA);
            move_plates(n, src, tmp, dst);
            break;
    }
}

/***************************************************************************
    �������ƣ�hanoi
    ��    �ܣ��ݹ麺ŵ��
    ���������int n������
              char src����ʼ��
              char tmp���м���
              char dst��Ŀ����
    �� �� ֵ��void
    ˵    ����������15��
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst, int num)
{
    if (n == 0)
        return;
    hanoi(n - 1, src, dst, tmp, num);
    if (cnt == 1 && num == 7)
        return;
    way_of_out(n, src, tmp, dst, num);
    hanoi(n - 1, tmp, src, dst, num);
}

/***************************************************************************
  �������ƣ�clear_all
  ��    �ܣ���վ�̬ȫ�ֱ���
  ���������void
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void clear_all()
{
    cnt = 0;
    top[0] = 0;
    top[1] = 0;
    top[2] = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            d[i][j] = 0;
        }
    }
    yanshi = 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void t()
{

}