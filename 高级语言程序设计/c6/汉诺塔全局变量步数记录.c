/*2151974 软件 赵明泽*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----具体要求----
   1、不允许添加其它头文件
   2、允许定义一个全局变量、不允许定义静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */

int cnt = 0;

   /***************************************************************************
     函数名称：
     功    能：打印n层汉诺塔的移动顺序
     输入参数：int n：层数
               char src：起始柱
               char tmp：中间柱
               char dst：目标柱
     返 回 值：
     说    明：1、函数名、形参、返回类型均不准动
               2、本函数不允许出现任何形式的循环
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 0)
    {
        return;
    }
    hanoi(n - 1, src, dst, tmp);
    /*cout << setiosflags(ios::right) << setw(2) << n << "# " << src << "-->" << dst << endl;*/
    printf("%5d:%3d# %c-->%c\n", ++cnt, n, src, dst);
    hanoi(n - 1, tmp, src, dst);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
            2、处理输入错误时，允许使用循环
            3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
int main()
{
    char start, end, tmp;
    int n;
    int ret1;

    while (1)
    {
        printf("请输入汉诺塔的层数(1-16)\n");
        ret1 = scanf("%d", &n);

        if (ret1 == 0 || n < 1 || n > 16)
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

    printf("移动步骤为:\n");

    hanoi(n, start, tmp, end);

    return 0;
}