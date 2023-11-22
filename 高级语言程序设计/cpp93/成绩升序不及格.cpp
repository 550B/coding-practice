/*2151974 软件 赵明泽*/
#include <iostream>
#include <string>
using namespace std;

const int STU = 10;

/***************************************************************************
  函数名称：data_in
  功    能：输入数据
  输入参数：string num[STU], string name[STU], int score[STU]
  返 回 值：void
  说    明：
***************************************************************************/
void data_in(string num[STU], string name[STU], int score[STU])
{
	int cnt = 0;
	while (cnt < STU)
	{
		cout << "请输入第" << cnt + 1 << "个人的学号、姓名、成绩" << endl;
		cin >> num[cnt] >> name[cnt] >> score[cnt];
		cnt++;
	}
}

/***************************************************************************
  函数名称：data_sort
  功    能：数据排序
  输入参数：string num[STU], string name[STU], int score[STU]
  返 回 值：void
  说    明：
***************************************************************************/
void data_sort(string num[STU], string name[STU], int score[STU])
{
	for (int i = 0; i < STU; i++)
	{
		for (int j = i + 1; j < STU; j++)
		{
			if (score[i]>score[j])
			{
				string t1;
				t1 = num[j];
				num[j] = num[i];
				num[i] = t1;
				string t2;
				t2 = name[j];
				name[j] = name[i];
				name[i] = t2;
				int t = score[j];
				score[j] = score[i];
				score[i] = t;
			}
		}
	}
}

/***************************************************************************
  函数名称：data_out
  功    能：输出
  输入参数：string num[STU], string name[STU], int score[STU]
  返 回 值：void
  说    明：
***************************************************************************/
void data_out(string num[STU], string name[STU], int score[STU])
{
	cout << endl << "不及格名单(成绩升序):" << endl;
	for (int i = 0; i < STU; i++)
	{
		if (score[i] < 60)
		{
			cout << name[i] << " " << num[i] << " " << score[i] << endl;
		}
	}
}

/***************************************************************************
  函数名称：main
  功    能：调用函数
  输入参数：
  返 回 值：0
  说    明：
***************************************************************************/
int main()
{
	string num[STU], name[STU];
	int score[STU];
	data_in(num, name, score);
	data_sort(num, name, score);
	data_out(num, name, score);

	return 0;
}