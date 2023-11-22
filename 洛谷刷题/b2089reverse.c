#include <stdio.h>
int main()
{
	int n,num[101];
	scanf("%d",&n);
	for(int i=n-1;i>=0;i--)
	{
		scanf("%d",&num[i]);
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",num[i]);
	}
	return 0;
}
