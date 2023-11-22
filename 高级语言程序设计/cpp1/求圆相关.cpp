/*2151974 软件 赵明泽*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	cout << "请输入半径和高度" << endl;

	const double Pi = 3.14159;
	double r, h, c, s, biaos, v, zhuv;

	cin >> r >> h;

	c = 2.0 * Pi * r;
	s = Pi * r * r;
	biaos = 4.0 * Pi * r * r;
	v = (4.0 / 3.0) * Pi * r * r * r;
	zhuv = s * h;

	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << "圆周长" << "    " << " : " << c << endl;
	cout << "圆面积" << "    " << " : " << s << endl;
	cout << "圆球表面积" << " : " << biaos << endl;
	cout << "圆球体积" << "  " << " : " << v << endl;
	cout << "圆柱体积" << "  " << " : " << zhuv << endl;

	return 0;

}