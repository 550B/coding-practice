/*2151974 ��� ������*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	cout << "������뾶�͸߶�" << endl;

	const double Pi = 3.14159;
	double r, h, c, s, biaos, v, zhuv;

	cin >> r >> h;

	c = 2.0 * Pi * r;
	s = Pi * r * r;
	biaos = 4.0 * Pi * r * r;
	v = (4.0 / 3.0) * Pi * r * r * r;
	zhuv = s * h;

	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << "Բ�ܳ�" << "    " << " : " << c << endl;
	cout << "Բ���" << "    " << " : " << s << endl;
	cout << "Բ������" << " : " << biaos << endl;
	cout << "Բ�����" << "  " << " : " << v << endl;
	cout << "Բ�����" << "  " << " : " << zhuv << endl;

	return 0;

}