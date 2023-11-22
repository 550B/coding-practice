/*2151974 软件 赵明泽*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cnt = 0;    //一个计数用的全局变量
int atop = 0, btop = 0, ctop = 0;   //三个栈的栈顶指针
int a[12] = { 0 }, b[12] = { 0 }, c[12] = { 0 };    //三个全局一维数组

/***************************************************************************
    函数名称：printStack
    功    能：打印数组里的玩意
    输入参数：void
    返 回 值：void
    说    明：为了hanoi里面没有循环(?)
***************************************************************************/
void printStack()
{
    printf(" A:");
    for (int i = 0; i < atop; i++)
    {
        printf("%2d", a[i]);
    }
    for (int j = 10 - atop; j > 0; j--)
    {
        printf("  ");
    }

    printf(" B:");
    for (int i = 0; i < btop; i++)
    {
        printf("%2d", b[i]);
    }
    for (int j = 10 - btop; j > 0; j--)
    {
        printf("  ");
    }

    printf(" C:");
    for (int i = 0; i < ctop; i++)
    {
        printf("%2d", c[i]);
    }
    for (int j = 10 - ctop; j > 0; j--)
    {
        printf("  ");
    }
    printf("\n");
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
    /*cout << setiosflags(ios::right) << setw(2) << n << "# " << src << "-->" << dst << endl;*/
    //printf("%5d:%3d# %c-->%c\n", ++cnt, n, src, dst);
    switch (src)
    {
        case 'A':
            if (dst == 'B')
            {
                printf("第%4d 步(%2d): %c-->%c", ++cnt, b[btop++] = a[--atop], src, dst);
            }
            else
            {
                printf("第%4d 步(%2d): %c-->%c", ++cnt, c[ctop++] = a[--atop], src, dst);
            }
            break;
        case 'B':
            if (dst == 'A')
            {
                printf("第%4d 步(%2d): %c-->%c", ++cnt, a[atop++] = b[--btop], src, dst);
            }
            else
            {
                printf("第%4d 步(%2d): %c-->%c", ++cnt, c[ctop++] = b[--btop], src, dst);
            }
            break;
        default:
            if (dst == 'B')
            {
                printf("第%4d 步(%2d): %c-->%c", ++cnt, b[btop++] = c[--ctop], src, dst);
            }
            else
            {
                printf("第%4d 步(%2d): %c-->%c", ++cnt, a[atop++] = c[--ctop], src, dst);
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
    int ret1;

    while (1)
    {
        printf("请输入汉诺塔的层数(1-10)\n");
        ret1 = scanf("%d", &n);

        if (ret1 == 0 || n < 1 || n > 10)
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
        printf("请输入起始柱(A-C)\n");
        start = getchar();

        if (start != 'A' && start != 'a' && start != 'B' && start != 'b' && start != 'C' && start != 'c')
        {
            char t = start;
            while (t == '\n' || t == '\t' || t == ' ')
            {
                t = getchar();
            }
            while (t != '\n' && t != EOF)
            {
                t = getchar();
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
        printf("请输入目标柱(A-C)\n");
        end = getchar();

        if (end != 'A' && end != 'a' && end != 'B' && end != 'b' && end != 'C' && end != 'c')
        {
            char t = end;
            while (t == '\n' || t == '\t' || t == ' ')
            {
                t = getchar();
            }
            while (t != '\n' && t != EOF)
            {
                t = getchar();
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
                /*cout << "目标柱(" << end << ")不能与起始柱(" << start << ")相同\n" << endl;*/
                printf("目标柱(%c)不能与起始柱(%c)相同\n", end, start);
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

    //打印第一行初始：
    printf("初始:               ");
    printStack();

    /*printf("%17c:", 'A');
    for (int i = 0; i < atop; i++)
    {
        printf("%2d", a[i]);
    }
    for (int j = 10 - atop; j > 0; j--)
    {
        printf("  ");
    }
    
    printf(" B:");
    for (int i = 0; i < btop; i++)
    {
        printf("%2d", b[i]);
    }
    for (int j = 10 - btop; j > 0; j--)
    {
        printf("  ");
    }
    
    printf(" C:");
    for (int i = 0; i < ctop; i++)
    {
        printf("%2d", c[i]);
    }
    for (int j = 10 - ctop; j > 0; j--)
    {
        printf("  ");
    }
    printf("\n");*/

   /* printf("\n");
    printf("第1018 步( 2): C-->A A: 2                   B:10 9 8 7 6 5 4 1     C: 3");*/

    hanoi(n, start, tmp, end);

    return 0;
}