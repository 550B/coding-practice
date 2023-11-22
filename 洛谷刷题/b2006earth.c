#include <stdio.h>
int main()
{
	int x,a,y,b;
	scanf("%d%d%d%d",&x,&a,&y,&b);
	double t,z;
	t=(double)(a*x-b*y)/(double)(a-b);
	printf("%.2f",t);
	return 0;
}
