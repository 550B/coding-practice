/*2151974 软件 赵明泽*/
#include <iostream>
#include <conio.h>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;

//以下是整体偏移值
const int DELTA = 16;

/* ----------------------------------------------------------------------------------

     本文件功能：
	1、放被 hanoi_main.cpp 调用的菜单函数，要求显示各菜单项，读入正确的选项后返回

     本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、不允许定义静态全局变量（全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  函数名称：title
  功    能：打印初始显示框
  输入参数：void
  返 回 值：void
  说    明：
***************************************************************************/
void title()
{
	cout << "---------------------------------" << endl;
	cout << "1.基本解" << endl;
	cout << "2.基本解(步数记录)" << endl;
	cout << "3.内部数组显示(横向)" << endl;
	cout << "4.内部数组显示(纵向+横向)" << endl;
	cout << "5.图形解-预备-画三个圆柱" << endl;
	cout << "6.图形解-预备-在起始柱上画n个盘子" << endl;
	cout << "7.图形解-预备-第一次移动" << endl;
	cout << "8.图形解-自动移动版本" << endl;
	cout << "9.图形解-游戏版" << endl;
	cout << "0.退出" << endl;
	cout << "---------------------------------" << endl;
	cout << "[请选择:]";
}

/***************************************************************************
  函数名称：choice
  功    能：输入选择数字，返回选择的结果
  输入参数：void
  返 回 值：int
  说    明：
***************************************************************************/
int choice()
{
	char temp;
	while (1)
	{
		temp = _getch();
		if (temp >= '0' && temp <= '9')
		{
            cout << temp << endl << endl << endl;
			break;
		}
	}
	return (int)(temp - '0');
}

/***************************************************************************
    函数名称：menu
    功    能：重复调用菜单
    输入参数：void
    返 回 值：int
    说    明：
***************************************************************************/
int menu()
{
    title();
    return choice();
}

/***************************************************************************
  函数名称：un_deux_trois
  功    能：前三个
  输入参数：int& n, int& choice, char& src, char& tmp, char& dst, int& cols, int& lines, int& buffer_cols, int& buffer_lines
  返 回 值：void
  说    明：
***************************************************************************/
void un_deux_trois(int& n, int& choice, char& src, char& tmp, char& dst, int& cols, int& lines, int& buffer_cols, int& buffer_lines)
{
	data_in(n, src, dst, tmp);
	hanoi(n, src, tmp, dst, choice);
	cout << endl;
	cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
	to_be_continued(buffer_cols, buffer_lines);
}

/***************************************************************************
  函数名称：quatre
  功    能：第四个
  输入参数：int& n, int& choice, char& src, char& tmp, char& dst
  返 回 值：void
  说    明：
***************************************************************************/
void quatre(int& n, int& choice, char& src, char& tmp, char& dst)
{
	data_in(n, src, dst, tmp, 1);
	cct_setcursor(3);
	H_and_Stack_pre(n, src, tmp, dst);
	hanoi(n, src, tmp, dst, choice);
	cct_setcursor(2);
	to_be_continued();
}

/***************************************************************************
  函数名称：cinq
  功    能：第5个
  输入参数：void
  返 回 值：void
  说    明：
***************************************************************************/
void cinq()
{
	cct_cls();
	cct_setcursor(3);
	three_poles();
	cct_setcursor(2);
	to_be_continued();
}

/***************************************************************************
  函数名称：six
  功    能：第6个
  输入参数：int& n, int& choice, char& src, char& tmp, char& dst
  返 回 值：void
  说    明：
***************************************************************************/
void six(int& n, int& choice, char& src, char& tmp, char& dst)
{
	data_in(n, src, dst, tmp);
	cct_setcursor(3);
	cct_cls();
	plates(n, src, tmp, dst, 0);
	cct_setcursor(2);
	to_be_continued();
}

/***************************************************************************
  函数名称：sept
  功    能：第7个
  输入参数：int& n, int& choice, char& src, char& tmp, char& dst
  返 回 值：void
  说    明：
***************************************************************************/
void sept(int& n, int& choice, char& src, char& tmp, char& dst)
{
	data_in(n, src, dst, tmp);
	cct_setcursor(3);
	cct_cls();
	plates(n, src, tmp, dst);
	hanoi(n, src, tmp, dst, choice);
	cct_setcursor(2);
	to_be_continued();
}

/***************************************************************************
  函数名称：huit
  功    能：第8个
  输入参数：int& n, int& choice, char& src, char& tmp, char& dst
  返 回 值：void
  说    明：
***************************************************************************/
void huit(int& n, int& choice, char& src, char& tmp, char& dst)
{
	data_in(n, src, dst, tmp, 1);
	cct_setcursor(3);
	cct_cls();
	H_and_Stack_pre(n, src, tmp, dst, DELTA);
	plates(n, src, tmp, dst);
	hanoi(n, src, tmp, dst, choice);
	cct_setcursor(2);
	to_be_continued();
}

/***************************************************************************
  函数名称：neuf
  功    能：第9个
  输入参数：int& n, int& choice, char& src, char& tmp, char& dst
  返 回 值：void
  说    明：
***************************************************************************/
void neuf(int& n, int& choice, char& src, char& tmp, char& dst)
{
	data_in(n, src, dst, tmp);
	cct_cls();
	H_and_Stack_pre(n, src, tmp, dst, DELTA);
	plates(n, src, tmp, dst, 0);
	cct_setcolor();
	games(n, src, dst);
	to_be_continued();
}