/*2151974 ��� ������*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cnt = 0;    //һ�������õ�ȫ�ֱ���
int atop = 0, btop = 0, ctop = 0;   //����ջ��ջ��ָ��
int a[12] = { 0 }, b[12] = { 0 }, c[12] = { 0 };    //����ȫ��һά����

/***************************************************************************
    �������ƣ�printStack
    ��    �ܣ���ӡ�����������
    ���������void
    �� �� ֵ��void
    ˵    ����Ϊ��hanoi����û��ѭ��(?)
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
    �������ƣ�
    ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
    ���������int n������
              char src����ʼ��
              char tmp���м���
              char dst��Ŀ����
    �� �� ֵ��
    ˵    ����
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
                printf("��%4d ��(%2d): %c-->%c", ++cnt, b[btop++] = a[--atop], src, dst);
            }
            else
            {
                printf("��%4d ��(%2d): %c-->%c", ++cnt, c[ctop++] = a[--atop], src, dst);
            }
            break;
        case 'B':
            if (dst == 'A')
            {
                printf("��%4d ��(%2d): %c-->%c", ++cnt, a[atop++] = b[--btop], src, dst);
            }
            else
            {
                printf("��%4d ��(%2d): %c-->%c", ++cnt, c[ctop++] = b[--btop], src, dst);
            }
            break;
        default:
            if (dst == 'B')
            {
                printf("��%4d ��(%2d): %c-->%c", ++cnt, b[btop++] = c[--ctop], src, dst);
            }
            else
            {
                printf("��%4d ��(%2d): %c-->%c", ++cnt, a[atop++] = c[--ctop], src, dst);
            }
            break;
    }
    printStack();
    hanoi(n - 1, tmp, src, dst);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
    char start, end, tmp;
    int n;
    int ret1;

    while (1)
    {
        printf("�����뺺ŵ���Ĳ���(1-10)\n");
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
        printf("��������ʼ��(A-C)\n");
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
        printf("������Ŀ����(A-C)\n");
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
                /*cout << "Ŀ����(" << end << ")��������ʼ��(" << start << ")��ͬ\n" << endl;*/
                printf("Ŀ����(%c)��������ʼ��(%c)��ͬ\n", end, start);
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

    //��ʼ������ȫ������
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

    //��ӡ��һ�г�ʼ��
    printf("��ʼ:               ");
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
    printf("��1018 ��( 2): C-->A A: 2                   B:10 9 8 7 6 5 4 1     C: 3");*/

    hanoi(n, start, tmp, end);

    return 0;
}