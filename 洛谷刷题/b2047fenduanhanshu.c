#include <stdio.h>
int main()
{
	float x;
	scanf("%f",&x);
	if(x>=0&&x<5)printf("%.3f",2.5-x);
	else if(x>=5&&x<10)printf("%.3f",2-1.5*(x-3)*(x-3));
	else printf("%.3f",x/2-1.5);
	return 0;
}
