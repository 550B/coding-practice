/*2151974 ��� ������*/
#include <iostream>
#include <iomanip>
#include <tchar.h>
#include <string.h>
#include <conio.h>
#include <fstream>
#include <Windows.h>
using namespace std;

const int MAXSHOP = 30;
const int MAXSPE = 10;

struct SHOP
{
	char ch;
	char name[33];
	double price;
}list[MAXSHOP];

struct SPECIAL
{
	char ch[20];
	char name[33];
	double price;
}special[MAXSPE];

/* ������ɫ���ú궨��ȡ�����֣�������䣩 */
#define COLOR_BLACK		0	//��
#define COLOR_BLUE		1	//��
#define COLOR_GREEN		2	//��
#define COLOR_CYAN		3	//��
#define COLOR_RED		4	//��
#define COLOR_PINK		5	//��
#define COLOR_YELLOW	6	//��
#define COLOR_WHITE		7	//��
#define COLOR_HBLACK	8	//����
#define COLOR_HBLUE		9	//����
#define COLOR_HGREEN	10	//����
#define COLOR_HCYAN		11	//����
#define COLOR_HRED		12	//����
#define COLOR_HPINK		13	//����
#define COLOR_HYELLOW	14	//����
#define COLOR_HWHITE	15	//����

//����
const int RIGHT_BORDER = 82;
const int BOTTOM = 4;

/* --------------------------------------------------------------------------------------- */
/*   �˴�����������̬ȫ�ֱ�����Ŀ�������к���������Ҫ�ٴ� HANDLE ������ʹ�ⲿ����ʱ������  */
/*   ע��Ϊ��ֹͬ������̬ȫ��һ�㽨���__��Ϊ��������ʼ                                    */
/* --------------------------------------------------------------------------------------- */
static const HANDLE __hout = GetStdHandle(STD_OUTPUT_HANDLE);		//ȡ��׼����豸��Ӧ�ľ��
static const HANDLE __hin = GetStdHandle(STD_INPUT_HANDLE);		//ȡ��׼�����豸��Ӧ�ľ��

