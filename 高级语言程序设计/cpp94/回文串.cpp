/*2151974 ��� ������*/
#include <iostream>
using namespace std;

int main()
{
	char ch[82];
	char* p, * q;

	cout << "������һ������С��80���ַ��������Ĵ���" << endl;

	fgets(ch, 81, stdin);
	p = ch;
	q = ch;
	while (*q != '\n')
	{
		q++;
	}
	*q = '\0';
	if (q != p)
	{
		q--;
	}
	else
	{
		cout << "yes" << endl;
		return 0;
	}

	while (p < q)
	{
		if (*p == *q)
		{
			p++;
			q--;
			continue;
		}
		else
		{
			cout << "no" << endl;
			return 0;
		}
	}
	cout << "yes" << endl;

	return 0;
}