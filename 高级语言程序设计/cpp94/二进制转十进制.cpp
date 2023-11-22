/*2151974 软件 赵明泽*/
#include <iostream>
using namespace std;

int main()
{
	char b[33];
	unsigned int result = 0;
	char* p, * q;
	unsigned int two = 1;

	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	cin >> b;

	p = b;
	q = b;
	while (*q != '\0')
	{
		q++;
	}
	while (q - p - 1)
	{
		two *= 2;
		p++;
	}
	p = b;

	while (q - p)
	{
		result += (int)((*p) - '0') * two;
		two /= 2;
		p++;
	}
	cout << result << endl;

	return 0;
}