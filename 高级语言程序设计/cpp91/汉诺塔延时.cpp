/*2151974 软件 赵明泽*/
#include <iostream>
#include "5-b7.h"
#include <Windows.h>
#include <iomanip>
using namespace std;

int yanshi;     //延时
int shuzu;      //是否显示数组
int cnt = 0;    //一个计数用的全局变量
int atop = 0, btop = 0, ctop = 0;   //三个栈的栈顶指针
int a[12] = { 0 }, b[12] = { 0 }, c[12] = { 0 };    //三个全局一维数组

//以下是挪动坐标
const int JZX = 9;
const int JZY = 12;
const int Z = JZY - 1;
const int A = JZX + 2;
const int B = JZX + 12;
const int C = JZX + 22;

/***************************************************************************
    函数名称：printH
    功    能：打印可视化汉诺塔
    输入参数：void
    返 回 值：void
    说    明：
***************************************************************************/
void printH()
{
    cct_gotoxy(JZX, JZY);
    cout << "=========================";
    cct_gotoxy(A, JZY + 1);
    cout << "A         B         C";
    cct_gotoxy(A, Z);
    for (int i = Z, j = 0; j < atop; i--, j++)
    {
        cct_gotoxy(A, i);
        if (a[j] == 10)
        {
            cct_gotoxy(A - 1, Z);
            cout << a[j];
        }
        else
        {
            cout << a[j];
        }
    }
    cct_gotoxy(B, Z);
    for (int i = Z, j = 0; j < btop; i--, j++)
    {
        cct_gotoxy(B, i);
        if (b[j] == 10)
        {
            cct_gotoxy(B - 1, Z);
            cout << b[j];
        }
        else
        {
            cout << b[j];
        }
    }
    cct_gotoxy(C, Z);
    for (int i = Z, j = 0; j < ctop; i--, j++)
    {
        cct_gotoxy(C, i);
        if (c[j] == 10)
        {
            cct_gotoxy(C - 1, Z);
            cout << c[j];
        }
        else
        {
            cout << c[j];
        }
    }
}

/***************************************************************************
    函数名称：printStack
    功    能：打印数组里的玩意
    输入参数：void
    返 回 值：void
    说    明：
***************************************************************************/
void printStack()
{
    cout << " A:";
    for (int i = 0; i < atop; i++)
    {
        cout << setw(2) << a[i];
    }
    for (int j = 10 - atop; j > 0; j--)
    {
        cout << "  ";
    }

    cout << " B:";
    for (int i = 0; i < btop; i++)
    {
        cout << setw(2) << b[i];
    }
    for (int j = 10 - btop; j > 0; j--)
    {
        cout << "  ";
    }

    cout << " C:";
    for (int i = 0; i < ctop; i++)
    {
        cout << setw(2) << c[i];
    }
    for (int j = 10 - ctop; j > 0; j--)
    {
        cout << "  ";
    }
}

