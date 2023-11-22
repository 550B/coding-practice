#include <stdio.h>
int main()
{
	int x,n;
	scanf("%d%d",&x,&n);
	double population = x;
	for(int i=n;i>0;i--)
	{
		population*=1.001;
	}
	printf("%.4lf",population);
	return 0;
}
