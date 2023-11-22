/*2151974 ��� ������*/
/* 1951889 ����Ǫ 2154270 �Գ��� 2151753 ������ 2050780 ���� 2150806 ����Դ 2151474 ����͢ 2152568 ���κ� 2151355 ������ 2151569 ����ʶ 2151804 ����� */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAXLEN = 999;

int main()
{
	cerr << "�ļ���������ʽ������:" << endl;
	cerr << "    a.hex                     : ����·����ʽ" << endl;
	cerr << "    ..\\data\\b.txt             : ���·����ʽ" << endl;
	cerr << "    C:\\Windows\\System32\\c.hex : �������·����ʽ" << endl;
	cerr << "������Ҫת����hex��ʽ�ļ��� : ";
	char name1[MAXLEN];
	cin >> name1;
	cerr << "������ת������ļ���        : ";
	char name2[MAXLEN];
	cin >> name2;

	ifstream in;
	in.open(name1, ios::in | ios::binary);
	if (in.is_open() == 0)
	{
		cout << "�����ļ�" << name1 << "��ʧ��!" << endl;
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
			cout << "������ƫ����0xcccccccc��������ֵ0x" << hex << setw(8) << setfill('0') << cnt << endl;
			return 0;
		}
		if (t != cnt)
		{
			cout << "������ƫ����0x" << hex << setw(8) << setfill('0') << t << "��������ֵ0x" << hex << setw(8) << setfill('0') << cnt << endl;
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