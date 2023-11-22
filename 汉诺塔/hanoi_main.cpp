/*2151974 ��� ������*/
#include <iostream>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;

/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
	1����main����
	2����ʼ����Ļ
	3�����ò˵�������hanoi_menu.cpp�У�������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����hanoi_multiple_solutions.cpp�У�

     ���ļ�Ҫ��
	1����������ȫ�ֱ��������ⲿȫ�ֺ;�̬ȫ�֣�const��#define�������Ʒ�Χ�ڣ�
	2����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	3���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	int n, choice;
	char src, tmp, dst;
	int cols, lines, buffer_cols, buffer_lines;
	cct_setconsoleborder(120, 40, 120, 9000);/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
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
