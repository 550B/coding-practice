/*2151974 软件 赵明泽*/
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;

/***************************************************************************
  函数名称：title
  功    能：打印初始显示框
  输入参数：void
  返 回 值：void
  说    明：
***************************************************************************/
void title()
{
	cout << "--------------------------------------------" << endl;
	cout << "1.内部数组，随机生成初始5个球" << endl;
	cout << "2.内部数组，随机生成60%的球，寻找移动路径" << endl;
	cout << "3.内部数组，完整版" << endl;
	cout << "4.画出n*n的框架（无分隔线），随机显示5个球" << endl;
	cout << "5.画出n*n的框架（有分隔线），随机显示5个球" << endl;
	cout << "6.n*n的框架，60%的球，支持鼠标，完成一次移动" << endl;
	cout << "7.cmd图形界面完整版" << endl;
	cout << "0.退出" << endl;
	cout << "--------------------------------------------" << endl;
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
		if (temp >= '0' && temp <= '7')
		{
			cout << temp;
			Sleep(200);
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
  函数名称：cin_row
  功    能：输入行数
  输入参数：void
  返 回 值：int
  说    明：
***************************************************************************/
int cin_row()
{
	int row;
	while (1)
	{
		cout << "请输入行数(7-9):" << endl;
		cin >> row;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(999, '\n');
			continue;
		}
		if (row < 7 || row > 9)
			continue;
		break;
	}
	return row;
}

/***************************************************************************
  函数名称：cin_col
  功    能：输入列数
  输入参数：void
  返 回 值：int
  说    明：
***************************************************************************/
int cin_col()
{
	int col;
	while (1)
	{
		cout << "请输入列数(7-9):" << endl;
		cin >> col;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(999, '\n');
			continue;
		}
		if (col < 7 || col > 9)
			continue;
		break;
	}
	return col;
}

/***************************************************************************
  函数名称：data_in
  功    能：输入数据
  输入参数：
  返 回 值：void
  说    明：
***************************************************************************/
void data_in(int& row, int& col)
{
	cct_cls();
	row = cin_row();
	col = cin_col();
}

/***************************************************************************
  函数名称：eins
  功    能：第一个选项函数的集合
  输入参数：int& row, int& col, int g[MAXG][MAXG]
  返 回 值：void
  说    明：
***************************************************************************/
void eins(int& row, int& col, int g[MAXG][MAXG])
{
	data_in(row, col);
	new_a_graph(row, col, g);
	cout << endl << "初始数组:" << endl;
	print_sheet(row, col, g);
	orders_end();
	cct_cls();
}

/***************************************************************************
  函数名称：zwei
  功    能：第二个选项函数的集合
  输入参数：int& row, int& col, int g[MAXG][MAXG], int n[], int path[][2], int tp[2][2]
  返 回 值：void
  说    明：
***************************************************************************/
void zwei(int& row, int& col, int g[MAXG][MAXG], int n[], int path[][2], int tp[2][2])
{
	data_in(row, col);
	new_a_graph(row, col, g, 1);
	cout << endl << "当前数组:" << endl;
	print_sheet(row, col, g);
	next_three(n);
	if (!orders(row, col, g, path, tp, 1))
	{
		cout << endl << endl << "查找结果数组:" << endl;
		print_sheet(row, col, g, path, 1);
		cout << endl << "移动路径(不同色标识):" << endl << endl;
		print_sheet(row, col, g, path, 2);
	}
	else
		cout << endl;
	orders_end();
	cct_cls();
}

/***************************************************************************
  函数名称：drei
  功    能：第三个选项函数的集合
  输入参数：int& row, int& col, int g[MAXG][MAXG], int n[], int path[][2], int tp[2][2]
  返 回 值：void
  说    明：
***************************************************************************/
void drei(int& row, int& col, int g[MAXG][MAXG], int n[], int path[][2], int tp[2][2])
{
	int score = 0, sum = 0;
	data_in(row, col);
	new_a_graph(row, col, g);
	while (whether_end(row, col, g)) {
		cout << endl << "当前数组:" << endl;
		print_sheet(row, col, g);
		next_three(n);
		if(!orders(row, col, g, path, tp, 1))
		{
			move_only(tp, g);
			score = five(row, col, g);
			if (!score)
				fill_only(row, col, n, g);
			score += five(row, col, g);
			sum += score;
			cout << endl << endl << "移动后的数组(不同色标识):" << endl;
			print_sheet(row, col, g);
			cout << endl << "本次得分：" << score << " 总得分：" << sum << endl;
			score = 0;
		}
	}
	orders_end();
	cct_cls();
}

