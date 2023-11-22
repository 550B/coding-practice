#include <stdio.h>
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	double tmp = (double)b/(double)a * 100;
	printf("%.3lf%%",tmp);
	return 0;
}
