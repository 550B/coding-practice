/*2151974 ��� ������*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num = 0, ge = 0, shi = 0, bai = 0, qian = 0, wan = 0;

	printf("������һ��[1..30000]�������:\n");
	scanf("%d", &num);

	ge = num % 10;
	shi = (num / 10) % 10;
	bai = (num / 100) % 10;
	qian = (num / 1000) % 10;
	wan = num / 10000;

	printf("��λ : %d\n", wan);
	printf("ǧλ : %d\n", qian);
	printf("��λ : %d\n", bai);
	printf("ʮλ : %d\n", shi);
	printf("��λ : %d\n", ge);

	return 0;

}


