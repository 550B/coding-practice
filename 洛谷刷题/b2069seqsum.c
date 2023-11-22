#include <stdio.h>
double sum=2;
int n,p=1,q=2;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int pp,qq;
		pp=q;qq=p+q;
		sum+=(double)qq/(double)pp;
		p=pp;q=qq;
	}
	printf("%.4lf",sum);
	return 0;
}
