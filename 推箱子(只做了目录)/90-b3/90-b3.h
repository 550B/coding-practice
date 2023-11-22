/*2151974 软件 赵明泽*/
#pragma once

/* 定义文件名相关 */

const int MAX_LEN_OF_FILENAME = 33;			//最长文件名

const int MAX_CNT_OF_FILENAME = 9999;		//最大文件个数

/* 定义坐标 */

const int X = 115;

const int Y = 2;

/* 90-b3-base.cpp */



/* 90-b3-console.cpp */

void read(int cur, const char files[][MAX_LEN_OF_FILENAME]);

/* 90-b3-popmenu.cpp */

int read_name(char files[][MAX_LEN_OF_FILENAME]);

void print_level(int cnt, int top, int cur, const char files[][MAX_LEN_OF_FILENAME]);

void orders_end();

void move_button(int cnt, const char files[][MAX_LEN_OF_FILENAME]);

char* tj_strcat(char* s1, const char* s2);

char* tj_strcpy(char* s1, const char* s2);