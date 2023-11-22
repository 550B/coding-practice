/*2151974 软件 赵明泽*/
#pragma once

/* ------------------------------------------------------------------------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */

/*hanoi_menu.cpp下的函数声明*/

void title();

int choice();

int menu();

void un_deux_trois(int& n, int& choice, char& src, char& tmp, char& dst, int& cols, int& lines, int& buffer_cols, int& buffer_lines);

void quatre(int& n, int& choice, char& src, char& tmp, char& dst);

void cinq();

void six(int& n, int& choice, char& src, char& tmp, char& dst);

void sept(int& n, int& choice, char& src, char& tmp, char& dst);

void huit(int& n, int& choice, char& src, char& tmp, char& dst);

void neuf(int& n, int& choice, char& src, char& tmp, char& dst);

/*hanoi_multiple_solutions下的函数声明*/

void data_in(int& n, char& start, char& end, char& tmp, const int WHETHER_DELAY = 0);

void hanoi(int n, char src, char tmp, char dst, int num);

void way_of_out(int n, char src, char tmp, char dst, int num);

void to_be_continued(const int X = 0, const int Y = 38);

void time_delay();

void H_and_Stack_pre(int n, char src, char tmp, char dst, const int D = 0);

void clear_all();

void three_poles();

void plates(int n, char src, char tmp, char dst, const int TIME = 1000);

void move_plates(int n, char src, char tmp, char dst);

void games(int n, char src, char dst);