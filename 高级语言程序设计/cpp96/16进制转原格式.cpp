/*2151974 软件 赵明泽*/
/* 1951889 王淞仟 2154270 赵楚钧 2151753 彭坤宇 2050780 焦骜 2150806 刘广源 2151474 刘奕廷 2152568 孙治弘 2151355 王亚涛 2151569 明添识 2151804 臧若曦 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAXLEN = 999;

int main()
{
	cerr << "文件名以下形式均可以:" << endl;
	cerr << "    a.hex                     : 不带路径形式" << endl;
	cerr << "    ..\\data\\b.txt             : 相对路径形式" << endl;
	cerr << "    C:\\Windows\\System32\\c.hex : 绝对相对路径形式" << endl;
	cerr << "请输入要转换的hex格式文件名 : ";
	char name1[MAXLEN];
	cin >> name1;
	cerr << "请输入转换后的文件名        : ";
	char name2[MAXLEN];
	cin >> name2;

	ifstream in;
	in.open(name1, ios::in | ios::binary);
	if (in.is_open() == 0)
	{
		cout << "输入文件" << name1 << "打开失败!" << endl;
		return 0;
	}

	ofstream out;
	out.open(name2, ios::out | ios::binary);
	if (out.is_open() == 0)
		return 0;

	long long int cnt = 0;
	while (!in.eof())
	{
		if (in.peek() == -1)
			break;
		long long int t;
		in >> hex >> t;
		if (!in.good())
		{
			cout << "最左侧的偏移量0xcccccccc不是期望值0x" << hex << setw(8) << setfill('0') << cnt << endl;
			return 0;
		}
		if (t != cnt)
		{
			cout << "最左侧的偏移量0x" << hex << setw(8) << setfill('0') << t << "不是期望值0x" << hex << setw(8) << setfill('0') << cnt << endl;
			return 0;
		}
		in.seekg(3, ios::cur);
		for (int k = 0; k < 2; k++)
		{
			int count = 0;
			for (int j = 0; j < 8; j++)
			{
				for (int m = 0; m < 2; m++)
				{
					if (in.peek() != ' ')
					{
						count++;
					}
					in.seekg(1, ios::cur);
				}
				in.seekg(1, ios::cur);
			}
			count /= 2;
			in.seekg(-24, ios::cur);
			for (int i = 0; i < count; i++)
			{
				int tmp;
				in >> hex >> tmp;
				if (!in.good())
					break;
				out << (char)tmp;
			}
			if (!in.good())
				break;
			if (k == 0)
				in.seekg(3, ios::cur);
		}
		char tem;
		while (tem = in.get() != '\n')
			if (tem == EOF)
				break;
		cnt += 16;
		if (!in.good())
			break;
	}
	in.close();
	out.close();
	return 0;
}