/*2151974 ��� ������*/
#include <iostream>
using namespace std;

#define  N  10	/* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */

int main()
{
	/* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;
	bool is_num;

	/* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */
	cout << "�����������������������ֵ��ַ���" << endl;
	
	gets_s(str);

	pa = a;
	pnum = a;
	p = str;

	while (*p != '\0')
	{
		is_num = true;
		if (*p < '0' || *p > '9')
		{
			p++;
			continue;
		}
		else
		{
			if (is_num && (pnum - pa) <= 9)
			{
				*pnum = atoi(p);
				pnum++;
			}
			while (*p >= '0' && *p <= '9')
			{
				is_num = false;
				p++;
			}
		}
		p++;
	}
	
	cout << "����" << (int)(pnum - pa) << "������" << endl;
	while (pnum - pa)
	{
		cout << *pa++ << " ";
	}
	cout << endl;

	return 0;
}