/***************************************************************************
  �������ƣ�
  ��    �ܣ�������ƶ���ָ��λ��
  ���������const int X       ��X�����꣨�У�
			const int Y       ��Y�����꣨�У�
  �� �� ֵ��
  ˵    ������Ļ���Ͻ�����Ϊ(0,0)����cmd���ڵĴ�Сδ������������£�Win10Ϊ��
			����x�ᣬ��Ӧ��(0-119)
			����y�ᣬ��Ӧ��(0-29)
***************************************************************************/
void cct_gotoxy(const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(__hout, coord);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�����ָ������ɫ
  ���������const int bg_color ������ɫ��0-15��
			const int fg_color ��ǰ��ɫ��0-15��
  �� �� ֵ��
  ˵    ������ɫ��ȡֵ�ɱ���ɫ+ǰ��ɫ��ɣ���16��
			fg_color��0-7    ��   ��   ��   ��   ��   ��   ��   ��
					  8-15 ���� ���� ���� ���� ���� ���� ���� ����
			bg_color��0-7    ��   ��   ��   ��   ��   ��   ��   ��
					  8-15 ���� ���� ���� ���� ���� ���� ���� ����
			���յ���ɫΪ ����ɫ*16+ǰ��ɫ
***************************************************************************/
void cct_setcolor(const int bg_color = COLOR_BLACK, const int fg_color = COLOR_WHITE)
{
	SetConsoleTextAttribute(__hout, bg_color * 16 + fg_color);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ָ��λ�ã���ָ����ɫ����ʾһ���ַ����ɴ�
  ���������const int X       ��X�����꣨�У�
			const int Y       ��Y�����꣨�У�
			const char ch     ��Ҫ������ַ�ֵ
			const int bg_color������ɫ��ȱʡΪCOLOR_BLACK��
			const int fg_color������ɫ��ȱʡΪCOLOR_WHITE��
			const int rpt     ���ظ�������ȱʡΪ1��
  �� �� ֵ��
  ˵    ����X��Y�ķ�Χ�μ�gotoxy������˵��
***************************************************************************/
void cct_showch(const int X, const int Y, const char ch, const int bg_color = COLOR_BLACK, const int fg_color = COLOR_WHITE, const int rpt = 1)
{
	int i;

	cct_gotoxy(X, Y);
	cct_setcolor(bg_color, fg_color);

	/* ѭ��n�Σ���ӡ�ַ�ch */
	for (i = 0; i < rpt; i++)
		putchar(ch);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void file_read(SHOP list[], SPECIAL special[])
{
	SHOP* p = list;
	ifstream in;
	in.open("KFC-price.cfg", ios::in);
	if (in.is_open() == 0)
	{
		cout << "��ʧ��!" << endl;
		return;
	}

	while (1)
	{
		char tmp = in.get();
		if (tmp == '[')
		{
			char temp[10];
			in.getline(temp, 10);
			if (strcmp(temp, "��Ʒ�˵�]"))
			{
				continue;
			}
			else
			{
				break;
			}
		}
	}

	while (!in.eof())
	{
		char tmp = in.get();
		if (tmp == '#')
		{
			while (in.get() != '\n');
		}
		else if (tmp >= 33 && tmp <= 126)
		{
			p->ch = tmp;
			char temp;
			while (temp = in.peek() == ' ')
				in.get();
			char* q = p->name;
			while (temp = in.get() != ' ')
			{
				*q++ = temp;
			}
			in >> p->price;
			p++;
		}
		if (tmp == '[')
		{
			char temp[10];
			in.getline(temp, 10);
			if (strcmp(temp, "��ϲ˵�]"))
			{
				continue;
			}
			else
			{
				break;
			}
		}
	}









	in.close();
}

/***************************************************************************
  �������ƣ�print_things
  ��    �ܣ���ӡ��Ʒ����
  ���������int* p, const int SHOPPING_CART = 1
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void print_things(int* p, const int SHOPPING_CART = 1)
{
	int* q = p;
	for (int i = 0; i < 26; i++, p++)
	{
		if (*p == 1)
			cout << list[p - q].name;
		else if (*p > 1)
			cout << list[p - q].name << "*" << *p;
		if (*p)
		{
			int tmp = 0;
			for (int j = 1; j < 26 - (p - q); j++)
				tmp += *(p + j);
			if (tmp)
				cout << "+";
			else if (SHOPPING_CART)
				cout << '=';
		}
	}
}

/***************************************************************************
  �������ƣ�print_favorable
  ��    �ܣ���ӡ�Ż���Ϣ
  ���������void
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void print_favorable()
{
	int count[26] = {};
	const struct SPECIAL* p = &special[0];
	while (*p->ch != 0)
	{
		cout << p->name << "(" << p->ch << ")=";
		const char* q = p->ch;
		while (*q != '\0')
		{
			count[(int)(*q - 'A')]++;
			q++;
		}
		print_things(count);
		cout << p->price << endl;
		for (int i = 0; i < 26; i++)
			count[i] = 0;
		p++;
	}
}

/***************************************************************************
  �������ƣ�judge
  ��    �ܣ��ж��Żݺͼ���۸�
  ���������int* p
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void judge(int* p)
{
	int* q = p;
	const int SIZE_OF_SPECIAL = sizeof(special) / sizeof(SPECIAL);
	int sp[SIZE_OF_SPECIAL] = {};
	cout << "���Ĺ��ﳵ=";
	print_things(p, 0);
	cout << endl << "���ƣ�";
	const struct SPECIAL* pp = &special[0];
	while (*pp->ch != 0)
	{
		const char* qq = pp->ch;
		while (1)
		{
			while (*qq != '\0')
			{
				(*(p + (*qq - 'A')))--;
				qq++;
			}
			qq = pp->ch;
			int sign = 1;
			while (*qq != '\0')
			{
				if (*(p + (*qq - 'A')) < 0)
				{
					sign = 0;
					break;
				}
				qq++;
			}
			qq = pp->ch;
			if (sign)
				sp[pp - special]++;
			else
			{
				while (*qq != '\0')
				{
					(*(p + (*qq - 'A')))++;
					qq++;
				}
				break;
			}
		}
		pp++;
	}
	double result = 0;
	for (int i = 0; i < SIZE_OF_SPECIAL; i++)
		if (sp[i])
			result += special[i].price * sp[i];
	for (int i = 0; i < 26; i++)
		result += list[i].price * (*(p + i));
	cout << result << "Ԫ" << endl;
}

/***************************************************************************
  �������ƣ�read
  ��    �ܣ���ȡ�㵥��Ϣ
  ���������void
  �� �� ֵ��int
  ˵    ����
***************************************************************************/
int read()
{
	char tmp[5000];
	int count[26] = { 0 };
	char ch;
	char* p = tmp;
	while ((ch = getchar()) != '\n' && ch != EOF)
	{
		*p = ch;
		p++;
	}
	*p = '\0';
	p = tmp;
	if (*p == '\0')
		return 2;
	while (*p != '\0')
	{
		if (*p >= 'a' && *p <= 'z')
			(*p) -= 'a' - 'A';
		if (*p >= 'A' && *p <= 'Z')
			count[(*p) - 'A']++;
		else if (*p == '0' && p == tmp && *(p + 1) == '\0')
			return 0;
		else
		{
			cout << "������󣬰����������." << endl;
			return 1;
		}
		p++;
	}
	judge(count);
	cout << "�㵥��ɣ������������." << endl;
	return 1;
}

/***************************************************************************
  �������ƣ�menu
  ��    �ܣ��˵�
  ���������void
  �� �� ֵ��int
  ˵    ����
***************************************************************************/
int menu()
{
	system("cls");
	for (int i = 0; i < RIGHT_BORDER; i++)
	{
		cct_showch(i, 0, ' ', i % 15 + 1);
	}
	cct_showch(0, BOTTOM - 3, ' ', 2);
	cct_showch(RIGHT_BORDER - 1, BOTTOM - 3, ' ', 2);
	cct_showch(0, BOTTOM - 2, ' ', 3);
	cct_showch(RIGHT_BORDER - 1, BOTTOM - 2, ' ', 3);
	cct_showch(0, BOTTOM - 1, ' ', 4);
	cct_showch(RIGHT_BORDER - 1, BOTTOM - 1, ' ', 4);
	for (int i = 0; i < RIGHT_BORDER; i++)
	{
		cct_showch(i, BOTTOM, ' ', i % 15 + 5);
	}
	for (int i = 1; i <= 13; i++)
	{
		cct_showch(0, BOTTOM + i, ' ', 6);
		cct_showch(RIGHT_BORDER - 1, BOTTOM + i, ' ', 6);
	}
	cct_setcolor();
	cct_gotoxy(1, 1);
	for (int i = 0; i < RIGHT_BORDER - 2; i++)
	{
		cout << '=';
	}
	cout << endl;
	cct_gotoxy(35, 2);
	cout << "KFC���";
	cct_gotoxy(1, 3);
	for (int i = 0; i < RIGHT_BORDER - 2; i++)
	{
		cout << '=';
	}
	cct_gotoxy(2, BOTTOM + 1);
	for (int i = 0; i < sizeof(list) / sizeof(SHOP) - 1; i += 2)
	{
		if (list[i].ch == '\0')
			break;
		cout << list[i].ch << " " << setiosflags(ios::left) << setw(28) << list[i].name << setw(8) << list[i].price << "|";
		if (list[i + 1].ch == '\0')
			break;
		cout << " " << list[i + 1].ch << " " << setw(30) << list[i + 1].name << setw(5) << list[i + 1].price;
		cct_gotoxy(2, BOTTOM + 1 + (i + 2) / 2);
	}
	cct_gotoxy(0, 18);
	cout << endl << "���Ż���Ϣ����" << endl;
	print_favorable();

	cout << endl << "���������˵������" << endl;
	cout << "ANV=�������ȱ�+����(С)+���¿���(С) / akaak=�������ȱ�*3+��������*2" << endl;
	cout << "��ĸ���ִ�Сд������˳�򣬵�������0���˳�����" << endl;

	cout << endl << "��ѡ����";
	return read();
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
	system("mode con cols=120 lines=45");
	file_read(list, special);
	while (1)
	{
		int choice;
		if (choice = menu())
		{
			if (choice == 1)
				char t = _getch();
		}
		else
			break;
	}
	return 0;
}