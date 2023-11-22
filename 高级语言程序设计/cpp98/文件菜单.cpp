/*2151974 软件 赵明泽*/
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

/* 定义颜色（用宏定义取代数字，方便记忆） */
#define COLOR_BLACK		0	//黑
#define COLOR_BLUE		1	//蓝
#define COLOR_GREEN		2	//绿
#define COLOR_CYAN		3	//青
#define COLOR_RED		4	//红
#define COLOR_PINK		5	//粉
#define COLOR_YELLOW	6	//黄
#define COLOR_WHITE		7	//白
#define COLOR_HBLACK	8	//亮黑
#define COLOR_HBLUE		9	//亮蓝
#define COLOR_HGREEN	10	//亮绿
#define COLOR_HCYAN		11	//亮青
#define COLOR_HRED		12	//亮红
#define COLOR_HPINK		13	//亮粉
#define COLOR_HYELLOW	14	//亮黄
#define COLOR_HWHITE	15	//亮白

//坐标
const int RIGHT_BORDER = 82;
const int BOTTOM = 4;

/* --------------------------------------------------------------------------------------- */
/*   此处定义两个静态全局变量，目的是所有函数都不需要再带 HANDLE 参数，使外部调用时更方便  */
/*   注：为防止同名，静态全局一般建议加__做为变量名开始                                    */
/* --------------------------------------------------------------------------------------- */
static const HANDLE __hout = GetStdHandle(STD_OUTPUT_HANDLE);		//取标准输出设备对应的句柄
static const HANDLE __hin = GetStdHandle(STD_INPUT_HANDLE);		//取标准输入设备对应的句柄

/***************************************************************************
  函数名称：
  功    能：将光标移动到指定位置
  输入参数：const int X       ：X轴坐标（列）
			const int Y       ：Y轴坐标（行）
  返 回 值：
  说    明：屏幕左上角坐标为(0,0)，在cmd窗口的大小未被调整的情况下，Win10为：
			横向x轴，对应列(0-119)
			纵向y轴，对应行(0-29)
***************************************************************************/
void cct_gotoxy(const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(__hout, coord);
}

/***************************************************************************
  函数名称：
  功    能：设置指定的颜色
  输入参数：const int bg_color ：背景色（0-15）
			const int fg_color ：前景色（0-15）
  返 回 值：
  说    明：颜色的取值由背景色+前景色组成，各16种
			fg_color：0-7    黑   蓝   绿   青   红   粉   黄   白
					  8-15 亮黑 亮蓝 亮绿 亮青 亮红 亮粉 亮黄 亮白
			bg_color：0-7    黑   蓝   绿   青   红   粉   黄   白
					  8-15 亮黑 亮蓝 亮绿 亮青 亮红 亮粉 亮黄 亮白
			最终的颜色为 背景色*16+前景色
***************************************************************************/
void cct_setcolor(const int bg_color = COLOR_BLACK, const int fg_color = COLOR_WHITE)
{
	SetConsoleTextAttribute(__hout, bg_color * 16 + fg_color);
}

/***************************************************************************
  函数名称：
  功    能：在指定位置，用指定颜色，显示一个字符若干次
  输入参数：const int X       ：X轴坐标（列）
			const int Y       ：Y轴坐标（行）
			const char ch     ：要输出的字符值
			const int bg_color：背景色（缺省为COLOR_BLACK）
			const int fg_color：背景色（缺省为COLOR_WHITE）
			const int rpt     ：重复次数（缺省为1）
  返 回 值：
  说    明：X、Y的范围参见gotoxy函数的说明
***************************************************************************/
void cct_showch(const int X, const int Y, const char ch, const int bg_color = COLOR_BLACK, const int fg_color = COLOR_WHITE, const int rpt = 1)
{
	int i;

	cct_gotoxy(X, Y);
	cct_setcolor(bg_color, fg_color);

	/* 循环n次，打印字符ch */
	for (i = 0; i < rpt; i++)
		putchar(ch);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void file_read(SHOP list[], SPECIAL special[])
{
	SHOP* p = list;
	ifstream in;
	in.open("KFC-price.cfg", ios::in);
	if (in.is_open() == 0)
	{
		cout << "打开失败!" << endl;
		return;
	}

	while (1)
	{
		char tmp = in.get();
		if (tmp == '[')
		{
			char temp[10];
			in.getline(temp, 10);
			if (strcmp(temp, "单品菜单]"))
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
			if (strcmp(temp, "组合菜单]"))
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
  函数名称：print_things
  功    能：打印物品名称
  输入参数：int* p, const int SHOPPING_CART = 1
  返 回 值：void
  说    明：
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
  函数名称：print_favorable
  功    能：打印优惠信息
  输入参数：void
  返 回 值：void
  说    明：
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
  函数名称：judge
  功    能：判断优惠和计算价格
  输入参数：int* p
  返 回 值：void
  说    明：
***************************************************************************/
void judge(int* p)
{
	int* q = p;
	const int SIZE_OF_SPECIAL = sizeof(special) / sizeof(SPECIAL);
	int sp[SIZE_OF_SPECIAL] = {};
	cout << "您的购物车=";
	print_things(p, 0);
	cout << endl << "共计：";
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
	cout << result << "元" << endl;
}

/***************************************************************************
  函数名称：read
  功    能：读取点单信息
  输入参数：void
  返 回 值：int
  说    明：
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
			cout << "输入错误，按任意键继续." << endl;
			return 1;
		}
		p++;
	}
	judge(count);
	cout << "点单完成，按任意键继续." << endl;
	return 1;
}

/***************************************************************************
  函数名称：menu
  功    能：菜单
  输入参数：void
  返 回 值：int
  说    明：
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
	cout << "KFC点餐";
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
	cout << endl << "【优惠信息】：" << endl;
	print_favorable();

	cout << endl << "【输入规则说明】：" << endl;
	cout << "ANV=香辣鸡腿堡+薯条(小)+百事可乐(小) / akaak=香辣鸡腿堡*3+香辣鸡翅*2" << endl;
	cout << "字母不分大小写，不限顺序，单独输入0则退出程序" << endl;

	cout << endl << "请选购：";
	return read();
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