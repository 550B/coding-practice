/*2151974 软件 赵明泽*/
#include <iostream>
#include <iomanip>
using namespace std;

int cnt = 0;
int top[3] = {};
int d[3][10] = {};

/***************************************************************************
    函数名称：printStack
    功    能：打印数组里的玩意
    输入参数：void
    返 回 值：void
    说    明：为了hanoi里面没有循环(?)
***************************************************************************/
void printStack()
{
    cout << " A:";
    for (int i = 0; i < top[0]; i++)
    {
        cout << setw(2) << d[0][i];
    }
    for (int j = 10 - top[0]; j > 0; j--)
    {
        cout << "  ";
    }

    cout << " B:";
    for (int i = 0; i < top[1]; i++)
    {
        cout << setw(2) << d[1][i];
    }
    for (int j = 10 - top[1]; j > 0; j--)
    {
        cout << "  ";
    }

    cout << " C:";
    for (int i = 0; i < top[2]; i++)
    {
        cout << setw(2) << d[2][i];
    }
    for (int j = 10 - top[2]; j > 0; j--)
    {
        cout << "  ";
    }
    cout << endl;
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

    switch (src)
    {
        case 'A':
            if (dst == 'B')
            {
                d[1][top[1]++] = d[0][--top[0]];
                cout << "第" << setw(4) << ++cnt << " 步(" << setw(2) << d[1][top[1]-1] << "): " << src << "-->" << dst;
            }
            else
            {
                d[2][top[2]++] = d[0][--top[0]];
                cout << "第" << setw(4) << ++cnt << " 步(" << setw(2) << d[2][top[2]-1] << "): " << src << "-->" << dst;
            }
            break;
        case 'B':
            if (dst == 'A')
            {
                d[0][top[0]++] = d[1][--top[1]];
                cout << "第" << setw(4) << ++cnt << " 步(" << setw(2) << d[0][top[0]-1] << "): " << src << "-->" << dst;
            }
            else
            {
                d[2][top[2]++] = d[1][--top[1]];
                cout << "第" << setw(4) << ++cnt << " 步(" << setw(2) << d[2][top[2]-1] << "): " << src << "-->" << dst;
            }
            break;
        default:
            if (dst == 'B')
            {
                d[1][top[1]++] = d[2][--top[2]];
                cout << "第" << setw(4) << ++cnt << " 步(" << setw(2) << d[1][top[1]-1] << "): " << src << "-->" << dst;
            }
            else
            {
                d[0][top[0]++] = d[2][--top[2]];
                cout << "第" << setw(4) << ++cnt << " 步(" << setw(2) << d[0][top[0]-1] << "): " << src << "-->" << dst;
            }
            break;
    }
    printStack();
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

    while (1)
    {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;

        if (cin.fail() || n < 1 || n > 10)
        {
            cin.clear();
            char t;
            while ((t = getchar()) != '\n' && t != EOF)
            {
                continue;
            }
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
            while ((t = getchar()) != '\n' && t != EOF)
            {
                continue;
            }
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
            while ((t = getchar()) != '\n' && t != EOF)
            {
                continue;
            }
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

    //初始化全局数组
    switch (start)
    {
        case 'A':
            for (int i = n; i > 0; i--)
            {
                d[0][top[0]] = i;
                top[0]++;
            }
            break;
        case 'B':
            for (int i = n; i > 0; i--)
            {
                d[1][top[1]] = i;
                top[1]++;
            }
            break;
        case 'C':
            for (int i = n; i > 0; i--)
            {
                d[2][top[2]] = i;
                top[2]++;
            }
            break;
    }

    //打印第一行初始：
    cout << "初始:               ";
    printStack();

    hanoi(n, start, tmp, end);

    return 0;
}