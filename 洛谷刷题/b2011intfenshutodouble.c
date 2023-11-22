#include <stdio.h>
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	double tmp = (double)a/(double)b;
	printf("%.9lf",tmp);
	return 0;
}
