#include <stdio.h>
int main()
{
	int n;
	double sum;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		double tmp;
		scanf("%lf",&tmp);
		sum+=tmp;
	}
	printf("%lf",sum/n);
	return 0;
}
