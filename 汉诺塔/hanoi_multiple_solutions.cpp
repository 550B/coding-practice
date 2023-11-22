/*2151974 软件 赵明泽*/
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
using namespace std;

static int cnt = 0;            //总移动步数
static int top[3] = {};        //圆柱上现有圆盘的数量
static int d[3][10] = {};      //圆柱上现有圆盘的编号
static int yanshi;             //记录延时

//以下是颜色常量数组
const int COLOR[12] = { 1,2,3,4,5,6,8,9,10,11,12,13 };

//以下是纵向数组坐标
const int JZX = 9;
const int JZY = 12;
const int Z = JZY - 1;
const int A = JZX + 2;
const int B = JZX + 12;
const int C = JZX + 22;

//以下是三根柱子坐标
const int LX = 1;
const int MX = 12;
const int DY = 15;
const int UY = 3;
const int G = 32;

//以下是整体偏移值
const int DELTA = 16;

/* ----------------------------------------------------------------------------------

     本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */


/***************************************************************************
  函数名称：quantity_of_plates
  功    能：输入汉诺塔层数
  输入参数：void
  返 回 值：int
  说    明：
***************************************************************************/
int quantity_of_plates()
{
    int n;
    while (1)
    {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
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
  函数名称：scan_source
  功    能：输入汉诺塔起始柱
  输入参数：void
  返 回 值：char
  说    明：
***************************************************************************/
char scan_source()
{
    char start;
    while (1)
    {
        cout << "请输入起始柱(A-C)" << endl;
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
  函数名称：destination
  功    能：输入汉诺塔目标柱
  输入参数：char start
  返 回 值：char
  说    明：
***************************************************************************/
char scan_destination(char start)
{
    char end;
    while (1)
    {
        cout << "请输入目标柱(A-C)" << endl;
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
                cout << "目标柱(";
                putchar(end);
                cout << ")不能与起始柱(";
                putchar(start);
                cout << ")相同" << endl;
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
  函数名称：temporary
  功    能：计算汉诺塔中间柱
  输入参数：char start, char end
  返 回 值：char
  说    明：
***************************************************************************/
char temporary(char start, char end)
{
    return 'A' + 'B' + 'C' - start - end;
}

/***************************************************************************
  函数名称：time_delay
  功    能：输入汉诺塔延时
  输入参数：void
  返 回 值：void
  说    明：
***************************************************************************/
void time_delay()
{
    while (1)
    {
        cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)";
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
    函数名称：data_in
    功    能：输入汉诺塔基本参数并初始化
    输入参数：int& n, char& start, char& end, char& tmp, const int WHETHER_DELAY = 0
    返 回 值：void
    说    明：
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
  函数名称：to_be_continued
  功    能：显示提示信息
  输入参数：
  返 回 值：
  说    明：如果读不懂，暂时放着，等指针和引用学习完成后再阅读
***************************************************************************/
void to_be_continued(const int X = 0, const int Y = 0)
{
    cct_setcolor(); //恢复缺省颜色
    cct_gotoxy(X, Y);

    cout << "按回车键继续...";

    /* 忽略除回车键外的所有输入（注意：_getch的回车是\r，而getchar是\n）*/
    while (_getch() != '\r')
        ;

    cct_cls();

    return;
}

/***************************************************************************
  函数名称：how_long_will_u_sleep
  功    能：查询睡眠时长
  输入参数：const int a = 0
  返 回 值：void
  说    明：
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
    函数名称：printH
    功    能：打印可视化汉诺塔
    输入参数：const int D = 0
    返 回 值：void
    说    明：
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
    函数名称：printStack
    功    能：打印数组里的玩意
    输入参数：
    返 回 值：void
    说    明：
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
    函数名称：H_and_Stack_pre
    功    能：为打印纵横数组做的提前准备
    输入参数：int n, char src, char tmp, char dst, const int D = 0
    返 回 值：void
    说    明：
***************************************************************************/
void H_and_Stack_pre(int n, char src, char tmp, char dst, const int D = 0)
{
    cct_cls();
    cct_gotoxy(0, 0);
    cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << yanshi;
    printH(D);
    cct_gotoxy(0, JZY + D + 5);
    cout << "初始:   ";
    printStack();
}

/***************************************************************************
    函数名称：H_and_Stack
    功    能：打印纵横数组
    输入参数：int n, char src, char tmp, char dst, const int D = 0, const int JUDGE = 0
    返 回 值：void
    说    明：
***************************************************************************/
void H_and_Stack(int n, char src, char tmp, char dst, const int D = 0, const int JUDGE = 0)
{
    if (!JUDGE)
        how_long_will_u_sleep();
    cct_gotoxy(0, JZY + D + 5);
    d[(int)(dst - 'A')][top[(int)(dst - 'A')]++] = d[(int)(src - 'A')][--top[(int)(src - 'A')]];
    cout << setiosflags(ios::right) << "第" << setw(4) << ++cnt << " 步(" << setw(2) << d[(int)(dst - 'A')][top[(int)(dst - 'A')] - 1] << "#: " << src << "-->" << dst << ")";
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
  函数名称：three_poles
  功    能：画出三个圆柱
  输入参数：void
  返 回 值：void
  说    明：
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
  函数名称：plates
  功    能：画出圆盘
  输入参数：int n, char src, char tmp, char dst
  返 回 值：void
  说    明：
***************************************************************************/
void plates(int n, char src, char tmp, char dst, const int TIME = 1000)
{
    cct_gotoxy(0, 0);
    cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层";
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
  函数名称：move_plates
  功    能：移动盘子
  输入参数：int n, char src, char tmp, char dst
  返 回 值：void
  说    明：
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
  函数名称：games_backspace
  功    能：模拟退格
  输入参数：int X, int Y, int& x, int& y, char tmp[], const int JUDGE = 0
  返 回 值：int
  说    明：
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
  函数名称：games_data
  功    能：数据处理
  输入参数：int n, char src, char dst
  返 回 值：void
  说    明：
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
  函数名称：games_check
  功    能：检查指令合理性
  输入参数：char src, char dst, int X, int Y
  返 回 值：int
  说    明：
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
        cout << "源柱为空！";
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
        cout << "大盘压小盘，非法移动！";
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
  函数名称：games
  功    能：初始化页面并读取指令
  输入参数：int n, char src, char dst
  返 回 值：void
  说    明：
***************************************************************************/
void games(int n, char src, char dst)
{
    char h[20];
    int cnt = 0;
    int X, Y, x, y;
    cct_gotoxy(0, JZY + DELTA + 7);
    cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出)：";
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
                cout << "游戏中止!!!!!!!!";
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
                    cout << "游戏结束!!!!!!!!";
                    break;
                }
                cnt = games_backspace(X, Y, x, y, h, 1);
            } 
        }
    }
}

/***************************************************************************
    函数名称：way_of_out
    功    能：选择汉诺塔输出方式
    输入参数：int n, char src, char tmp, char dst, int num
    返 回 值：void
    说    明：
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
            cout << setiosflags(ios::right) << "第" << setw(4) << ++cnt << " 步(" << setw(2) << d[(int)(dst - 'A')][top[(int)(dst - 'A')] - 1] << "#: " << src << "-->" << dst << ")" << endl;
            break;
        case 3:
            d[(int)(dst - 'A')][top[(int)(dst - 'A')]++] = d[(int)(src - 'A')][--top[(int)(src - 'A')]];
            cout << setiosflags(ios::right) << "第" << setw(4) << ++cnt << " 步(" << setw(2) << d[(int)(dst - 'A')][top[(int)(dst - 'A')] - 1] << "#: " << src << "-->" << dst << ")";
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
    函数名称：hanoi
    功    能：递归汉诺塔
    输入参数：int n：层数
              char src：起始柱
              char tmp：中间柱
              char dst：目标柱
    返 回 值：void
    说    明：不超过15行
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
  函数名称：clear_all
  功    能：清空静态全局变量
  输入参数：void
  返 回 值：void
  说    明：
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void t()
{

}