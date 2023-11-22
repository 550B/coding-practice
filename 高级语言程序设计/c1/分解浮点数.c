/*2151974 软件 赵明泽*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("请输入[0-100亿)之间的数字:\n");

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

	printf("十亿位 : %d\n", shiyi);
	printf("亿位   : %d\n", yi);
	printf("千万位 : %d\n", qianwan);
	printf("百万位 : %d\n", baiwan);
	printf("十万位 : %d\n", shiwan);
	printf("万位   : %d\n", wan);
	printf("千位   : %d\n", qian);
	printf("百位   : %d\n", bai);
	printf("十位   : %d\n", shi);
	printf("圆     : %d\n", yuan);
	printf("角     : %d\n", jiao);
	printf("分     : %d\n", fen);

	return 0;

}