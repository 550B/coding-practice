/*2151974 软件 赵明泽*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num = 0, ge = 0, shi = 0, bai = 0, qian = 0, wan = 0;

	printf("请输入一个[1..30000]间的整数:\n");
	scanf("%d", &num);

	ge = num % 10;
	shi = (num / 10) % 10;
	bai = (num / 100) % 10;
	qian = (num / 1000) % 10;
	wan = num / 10000;

	printf("万位 : %d\n", wan);
	printf("千位 : %d\n", qian);
	printf("百位 : %d\n", bai);
	printf("十位 : %d\n", shi);
	printf("个位 : %d\n", ge);

	return 0;

}


