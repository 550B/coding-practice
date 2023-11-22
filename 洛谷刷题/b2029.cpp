#include <stdio.h>
#include <cmath>
#define PI 3.14
int main()
{
	int h,r;
	scanf("%d%d",&h,&r);
	printf("%d",(int)(20000.0/(PI*r*r*h))+1);
	return 0;
}
