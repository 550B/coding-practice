/*2151974 软件 赵明泽*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("请输入半径和高度\n");

	double r, h, c, s, biaos, v, zhuv;
	const double Pi = 3.14159;

	scanf("%lf %lf", &r, &h);

	c = 2.0 * Pi * r;
	s = Pi * r * r;
	biaos = 4.0 * Pi * r * r;
	v = (4.0 / 3.0) * Pi * r * r * r;
	zhuv = s * h;

	printf("圆周长     : %.2f\n", c);
	printf("圆面积     : %.2f\n", s);
	printf("圆球表面积 : %.2f\n", biaos);
	printf("圆球体积   : %.2f\n", v);
	printf("圆柱体积   : %.2f\n", zhuv);

	return 0;

}