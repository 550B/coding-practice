/*2151974 ��� ������*/
#include <iostream>
#include <conio.h>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;

//����������ƫ��ֵ
const int DELTA = 16;

/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
	1���ű� hanoi_main.cpp ���õĲ˵�������Ҫ����ʾ���˵��������ȷ��ѡ��󷵻�

     ���ļ�Ҫ��
	1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
	2���������徲̬ȫ�ֱ�����ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
	3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  �������ƣ�title
  ��    �ܣ���ӡ��ʼ��ʾ��
  ���������void
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void title()
{
	cout << "---------------------------------" << endl;
	cout << "1.������" << endl;
	cout << "2.������(������¼)" << endl;
	cout << "3.�ڲ�������ʾ(����)" << endl;
	cout << "4.�ڲ�������ʾ(����+����)" << endl;
	cout << "5.ͼ�ν�-Ԥ��-������Բ��" << endl;
	cout << "6.ͼ�ν�-Ԥ��-����ʼ���ϻ�n������" << endl;
	cout << "7.ͼ�ν�-Ԥ��-��һ���ƶ�" << endl;
	cout << "8.ͼ�ν�-�Զ��ƶ��汾" << endl;
	cout << "9.ͼ�ν�-��Ϸ��" << endl;
	cout << "0.�˳�" << endl;
	cout << "---------------------------------" << endl;
	cout << "[��ѡ��:]";
}

/***************************************************************************
  �������ƣ�choice
  ��    �ܣ�����ѡ�����֣�����ѡ��Ľ��
  ���������void
  �� �� ֵ��int
  ˵    ����
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
    �������ƣ�menu
    ��    �ܣ��ظ����ò˵�
    ���������void
    �� �� ֵ��int
    ˵    ����
***************************************************************************/
int menu()
{
    title();
    return choice();
}

/***************************************************************************
  �������ƣ�un_deux_trois
  ��    �ܣ�ǰ����
  ���������int& n, int& choice, char& src, char& tmp, char& dst, int& cols, int& lines, int& buffer_cols, int& buffer_lines
  �� �� ֵ��void
  ˵    ����
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
  �������ƣ�quatre
  ��    �ܣ����ĸ�
  ���������int& n, int& choice, char& src, char& tmp, char& dst
  �� �� ֵ��void
  ˵    ����
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
  �������ƣ�cinq
  ��    �ܣ���5��
  ���������void
  �� �� ֵ��void
  ˵    ����
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
  �������ƣ�six
  ��    �ܣ���6��
  ���������int& n, int& choice, char& src, char& tmp, char& dst
  �� �� ֵ��void
  ˵    ����
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
  �������ƣ�sept
  ��    �ܣ���7��
  ���������int& n, int& choice, char& src, char& tmp, char& dst
  �� �� ֵ��void
  ˵    ����
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
  �������ƣ�huit
  ��    �ܣ���8��
  ���������int& n, int& choice, char& src, char& tmp, char& dst
  �� �� ֵ��void
  ˵    ����
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
  �������ƣ�neuf
  ��    �ܣ���9��
  ���������int& n, int& choice, char& src, char& tmp, char& dst
  �� �� ֵ��void
  ˵    ����
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