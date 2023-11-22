/*2151974 软件 赵明泽*/
#include <iostream>

using namespace std;
int main()
{
	int num = 0, ge = 0, shi = 0, bai = 0, qian = 0, wan = 0;

	cout << "请输入一个[1..30000]间的整数:" << endl;
	cin >> num;

	ge = num % 10;
	shi = (num / 10) % 10;
	bai = (num / 100) % 10;
	qian = (num / 1000) % 10;
	wan = num / 10000;

	cout << "万位 : " << wan << endl;
	cout << "千位 : " << qian << endl;
	cout << "百位 : " << bai << endl;
	cout << "十位 : " << shi << endl;
	cout << "个位 : " << ge << endl;

	return 0;

}




