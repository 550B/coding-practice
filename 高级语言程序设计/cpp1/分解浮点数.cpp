/*2151974 ��� ������*/
#include <iostream>

using namespace std;
int main()
{
	cout << "������[0-100��)֮�������:" << endl;

	double num;
	int shiyi = 0, yi = 0, qianwan = 0, baiwan = 0, shiwan = 0, wan = 0, qian = 0, bai = 0, shi = 0, yuan = 0, jiao = 0, fen = 0;
	int a = 0;

	cin >> num;

	shiyi = (int)(num / 1000000000);
	a = (int)(num - shiyi * 1000000000.0);
	yi = (a / 100000000) % 10;
	qianwan = (a / 10000000) % 10;
	baiwan = (a / 1000000) % 10;
	shiwan = (a / 100000) % 10;
	wan = (a / 10000) % 10;
	qian = (a / 1000) % 10;
	bai = (a / 100) % 10;
	shi = (a / 10) % 10;
	yuan = a % 10;
	jiao = (int)((num - shiyi * 1000000000.0 - yi * 100000000.0 - qianwan * 10000000.0 - baiwan * 1000000.0 - shiwan * 100000.0 - wan * 10000.0 - qian * 1000.0 - bai * 100.0 - shi * 10.0 - yuan + 0.000001) * 10);
	fen = ((int)((num - shiyi * 1000000000.0 - yi * 100000000.0 - qianwan * 10000000.0 - baiwan * 1000000.0 - shiwan * 100000.0 - wan * 10000.0 - qian * 1000.0 - bai * 100.0 - shi * 10.0 - yuan - jiao * 0.1 + 0.000001) * 10000) / 100 % 10);

	cout << "ʮ��λ : " << shiyi << endl;
	cout << "��λ   : " << yi << endl;
	cout << "ǧ��λ : " << qianwan << endl;
	cout << "����λ : " << baiwan << endl;
	cout << "ʮ��λ : " << shiwan << endl;
	cout << "��λ   : " << wan << endl;
	cout << "ǧλ   : " << qian << endl;
	cout << "��λ   : " << bai << endl;
	cout << "ʮλ   : " << shi << endl;
	cout << "Բ     : " << yuan << endl;
	cout << "��     : " << jiao << endl;
	cout << "��     : " << fen << endl;

	return 0;

}