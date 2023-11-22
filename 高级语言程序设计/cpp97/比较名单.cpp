/*2151974 软件 赵明泽*/

/* 允许按需加入系统的宏定义、需要的头文件等 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

#define MAX_STU_NUM			256	//约定最大人数为256人（两轮的总和，包括退选、补选）
#define MAX_NAME_LEN			32	//学生姓名的最大长度不超过16个汉字
#define MAX_FILENAME_LEN		256	//文件名的最大长度

/* stu_info 类存放每个学生的信息，包括学号、姓名、其它需要的私有信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_list;
class stu_info {
private:
	int  stu_no;			//学号
	char stu_name[MAX_NAME_LEN];	//姓名

	/* 允许按需加入private数据成员、成员函数以及其它需要的内容 */
	int round;
	friend stu_list;
public:
	/* 本类不允许定义任何的公有数据成员、成员函数 */
};

/* stu_list 类整个选课信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_list {
private:
	stu_info stu[MAX_STU_NUM + 1];

	/* 允许按需加入private数据成员和成员函数 */
public:
	int read(const char* filename, const int append = 0);	//从文件中读入选课信息并进行处理，第2个参数值为0表示覆盖方式，1表示追加方式
	int print(const char* prompt = NULL);			//打印当前读入的选课名单

	/* 允许按需加入其它public成员函数 */
	stu_info* p = stu;
	void copy(stu_info* p, int num, char ch[], int append);
	void copy2(stu_info* p, int num, char ch[]);
	void stunumsort();
};

/* --- 此处给出上面两个类的成员函数的体外实现 --- */
void stu_list::copy(stu_info* p, int num, char ch[], int append)
{
	p->stu_no = num;
	strcpy(p->stu_name, ch);
	p->round = append;
}

void stu_list::copy2(stu_info* p, int num, char ch[])
{
	stu_info* q = p;
	int sign = 0;
	while (--q != stu - 1)
	{
		if (!strcmp(q->stu_name,ch))
		{
			sign = 1;
			q->round = 1;
			break;
		}
	}
	if(!sign)
	{
		stu_list::p->stu_no = num;
		strcpy(stu_list::p->stu_name, ch);
		stu_list::p->round = 2;
		stu_list::p++;
	}
	stu_list::p->stu_no = -1;
}

void stu_list::stunumsort()
{
	int len = p - stu;
	for (int i = 1; i < len; i++)
	{
		for (int j = len - 1; j >= i; j--)
		{
			if (stu[j].stu_no < stu[j - 1].stu_no)
			{
				int tmpr = stu[j - 1].round;
				stu[j - 1].round = stu[j].round;
				stu[j].round = tmpr;
				char tmpch[MAX_NAME_LEN];
				strcpy(tmpch, stu[j - 1].stu_name);
				strcpy(stu[j - 1].stu_name, stu[j].stu_name);
				strcpy(stu[j].stu_name, tmpch);
				int tmpn = stu[j - 1].stu_no;
				stu[j - 1].stu_no = stu[j].stu_no;
				stu[j].stu_no = tmpn;
			}
		}
	}
}

int stu_list::read(const char* filename, const int append)
{
	ifstream in;
	in.open(filename, ios::in | ios::binary);
	if (in.is_open() == 0)
	{
		cout << "文件[" << filename << "]打开失败" << endl;
		return -1;
	}

	stu_info* q = stu_list::p;
	while (!in.eof())
	{
		int tmp;
		in >> tmp;
		if (in.fail())
		{
			break;
		}
		char nametmp[MAX_NAME_LEN];
		in >> nametmp;
		if (append)
		{
			copy2(q, tmp, nametmp);
			continue;
		}
		else
		{
			copy(q, tmp, nametmp, append);
		}
		q++;
	}
	if (append)
		stunumsort();
	else
	{
		q->stu_no = -1;
		stu_list::p = q;
	}
	in.close();
	return 0;
}

int stu_list::print(const char* prompt)
{
	cout << prompt << endl;
	cout << "===========================================================" << endl;
	cout << "序号 学号    姓名                             第一轮 第二轮" << endl;
	cout << "===========================================================" << endl;
	int cnt = 1;
	stu_info* p = stu;
	while (p->stu_no != -1)
	{
		cout << setiosflags(ios::left) << setw(5) << cnt++;
		cout << p->stu_no << " ";
		cout << setiosflags(ios::left) << setw(33) << p->stu_name;
		if (p->round == 0)
		{
			cout << "Y      退课" << endl;
		}
		else if (p->round == 1)
		{
			cout << "Y      Y" << endl;
		}
		else if (p->round == 2)
		{
			cout << "/      补选" << endl;
		}
		p++;
	}
	cout << "===========================================================" << endl;
	return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "请输入前一轮选课的数据文件 : ";
	cin >> file1;
	cout << "请输入后一轮选课的数据文件 : ";
	cin >> file2;

	stu_list list;

	/* 读入第一个数据文件 */
	if (list.read(file1) < 0)
		return -1;

	/* 读入第二个数据文件，参数2的值为1表示追加方式 */
	if (list.read(file2, 1) < 0)
		return -1;

	list.print("最终选课名单");

	return 0;
}