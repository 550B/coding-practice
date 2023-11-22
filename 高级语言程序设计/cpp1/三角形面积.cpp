/*2151974 软件 赵明泽*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main()
{
	int a, b, deg;
	float s;
	float rad;
	const double Pi = 3.14159;

	cout << "请输入三角形的两边及其夹角（角度）" << endl;
	cin >> a >> b >> deg;

	rad = (float)(deg * Pi) / 180.0f;
	s = 0.5f * a * b * (float)sin(rad);

	cout << setiosflags(ios::fixed) << setprecision(3);
	cout << "三角形面积为 : " << s << endl;

	return 0;

}



//#include <iostream>
//#include <cmath>
//#include <iomanip>
//
//using namespace std;
//int main()
//{
//	int a, b, deg;
//	double s;
//	double rad;
//	const double Pi = 3.14159;
//
//	cout << "请输入三角形的两边及其夹角（角度）" << endl;
//	cin >> a >> b >> deg;
//
//	rad = (deg * Pi) / 180.0;
//	s = 0.5 * a * b * sin(rad);
//
//	cout << setiosflags(ios::fixed) << setprecision(3);
//	cout << "三角形面积为 : " << s << endl;					输出是一样的
//
//	return 0;
//
//}