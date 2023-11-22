#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;

int cnt = 0;

/***************************************************************************
  �������ƣ�fibonacci
  ��    �ܣ�����fibonacci���еĵ�n���ֵ
  ���������int n
  �� �� ֵ��int
  ˵    �����������κ���ʽ��ѭ������
***************************************************************************/
int fibonacci(int n)
{
	if (n == 1)
	{
		cnt++;
		return 1;
	}
	else if (n == 2)
	{
		cnt++;
		return 1;
	}
	else
	{
		cnt++;
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main�����������޸�
***************************************************************************/
int main()
{
	int n, f;
	cout << "������Fibonacci���е�����[1-46]" << endl;
	cin >> n;

	LARGE_INTEGER tick, begin, end;
	QueryPerformanceFrequency(&tick);	//���ʱ��Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ����ʱ������
	f = fibonacci(n);
	cout << "Fibonacci���е�" << n << "���ֵ : " << f << endl;
	cout << "count is:" << cnt << endl;
	QueryPerformanceCounter(&end);//�����ֹӲ����ʱ������
	cout << "������Ƶ�� : " << tick.QuadPart << "Hz" << endl;
	cout << "���������� : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;

	return 0;
}