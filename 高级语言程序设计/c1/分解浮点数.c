/*2151974 ��� ������*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("������[0-100��)֮�������:\n");

	double num;
	int shiyi = 0, yi = 0, qianwan = 0, baiwan = 0, shiwan = 0, wan = 0, qian = 0, bai = 0, shi = 0, yuan = 0, jiao = 0, fen = 0;
	int a = 0;

	scanf("%lf", &num);

	/*printf("%.50lf", num);*/

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
	jiao = (int)((num - shiyi * 1000000000.0 - yi * 100000000.0 - qianwan * 10000000.0 - baiwan * 1000000.0 - shiwan * 100000.0 - wan * 10000.0 - qian * 1000.0 - bai * 100.0 - shi * 10.0 - yuan+0.000001) * 10);
	fen = ((int)((num - shiyi * 1000000000.0 - yi * 100000000.0 - qianwan * 10000000.0 - baiwan * 1000000.0 - shiwan * 100000.0 - wan * 10000.0 - qian * 1000.0 - bai * 100.0 - shi * 10.0 - yuan - jiao * 0.1 + 0.000001) * 10000) / 100 % 10);

	printf("ʮ��λ : %d\n", shiyi);
	printf("��λ   : %d\n", yi);
	printf("ǧ��λ : %d\n", qianwan);
	printf("����λ : %d\n", baiwan);
	printf("ʮ��λ : %d\n", shiwan);
	printf("��λ   : %d\n", wan);
	printf("ǧλ   : %d\n", qian);
	printf("��λ   : %d\n", bai);
	printf("ʮλ   : %d\n", shi);
	printf("Բ     : %d\n", yuan);
	printf("��     : %d\n", jiao);
	printf("��     : %d\n", fen);

	return 0;

}