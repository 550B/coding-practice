#include <stdio.h>
int i,j,N=400000;
int a[400000];
int main()
{
	int k;
	scanf("%d",&k);
	a[0]=a[1]=1;
	for(i=2;i<=N;i++)
	{
		if(a[i]!=1)
		{
			j=2;
			while(i*j<=N)
			{
				a[i*j]=1;
				j++;
			}
		}
	}
	for(i=0;i<N;i++)
	{
		if(a[i]==0)k--;
		if(k==0)
		{
			printf("%d",i);
			break;
		}
	}
	return 0;
}
