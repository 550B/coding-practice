/*2151974 软件 赵明泽*/
#include <iostream>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;

/* ----------------------------------------------------------------------------------

     本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

     本文件要求：
	1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	int n, choice;
	char src, tmp, dst;
	int cols, lines, buffer_cols, buffer_lines;
	cct_setconsoleborder(120, 40, 120, 9000);/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	while (1)
	{
		switch(choice = menu())
		{
			case 1:
			case 2:
			case 3:
				un_deux_trois(n, choice, src, tmp, dst, cols, lines, buffer_cols, buffer_lines);
				break;
			case 4:
				quatre(n, choice, src, tmp, dst);
				break;
			case 5:
				cinq();
				break;
			case 6:
				six(n, choice, src, tmp, dst);
				break;
			case 7:
				sept(n, choice, src, tmp, dst);
				break;
			case 8:
				huit(n, choice, src, tmp, dst);
				break;
			case 9:
				neuf(n, choice, src, tmp, dst);
				break;
			case 0:
				return 0;
		}
		clear_all();
	}
	return 0;
}
