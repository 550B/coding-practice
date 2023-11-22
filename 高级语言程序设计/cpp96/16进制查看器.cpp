/*2151974 ��� ������*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX_LEN = 999;

int main()
{
	cerr << "�ļ���������ʽ������:" << endl;
	cerr << "    a.txt                     : ����·����ʽ" << endl;
	cerr << "    ..\\data\\b.dat             : ���·����ʽ" << endl;
	cerr << "    C:\\Windows\\System32\\c.dat : �������·����ʽ" << endl;
	cerr << "�������ļ��� : ";
	char name[MAX_LEN];
	cin >> name;

	ifstream in;
	in.open(name, ios::in | ios::binary);
	if (in.is_open() == 0)
	{
		cout << "�����ļ�" << name << "��ʧ��!" << endl;
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