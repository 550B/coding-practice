/*2151974 ��� ������*/
#include <iostream>

using namespace std;
int main()
{
	int num = 0, ge = 0, shi = 0, bai = 0, qian = 0, wan = 0;

	cout << "������һ��[1..30000]�������:" << endl;
	cin >> num;

	ge = num % 10;
	shi = (num / 10) % 10;
	bai = (num / 100) % 10;
	qian = (num / 1000) % 10;
	wan = num / 10000;

	cout << "��λ : " << wan << endl;
	cout << "ǧλ : " << qian << endl;
	cout << "��λ : " << bai << endl;
	cout << "ʮλ : " << shi << endl;
	cout << "��λ : " << ge << endl;

	return 0;

}




