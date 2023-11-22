#include <stdio.h>
int n;
double sum;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		if(i%2)sum+=1.0/i;
		else sum-=1.0/i;
	}
	printf("%.4lf",sum);
	return 0;
}
