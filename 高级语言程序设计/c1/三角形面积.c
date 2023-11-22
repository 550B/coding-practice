/*2151974 软件 赵明泽*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, deg;
	float s, rad;
	const double Pi = 3.14159;

	printf("请输入三角形的两边及其夹角（角度）\n");
	scanf("%d%d%d", &a, &b, &deg);

	rad = (float)(deg * Pi) / 180.0f;
	s = 0.5f * a * b * (float)sin(rad);

	printf("三角形面积为 : %.3f\n", s);

	return 0;

}





//#define  _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int a, b, deg;
//	double s, rad;
//	const double Pi = 3.14159;
//
//	printf("请输入三角形的两边及其夹角（角度）\n");
//	scanf("%d%d%d", &a, &b, &deg);
//
//	rad = (deg * Pi) / 180.0;
//	s = 0.5 * a * b * sin(rad);
//
//	printf("三角形面积为 : %.3lf\n", s);			结果是一样的
//
//	return 0;
//
//}