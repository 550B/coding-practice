/*2151974 软件 赵明泽*/
#pragma once

//可用颜色数组
const int color[8] = { 0,1,2,3,4,5,6,8 };

//图的最大范围
const int MAXG = 11;

//后续随机数最大个数
const int MAXN = 3;

//90-b2-tool.cpp里的函数
void new_a_graph(const int row, const int col, int g[MAXG][MAXG], const int choice = 0);

void clear_all(int& row, int& col, int g[MAXG][MAXG], int path[MAXG * MAXG][2], int tp[2][2]);

int find_path(const int row, const int col, const int g[MAXG][MAXG], const int tp[2][2], int path[][2]);

void next_three(int n[MAXN], const int choice = 1);

void orders_end();

int whether_end(const int row, const int col, const int g[MAXG][MAXG]);

int five(const int row, const int col, int g[MAXG][MAXG]);

void move_only(const int tp[2][2], int g[MAXG][MAXG]);

void to_be_continued(const char* prompt);

void fill_only(const int row, const int col, const int next[MAXN], int g[MAXG][MAXG]);

//90-b2-base.cpp里的函数
void print_sheet(const int row, const int col, const int g[][MAXG], const int p[][2] = 0, const int choice = 0);

int orders(const int row, const int col, int g[MAXG][MAXG], int path[][2], int tp[2][2], const int choice = 0);

int orders_backspace(int X, int Y, int& x, int& y, char tmp[], const int JUDGE = 0);

//90-b2-console.cpp里的函数
void print_border(const int row, const int col, const int g[MAXG][MAXG], const int choice = 0);

void print_block(const int row, const int col, const int g[MAXG][MAXG]);

int show_mouse(const int row, const int col, const int g[MAXG][MAXG], int tp[2][2], int path[][2]);

void print_score(const int score);

void print_next(const int next[]);

int count_five(const int row, const int col, const int g[MAXG][MAXG], int count[]);

void print_count(const int row, const int col, int count[], int xiaochu[]);