/***************************************************************************
  函数名称：vier_und_fuenf
  功    能：第四、五个选项函数的集合
  输入参数：int& row, int& col, int g[MAXG][MAXG], const int choice = 0
  返 回 值：void
  说    明：
***************************************************************************/
void vier_und_fuenf(int& row, int& col, int g[MAXG][MAXG], const int choice = 0)
{
	int a, b, t;
	data_in(row, col);
	new_a_graph(row, col, g);
	cout << endl << "初始数组:" << endl;
	print_sheet(row, col, g);
	to_be_continued("按回车键显示图形...");
	a = 2 + row + choice * (row - 1) + 4, b = 39;
	cct_setconsoleborder(b, a);
	cct_setfontsize("新宋体", 32);
	cct_getconsoleborder(a, b, t, t);
	cout << "屏幕：" << b << "行" << a << "列" << endl;
	if (choice)
		print_block(row, col, g);
	else
		print_border(row, col, g);
	orders_end();
	cct_setfontsize("", 0);
	cct_setconsoleborder(120, 40);
	cct_cls();
}

/***************************************************************************
  函数名称：sechs
  功    能：第六个选项函数的集合
  输入参数：int& row, int& col, int g[MAXG][MAXG], int next[], int path[][2], int tp[2][2]
  返 回 值：void
  说    明：
***************************************************************************/
void sechs(int& row, int& col, int g[MAXG][MAXG], int next[], int path[][2], int tp[2][2])
{
	int a, b, t;
	data_in(row, col);
	new_a_graph(row, col, g, 1);
	a = row * 2 + 5, b = 39;
	cct_setconsoleborder(b, a);
	cct_setfontsize("新宋体", 32);
	cct_getconsoleborder(a, b, t, t);
	cout << "屏幕：" << b << "行" << a << "列(右键退出)" << endl;
	print_block(row, col, g);
	show_mouse(row, col, g, tp, path);
	orders_end();
	cct_setfontsize("", 0);
	cct_setconsoleborder(120, 40);
	cct_cls();
}

/***************************************************************************
  函数名称：sieben
  功    能：第七个选项函数的集合
  输入参数：int& row, int& col, int g[MAXG][MAXG], int next[], int path[][2], int tp[2][2]
  返 回 值：void
  说    明：
***************************************************************************/
void sieben(int& row, int& col, int g[MAXG][MAXG], int next[], int path[][2], int tp[2][2])
{
	int a, b, t, score = 0, sum = 0, count[8] = {}, tmp, xiaochu[8] = {};
	data_in(row, col);
	new_a_graph(row, col, g);
	a = 23, b = 70;
	cct_setconsoleborder(b, a);
	cct_setfontsize("新宋体", 24);
	cct_getconsoleborder(a, b, t, t);
	cout << "屏幕：" << b << "行" << a << "列(右键退出)" << endl;
	print_block(row, col, g);
	while(whether_end(row,col,g)) {
		print_score(sum);
		next_three(next, 0);
		print_next(next);
		tmp = count_five(row, col, g, count);
		xiaochu[tmp / 100] += tmp % 100;
		print_count(row, col, count, xiaochu);
		if (!show_mouse(row, col, g, tp, path))
			break;
		move_only(tp, g);
		score = five(row, col, g);
		if (!score)
			fill_only(row, col, next, g);
		score += five(row, col, g);
		sum += score;
		cct_gotoxy(0, 1);
		print_block(row, col, g);
		score = 0;
	}
	orders_end();
	cct_setfontsize("", 0);
	cct_setconsoleborder(120, 40);
	cct_cls();
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
	int row, col, g[MAXG][MAXG] = {}, next[MAXN] = {}, path[MAXG * MAXG][2] = {}, tp[2][2] = {};
	cct_setconsoleborder(120, 40, 120, 9000);/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	while (1){
		switch (menu()){
			case 0:
				return 0;
			case 1:
				eins(row, col, g);
				break;
			case 2:
				zwei(row, col, g, next, path, tp);
				break;
			case 3:
				drei(row, col, g, next, path, tp);
				break;
			case 4:
				vier_und_fuenf(row, col, g);
				break;
			case 5:
				vier_und_fuenf(row, col, g, 1);
				break;
			case 6:
				sechs(row, col, g, next, path, tp);
				break;
			case 7:
				sieben(row, col, g, next, path, tp);
				break;
		}
		clear_all(row, col, g, path, tp);
	}
	return 0;
}