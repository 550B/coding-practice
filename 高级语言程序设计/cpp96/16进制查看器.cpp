/*2151974 软件 赵明泽*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX_LEN = 999;

int main()
{
	cerr << "文件名以下形式均可以:" << endl;
	cerr << "    a.txt                     : 不带路径形式" << endl;
	cerr << "    ..\\data\\b.dat             : 相对路径形式" << endl;
	cerr << "    C:\\Windows\\System32\\c.dat : 绝对相对路径形式" << endl;
	cerr << "请输入文件名 : ";
	char name[MAX_LEN];
	cin >> name;

	ifstream in;
	in.open(name, ios::in | ios::binary);
	if (in.is_open() == 0)
	{
		cout << "输入文件" << name << "打开失败!" << endl;
		return 0;
	}

	long long int cnt = 0;
	int tmp[16];
	int* p = tmp;
	while (!in.eof())
	{
		//d:\demos\8.txt
		p = tmp;
		cout << setiosflags(ios::uppercase) << setw(8) << setfill('0') << hex << cnt << ":  ";
		for (int k = 0; k < 2; k++)
		{
			for (int i = 0; i < 8; i++)
			{
				if (in.peek() == -1)
					break;
				*p = in.get();
				cout << setw(2) << setfill('0') << hex << *p << " ";
				p++;
			}
			if (in.peek() == -1)
				break;
			if (k == 0)
				cout << "- ";
		}
		int curr = p - tmp;
		if (curr > 8)
			for (int i = 16 - curr; i > 0; i--)
				cout << "   ";
		else
		{
			for (int i = 16 - curr; i > 0; i--)
				cout << "   ";
			cout << "  ";
		}
		cout << " ";
		p = tmp;
		for (int i = 0; i < curr; i++)
		{
			char ch = *p++;
			if (ch >= 33 && ch <= 126)
				cout << ch;
			else
				cout << '.';
		}
		if (in.peek() == -1)
			break;
		cout << endl;
		cnt += 16;
	}
	cout << endl;
	in.close();
	return 0;
}