#include <stdio.h>
int n,a,b;
double x,y;
int main()
{
	scanf("%d",&n);
	scanf("%d%d",&a,&b);
	x=(double)b/(double)a;
	for(int i=n-1;i>0;i--)
	{
		scanf("%d%d",&a,&b);
		y=(double)b/(double)a;
		if(y-x>0.05)printf("better\n");
		else if(x-y>0.05)printf("worse\n");
		else printf("same\n");
	}
	return 0;
}
