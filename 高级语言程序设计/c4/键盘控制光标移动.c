/*2151974 ��� ������*/
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
			char ch    ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
	printf("***********************************************************************\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("***********************************************************************\n");

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/

/***************************************************************************
  �������ƣ�menu
  ��    �ܣ��˵���ʾ��ѡ��
  ���������void
  �� �� ֵ��int
  ˵    ����NULL
***************************************************************************/
int menu()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	cls(hout);

	printf("1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)\n");
	printf("2.��I��J��K��L��������������(��Сд���ɣ��߽����)\n");
	printf("3.�ü�ͷ�������������ң��߽�ֹͣ������дHPKMʱ�����ƶ���\n");
	printf("4.�ü�ͷ�������������ң��߽���ƣ�����дHPKMʱ�����ƶ���\n");
	printf("5.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ,�����ͷ���������ƶ�)\n");
	printf("6.��I��J��K��L��������������(��Сд���ɣ��߽����,�����ͷ���������ƶ�)\n");
	printf("0.�˳�\n");
	printf("[��ѡ��0-6]");

	char ch;
	ch = _getche();
	int num;
	switch (ch)
	{
		case '0':
			num = 0;
			break;
		case '1':
			num = 1;
			break;
		case '2':
			num = 2;
			break;
		case '3':
			num = 3;
			break;
		case '4':
			num = 4;
			break;
		case '5':
			num = 5;
			break;
		case '6':
			num = 6;
			break;
		default:
			num = 2151974;
			break;
	}
	return num;
}

/***************************************************************************
  �������ƣ�move_by_arrow
  ��    �ܣ��ü�ͷ�ƶ�����
  ���������int hr
  �� �� ֵ��void
  ˵    ����NULL
***************************************************************************/
void move_by_arrow(int hr)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	//��������Ų��
	char f, t;
	int x2 = 35, y2 = 9;

	while (1)
	{
		f = _getch();
		if (f == 'q' || f == 'Q')
		{
			break;
		}
		if ((int)f == 32)
		{
			putchar(' ');
			gotoxy(hout, x2, y2);
		}
		if ((int)f == -32)
		{
			t = _getch();

			if (hr == 3)
			{
				if ((x2 == 1 && t == 75) || (x2 == 69 && t == 77) || (y2 == 1 && t == 72) || (y2 == 17 && t == 80))
				{
					continue;
				}
			}
			else if (hr == 4)
			{
				if (x2 == 1 && t == 75)
				{
					x2 = 69;
					gotoxy(hout, x2, y2);
					continue;
				}
				if (x2 == 69 && t == 77)
				{
					x2 = 1;
					gotoxy(hout, x2, y2);
					continue;
				}
				if (y2 == 1 && t == 72)
				{
					y2 = 17;
					gotoxy(hout, x2, y2);
					continue;
				}
				if (y2 == 17 && t == 80)
				{
					y2 = 1;
					gotoxy(hout, x2, y2);
					continue;
				}
			}

			//normal
			if ((int)t == 75)
			{
				x2 -= 1;
				gotoxy(hout, x2, y2);
			}
			if ((int)t == 77)
			{
				x2 += 1;
				gotoxy(hout, x2, y2);
			}
			if ((int)t == 72)
			{
				y2 -= 1;
				gotoxy(hout, x2, y2);
			}
			if ((int)t == 80)
			{
				y2 += 1;
				gotoxy(hout, x2, y2);
			}
		}
	}
}

/***************************************************************************
  �������ƣ�move_by_ijkl_better
  ��    �ܣ���ijkl�ƶ�����
  ���������int hr
  �� �� ֵ��void
  ˵    ����NULL
***************************************************************************/
void move_by_ijkl_better(int hr)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	//��������Ų��
	char m, n;
	int x3 = 35, y3 = 9;

	while (1)
	{
		m = _getch();
		if ((int)m == -32)
		{
			n = _getch();
			continue;
		}
		if (m == 'q' || m == 'Q')
		{
			break;
		}
		//�ж��Ƿ����
		if (hr == 5)		//������
		{
			if ((x3 == 1 && (m == 'j' || m == 'J')) || (x3 == 69 && (m == 'l' || m == 'L')) || (y3 == 1 && (m == 'i' || m == 'I')) || (y3 == 17 && (m == 'k' || m == 'K')))
			{
				continue;
			}
		}
		else if (hr == 6)	//����
		{
			if (x3 == 1 && (m == 'j' || m == 'J'))
			{
				x3 = 69;
				gotoxy(hout, x3, y3);
				continue;
			}
			if (x3 == 69 && (m == 'l' || m == 'L'))
			{
				x3 = 1;
				gotoxy(hout, x3, y3);
				continue;
			}
			if (y3 == 1 && (m == 'i' || m == 'I'))
			{
				y3 = 17;
				gotoxy(hout, x3, y3);
				continue;
			}
			if (y3 == 17 && (m == 'k' || m == 'K'))
			{
				y3 = 1;
				gotoxy(hout, x3, y3);
				continue;
			}
		}
		//����
		if (m == 'j' || m == 'J')
		{
			x3 -= 1;
			gotoxy(hout, x3, y3);
		}
		if (m == 'l' || m == 'L')
		{
			x3 += 1;
			gotoxy(hout, x3, y3);
		}
		if (m == 'i' || m == 'I')
		{
			y3 -= 1;
			gotoxy(hout, x3, y3);
		}
		if (m == 'k' || m == 'K')
		{
			y3 += 1;
			gotoxy(hout, x3, y3);
		}
		if ((int)m == 32)
		{
			putchar(' ');
			gotoxy(hout, x3, y3);
		}
	}
}