/***************************************************************************
    函数名称：
    功    能：打印n层汉诺塔的移动顺序
    输入参数：int n：层数
              char src：起始柱
              char tmp：中间柱
              char dst：目标柱
    返 回 值：
    说    明：
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 0)
    {
        return;
    }
    hanoi(n - 1, src, dst, tmp);

    printH();

    cct_gotoxy(0, JZY + 5);
    switch (src)
    {
        case 'A':
            if (dst == 'B')
            {
                b[btop++] = a[--atop];
                cout << "第" << setw(4) << ++cnt << "步(" << b[btop - 1] << "#: " << src << "-->" << dst << ") ";
            }
            else
            {
                c[ctop++] = a[--atop];
                cout << "第" << setw(4) << ++cnt << "步(" << c[ctop - 1] << "#: " << src << "-->" << dst << ") ";
            }
            break;
        case 'B':
            if (dst == 'A')
            {
                a[atop++] = b[--btop];
                cout << "第" << setw(4) << ++cnt << "步(" << a[atop - 1] << "#: " << src << "-->" << dst << ") ";
            }
            else
            {
                c[ctop++] = b[--btop];
                cout << "第" << setw(4) << ++cnt << "步(" << c[ctop - 1] << "#: " << src << "-->" << dst << ") ";
            }
            break;
        default:
            if (dst == 'B')
            {
                b[btop++] = c[--ctop];
                cout << "第" << setw(4) << ++cnt << "步(" << b[btop - 1] << "#: " << src << "-->" << dst << ") ";
            }
            else
            {
                a[atop++] = c[--ctop];
                cout << "第" << setw(4) << ++cnt << "步(" << a[atop - 1] << "#: " << src << "-->" << dst << ") ";
            }
            break;
    }

    if (shuzu)
    {
        printStack();
        cct_gotoxy(89, JZY + 5);
    }
    else
    {
        cout << setw(72) << setfill(' ');
    }

    switch (src)
    {
        case 'A':
            if (yanshi == 0 && shuzu == 1)
            {
                while (getchar() != '\n');
            }
            cct_gotoxy(A - 1, Z - atop);
            cout << "  ";
            break;
        case 'B':
            if (yanshi == 0 && shuzu == 1)
            {
                while (getchar() != '\n');
            }
            cct_gotoxy(B - 1, Z - btop);
            cout << "  ";
            break;
        case 'C':
            if (yanshi == 0 && shuzu == 1)
            {
                while (getchar() != '\n');
            }
            cct_gotoxy(C - 1, Z - ctop);
            cout << "  ";
            break;
    }
    printH();
    switch (dst)
    {
        case 'A':
            cct_gotoxy(A + 1, Z - atop + 1);
            break;
        case 'B':
            cct_gotoxy(B + 1, Z - btop + 1);
            break;
        case 'C':
            cct_gotoxy(C + 1, Z - ctop + 1);
            break;
    }
    switch (yanshi)
    {
        case 0:
            while (getchar() != '\n');
            break;
        case 1:
            Sleep(1000);
            break;
        case 2:
            Sleep(100);
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

    hanoi(n - 1, tmp, src, dst);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
    char start, end, tmp;
    int n;
    //int ret1;

    while (1)
    {
        //printf();
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        //ret1 = scanf("%d", &n);
        cin >> n;

        if (/*ret1 == 0*/cin.fail() || n < 1 || n > 10)
        {
            cin.clear();
            char t;
            while ((t = getchar()) != '\n' && t != EOF);
            continue;
        }
        else
        {
            char t;
            while ((t = getchar()) != '\n' && t != EOF)
            {
                continue;
            }
            break;
        }
    }

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
            switch (start)
            {
                case 'a':
                    start = 'A';
                    break;
                case 'b':
                    start = 'B';
                    break;
                case 'c':
                    start = 'C';
                    break;
            }

            char t;
            while ((t = getchar()) != '\n' && t != EOF)
            {
                continue;
            }
            break;
        }
    }

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
            switch (end)
            {
                case 'a':
                    end = 'A';
                    break;
                case 'b':
                    end = 'B';
                    break;
                case 'c':
                    end = 'C';
                    break;
            }

            if (start == end)
            {
                cout << "目标柱(" << end << ")不能与起始柱(" << start << ")相同" << endl;
                char t;
                while ((t = getchar()) != '\n' && t != EOF)
                {
                    continue;
                }
                continue;
            }

            char t;
            while ((t = getchar()) != '\n' && t != EOF)
            {
                continue;
            }
            break;
        }
    }

    int pd = start + end;

    if (pd == 131)
    {
        tmp = 'C';
    }
    else if (pd == 132)
    {
        tmp = 'B';
    }
    else
    {
        tmp = 'A';
    }

    //初始化三个全局数组
    switch (start)
    {
        case 'A':
            for (int i = n; i > 0; i--)
            {
                a[atop] = i;
                atop++;
            }
            break;
        case 'B':
            for (int i = n; i > 0; i--)
            {
                b[btop] = i;
                btop++;
            }
            break;
        case 'C':
            for (int i = n; i > 0; i--)
            {
                c[ctop] = i;
                ctop++;
            }
            break;
    }

    //输入延时
    while (1)
    {
        cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
        cin >> yanshi;

        if (cin.fail() || yanshi < 0 || yanshi > 5)
        {
            cin.clear();
            char t;
            while ((t = getchar()) != '\n' && t != EOF);
            continue;
        }
        else
        {
            char t;
            while ((t = getchar()) != '\n' && t != EOF);
            break;
        }
    }

    //输入是否显示数组
    while (1)
    {
        cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
        cin >> shuzu;

        if (cin.fail() || shuzu < 0 || shuzu > 1)
        {
            cin.clear();
            char t;
            while ((t = getchar()) != '\n' && t != EOF);
            continue;
        }
        else
        {
            char t;
            while ((t = getchar()) != '\n' && t != EOF);
            break;
        }
    }

    //清屏
    cct_cls();

    //打印初始：
    cct_gotoxy(0, 0);
    cout << "从 " << start << " 移动到 " << end << "，共 " << n << " 层，延时设置为 " << yanshi << "，";
    if (!shuzu)
    {
        cout << "不";
    }
    cout << "显示内部数组值";
    if (shuzu)
    {
        cct_gotoxy(0, JZY + 5);
        cout << "初始:               ";
        printStack();
        switch (yanshi)
        {
            case 0:
                while (getchar() != '\n');
                break;
            case 1:
                Sleep(1000);
                break;
            case 2:
                Sleep(100);
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
    //打印可视化汉诺塔
    printH();
    switch (start)
    {
        case 'A':
            cct_gotoxy(A + 1, Z - atop + 1);
            break;
        case 'B':
            cct_gotoxy(B + 1, Z - btop + 1);
            break;
        case 'C':
            cct_gotoxy(C + 1, Z - ctop + 1);
            break;
    }
    if (yanshi == 0)
    {
        while (getchar() != '\n');
    }

    hanoi(n, start, tmp, end);

    cct_gotoxy(0, JZY + 15);
    system("pause"); //最后用这句表示暂停（注意：只适合于特定程序，无特别声明的程序加此句则得分为0）
    return 0;
}