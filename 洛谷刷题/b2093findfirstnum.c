#include <stdio.h>
int main()
{
	int n,num[10001],x;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	scanf("%d",&x);
	int j;
	for(j=0;j<n;j++)
	{
		if(x==num[j])
		{
			printf("%d",j);
			break;
		}
	}
	if(j==n)printf("%d",-1);
	return 0;
}
