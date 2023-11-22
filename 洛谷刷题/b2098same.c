#include <stdio.h>
#include <cstack>
int n,cnt[102],num[20001];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int p;
		scanf("%d",&p);
		num[p]++;
	}
	for(int i=10;i<=100;i++)
	{
		if(num[i])printf("%d ",i);
	}
	return 0;
}