/***************************************************************************
  �������ƣ�move_by_ijkl
  ��    �ܣ���ijkl�����ͷ�ƶ�����
  ���������int hr
  �� �� ֵ��void
  ˵    ����NULL
***************************************************************************/
void move_by_ijkl(int hr)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	//��������Ų��
	char a;
	int x1 = 35, y1 = 9;

	while (1)
	{
		a = _getch();
		if (a == 'q' || a == 'Q')
		{
			break;
		}
		//�ж��Ƿ����
		if (hr == 1)		//������
		{
			if ((x1 == 1 && (a == 'j' || a == 'J')) || (x1 == 69 && (a == 'l' || a == 'L')) || (y1 == 1 && (a == 'i' || a == 'I')) || (y1 == 17 && (a == 'k' || a == 'K')))
			{
				continue;
			}
		}
		else if (hr == 2)	//����
		{
			if (x1 == 1 && (a == 'j' || a == 'J'))
			{
				x1 = 69;
				gotoxy(hout, x1, y1);
				continue;
			}
			if (x1 == 69 && (a == 'l' || a == 'L'))
			{
				x1 = 1;
				gotoxy(hout, x1, y1);
				continue;
			}
			if (y1 == 1 && (a == 'i' || a == 'I'))
			{
				y1 = 17;
				gotoxy(hout, x1, y1);
				continue;
			}
			if (y1 == 17 && (a == 'k' || a == 'K'))
			{
				y1 = 1;
				gotoxy(hout, x1, y1);
				continue;
			}
		}
		//����
		if (a == 'j' || a == 'J')
		{
			x1 -= 1;
			gotoxy(hout, x1, y1);
		}
		if (a == 'l' || a == 'L')
		{
			x1 += 1;
			gotoxy(hout, x1, y1);
		}
		if (a == 'i' || a == 'I')
		{
			y1 -= 1;
			gotoxy(hout, x1, y1);
		}
		if (a == 'k' || a == 'K')
		{
			y1 += 1;
			gotoxy(hout, x1, y1);
		}
		if ((int)a == 32)
		{
			putchar(' ');
			gotoxy(hout, x1, y1);
		}
	}
}

/***************************************************************************
  �������ƣ�moving
  ��    �ܣ���ʼ����Ϸ�����ѡ���ƶ�������ʽ
  ���������int choice
  �� �� ֵ��void
  ˵    ����NULL
***************************************************************************/
void moving(int choice)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	/* ��ʾ��ʼ�ı߿����е�����ַ� */
	init_border(hout);

	//�ѹ���ƶ�����Ļ������
	gotoxy(hout, 35, 9);

	//ѡ��
	switch (choice)
	{
		case 1:
		case 2:
			move_by_ijkl(choice);
			break;
		case 3:
		case 4:
			move_by_arrow(choice);
			break;
		default:
			move_by_ijkl_better(choice);
			break;
	}

	//�˳�ģ��
	gotoxy(hout, 0, 23);
	printf("��Ϸ���������س������ز˵�.");
	//���س��˳�
	char b;
	while (1)
	{
		b = _getch();
		if ((int)b == 13)
		{
			break;
		}
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand((unsigned int)(time(0)));

	/* �˾�������ǵ���ϵͳ��cls�������� */
	cls(hout);

	//ѡ��
	while (1)
	{
		int tmp;
		tmp = menu();

		if (tmp == 2151974)
		{
			cls(hout);
			continue;
		}
		else if (tmp == 0)
		{
			break;
		}
		else
		{
			cls(hout);
			moving(tmp);
		}
	}

	return 0;
}

/*
˼��
1���ܡ���Ϊ�������Ҽ�ͷ����ASCII������������ͷ��ʱ����ʵ������ֵ��
�����char���ͣ���һ��ֵ��-32���ڶ���ֵ�ֱ�����������72��80��75��77.
�����int���ͣ���һ��ֵ��224���ڶ���ֵͬ�ϡ�
��д��ĸ��K����ASCII��������75.
ѭ��������һ���������ֲ�û��ʲô�ã�Ȼ��ʼ���ڶ��������������ͷ�ĵڶ�����
���ú�Kһ����Ҳ���ǹ�����ƣ����ԾͲ�������������

2����һ�����п��ܲ���20������ȡģ����õ�0ʱ����ĸ����������*λ�ã����Ǹ�λ��
����������ĸ�����Ե�����ĸ����
*/