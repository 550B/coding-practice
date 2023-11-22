/*2151974 软件 赵明泽*/
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "90-b3.h"
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
	cout << "1.显示关卡" << endl;
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
		if (temp >= '0' && temp <= '1')
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	cct_setconsoleborder(130, 48, 130, 15000);/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	while (1) {
		switch (menu()) {
			case 0:
				return 0;
			case 1:
				cct_cls();
				int cnt = 0;
				char files[MAX_CNT_OF_FILENAME][MAX_LEN_OF_FILENAME];
				cnt = read_name(files);
				if (cnt) {
					print_level(cnt, 0, 0, files);
					move_button(cnt, files);
				}
				else {
					cct_gotoxy(0, 1);
					cout << "无法找到任何关卡文件";
				}
				cct_gotoxy(0, 43);
				orders_end();
				cct_cls();
				break;
		}
		//clear_all(row, col, g, path, tp);
	}
	return 0;
}