#include <stdio.h>
int n;
double res=2,tmp=1;
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		tmp*=1.0/i;
		res+=tmp;
	}
	printf("%.10lf",res);
	return 0;
}
