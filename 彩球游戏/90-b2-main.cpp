/*2151974 ��� ������*/
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;

/***************************************************************************
  �������ƣ�title
  ��    �ܣ���ӡ��ʼ��ʾ��
  ���������void
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void title()
{
	cout << "--------------------------------------------" << endl;
	cout << "1.�ڲ����飬������ɳ�ʼ5����" << endl;
	cout << "2.�ڲ����飬�������60%����Ѱ���ƶ�·��" << endl;
	cout << "3.�ڲ����飬������" << endl;
	cout << "4.����n*n�Ŀ�ܣ��޷ָ��ߣ��������ʾ5����" << endl;
	cout << "5.����n*n�Ŀ�ܣ��зָ��ߣ��������ʾ5����" << endl;
	cout << "6.n*n�Ŀ�ܣ�60%����֧����꣬���һ���ƶ�" << endl;
	cout << "7.cmdͼ�ν���������" << endl;
	cout << "0.�˳�" << endl;
	cout << "--------------------------------------------" << endl;
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
  �������ƣ�cin_row
  ��    �ܣ���������
  ���������void
  �� �� ֵ��int
  ˵    ����
***************************************************************************/
int cin_row()
{
	int row;
	while (1)
	{
		cout << "����������(7-9):" << endl;
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
  �������ƣ�cin_col
  ��    �ܣ���������
  ���������void
  �� �� ֵ��int
  ˵    ����
***************************************************************************/
int cin_col()
{
	int col;
	while (1)
	{
		cout << "����������(7-9):" << endl;
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
  �������ƣ�data_in
  ��    �ܣ���������
  ���������
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void data_in(int& row, int& col)
{
	cct_cls();
	row = cin_row();
	col = cin_col();
}

/***************************************************************************
  �������ƣ�eins
  ��    �ܣ���һ��ѡ����ļ���
  ���������int& row, int& col, int g[MAXG][MAXG]
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void eins(int& row, int& col, int g[MAXG][MAXG])
{
	data_in(row, col);
	new_a_graph(row, col, g);
	cout << endl << "��ʼ����:" << endl;
	print_sheet(row, col, g);
	orders_end();
	cct_cls();
}

/***************************************************************************
  �������ƣ�zwei
  ��    �ܣ��ڶ���ѡ����ļ���
  ���������int& row, int& col, int g[MAXG][MAXG], int n[], int path[][2], int tp[2][2]
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void zwei(int& row, int& col, int g[MAXG][MAXG], int n[], int path[][2], int tp[2][2])
{
	data_in(row, col);
	new_a_graph(row, col, g, 1);
	cout << endl << "��ǰ����:" << endl;
	print_sheet(row, col, g);
	next_three(n);
	if (!orders(row, col, g, path, tp, 1))
	{
		cout << endl << endl << "���ҽ������:" << endl;
		print_sheet(row, col, g, path, 1);
		cout << endl << "�ƶ�·��(��ͬɫ��ʶ):" << endl << endl;
		print_sheet(row, col, g, path, 2);
	}
	else
		cout << endl;
	orders_end();
	cct_cls();
}

/***************************************************************************
  �������ƣ�drei
  ��    �ܣ�������ѡ����ļ���
  ���������int& row, int& col, int g[MAXG][MAXG], int n[], int path[][2], int tp[2][2]
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void drei(int& row, int& col, int g[MAXG][MAXG], int n[], int path[][2], int tp[2][2])
{
	int score = 0, sum = 0;
	data_in(row, col);
	new_a_graph(row, col, g);
	while (whether_end(row, col, g)) {
		cout << endl << "��ǰ����:" << endl;
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
			cout << endl << endl << "�ƶ��������(��ͬɫ��ʶ):" << endl;
			print_sheet(row, col, g);
			cout << endl << "���ε÷֣�" << score << " �ܵ÷֣�" << sum << endl;
			score = 0;
		}
	}
	orders_end();
	cct_cls();
}

/***************************************************************************
  �������ƣ�vier_und_fuenf
  ��    �ܣ����ġ����ѡ����ļ���
  ���������int& row, int& col, int g[MAXG][MAXG], const int choice = 0
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void vier_und_fuenf(int& row, int& col, int g[MAXG][MAXG], const int choice = 0)
{
	int a, b, t;
	data_in(row, col);
	new_a_graph(row, col, g);
	cout << endl << "��ʼ����:" << endl;
	print_sheet(row, col, g);
	to_be_continued("���س�����ʾͼ��...");
	a = 2 + row + choice * (row - 1) + 4, b = 39;
	cct_setconsoleborder(b, a);
	cct_setfontsize("������", 32);
	cct_getconsoleborder(a, b, t, t);
	cout << "��Ļ��" << b << "��" << a << "��" << endl;
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
  �������ƣ�sechs
  ��    �ܣ�������ѡ����ļ���
  ���������int& row, int& col, int g[MAXG][MAXG], int next[], int path[][2], int tp[2][2]
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void sechs(int& row, int& col, int g[MAXG][MAXG], int next[], int path[][2], int tp[2][2])
{
	int a, b, t;
	data_in(row, col);
	new_a_graph(row, col, g, 1);
	a = row * 2 + 5, b = 39;
	cct_setconsoleborder(b, a);
	cct_setfontsize("������", 32);
	cct_getconsoleborder(a, b, t, t);
	cout << "��Ļ��" << b << "��" << a << "��(�Ҽ��˳�)" << endl;
	print_block(row, col, g);
	show_mouse(row, col, g, tp, path);
	orders_end();
	cct_setfontsize("", 0);
	cct_setconsoleborder(120, 40);
	cct_cls();
}

/***************************************************************************
  �������ƣ�sieben
  ��    �ܣ����߸�ѡ����ļ���
  ���������int& row, int& col, int g[MAXG][MAXG], int next[], int path[][2], int tp[2][2]
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void sieben(int& row, int& col, int g[MAXG][MAXG], int next[], int path[][2], int tp[2][2])
{
	int a, b, t, score = 0, sum = 0, count[8] = {}, tmp, xiaochu[8] = {};
	data_in(row, col);
	new_a_graph(row, col, g);
	a = 23, b = 70;
	cct_setconsoleborder(b, a);
	cct_setfontsize("������", 24);
	cct_getconsoleborder(a, b, t, t);
	cout << "��Ļ��" << b << "��" << a << "��(�Ҽ��˳�)" << endl;
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	int row, col, g[MAXG][MAXG] = {}, next[MAXN] = {}, path[MAXG * MAXG][2] = {}, tp[2][2] = {};
	cct_setconsoleborder(120, 40, 120, 9000);/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
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