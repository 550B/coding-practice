/*2151974 ��� ������*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("������뾶�͸߶�\n");

	double r, h, c, s, biaos, v, zhuv;
	const double Pi = 3.14159;

	scanf("%lf %lf", &r, &h);

	c = 2.0 * Pi * r;
	s = Pi * r * r;
	biaos = 4.0 * Pi * r * r;
	v = (4.0 / 3.0) * Pi * r * r * r;
	zhuv = s * h;

	printf("Բ�ܳ�     : %.2f\n", c);
	printf("Բ���     : %.2f\n", s);
	printf("Բ������ : %.2f\n", biaos);
	printf("Բ�����   : %.2f\n", v);
	printf("Բ�����   : %.2f\n", zhuv);

	return 0;

}