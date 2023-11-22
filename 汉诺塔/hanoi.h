/*2151974 ��� ������*/
#pragma once

/* ------------------------------------------------------------------------------------------------------

     ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
   ------------------------------------------------------------------------------------------------------ */

/*hanoi_menu.cpp�µĺ�������*/

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

/*hanoi_multiple_solutions�µĺ�������*/

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