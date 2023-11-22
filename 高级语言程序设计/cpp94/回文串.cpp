/*2151974 软件 赵明泽*/
#include <iostream>
using namespace std;

int main()
{
	char ch[82];
	char* p, * q;

	cout << "请输入一个长度小于80的字符串（回文串）" << endl;

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