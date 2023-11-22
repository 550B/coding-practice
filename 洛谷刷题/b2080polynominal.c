#include <stdio.h>
#include <math.h>
double x;
int n;
double res;
int main()
{
	scanf("%lf%d",&x,&n);
	res=1.0*(1-pow(x,n+1))/(1-x);
	printf("%.2lf",res);
	return 0;
} 
