/*2151974 ��� ������*/
#include <iostream>
#include <iomanip>
using namespace std;

int cnt = 0;
int top[3] = {};
int d[3][10] = {};

/***************************************************************************
    �������ƣ�printStack
    ��    �ܣ���ӡ�����������
    ���������void
    �� �� ֵ��void
    ˵    ����Ϊ��hanoi����û��ѭ��(?)
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

    switch (src)
    {
        case 'A':
            if (dst == 'B')
            {
                d[1][top[1]++] = d[0][--top[0]];
                cout << "��" << setw(4) << ++cnt << " ��(" << setw(2) << d[1][top[1]-1] << "): " << src << "-->" << dst;
            }
            else
            {
                d[2][top[2]++] = d[0][--top[0]];
                cout << "��" << setw(4) << ++cnt << " ��(" << setw(2) << d[2][top[2]-1] << "): " << src << "-->" << dst;
            }
            break;
        case 'B':
            if (dst == 'A')
            {
                d[0][top[0]++] = d[1][--top[1]];
                cout << "��" << setw(4) << ++cnt << " ��(" << setw(2) << d[0][top[0]-1] << "): " << src << "-->" << dst;
            }
            else
            {
                d[2][top[2]++] = d[1][--top[1]];
                cout << "��" << setw(4) << ++cnt << " ��(" << setw(2) << d[2][top[2]-1] << "): " << src << "-->" << dst;
            }
            break;
        default:
            if (dst == 'B')
            {
                d[1][top[1]++] = d[2][--top[2]];
                cout << "��" << setw(4) << ++cnt << " ��(" << setw(2) << d[1][top[1]-1] << "): " << src << "-->" << dst;
            }
            else
            {
                d[0][top[0]++] = d[2][--top[2]];
                cout << "��" << setw(4) << ++cnt << " ��(" << setw(2) << d[0][top[0]-1] << "): " << src << "-->" << dst;
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

    while (1)
    {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
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
        cout << "��������ʼ��(A-C)" << endl;
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
        cout << "������Ŀ����(A-C)" << endl;
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
                cout << "Ŀ����(" << end << ")��������ʼ��(" << start << ")��ͬ" << endl;
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

    //��ʼ��ȫ������
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

    //��ӡ��һ�г�ʼ��
    cout << "��ʼ:               ";
    printStack();

    hanoi(n, start, tmp, end);

    return 0;
}